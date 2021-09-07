#include <si7021.h>

#define SDA_GPIO 32
#define SCL_GPIO 33

void temperature_filter(float temperature_to_filter){
    // ESP_LOGI(TAG, "Temperature to filter %.2f\n", temperature_to_filter);
    temperature = temperature_to_filter;
}

void humidity_filter(float humidity_to_filter){
    // ESP_LOGI(TAG, "humidity to filter %.2f\n", humidity_to_filter);
    humidity = humidity_to_filter;
}

/*  Task to sensor humidity and temperatura */
void task_sensor(void *pvParameters)
{
    i2c_dev_t dev;
    memset(&dev, 0, sizeof(i2c_dev_t));

    ESP_ERROR_CHECK(si7021_init_desc(&dev, 0, SDA_GPIO, SCL_GPIO));

    float val;
    esp_err_t res;

    while (1)
    {        
        res = si7021_measure_temperature(&dev, &val);
        if (res != ESP_OK)
            printf("Could not measure temperature: %d (%s)\n", res, esp_err_to_name(res));
        else {
            // printf("Temperature: %.2f\n", val);
            temperature_filter(val);
        }

        res = si7021_measure_humidity(&dev, &val);
        if (res != ESP_OK)
            printf("Could not measure humidity: %d (%s)\n", res, esp_err_to_name(res));
        else {
            // printf("Humidity: %.2f\n", val);
            humidity_filter(val);
        }

        vTaskDelay(pdMS_TO_TICKS(1000));


       

    }

    
}


