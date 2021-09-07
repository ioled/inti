#include "lwip/apps/sntp.h"
#include <time.h>

static void initialize_sntp(void)
{
    ESP_LOGI(TAG, "Initializing SNTP");
    sntp_setoperatingmode(SNTP_OPMODE_POLL);
    sntp_setservername(0, "time.google.com");
    sntp_init();
}

static void obtain_time(void)
{
    initialize_sntp();
    // Wait for time to be set
    time_t now = 0;
    char strftime_buf[64];

    struct tm timeinfo = {0};

    int retry = 0;
    const int retry_count = 15;

    while (timeinfo.tm_year < (2016 - 1900) && ++retry < retry_count) {
        ESP_LOGI(TAG, "Waiting for system time to be set... (%d/%d)", retry, retry_count);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        time(&now);

        // Set timezone to Chile Standard Time
        setenv("TZ", "CLST3", 1);
        tzset();

        localtime_r(&now, &timeinfo);
        
    }
    strftime(strftime_buf, sizeof(strftime_buf), "%c", &timeinfo);

    ESP_LOGI(TAG, "Time is set...");
    ESP_LOGI(TAG, "The current date/time in Chile is: %s", strftime_buf);

    // setup datetime: 2016-10-09 13:50:10
    i2c_dev_t dev;
    memset(&dev, 0, sizeof(i2c_dev_t));
    ESP_ERROR_CHECK(ds3231_init_desc(&dev, 0, SDA_GPIO, SCL_GPIO));

    struct tm time = {
        .tm_year = (int) timeinfo.tm_year, //since 1900 (2016 - 1900)
        .tm_mon  = (int) timeinfo.tm_mon,  // 0-based
        .tm_mday = (int) timeinfo.tm_mday,
        .tm_hour = (int) timeinfo.tm_hour,
        .tm_min  = (int) timeinfo.tm_min,
        .tm_sec  = (int) timeinfo.tm_sec
    };
    ESP_ERROR_CHECK(ds3231_set_time(&dev, &time));
}