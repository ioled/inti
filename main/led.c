#include "driver/ledc.h"

#define LEDC_TIMER              LEDC_TIMER_0
#define LEDC_MODE               LEDC_LOW_SPEED_MODE
#define LEDC_CHANNEL            LEDC_CHANNEL_0
#define LEDC_DUTY_RES           LEDC_TIMER_13_BIT   // Set duty resolution to 13 bits
#define LEDC_DUTY_EXAMPLE       (4095)              // Set duty to 50%. ((2 ** 13) - 1) * 50% = 4095
#define LEDC_FREQUENCY          (5000)              // Frequency in Hertz. Set frequency at 5 kHz

#define RELAY_GPIO 13

#define SIGNAL_LED_GPIO 4

void example_ledc_init(void)
{
    // Prepare and then apply the LEDC PWM timer configuration
    ledc_timer_config_t ledc_timer = {
        .speed_mode       = LEDC_MODE,
        .timer_num        = LEDC_TIMER,
        .duty_resolution  = LEDC_DUTY_RES,
        .freq_hz          = LEDC_FREQUENCY,  // Set output frequency at 5 kHz
        .clk_cfg          = LEDC_AUTO_CLK
    };
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));

    // Prepare and then apply the LEDC PWM channel configuration
    ledc_channel_config_t ledc_channel = {
        .speed_mode     = LEDC_MODE,
        .channel        = LEDC_CHANNEL,
        .timer_sel      = LEDC_TIMER,
        .intr_type      = LEDC_INTR_DISABLE,
        .gpio_num       = SIGNAL_LED_GPIO,
        .duty           = 0, // Set duty to 0%
        .hpoint         = 0
    };
    ESP_ERROR_CHECK(ledc_channel_config(&ledc_channel));
}

/*  Apply the percentage on the signal to the LED panel and keep the relay on. 
    In case of receiving a percentage of 0, the relay is turned off.  */
void apply_led_percent(float percent_from_iot_core)
{   
    if (percent_from_iot_core > 0) {
        // Turn on relay
        gpio_set_level(RELAY_GPIO, true);

        float percent_to_binary = percent_from_iot_core * 8191;
        ESP_ERROR_CHECK(ledc_set_duty(LEDC_MODE, LEDC_CHANNEL, (int)percent_to_binary));

        // Update duty to apply the new value
        ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, LEDC_CHANNEL));
    } else {
        gpio_set_level(RELAY_GPIO, false);
    }
}
