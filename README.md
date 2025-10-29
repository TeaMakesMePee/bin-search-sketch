# Binary Search Algorithm Visualizer (ESP32 & Arduino)

This project is a simple hardware demonstration designed to visualize the step-by-step execution of the binary search algorithm. It utilizes an LED array to provide real-time, physical feedback on how the search space is narrowed until the target element is found.

## Core Functionality

The primary goals of this implementation were technical control and algorithm accuracy:

* **Algorithm Implementation**: The binary search algorithm is fully implemented on the ESP32 microcontroller using the Arduino framework.
* **Physical Feedback**: GPIO control and precise timing logic were programmed in C++ to animate the search process, showing the reduction of the search space on a simple LED array.

## Hardware Requirements

* **Microcontroller**: ESP32 Development Board (e.g., NodeMCU-32S, ESP32-WROOM)
* **Display**: 10 LEDs in a linear array
* **Additional Components**: 
  - 10x 220Ω resistors
  - Breadboard
  - Jumper wires

## Software and Dependencies

* **Development Environment**: Arduino IDE or PlatformIO
* **Language**: C++
* **Framework**: Arduino
* **Libraries**: Standard Arduino Libraries (built-in GPIO functions)

## Wiring Configuration

Connect each LED with a 220Ω resistor to the following GPIO pins:

| LED Index | GPIO Pin |
|-----------|----------|
| 0 | 13 |
| 1 | 12 |
| 2 | 14 |
| 3 | 27 |
| 4 | 26 |
| 5 | 25 |
| 6 | 33 |
| 7 | 32 |
| 8 | 15 |
| 9 | 4 |

Connect the cathode (negative) of each LED to GND.

## How It Works

1. **Target Selection**: A random LED is selected as the search target
2. **Reset Animation**: Wave pattern displays across all LEDs (left-to-right on, right-to-left off, repeated twice)
3. **Target Indicator**: The target LED blinks 3 times
4. **Binary Search Execution**:
   - All active LEDs flash for 1 second
   - Middle position is calculated
   - Pruned LEDs turn off with wave animation:
     - Left pruning: Wave from right to left
     - Right pruning: Wave from left to right
5. **Success**: Found LED blinks 3 times

## Installation

1. Clone or download this repository
2. Open the `.ino` file in Arduino IDE
3. Select your ESP32 board from Tools → Board
4. Select the correct COM port
5. Upload the code to your ESP32

## Usage

After uploading, the visualization runs continuously in a loop. Open the Serial Monitor (115200 baud) to see debug information about the search process.

## Customization

You can modify the following parameters in the code:

* `ledPins[]`: Change GPIO pin assignments
* `NUM_LEDS`: Adjust the number of LEDs (default: 10)
* Delay timings for faster/slower animations

## License

This project is open source and available for educational purposes.

## Video demo

https://www.youtube.com/watch?v=LeCxggS_f8w
