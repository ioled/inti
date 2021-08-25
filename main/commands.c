#include "ota.c"

/*  Executes a routine depending on the type of command received 
    by the device from the Iot Core.  */
void apply_command(char* command_from_iot_core)
{   
    int compare_string_with_reset_result;
    compare_string_with_reset_result = strcmp(command_from_iot_core,  "\"reset\"");

    int compare_string_with_ota_result;
    compare_string_with_ota_result = strcmp(command_from_iot_core,  "\"ota\"");

    if (compare_string_with_reset_result == 0) {
        ESP_LOGI(TAG, "Restarting now ...");
        fflush(stdout);
        esp_restart();
    } 

    if (compare_string_with_ota_result == 0) {
        ESP_LOGI(TAG, "Update !");    
        turn_strip_led_color(PURPLE);
        xTaskCreate(&simple_ota_example_task, "ota_example_task", 8192, NULL, 5, NULL);
    
    } 
}