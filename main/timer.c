int y_hour[24];
int time_hour[24] = {0 , 1 , 2 , 3 , 4 , 5, 6 , 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};

/* Create vector time hour necessary for timer */
void create_vector_time_hour(int hour_on, int hour_off){   
    if (hour_off > hour_on){
        for(int i = 0; i < 24; i++){
            y_hour[i] = 0;
            if (time_hour[i] >= hour_on && time_hour[i] < hour_off) {
                y_hour[i] = 1;
            }
        }
    }

    if (hour_on > hour_off){
        for(int i = 0; i < 24; i++){
            y_hour[i] = 1;
            if (time_hour[i] >= hour_off && time_hour[i] < hour_on) {
                y_hour[i] = 0;
            }
        }
    }

    for(int i = 0; i < 24; i++){
        ESP_LOGI(TAG, "Vector time hour for hour %d: %d", i, y_hour[i]);
    }
}