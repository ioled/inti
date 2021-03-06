#include <iotc.h>
#include <iotc_jwt.h>

#include "commands.c"

#define IOTC_UNUSED(x) (void)(x)

#define DEVICE_PATH "projects/%s/locations/%s/registries/%s/devices/%s"
#define SUBSCRIBE_TOPIC_COMMAND "/devices/%s/commands/#"
#define SUBSCRIBE_TOPIC_CONFIG "/devices/%s/config"
#define PUBLISH_TOPIC_EVENT "/devices/%s/events"
#define PUBLISH_TOPIC_STATE "/devices/%s/state"
#define DATA_TO_PUBLISH "{\"hum\": %f, \"temp\": %f, \"duty\": %f, \"rtc_time\": \"%d-%d-%d %d:%d:%d\"}"
#define STATE_TO_PUBLISH "{\"firmware_version\": \"%s\", \"sensor_healh_ok\": \"%s\", \"rtc_time\": \"%d-%d-%d %d:%d:%d\"}"

char *subscribe_topic_command, *subscribe_topic_config;

iotc_mqtt_qos_t iotc_example_qos = IOTC_MQTT_QOS_AT_LEAST_ONCE;
static iotc_timed_task_handle_t delayed_publish_task =
    IOTC_INVALID_TIMED_TASK_HANDLE;
iotc_context_handle_t iotc_context = IOTC_INVALID_CONTEXT_HANDLE;

/** Publish message in topic event 
 * event: {"hum": 58.876556, "temp": 18.069016, "duty": 0.100000}
*/
void publish_telemetry_event(iotc_context_handle_t context_handle,
                             iotc_timed_task_handle_t timed_task, void *user_data)
{
    IOTC_UNUSED(timed_task);
    IOTC_UNUSED(user_data);

    char *publish_topic = NULL;
    asprintf(&publish_topic, PUBLISH_TOPIC_EVENT, device_id);
    char *publish_message = NULL;
    
    int duty = read_duty_from_nvs(1);

    int compare_string_with_timer_state;
    read_timer_configuration_from_nvs(1);
    compare_string_with_timer_state = strcmp(timer_state,  "true");
                
    if (compare_string_with_timer_state == 0){
        asprintf(&publish_message, DATA_TO_PUBLISH, humidity, temperature, ((float)(duty) / 100) * y_hour[global_time_hour], global_time_year, global_time_mon, global_time_mday, global_time_hour, global_time_min, global_time_sec);
    } else {
        asprintf(&publish_message, DATA_TO_PUBLISH, humidity, temperature, ((float)(duty) / 100), global_time_year, global_time_mon, global_time_mday, global_time_hour, global_time_min, global_time_sec);
    }

    ESP_LOGI(TAG, "Publishing msg \"%s\" to topic: \"%s\"\n", publish_message, publish_topic);

    iotc_publish(context_handle, publish_topic, publish_message,
                 iotc_example_qos,
                 /*callback=*/NULL, /*user_data=*/NULL);
    free(publish_topic);
    free(publish_message);
}

void iotc_mqttlogic_subscribe_config_callback(
    iotc_context_handle_t in_context_handle, iotc_sub_call_type_t call_type,
    const iotc_sub_call_params_t *const params, iotc_state_t state,
    void *user_data)
{
    IOTC_UNUSED(in_context_handle);
    IOTC_UNUSED(call_type);
    IOTC_UNUSED(state);
    IOTC_UNUSED(user_data);
    if (params != NULL && params->message.topic != NULL) {
        ESP_LOGI(TAG, "Subscription Topic: %s", params->message.topic);
        char *sub_message = (char *)malloc(params->message.temporary_payload_data_length + 1);
        if (sub_message == NULL) {
            ESP_LOGE(TAG, "Failed to allocate memory");
            return;
        }
        memcpy(sub_message, params->message.temporary_payload_data, params->message.temporary_payload_data_length);
        sub_message[params->message.temporary_payload_data_length] = '\0';
        ESP_LOGI(TAG, "Message Payload: %s ", sub_message);

        char* duty_str = NULL;
        char* timer_state_str = NULL;
        char* time_on_str = NULL;
        char* time_off_str = NULL;

        float percent_from_iot_core;

        // Parse data from IoT Core. Go to end if receive null from IoT Core
        cJSON *json = cJSON_Parse(sub_message);
        if (json == NULL)
        {
            const char *error_ptr = cJSON_GetErrorPtr();
            if (error_ptr != NULL)
            {
                ESP_LOGI(TAG, "Reciving null message from IoT Core");
            }
            goto end;
        }

        cJSON *esp = cJSON_GetObjectItemCaseSensitive(json, "esp");
        
        cJSON *led1 = cJSON_GetObjectItemCaseSensitive(esp, "led1");
        cJSON *duty = cJSON_GetObjectItemCaseSensitive(led1, "duty");

        cJSON *timer = cJSON_GetObjectItemCaseSensitive(esp, "timer");
        cJSON *timer_state_json = cJSON_GetObjectItemCaseSensitive(timer, "timerState");
        cJSON *time_on_json = cJSON_GetObjectItemCaseSensitive(timer, "timeOn");
        cJSON *time_off_json = cJSON_GetObjectItemCaseSensitive(timer, "timeOff");

        duty_str = cJSON_Print(duty);
        ESP_LOGI(TAG, "duty: %s \n", duty_str);

        timer_state_str = cJSON_Print(timer_state_json);
        ESP_LOGI(TAG, "timer state: %s \n", timer_state_str);

        time_on_str = cJSON_Print(time_on_json);
        ESP_LOGI(TAG, "time on: %s \n", time_on_str);

        time_off_str = cJSON_Print(time_off_json);
        ESP_LOGI(TAG, "time off: %s \n", time_off_str);

        percent_from_iot_core = duty->valuedouble;

        write_duty_in_nvs((int)(percent_from_iot_core * 100));

        write_timer_configuration_in_nvs(timer_state_str, time_on_str, time_off_str);

        int compare_string_with_timer_state;
        compare_string_with_timer_state = strcmp(timer_state_str,  "true");
                
        if (compare_string_with_timer_state == 0){
            int hour_on = (time_on_str[1] - 48) * 10 + (time_on_str[2] - 48);
            int hour_off = (time_off_str[1] - 48) * 10 + (time_off_str[2] - 48);
            create_vector_time_hour(hour_on , hour_off);
        } else {
            apply_led_percent(percent_from_iot_core , 1);
        }

        end: 
            cJSON_Delete(json);                
        free(sub_message);

        // Finish of message received from IoT Core
        /* Publish event when receive configuration from IoT Core*/
        char *publish_topic = NULL;
        asprintf(&publish_topic, PUBLISH_TOPIC_EVENT, device_id);

        char *publish_message = NULL;

        int dutyFromMemory = read_duty_from_nvs(1);

        read_timer_configuration_from_nvs(1);
        compare_string_with_timer_state = strcmp(timer_state,  "true");
                    
        if (compare_string_with_timer_state == 0){
            asprintf(&publish_message, DATA_TO_PUBLISH, humidity, temperature, ((float)(dutyFromMemory) / 100) * y_hour[global_time_hour], global_time_year, global_time_mon, global_time_mday, global_time_hour, global_time_min, global_time_sec);
        } else {
            asprintf(&publish_message, DATA_TO_PUBLISH, humidity, temperature, ((float)(dutyFromMemory) / 100), global_time_year, global_time_mon, global_time_mday, global_time_hour, global_time_min, global_time_sec);
        }

        ESP_LOGI(TAG, "Publishing msg \"%s\" to topic: \"%s\"\n", publish_message, publish_topic);

        iotc_publish(in_context_handle, publish_topic, publish_message,
                    iotc_example_qos,
                    /*callback=*/NULL, /*user_data=*/NULL);
        free(publish_topic);
        free(publish_message);
    }
}

void iotc_mqttlogic_subscribe_commands_callback(
    iotc_context_handle_t in_context_handle, iotc_sub_call_type_t call_type,
    const iotc_sub_call_params_t *const params, iotc_state_t state,
    void *user_data)
{
    IOTC_UNUSED(in_context_handle);
    IOTC_UNUSED(call_type);
    IOTC_UNUSED(state);
    IOTC_UNUSED(user_data);
    if (params != NULL && params->message.topic != NULL) {
        ESP_LOGI(TAG, "Subscription Topic: %s", params->message.topic);
        char *sub_message = (char *)malloc(params->message.temporary_payload_data_length + 1);
        if (sub_message == NULL) {
            ESP_LOGE(TAG, "Failed to allocate memory");
            return;
        }
        memcpy(sub_message, params->message.temporary_payload_data, params->message.temporary_payload_data_length);
        sub_message[params->message.temporary_payload_data_length] = '\0';
        ESP_LOGI(TAG, "Message Payload: %s ", sub_message);

        char* str = NULL;

        // Parse data from IoT Core. Go to end if receive null from IoT Core
        cJSON *json = cJSON_Parse(sub_message);
        if (json == NULL)
        {
            const char *error_ptr = cJSON_GetErrorPtr();
            if (error_ptr != NULL)
            {
                ESP_LOGI(TAG, "Reciving null message from IoT Core");
            }
            goto end;
        }

        cJSON *command = cJSON_GetObjectItemCaseSensitive(json, "command");
        
        str = cJSON_Print(command);

        apply_command(str);
    
        end: 
            cJSON_Delete(json);                
        free(sub_message);
    }
}

void on_connection_state_changed(iotc_context_handle_t in_context_handle,
                                 void *data, iotc_state_t state)
{
    iotc_connection_data_t *conn_data = (iotc_connection_data_t *)data;

    switch (conn_data->connection_state) {
    /* IOTC_CONNECTION_STATE_OPENED means that the connection has been
       established and the IoTC Client is ready to send/recv messages */
    case IOTC_CONNECTION_STATE_OPENED:
        ESP_LOGI(TAG, "Connected to IoT Core");

        // Change current state to: CONNECTED_TO_MQTT
        set_current_state(CONNECTED_TO_MQTT);

        /* Publish immediately upon connect. 'publish_function' is defined
           in this example file and invokes the IoTC API to publish a
           message. */
        asprintf(&subscribe_topic_command, SUBSCRIBE_TOPIC_COMMAND, device_id);
        ESP_LOGI(TAG, "Subscribing to topic: \"%s\"", subscribe_topic_command);
        iotc_subscribe(in_context_handle, subscribe_topic_command, IOTC_MQTT_QOS_AT_LEAST_ONCE,
                       &iotc_mqttlogic_subscribe_commands_callback, /*user_data=*/NULL);

        asprintf(&subscribe_topic_config, SUBSCRIBE_TOPIC_CONFIG, device_id);
        ESP_LOGI(TAG, "Subscribing to topic: \"%s\"", subscribe_topic_config);
        iotc_subscribe(in_context_handle, subscribe_topic_config, IOTC_MQTT_QOS_AT_LEAST_ONCE,
                       &iotc_mqttlogic_subscribe_config_callback, /*user_data=*/NULL);

        /* Create a timed task to publish every 300 seconds (5 minutes) */
        delayed_publish_task = iotc_schedule_timed_task(in_context_handle,
                               publish_telemetry_event, 300,
                               15, /*user_data=*/NULL);

        /* Publish state when the device connect with IoT Core */
        char *publish_topic = NULL;
        asprintf(&publish_topic, PUBLISH_TOPIC_STATE, device_id);
        char *publish_message = NULL;
                    
        asprintf(&publish_message, STATE_TO_PUBLISH, TAG, sensor_health_ok, global_time_year, global_time_mon, global_time_mday, global_time_hour, global_time_min, global_time_sec);

        ESP_LOGI(TAG, "Publishing msg \"%s\" to topic: \"%s\"\n", publish_message, publish_topic);

        iotc_publish(in_context_handle, publish_topic, publish_message,
                    iotc_example_qos,
                    /*callback=*/NULL, /*user_data=*/NULL);

        free(publish_topic);
        free(publish_message);

        /* Publish event when the device connect with IoT Core */
        asprintf(&publish_topic, PUBLISH_TOPIC_EVENT, device_id);
        publish_message = NULL;
        
        int duty = read_duty_from_nvs(1);

        int compare_string_with_timer_state;
        read_timer_configuration_from_nvs(1);
        compare_string_with_timer_state = strcmp(timer_state,  "true");
                    
        if (compare_string_with_timer_state == 0){
            asprintf(&publish_message, DATA_TO_PUBLISH, humidity, temperature, ((float)(duty) / 100) * y_hour[global_time_hour], global_time_year, global_time_mon, global_time_mday, global_time_hour, global_time_min, global_time_sec);
        } else {
            asprintf(&publish_message, DATA_TO_PUBLISH, humidity, temperature, ((float)(duty) / 100), global_time_year, global_time_mon, global_time_mday, global_time_hour, global_time_min, global_time_sec);
        }

        ESP_LOGI(TAG, "Publishing msg \"%s\" to topic: \"%s\"\n", publish_message, publish_topic);

        iotc_publish(in_context_handle, publish_topic, publish_message,
                    iotc_example_qos,
                    /*callback=*/NULL, /*user_data=*/NULL);
        free(publish_topic);
        free(publish_message);

        break;

    /* IOTC_CONNECTION_STATE_OPEN_FAILED is set when there was a problem
       when establishing a connection to the server. The reason for the error
       is contained in the 'state' variable. Here we log the error state and
       exit out of the application. */

    /* Publish immediately upon connect. 'publish_function' is defined
       in this example file and invokes the IoTC API to publish a
       message. */
    case IOTC_CONNECTION_STATE_OPEN_FAILED:
        ESP_LOGE(TAG, "ERROR! Connection has failed reason %d", state);

        set_current_state(ERROR);

        /* exit it out of the application by stopping the event loop. */
        iotc_events_stop();
        break;

    /* IOTC_CONNECTION_STATE_CLOSED is set when the IoTC Client has been
       disconnected. The disconnection may have been caused by some external
       issue, or user may have requested a disconnection. In order to
       distinguish between those two situation it is advised to check the state
       variable value. If the state == IOTC_STATE_OK then the application has
       requested a disconnection via 'iotc_shutdown_connection'. If the state !=
       IOTC_STATE_OK then the connection has been closed from one side. */
    case IOTC_CONNECTION_STATE_CLOSED:
        free(subscribe_topic_command);
        free(subscribe_topic_config);
        /* When the connection is closed it's better to cancel some of previously
           registered activities. Using cancel function on handler will remove the
           handler from the timed queue which prevents the registered handle to be
           called when there is no connection. */
        if (IOTC_INVALID_TIMED_TASK_HANDLE != delayed_publish_task) {
            iotc_cancel_timed_task(delayed_publish_task);
            delayed_publish_task = IOTC_INVALID_TIMED_TASK_HANDLE;
        }

        if (state == IOTC_STATE_OK) {
            /* The connection has been closed intentionally. Therefore, stop
               the event processing loop as there's nothing left to do
               in this example. */
            iotc_events_stop();
        } else {
            ESP_LOGE(TAG, "Connection closed - reason %d!", state);
            /* The disconnection was unforeseen.  Try reconnect to the server
            with previously set configuration, which has been provided
            to this callback in the conn_data structure. */

            set_current_state(SEARCHING_NETWORK);

            iotc_connect(
                in_context_handle, conn_data->username, conn_data->password, conn_data->client_id,
                conn_data->connection_timeout, conn_data->keepalive_timeout,
                &on_connection_state_changed);
        }
        break;

    default:
        ESP_LOGE(TAG, "Incorrect connection state value.");
        break;
    }
}

static void mqtt_task(void *pvParameters)
{   
    /* Format the key type descriptors so the client understands
     which type of key is being represented. In this case, a PEM encoded
     byte array of a ES256 key. */
    iotc_crypto_key_data_t iotc_connect_private_key_data;
    iotc_connect_private_key_data.crypto_key_signature_algorithm = IOTC_CRYPTO_KEY_SIGNATURE_ALGORITHM_ES256;
    iotc_connect_private_key_data.crypto_key_union_type = IOTC_CRYPTO_KEY_UNION_TYPE_PEM;
    iotc_connect_private_key_data.crypto_key_union.key_pem.key = (char *) key_in_c;

    /* initialize iotc library and create a context to use to connect to the
    * GCP IoT Core Service. */
    const iotc_state_t error_init = iotc_initialize();

    if (IOTC_STATE_OK != error_init) {
        ESP_LOGE(TAG, " IoT Core failed to initialize, error: %d", error_init);
        vTaskDelete(NULL);
    }

    /*  Create a connection context. A context represents a Connection
        on a single socket, and can be used to publish and subscribe
        to numerous topics. */
    iotc_context = iotc_create_context();
    if (IOTC_INVALID_CONTEXT_HANDLE >= iotc_context) {
        ESP_LOGE(TAG, " IoT Core failed to create context, error: %d", -iotc_context);
        vTaskDelete(NULL);
    }

    /*  Queue a connection request to be completed asynchronously.
        The 'on_connection_state_changed' parameter is the name of the
        callback function after the connection request completes, and its
        implementation should handle both successful connections and
        unsuccessful connections as well as disconnections. */
    const uint16_t connection_timeout = 0;
    const uint16_t keepalive_timeout = 60;

    /* Generate the client authentication JWT, which will serve as the MQTT
     * password. */
    char jwt[IOTC_JWT_SIZE] = {0};
    size_t bytes_written = 0;
    iotc_state_t state = iotc_create_iotcore_jwt(
                             CONFIG_GIOT_PROJECT_ID,
                             /*jwt_expiration_period_sec=*/86400, &iotc_connect_private_key_data, jwt,
                             IOTC_JWT_SIZE, &bytes_written);

    if (IOTC_STATE_OK != state) {
        ESP_LOGE(TAG, "iotc_create_iotcore_jwt returned with error: %ul", state);
        vTaskDelete(NULL);
    }

    char *device_path = NULL;
    asprintf(&device_path, DEVICE_PATH, CONFIG_GIOT_PROJECT_ID, CONFIG_GIOT_LOCATION, CONFIG_GIOT_REGISTRY_ID, device_id);
    iotc_connect(iotc_context, NULL, jwt, device_path, connection_timeout,
                 keepalive_timeout, &on_connection_state_changed);
    free(device_path);
    /* The IoTC Client was designed to be able to run on single threaded devices.
        As such it does not have its own event loop thread. Instead you must
        regularly call the function iotc_events_process_blocking() to process
        connection requests, and for the client to regularly check the sockets for
        incoming data. This implementation has the loop operate endlessly. The loop
        will stop after closing the connection, using iotc_shutdown_connection() as
        defined in on_connection_state_change logic, and exit the event handler
        handler by calling iotc_events_stop(); */
    iotc_events_process_blocking();

    iotc_delete_context(iotc_context);

    iotc_shutdown();

    vTaskDelete(NULL);
}