static led_strip_t *pStrip_a;

static void turn_strip_led_color(void)
{   

    /* Set the LED pixel using RGB from 0 (0%) to 255 (100%) for each color */
    pStrip_a->set_pixel(pStrip_a, 0, 0, 16, 0);
    pStrip_a->set_pixel(pStrip_a, 1, 0, 16, 0);
    pStrip_a->set_pixel(pStrip_a, 2, 0, 16, 0);
    pStrip_a->set_pixel(pStrip_a, 3, 0, 16, 0);
    pStrip_a->set_pixel(pStrip_a, 4, 0, 16, 0);

    /* Refresh the strip to send data */
    pStrip_a->refresh(pStrip_a, 100);
    
}