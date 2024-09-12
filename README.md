# Pushbutton-Controlled LED

This project demonstrates how to control an LED using a momentary pushbutton switch. When the button is pressed, the LED turns on; when the button is released, the LED turns off.

## Components Required

- Arduino Board
- Breadboard
- Jumper Wires
- LED
- Momentary Tactile Pushbutton (4-pin)
- 10kΩ Resistor (for pull-down)
- 220Ω Resistor (for current limiting)

## Circuit Diagram

### Pushbutton Configuration:
The pushbutton has four pins, but only two are used in this project. When the button is pressed, it completes the circuit, allowing current to flow, which turns the LED on. The button acts as a momentary switch, meaning it only stays on while pressed.

### LED Configuration:
The LED is connected to an output pin on the Arduino, and a 220Ω resistor is placed in series to limit the current.

### Circuit Build:
1. Place the pushbutton on the breadboard.
2. Connect pin A of the pushbutton to one leg of the 10kΩ resistor and Arduino pin 2. Connect the other leg of the resistor to the GND rail on the breadboard.
3. Connect pin B of the pushbutton to the +5V rail.
4. Add the LED to the breadboard: connect the longer (positive) leg to Arduino pin 12 via a 220Ω resistor and the shorter (negative) leg to the GND rail.

![Circuit Setup](assets/setup.png)

## How It Works

- When the button is pressed, the circuit is completed, and the Arduino detects a HIGH signal on pin 2.
- The Arduino then turns on the LED by sending a HIGH signal to pin 12.
- When the button is released, the circuit is broken, the signal on pin 2 goes LOW, and the LED turns off.

This type of pushbutton is also known as a momentary switch, commonly used in keyboards and other electronic devices.

## Instructions to Run the Project

1. Build the circuit as described in the circuit build section.
2. Connect the Arduino to your computer using a USB cable.
3. Open the Arduino IDE and upload the provided code.
4. Press the button to turn the LED on and release it to turn it off.
