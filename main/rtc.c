#include <ds3231.h>

int global_time_year;
int global_time_mon;
int global_time_mday;

int global_time_hour;
int global_time_min;
int global_time_sec;

void time_task()
{
    i2c_dev_t dev;
    memset(&dev, 0, sizeof(i2c_dev_t));
    ESP_ERROR_CHECK(ds3231_init_desc(&dev, 0, SDA_GPIO, SCL_GPIO));

    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(250));

        struct tm time = {
            .tm_year = 121, //since 1900 (2016 - 1900)
            .tm_mon  = 8,  // 0-based
            .tm_mday = 7,
            .tm_hour = 22,
            .tm_min  = 16,
            .tm_sec  = 0
        };

        if (ds3231_get_time(&dev, &time) != ESP_OK)
        {
            printf("Could not get time\n");
            continue;
        }

        // printf("%04d-%02d-%02d %02d:%02d:%02d \n", time.tm_year + 1900, time.tm_mon + 1,
        //     time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec);
        global_time_year = time.tm_year + 1900;
        global_time_mon = time.tm_mon + 1;
        global_time_mday = time.tm_mday;
        
        global_time_hour = time.tm_hour;
        global_time_min = time.tm_min;
        global_time_sec = time.tm_sec;
        
        int compare_string_with_timer_state;
        read_timer_configuration_from_nvs(0);
        compare_string_with_timer_state = strcmp(timer_state,  "true");
        if (compare_string_with_timer_state == 0) {
            if (y_hour[time.tm_hour] == 1) {
                int duty = read_duty_from_nvs(0);
                apply_led_percent((float)(duty) / 100, 0);   
                
            } else {
                apply_led_percent(0, 0);   
            }
        } else {
            int duty = read_duty_from_nvs(0);
            apply_led_percent((float)(duty) / 100, 0);
        }
    }
}
    
