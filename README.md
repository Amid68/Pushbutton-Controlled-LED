# Pushbutton-Controlled LED

This project demonstrates how to control an LED using a momentary pushbutton switch. When the button is pressed, the LED toggles between ON and OFF states. The project has two versions:
1. **Arduino Version**: Located in `arduino/Pushbutton`, this version uses the Arduino framework.
2. **Embedded C Version**: Located in `src/`, this version is written in pure Embedded C, using direct register manipulation for greater flexibility and compatibility with non-Arduino environments.

## Components Required

- Arduino Board
- Breadboard
- Jumper Wires
- LED
- Momentary Tactile Pushbutton (4-pin)
- 10kΩ Resistor (for pull-up or pull-down)
- 220Ω Resistor (for current limiting)

## Circuit Diagram

### Pushbutton Configuration:
The pushbutton has four pins, but only two are used in this project. When the button is pressed, it completes the circuit, allowing current to flow, which toggles the LED. The button acts as a momentary switch, meaning it only stays on while pressed.

### LED Configuration:
The LED is connected to an output pin, and a 220Ω resistor is placed in series to limit the current.

### Circuit Build:
1. Place the pushbutton on the breadboard.
2. Connect pin A of the pushbutton to one leg of the 10kΩ resistor and Arduino pin 2. Connect the other leg of the resistor to the GND rail on the breadboard.
3. Connect pin B of the pushbutton to the +5V rail.
4. Add the LED to the breadboard: connect the longer (positive) leg to Arduino pin 12 via a 220Ω resistor and the shorter (negative) leg to the GND rail.

![Circuit Setup](assets/setup.png)

## Project Versions

### 1. Arduino Version

The original Arduino version uses the Arduino-specific functions (`pinMode()`, `digitalWrite()`, etc.) for simple and quick development. The code for this version is located in the `arduino/Pushbutton/` directory.

### 2. Embedded C Version (Pure C)

The Embedded C version, located in the `src/` directory, is designed for more advanced users who want to work with direct register manipulation and avoid Arduino dependencies. This version ensures compatibility with a broader range of embedded systems.

In this version:
- **GPIO and Timer Functions**: Instead of using Arduino's `digitalWrite()` or `pinMode()`, we control the hardware directly via registers (`DDRB`, `PORTB`, etc.).
- **Debouncing**: A software debounce mechanism is implemented using custom timing and delay functionality to prevent multiple button presses from being registered due to mechanical bounce.

## How It Works

- When the button is pressed, the microcontroller detects the state change and toggles the LED between ON and OFF states.
- A debouncing mechanism ensures that only one button press is registered even if there is noise from the mechanical button press.

## Instructions to Run the Project

### 1. Arduino Version

1. Build the circuit as described in the circuit build section.
2. Open the `arduino/Pushbutton/Pushbutton.ino` file in the Arduino IDE.
3. Connect your Arduino to the computer and upload the code.
4. Press the button to toggle the LED between ON and OFF states.

### 2. Embedded C Version

#### Prerequisites
- **GNU AVR Toolchain**: Ensure `avr-gcc`, `avr-libc`, and `avrdude` are installed.
- **Make**: For building the project using the `Makefile`.

#### Compilation and Upload Steps

1. Build the circuit as described in the circuit build section.
2. Clone or download the repository and navigate to the root directory.
3. **Modify the Makefile**: Open the `Makefile` and update the `PORT` line to match your system's serial port. For example:
   ```makefile
   PORT = /dev/ttyUSB0  # Update this to match your system
   ```
4. Run the following commands to compile and upload the Embedded C version to your board:
   ```bash
   make clean        # Clean previous build files
   make              # Compile the project and generate the .hex file
   make upload       # Upload the compiled .hex file to your board
   ```
5. Press the button to toggle the LED between ON and OFF states.
