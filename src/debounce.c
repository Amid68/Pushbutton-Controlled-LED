#include "../include/debounce.h"
#include "../include/timer.h"
#include <avr/io.h>
#include <util/delay.h>

static int last_button_state = 0;
static unsigned long last_debounce_time = 0;

int debounce_button(int current_state) {
    unsigned long current_time = get_millis();

    if (current_state != last_button_state) {
        last_debounce_time = current_time;
    }

    if ((current_time - last_debounce_time) > DEBOUNCE_DELAY) {
        return current_state;
    }

    last_button_state = current_state;
    return last_button_state;
}
