# Arduino Due Encoder A/B Signal Project

## Project Overview

This project provides a structured approach to measuring and analyzing rotary encoder signals using an Arduino Due microcontroller. It captures A/B phase signals from an incremental encoder to determine rotational direction, calculate pulse frequency, and derive key motion parameters such as revolutions per minute (RPM) and linear speed. The project leverages PlatformIO for streamlined development, compilation, and deployment.

## Key Features

- **Encoder Signal Processing:**
  - Captures quadrature encoder signals to determine rotation direction.
  - Computes real-time frequency (Hz) and RPM based on pulse count.
  - Calculates linear speed in both inches per minute and feet per minute based on encoder resolution and mechanical parameters.

- **Modular Code Architecture:**
  - Implements a structured software design by separating declarations, interrupt service routines, and computational logic into dedicated header and source files.
  - Facilitates code readability, maintainability, and scalability.

- **PlatformIO Integration:**
  - Employs PlatformIO for automated project configuration, dependency management, and firmware deployment.
  - Supports efficient debugging and serial data monitoring.

## Project Directory Structure

```
Arduino_Due_Encoder_A_B_Signal/
├── include/
│   └── encoder.h         # Header file containing function declarations and macros
├── src/
│   ├── encoder.cpp       # Source file implementing encoder ISR and data processing
│   └── main.cpp          # Main program logic
├── platformio.ini        # PlatformIO configuration file
└── README.md             # Project documentation
```

## System Requirements

- **Hardware Components:**
  - Arduino Due microcontroller
  - Incremental rotary encoder with A/B phase output
  - Required wiring and power supply

- **Software Environment:**
  - [PlatformIO](https://platformio.org/) (recommended with Visual Studio Code)
  - Arduino framework and associated libraries (managed by PlatformIO)

## Getting Started

### 1. Clone the Repository

Execute the following command in a terminal:

```bash
git clone https://github.com/yourusername/Arduino_Due_Encoder_A_B_Signal.git
cd Arduino_Due_Encoder_A_B_Signal
```

### 2. Open the Project in PlatformIO

- Launch Visual Studio Code and open the cloned project folder.
- Ensure the PlatformIO extension is installed and active.

### 3. Compile and Upload Firmware

- Use the PlatformIO build command to compile the source code.
- Connect the Arduino Due via the **Programming Port**.
- Upload the firmware using PlatformIO’s upload command.

### 4. Monitor Serial Output

- Open the PlatformIO Serial Monitor with a baud rate of **115200** to observe encoder readings and computed parameters in real-time.

## Licensing

This project is distributed under the [MIT License](LICENSE).

---

Contributions and modifications are welcome to improve functionality and optimize performance.
