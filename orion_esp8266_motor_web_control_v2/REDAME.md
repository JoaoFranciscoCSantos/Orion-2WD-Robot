# 🚀 Orion ESP8266 Motor Web Control v2

Version 2 of the web-based motor control system using ESP8266 (NodeMCU) and TB6612 motor driver.

This version builds on **orion_esp8266_motor_web_control_v1**, introducing real-time speed control and system stability improvements.

---

## 📌 Overview

v2 extends the functionality of v1 by adding:

- PWM speed control via web slider
- Memory optimization using PROGMEM
- WiFi sleep mode disabled (reduced latency)
- Improved power architecture
- Debounced slider requests
- Stability fixes after real-world testing

For full wiring details and base architecture, refer to:

👉 **orion_esp8266_motor_web_control_v1**

---

## 🧠 What's New in v2

### 🎛 Real-Time Speed Control

- Adjustable PWM (0–1023)
- Speed controlled via mobile-friendly slider
- Debounced HTTP requests to prevent flooding

---

### ⚡ Improved Stability

#### 1️⃣ PROGMEM Usage
Moved large HTML page to flash memory using:

    const char webpage[] PROGMEM
    server.send_P(...)

Prevents heap fragmentation and server crashes.

---

#### 2️⃣ WiFi Sleep Disabled

Added:

    WiFi.setSleepMode(WIFI_NONE_SLEEP);


This reduces command latency and eliminates 2-second delays.

---

#### 3️⃣ Power Architecture Correction

During testing, increasing RPM caused resets due to voltage drops.

**Fix:**

- Recommended use of a buck converter for NodeMCU
- Large capacitor (470µF–1000µF) across VM and GND
- Proper common ground wiring

Power wiring fundamentals are described in detail in v1.

---

## 🔌 Hardware

Same hardware as v1:

- NodeMCU ESP8266
- TB6612FNG Motor Driver
- N20 DC Gear Motor
- 7.4V Battery
- (Recommended) Buck Converter

Refer to v1 for complete wiring diagram.

---

## 🌐 WiFi Configuration

    Unchanged from v1.

    Use:

    ```cpp
    secrets.h

    Refer to v1 for setup instructions.

---

## How It Works

- ESP8266 connects to WiFi.
- Web server starts.
- Forward / Backward control motor direction.
- Slider adjusts PWM speed in real time.
- Timeout safety mechanism stops motor if no command is received.

---    

# 🛠 Issues Identified During v2 Development
## 🔁 Server Becoming Inaccessible

- Cause:
    HTML stored in RAM via String.

- Fix:
    Moved webpage to PROGMEM.

## ⏱ Command Delay (~2 seconds)

- Cause:
    ESP8266 WiFi power-saving mode.
- Fix:
    Disabled sleep mode.

## ⚡ High RPM Causing Instability
    
- Cause:
    Motor current spikes causing voltage drop.
- Fix:
    Improved power architecture (buck converter + capacitors).

---

# 📁 Project Structure
    orion_esp8266_motor_web_control_v2/
    ├── orion_esp8266_motor_web_control_v2.ino
    ├── secrets.example.h
    ├── .gitignore
    └── README.md

---

# 🛰 Orion Robotics Lab Series

v2 represents a transition from basic web control (v1) to real-time adjustable motor control with improved reliability.
    This version focuses on:
        - Performance tuning
        - Memory optimization
        - Power integrity
        - Reduced latency

---

# 📈 Future Improvements (v3 Ideas)

    - Encoder RPM display on UI
    - Closed-loop speed control (PID)
    - Dual motor support
    - WebSocket migration
    - AsyncWebServer implementation
