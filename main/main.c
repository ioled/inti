#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "led_strip.h"

#include "nvs_flash.h"

#include "lwip/err.h"
#include "lwip/sys.h"

#include "constants.c"

#include "wifi.c"

static uint8_t s_led_state = 0;
static led_strip_t *pStrip_a;

static void init_esp(void)
{   
    //Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    ESP_LOGI(TAG, "Initializing esp32 - iOLED Inti");

    /* LED strip initialization with the GPIO and pixels number*/
    ESP_LOGI(TAG, "Initializing Neopixel in pin %d:", NEOPIXEL_GPIO);
    pStrip_a = led_strip_init(0, NEOPIXEL_GPIO, NEOPIXEL_NUM_PIXELS);
    /* Set all LED off to clear all pixels */
    pStrip_a->clear(pStrip_a, 50);
}

static void blink_led(void)
{
    /* If the addressable LED is enabled */
    if (s_led_state) {
        /* Set the LED pixel using RGB from 0 (0%) to 255 (100%) for each color */
        pStrip_a->set_pixel(pStrip_a, 0, 0, 16, 0);
        pStrip_a->set_pixel(pStrip_a, 1, 0, 16, 0);
        pStrip_a->set_pixel(pStrip_a, 2, 0, 16, 0);
        pStrip_a->set_pixel(pStrip_a, 3, 0, 16, 0);
        pStrip_a->set_pixel(pStrip_a, 4, 0, 16, 0);

        /* Refresh the strip to send data */
        pStrip_a->refresh(pStrip_a, 100);
    } else {
        /* Set all LED off to clear all pixels */
        pStrip_a->clear(pStrip_a, 50);
    }
}

/* --------------- */

void app_main(void)
{
    init_esp();

    ESP_LOGI(TAG, "ESP_WIFI_MODE_STA");
    wifi_init_sta();

    while (1) {
        ESP_LOGI(TAG, "Turning the LED %s!", s_led_state == true ? "ON" : "OFF");
        blink_led("Buscando ");
        /* Toggle the LED state */
        s_led_state = !s_led_state;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}