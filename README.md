Binary Search Algorithm Visualizer (ESP32 & Arduino)

This project is a simple hardware demonstration designed to visualize the step-by-step execution of the binary search algorithm. It utilizes an LED array to provide real-time, physical feedback on how the search space is narrowed until the target element is found.

Core Functionality

The primary goals of this implementation were technical control and algorithm accuracy:

Algorithm Implementation: The binary search algorithm is fully implemented on the ESP32 microcontroller using the Arduino framework.

Physical Feedback: GPIO control and precise timing logic were programmed in C++ to animate the search process, showing the reduction of the search space on a simple LED array.

Hardware Requirements

Microcontroller: ESP32 Development Board (e.g., NodeMCU-32S, ESP32-WROOM)

Display: A linear array of LEDs (or NeoPixels/WS2812B strip, depending on implementation)

Wiring: Resistors and connecting wires (or a breadboard)

Software and Dependencies

Development Environment: Arduino IDE or PlatformIO

Language: C++

Framework: Arduino

Libraries: Standard Arduino Libraries (e.g., built-in GPIO functions).
