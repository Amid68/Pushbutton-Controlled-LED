#include "../include/gpio.h"
#include <avr/io.h>

void gpio_init(void) {
    DDRB |= (1 << LED_PIN);   
    DDRD &= ~(1 << BUTTON_PIN); 
    PORTD |= (1 << BUTTON_PIN);
}


int gpio_read_button(void) {
    return (PIND & (1 << BUTTON_PIN)) == 0 ? 1 : 0;
}

void gpio_write_led(int state) {
    if (state) {
        PORTB |= (1 << LED_PIN);
    } else {
        PORTB &= ~(1 << LED_PIN);
    }
}
