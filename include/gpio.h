#ifndef __GPIO_H__
#define __GPIO_H__

#define BUTTON_PIN PD2  
#define LED_PIN PB4    

void gpio_init(void);
int gpio_read_button(void);
void gpio_write_led(int state);

#endif
