#include <ds3231.h>

void time_task()
{
    i2c_dev_t dev;
    memset(&dev, 0, sizeof(i2c_dev_t));
    ESP_ERROR_CHECK(ds3231_init_desc(&dev, 0, SDA_GPIO, SCL_GPIO));

    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(250));

        struct tm time = {
            .tm_year = 116, //since 1900 (2016 - 1900)
            .tm_mon  = 9,  // 0-based
            .tm_mday = 9,
            .tm_hour = 13,
            .tm_min  = 50,
            .tm_sec  = 10
        };

        if (ds3231_get_time(&dev, &time) != ESP_OK)
        {
            printf("Could not get time\n");
            continue;
        }

        /* float is used in printf(). you need non-default configuration in
         * sdkconfig for ESP8266, which is enabled by default for this
         * example. see sdkconfig.defaults.esp8266
         */
        printf("%04d-%02d-%02d %02d:%02d:%02d \n", time.tm_year + 1900 /*Add 1900 for better readability*/, time.tm_mon + 1,
            time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec);
    }
}
    
