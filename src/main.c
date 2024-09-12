#include "../include/gpio.h"
#include "../include/debounce.h"
#include "../include/led.h"
#include "../include/timer.h"
#include <util/delay.h>

int main(void) {
    gpio_init();
    timer_init();

    int last_button_state = 1; 
    int button_state;

    while(1) {
        button_state = debounce_button(gpio_read_button());

        // Detect falling edge: button was pressed (goes from HIGH to LOW)
        if (button_state == 0 && last_button_state == 1) {
            toggle_led();  
        }

        // Save the current button state for the next loop iteration
        last_button_state = button_state;

        _delay_ms(10);  // Small delay to prevent bouncing issues
    }

    return 0;
}
