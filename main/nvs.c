/*  Read wifi credentials from NVS (ioled_data partition)  */
void read_wifi_credentials(){
    //Initialize NVS iOLED partition
    esp_err_t err = nvs_flash_init_partition("ioled_data");
    
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
        // Read wifi ssid
        ESP_LOGI(TAG, "Reading wifi ssid credential from NVS ... ");

        char wifi_ssid_example [32] = "wifi network ssid example";

        char wifi_ssid_readed [32];
        size_t required_size = sizeof(wifi_ssid_example);

        err = nvs_get_str(my_handle, "wifi_ssid", wifi_ssid_readed, &required_size);

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

        // Read wifi pass
        ESP_LOGI(TAG, "Reading wifi pass credential from NVS ... ");

        char wifi_pass_example [64] = "wifi network pass example";

        char wifi_pass_readed [64];
        required_size = sizeof(wifi_pass_example);

        err = nvs_get_str(my_handle, "wifi_pass", wifi_pass_readed, &required_size);

        switch (err) {
            case ESP_OK:
                ESP_LOGI(TAG, "Wifi PASS = %s\n", wifi_pass_readed);
                break;
            case ESP_ERR_NVS_NOT_FOUND:
                ESP_LOGI(TAG, "The value is not initialized yet!\n");
                break;
            default :
                ESP_LOGI(TAG, "Error (%s) reading!\n", esp_err_to_name(err));
        }

        // Close
        nvs_close(my_handle);
        
        // wifi_ssid = wifi_ssid_readed;
        strcpy(wifi_ssid, wifi_ssid_readed);
        strcpy(wifi_pass, wifi_pass_readed);
    }
}

/*  Write wifi credentials in NVS (ioled_data partition)  */
void write_wifi_credentials(char wifi_ssid_to_write[32], char wifi_pass_to_write[64]){
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
        ESP_LOGI(TAG, "Updating wifi ssid credential in NVS ... ");

        err = nvs_set_str(my_handle, "wifi_ssid", wifi_ssid_to_write);
        
        switch (err) {
            case ESP_OK:
                ESP_LOGI(TAG, "Wifi SSID: %s\n", wifi_ssid_to_write);
                break;
            default :
                ESP_LOGI(TAG, "Error (%s) reading!\n", esp_err_to_name(err));
        }
        
        // err = nvs_commit(my_handle);        

        ESP_LOGI(TAG, "Updating wifi pass credential in NVS ... ");

        err = nvs_set_str(my_handle, "wifi_pass", wifi_pass_to_write);
        
        switch (err) {
            case ESP_OK:
                ESP_LOGI(TAG, "Wifi Pass: %s\n", wifi_pass_to_write);
                break;
            default :
                ESP_LOGI(TAG, "Error (%s) reading!\n", esp_err_to_name(err));
        }

        err = nvs_commit(my_handle);        
 
        // Commit written value.
        // After setting any values, nvs_commit() must be called to ensure changes are written
        // to flash storage. Implementations may write to storage at other times,
        // but this is not guaranteed.
        err = nvs_commit(my_handle);        

        // Close
        nvs_close(my_handle);
    }
}

/*  Write duty in NVS (ioled_data partition)  */
void write_duty_in_nvs(int duty_to_save){
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
    nvs_handle_t my_handle;
    err = nvs_open("storage", NVS_READWRITE, &my_handle);
    if (err != ESP_OK) {
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
        return 0;
    } else {            
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
    