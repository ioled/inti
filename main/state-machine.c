

enum States
{
    INIT,
    AP_MODE,
    SEARCHING_NETWORK,
    CONNECTED_TO_MQTT
};

enum States current_state;

void state_machine() {
    switch(current_state){
        case INIT:
            ESP_LOGI(TAG, "Cambiando al estado INIT");

            turn_strip_led_color(WHITE);
            wifi_init_sta();
            obtain_time();
            break;
        case AP_MODE:
            ESP_LOGI(TAG, "Cambiando al estado AP");
            break;
        case SEARCHING_NETWORK:
            ESP_LOGI(TAG, "Cambiando al estado SEARCHING_NETWORK");
            turn_strip_led_color(WHITE);
            break;
        case CONNECTED_TO_MQTT:
            ESP_LOGI(TAG,"Cambiando al estado CONNECTED_TO_MQTT");
            turn_strip_led_color(GREEN);
            break;
        default:
            ESP_LOGI(TAG," ");        
    }
}

void set_current_state(enum States input_current_state){
    current_state = input_current_state;
    state_machine();
}
