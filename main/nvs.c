/*  Read wifi credentials from NVS (ioled_data partition)  */
char* read_wifi_credentials(){
    //Initialize NVS iOLED partition
    esp_err_t err = nvs_flash_init_partition("ioled_data");
    
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init_partition("ioled_data");
    }
    ESP_ERROR_CHECK(err);

    // Open
    ESP_LOGI(TAG, "Opening Non-Volatile Storage (NVS) partition... ");
    nvs_handle_t my_handle;
    err = nvs_open("storage", NVS_READWRITE, &my_handle);
    if (err != ESP_OK) {
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
        return " ";
    } else {
        ESP_LOGI(TAG, "Done\n");

        // Read
        ESP_LOGI(TAG, "Reading wifi ssid credential from NVS ... ");

        char wifi_ssid_example [128] = "wifi network ssid example";

        char wifi_ssid_readed [128];
        size_t required_size = sizeof(wifi_ssid_example);

        err = nvs_get_str(my_handle, "wifi_ssid", wifi_ssid_readed, &required_size);

        // char *str = malloc(sizeof(wifi_ssid_readed));

        switch (err) {
            case ESP_OK:
                ESP_LOGI(TAG, "Wifi SSID = %s\n", wifi_ssid_readed);
                break;
            case ESP_ERR_NVS_NOT_FOUND:
                ESP_LOGI(TAG, "The value is not initialized yet!\n");
                break;
            default :
                ESP_LOGI(TAG, "Error (%s) reading!\n", esp_err_to_name(err));
        }

        // Close
        nvs_close(my_handle);

        return wifi_ssid_readed;
    }
}

/*  Write wifi credentials in NVS (ioled_data partition)  */
void write_wifi_credentials(char wifi_ssid_to_write){
    //Initialize NVS iOLED partition
    esp_err_t err = nvs_flash_init_partition("ioled_data");
    // esp_err_t err = nvs_flash_init();

    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init_partition("ioled_data");
    }
    ESP_ERROR_CHECK(err);

    // Open
    ESP_LOGI(TAG, "Opening Non-Volatile Storage (NVS) partition... ");
    nvs_handle_t my_handle;
    err = nvs_open("storage", NVS_READWRITE, &my_handle);
    if (err != ESP_OK) {
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
    } else {
        ESP_LOGI(TAG, "Done\n");
            
        // Write
        ESP_LOGI(TAG, "Updating wifi ssid credential in NVS ... ");

        err = nvs_set_str(my_handle, "wifi_ssid", &wifi_ssid_to_write);

        // ESP_LOGI(TAG, (err != ESP_OK) ? "Failed!\n" : "Done\n");
 
        // Commit written value.
        // After setting any values, nvs_commit() must be called to ensure changes are written
        // to flash storage. Implementations may write to storage at other times,
        // but this is not guaranteed.
        ESP_LOGI(TAG, "Committing updates in NVS ... ");
        err = nvs_commit(my_handle);        
        // ESP_LOGI(TAG, (err != ESP_OK) ? "Failed!\n" : "Done\n");

        // Close
        nvs_close(my_handle);
    }
}

/*  Write duty to NVS (ioled_data partition)  */
void write_duty(int duty_to_save){
    //Initialize NVS iOLED partition
    esp_err_t err = nvs_flash_init_partition("ioled_data");
    // esp_err_t err = nvs_flash_init();

    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init_partition("ioled_data");
    }
    ESP_ERROR_CHECK(err);

    // Open
    nvs_handle_t my_handle;
    err = nvs_open("storage", NVS_READWRITE, &my_handle);
    if (err != ESP_OK) {
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
    } else {            
        // Write
        ESP_LOGI(TAG, "Updating duty in NVS ... ");

        err = nvs_set_i32(my_handle, "duty", duty_to_save);

        switch (err) {
            case ESP_OK:
                ESP_LOGI(TAG, "Duty: %d\n", duty_to_save);
                break;
            default :
                ESP_LOGI(TAG, "Error (%s) reading!\n", esp_err_to_name(err));
        }
 
        // Commit written value.
        // After setting any values, nvs_commit() must be called to ensure changes are written
        // to flash storage. Implementations may write to storage at other times,
        // but this is not guaranteed.
        err = nvs_commit(my_handle);                       
        // Close
        nvs_close(my_handle);
    }
}

/*  Read duty from NVS (ioled_data partition)  saved previously */ 
int read_duty_from_nvs(){
    //Initialize NVS iOLED partition
    esp_err_t err = nvs_flash_init_partition("ioled_data");
    // esp_err_t err = nvs_flash_init();

    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init_partition("ioled_data");
    }
    ESP_ERROR_CHECK(err);

    // Open
    ESP_LOGI(TAG, "Opening Non-Volatile Storage (NVS) partition... ");
    nvs_handle_t my_handle;
    err = nvs_open("storage", NVS_READWRITE, &my_handle);
    if (err != ESP_OK) {
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
        return 0;
    } else {
        ESP_LOGI(TAG, "Done\n");
            
        // Read
        ESP_LOGI(TAG, "Reading duty from NVS ... ");

        int32_t duty_in_nvs;
        err = nvs_get_i32(my_handle, "duty", &duty_in_nvs);

        switch (err) {
            case ESP_OK:
                ESP_LOGI(TAG, "Duty = %d\n", duty_in_nvs);
                break;
            default :
                ESP_LOGI(TAG, "Error (%s) reading!\n", esp_err_to_name(err));
        }
                      
        // Close
        nvs_close(my_handle);
        return duty_in_nvs;
    }
}
    