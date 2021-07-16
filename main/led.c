void change_led(double percent)
{   
    if (percent > 0) {
        gpio_set_level(RELAY_GPIO, true);
    } else {
        gpio_set_level(RELAY_GPIO, false);
    }
}