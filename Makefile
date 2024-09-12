MCU = atmega328p
F_CPU = 16000000UL
CC = avr-gcc
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall
LDFLAGS = -mmcu=$(MCU)
OBJCOPY = avr-objcopy

PROGRAMMER = arduino
PORT = /dev/cu.usbserial-2110   # Update this for your system

TARGET = main

SRC = src/main.c src/gpio.c src/debounce.c src/led.c src/timer.c
OBJ = $(SRC:.c=.o)

all: $(TARGET).hex

%.hex: %.elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

$(TARGET).elf: $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

upload: $(TARGET).hex
	avrdude -c $(PROGRAMMER) -p $(MCU) -P $(PORT) -U flash:w:$(TARGET).hex

clean:
	rm -f src/*.o *.elf *.hex

