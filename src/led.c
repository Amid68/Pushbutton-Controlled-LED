#include "../include/gpio.h"
#include "../include/led.h"

static int led_state = 0;

void toggle_led(void) {
    led_state = !led_state;
    gpio_write_led(led_state);
}
