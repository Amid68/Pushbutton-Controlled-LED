#include <avr/io.h>
#include <avr/interrupt.h>
#include "../include/timer.h"

static volatile unsigned long millis_counter = 0;

void timer_init(void) {
    TCCR0A |= (1 << WGM01); // set to mode 2 (ctc)

    OCR0A = 249;    // 16 MHz / (64 * prescaler * 1000) - 1

    TCCR0B |= (1 << CS01) | (1 << CS00);    // prescaler 64

    TIMSK0 |= (1 << OCIE0A);    // enable timer0 compare interrupt

    sei();  // enable global interrupts
}

// ISR (Interrupt Service Routine) for Timer0 Compare Match
ISR(TIMER0_COMPA_vect) {
    millis_counter++;   // increment counter every 1ms
}

unsigned long get_millis(void) {
    unsigned long millis_copy;

    // temp disable interrupts to prevent data corruption
    cli();
    millis_copy = millis_counter;
    sei();

    return millis_copy;
}
