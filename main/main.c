#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#include "led_strip.h"

#include "nvs.h"
#include "nvs_flash.h"

#include "lwip/err.h"
#include "lwip/sys.h"

#include "constants.c"

#include "wifi.c"
#include "sntp.c"
#include "led.c"
#include "neopixel.c"
#include "google-iot-core.c"

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

    ESP_LOGI(TAG, "Initializing signal led in pin %d", SIGNAL_LED_GPIO);
    example_ledc_init();
}


/* --------------- */

void app_main(void)
{   
    init_esp();

    set_current_state(INIT);

    xTaskCreate(&mqtt_task, "mqtt_task", 8192, NULL, 5, NULL);
    
}

