# Arduino Due Encoder A/B Signal Project

## Project Overview

This project is designed to process rotary encoder signals using an **Arduino Due**. It reads **A/B phase signals** from an incremental encoder to determine rotational direction, frequency, and RPM, while also calculating chain speed. The project is developed with **PlatformIO** for streamlined development, building, and debugging.

## Features

- **Encoder Signal Processing:**
  - Captures A/B signals from the encoder.
  - Determines rotational **direction** (forward/reverse).
  - Calculates **frequency (Hz), RPM, and chain speed**.

- **Modular Code Structure:**
  - `include/encoder.h` → Contains function declarations.
  - `src/encoder.cpp` → Implements encoder processing logic.
  - `src/main.cpp` → Main application loop.

- **PlatformIO Integration:**
  - Simplifies compilation, flashing, and serial monitoring.
  - Ensures structured development workflow.

## Project Structure

```
Arduino_Due_Encoder_A_B_Signal/
├── include/
│   └── encoder.h         # Encoder function declarations
├── src/
│   ├── encoder.cpp       # Encoder ISR and logic
│   └── main.cpp          # Main program
├── lib/                  # (Optional) Custom libraries (currently empty)
├── .gitignore            # Git ignored files
├── platformio.ini        # PlatformIO configuration file
├── detect_arduino_due.ps1 # PowerShell script to auto-detect Arduino Due
└── README.md             # This file
```

## Requirements

- **Hardware:**
  - Arduino Due board
  - Incremental rotary encoder with A/B signals

- **Software:**
  - [PlatformIO](https://platformio.org/) (recommended in Visual Studio Code)
  - Arduino framework libraries (managed by PlatformIO)

## Getting Started

### 1. Clone the Repository
```bash
git clone https://github.com/yourusername/Arduino_Due_Encoder_A_B_Signal.git
cd Arduino_Due_Encoder_A_B_Signal
```

### 2. Open in PlatformIO
- Launch **VS Code**.
- Open the project folder.
- Ensure the **PlatformIO extension** is installed.

### 3. Auto-Detect Arduino Due Upload Port
Before uploading, run the following **PowerShell script** to automatically detect the correct COM port:

```powershell
.\detect_arduino_due.ps1
```

- If an **Arduino Due is detected**, the script will update `platformio.ini` with the correct upload port.
- If **no Arduino Due is found**, it will display an error message in **red**.

### 4. Compile and Upload
- **Build the project** using PlatformIO’s build command.
- **Upload the firmware** using PlatformIO’s upload command.

### 5. Monitor Serial Output
```bash
pio device monitor --baud 115200
```
This will display encoder readings and calculated values.

## Usage Example

Modify `main.cpp` to read encoder values:

```cpp
#include "encoder.h"

void setup() {
    Serial.begin(115200);
    // Initialize encoder
}

void loop() {
    // Read encoder values and process them
}
```

## License
This project is licensed under the [MIT License](LICENSE).

---

For any modifications or additional features, feel free to contribute!
