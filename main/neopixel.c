static led_strip_t *pStrip_a;

enum Colors
{
    WHITE,
    BLUE,
    GREEN,
    IOLED_GREEN,
    HARD,
    RED,
    ORANGE
};

/*  Turn on the neopixel strip in the color set by the enum Colors type parameter*/
static void turn_strip_led_color(enum Colors color)
{   
    switch(color){

        case WHITE:
            /* Set the LED pixel using RGB from 0 (0%) to 255 (100%) for each color */
            pStrip_a->set_pixel(pStrip_a, 0, 16, 16, 16);
            pStrip_a->set_pixel(pStrip_a, 1, 16, 16, 16);
            pStrip_a->set_pixel(pStrip_a, 2, 16, 16, 16);
            pStrip_a->set_pixel(pStrip_a, 3, 16, 16, 16);

            /* Refresh the strip to send data */
            pStrip_a->refresh(pStrip_a, 100);
            break;
        
        case BLUE:
            /* Set the LED pixel using RGB from 0 (0%) to 255 (100%) for each color */
            pStrip_a->set_pixel(pStrip_a, 0, 0, 0, 16);
            pStrip_a->set_pixel(pStrip_a, 1, 0, 0, 16);
            pStrip_a->set_pixel(pStrip_a, 2, 0, 0, 16);
            pStrip_a->set_pixel(pStrip_a, 3, 0, 0, 16);

            /* Refresh the strip to send data */
            pStrip_a->refresh(pStrip_a, 100);
            break;

        
        case GREEN:
            /* Set the LED pixel using RGB from 0 (0%) to 255 (100%) for each color */
            pStrip_a->set_pixel(pStrip_a, 0, 0, 16, 0);
            pStrip_a->set_pixel(pStrip_a, 1, 0, 16, 0);
            pStrip_a->set_pixel(pStrip_a, 2, 0, 16, 0);
            pStrip_a->set_pixel(pStrip_a, 3, 0, 16, 0);

            /* Refresh the strip to send data */
            pStrip_a->refresh(pStrip_a, 100);
            break;
        
        case IOLED_GREEN:
            /* Set the LED pixel using RGB from 0 (0%) to 255 (100%) for each color */
            pStrip_a->set_pixel(pStrip_a, 0, 9, 204, 10);
            pStrip_a->set_pixel(pStrip_a, 1, 9, 204, 10);
            pStrip_a->set_pixel(pStrip_a, 2, 9, 204, 10);
            pStrip_a->set_pixel(pStrip_a, 3, 9, 204, 10);

            /* Refresh the strip to send data */
            pStrip_a->refresh(pStrip_a, 100);
            break;

        case HARD:
            /* Set the LED pixel using RGB from 0 (0%) to 255 (100%) for each color */
            pStrip_a->set_pixel(pStrip_a, 0, 16, 0, 0);
            pStrip_a->set_pixel(pStrip_a, 1, 0, 16, 0);
            pStrip_a->set_pixel(pStrip_a, 2, 0, 0, 16);
            pStrip_a->set_pixel(pStrip_a, 3, 16, 16, 16);

            /* Refresh the strip to send data */
            pStrip_a->refresh(pStrip_a, 100);
            break;

        case RED:
            /* Set the LED pixel using RGB from 0 (0%) to 255 (100%) for each color */
            pStrip_a->set_pixel(pStrip_a, 0, 16, 0, 0);
            pStrip_a->set_pixel(pStrip_a, 1, 16, 0, 0);
            pStrip_a->set_pixel(pStrip_a, 2, 16, 0, 0);
            pStrip_a->set_pixel(pStrip_a, 3, 16, 0, 0);

            /* Refresh the strip to send data */
            pStrip_a->refresh(pStrip_a, 100);
            break;
        
        case ORANGE:
            /* Set the LED pixel using RGB from 0 (0%) to 255 (100%) for each color */
            pStrip_a->set_pixel(pStrip_a, 0, 130, 30, 0);
            pStrip_a->set_pixel(pStrip_a, 1, 130, 30, 0);
            pStrip_a->set_pixel(pStrip_a, 2, 130, 30, 0);
            pStrip_a->set_pixel(pStrip_a, 3, 130, 30, 0);

            /* Refresh the strip to send data */
            pStrip_a->refresh(pStrip_a, 100);
            break;


        default:
            ESP_LOGI(TAG," ");   
        }
}

