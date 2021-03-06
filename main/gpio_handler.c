#define INTERNAL_BUTTON     0
#define EXTERNAL_BUTTON    14

#define ESP_INTR_FLAG_DEFAULT 0
#define GPIO_INPUT_PIN_SEL  1ULL<<INTERNAL_BUTTON

static xQueueHandle gpio_evt_queue = NULL;

static void IRAM_ATTR gpio_isr_handler(void* arg)
{
    uint32_t gpio_num = (uint32_t) arg;
    xQueueSendFromISR(gpio_evt_queue, &gpio_num, NULL);
}

static void gpio_task(void* arg)
{
    uint32_t io_num;
    for(;;) {
        if(xQueueReceive(gpio_evt_queue, &io_num, portMAX_DELAY)) {
            ESP_LOGE(TAG, "GPIO[%d] intr, val: %d\n", io_num, gpio_get_level(io_num));
            if(gpio_get_level(io_num) == 0){
                // set_current_state(AP_MODE);
                write_wifi_mode_in_nvs("AP");
                fflush(stdout);
                esp_restart();
            }
        }
    }
}

/* Create xTask action with button */
static void set_button(){
    // static httpd_handle_t server = NULL;    
    gpio_config_t io_conf;

    //interrupt of rising edge
    io_conf.intr_type = GPIO_INTR_POSEDGE;
    //bit mask of the pins, use GPIO4/5 here
    io_conf.pin_bit_mask = GPIO_INPUT_PIN_SEL;
    //set as input mode
    io_conf.mode = GPIO_MODE_INPUT;
    //enable pull-up mode
    io_conf.pull_up_en = 1;
    gpio_config(&io_conf);

    //change gpio intrrupt type for one pin
    gpio_set_intr_type(INTERNAL_BUTTON, GPIO_INTR_ANYEDGE);

    //change gpio intrrupt type for one pin
    gpio_set_intr_type(EXTERNAL_BUTTON, GPIO_INTR_ANYEDGE);

    //create a queue to handle gpio event from isr
    gpio_evt_queue = xQueueCreate(10, sizeof(uint32_t));
    
    //start gpio task
    xTaskCreate(gpio_task, "gpio_task", 2048, NULL, 10, NULL);

    //install gpio isr service
    gpio_install_isr_service(ESP_INTR_FLAG_DEFAULT);
    
    //hook isr handler for specific gpio pin
    gpio_isr_handler_add(INTERNAL_BUTTON, gpio_isr_handler, (void*) INTERNAL_BUTTON);

    //hook isr handler for specific gpio pin
    gpio_isr_handler_add(EXTERNAL_BUTTON, gpio_isr_handler, (void*) EXTERNAL_BUTTON);
}

