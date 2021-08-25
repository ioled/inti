void state_machine() {
    switch(current_state){
        case INIT:
            ESP_LOGI(TAG, "Change state to: INIT");                             
            turn_strip_led_color(WHITE);
            wifi_init_sta();
            obtain_time();
            
            break;
        case AP_MODE:
            ESP_LOGI(TAG, "Change state to: AP");
            turn_strip_led_color(BLUE);
            ESP_LOGI(TAG, "ESP_WIFI_MODE_AP");
            wifi_init_softap();

            break;
        case SEARCHING_NETWORK:
            ESP_LOGI(TAG, "Change state to: SEARCHING_NETWORK");   
            turn_strip_led_color(ORANGE);
            
            for (int i = 60; i > 0; i-- ){
                ESP_LOGI(TAG, "Restarting in %d seconds ...", i);
                vTaskDelay(1 * 1000 / portTICK_PERIOD_MS);
            }

            ESP_LOGI(TAG, "Restarting now ..."); 
            fflush(stdout);
            esp_restart(); 

            break;
        case CONNECTED_TO_MQTT:
            ESP_LOGI(TAG,"Change state to: CONNECTED_TO_MQTT");
            turn_strip_led_color(GREEN);

            break;  

        case ERROR:
            ESP_LOGI(TAG,"Change state to: ERROR");
            turn_strip_led_color(RED);

            for (int i = 120; i > 0; i-- ){
                ESP_LOGI(TAG, "Restarting in %d seconds ...", i);
                vTaskDelay(1 * 1000 / portTICK_PERIOD_MS);
            }

            ESP_LOGI(TAG, "Restarting now ..."); 
            fflush(stdout);
            esp_restart(); 

            break; 

        default:
            ESP_LOGI(TAG," ");        
    }
}

void set_current_state(enum States input_current_state){
    current_state = input_current_state;
    state_machine();
}
