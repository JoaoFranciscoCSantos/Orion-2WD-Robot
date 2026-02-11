# 🚀 Orion ESP8266 Motor Web Control v1

Web-based DC motor control using ESP8266 (NodeMCU) and TB6612 motor driver.

This project integrates WiFi connectivity with a responsive mobile-friendly web interface to control a DC motor in real time.

---

## 📌 Overview

This version combines:

- ESP8266 Web Server
- TB6612 motor driver control
- Forward / Backward control via browser
- Safe motor stop handling
- Externalized WiFi credentials (secrets.h)
- Hardware troubleshooting documentation

---

## 🧠 Features

- WiFi Client Mode
- Mobile responsive UI
- Touch and mouse support
- Safe motor initialization
- Clean separation of credentials
- Hardware validation project

---

## 📦 Hardware Used

- NodeMCU ESP8266
- TB6612FNG Motor Driver Module
- N20 DC Gear Motor (300 RPM)
- 7.4V (2S) Battery Pack

---

## 🔌 Wiring

### 🔋 Battery → TB6612

Battery + → VM
Battery - → GND


---

### ⚙ NodeMCU → TB6612

5V → VCC
GND → GND
D5 → PWMA
D7 → AIN1
D6 → AIN2
STBY → 3.3V


⚠️ IMPORTANT: All grounds must be connected together.

Battery GND
TB6612 GND
NodeMCU GND
Encoder GND (if used)


---

### 🔄 Motor → TB6612

M1 → A01
M2 → A02

If rotation direction is inverted, swap M1 and M2.

---

## 🌐 WiFi Setup

Create a file named:

 - secrets.h

    With the following content:

    ```cpp
    #define WIFI_SSID "YOUR_WIFI_NAME"
    #define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

Add this to your .gitignore file:

 - secrets.h
A template file secrets.example.h should be included in the repository.

## 🚀 How It Works
ESP8266 connects to your WiFi network.
The internal web server starts.
Open the IP address shown in Serial Monitor.
Use the Forward and Backward buttons to control the motor.
Motor stops when button is released.

## 🛠 Problems Encountered & Solutions
1️⃣ Motor Did Not Spin
 - Cause:
    - Grounds were not properly shared.

 - Solution:
    - All grounds must be connected together to create a common reference.

2️⃣ USB Randomly Disconnecting
 - Cause:
    - Motor current spikes causing instability.

 - Fix:
    - Ensure solid ground connections
    - Avoid abrupt direction switching
    - Optionally add 470µF–1000µF capacitor between VM and GND

3️⃣ STBY Pin Issue (GPIO15 / D8)
Cause:
D8 (GPIO15) has boot constraints and internal pull-down resistor.

Fix:
Connect STBY directly to 3.3V instead of using D8.

4️⃣ TB6612 LED Not Turning On
 - Cause:
    - Incorrect VCC wiring or missing ground reference.

 - Fix:
    - Ensure:
        VCC → 5V (NodeMCU VIN/5V)
        GND → Common ground

## 📁 Project Structure

orion_esp8266_motor_web_control_v1/

 ├── orion_esp8266_motor_web_control_v1.ino
 
 ├── secrets.example.h
 
 ├── .gitignore
 
 └── README.md

## 🛰 Orion Project Series
Part of the Orion ESP8266 robotics experimentation series.
This version validates:
 - Web-based motor control
 - Driver stability
 - Power integrity
 - Proper grounding architecture
 - Safe WiFi integration

## 📈 Future Improvements
 - Speed slider (PWM control)
 - RPM monitoring via encoder
 - Dual motor support
 - Closed-loop speed control (PID)
 - Joystick UI
