#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"
#include "driver/gpio.h"

#include "led_strip.h"

#include "nvs.h"
#include "nvs_flash.h"

#include "lwip/err.h"
#include "lwip/sys.h"

#include "cJSON.c"

/* Wifi SSID */
char wifi_ssid[32] = "VTR-8111353";

/* Wifi password */
char wifi_pass[64] = "dkYxgw2C4mmm";

/* Wifi mode */
char wifi_mode[10] = "STA";

#include "constants.c"
#include "neopixel.c"
#include "wifi.c"
#include "sntp.c"
#include "state-machine.c"
#include "nvs.c"
#include "gpio_handler.c"
#include "led.c"
#include "google-iot-core.c"
#include "http_server.c"

static void init_esp(void)
{      
    //Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      // 1.OTA app partition table has a smaller NVS partition size than the non-OTA
      // partition table. This size mismatch may cause NVS initialization to fail.
      // 2.NVS partition contains data in new format and cannot be recognized by this version of code.
      // If this happens, we erase NVS partition and initialize NVS again.
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    get_sha256_of_partitions();

    ESP_LOGI(TAG, "Initializing esp32 - iOLED Inti");

    /* LED strip initialization with the GPIO and pixels number*/
    ESP_LOGI(TAG, "Initializing Neopixel in pin %d", NEOPIXEL_GPIO);
    pStrip_a = led_strip_init(0, NEOPIXEL_GPIO, NEOPIXEL_NUM_PIXELS);
    /* Set all LED off to clear all pixels */
    pStrip_a->clear(pStrip_a, 50);

    ESP_LOGI(TAG, "Initializing integrated led in pin %d", INTEGRATED_LED_GPIO);
    gpio_reset_pin(INTEGRATED_LED_GPIO);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(INTEGRATED_LED_GPIO, GPIO_MODE_OUTPUT);

    ESP_LOGI(TAG, "Initializing relay in pin %d", RELAY_GPIO);
    gpio_reset_pin(RELAY_GPIO);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(RELAY_GPIO, GPIO_MODE_OUTPUT);

    ESP_LOGI(TAG, "Initializing signal led in pin %d\n", SIGNAL_LED_GPIO);
    example_ledc_init();

    ESP_LOGI(TAG, "Initializing button in pin %d\n", INTERNAL_BUTTON);
    set_button();

    int duty = read_duty_from_nvs();
    apply_led_percent((float)(duty) / 100);  

    read_wifi_mode_from_nvs();
    
    read_wifi_credentials_from_nvs(); 

}

/* ----------------------------------------------------------------------------------------- */

void app_main(void)
{   
    init_esp();

    int compare_string_with_wifi_mode = strcmp(wifi_mode,  "STA");

    if (compare_string_with_wifi_mode == 0) {
      set_current_state(INIT);
      xTaskCreate(&mqtt_task, "mqtt_task", 8192, NULL, 5, NULL);
    } else {
      set_current_state(AP_MODE);
      write_wifi_mode_in_nvs("STA");

      httpd_handle_t server = NULL;    

      // /* Start the server for the first time */
      server = start_webserver();
    }

    while (1) {            
      vTaskDelay(1* 60 * 1000 / portTICK_PERIOD_MS);
      ESP_LOGI(TAG, "Restarting now ..."); 
      fflush(stdout);
      esp_restart();               
    }

}




