# 🚀 Orion ESP8266 Motor Web Control v3

Dual-motor web-based control system using ESP8266 (NodeMCU) and TB6612 motor driver.

Version 3 extends v2 by introducing synchronized dual motor control, forming the base for a WiFi-controlled rover platform.

---

## 📌 Overview

v3 builds on:

👉 orion_esp8266_motor_web_control_v1  
👉 orion_esp8266_motor_web_control_v2  

Enhancements in v3:

- Dual motor support (Channel A + Channel B)
- Shared PWM speed control
- Stable web interface
- PROGMEM memory optimization
- WiFi sleep disabled for lower latency
- Improved power architecture

---

## 🧠 What's New in v3

### 🛞 Dual Motor Control

Both channels of the TB6612 are used:

- Channel A → Left motor
- Channel B → Right motor

Speed is applied simultaneously to both motors using a shared PWM value.

---

## 🔌 Wiring

### 🛞 Motor Left (Channel A)

PWMA → D5
AIN1 → D7
AIN2 → D6
A01 → Motor Left
A02 → Motor Left


---

### 🛞 Motor Right (Channel B)

PWMB → D1
BIN1 → D3
BIN2 → D2
B01 → Motor Right
B02 → Motor Right


---

### 🔋 Power

Same architecture introduced in v2:

- VM → Battery +
- GND → Common ground
- VCC → 5V (buck converter recommended)
- STBY → 3.3V

All grounds must be connected together.

Refer to v2 documentation for full explanation of power stability improvements.

---

## 🌐 Web Interface

Same UI as v2:

- Forward
- Backward
- Stop
- Speed slider (PWM 0–900)

HTML stored in PROGMEM to avoid heap fragmentation.

WiFi sleep disabled to reduce latency:

WiFi.setSleepMode(WIFI_NONE_SLEEP);


---

## ⚠️ Development Notes

During development:

- One motor initially failed to reverse due to polarity / logic configuration.
- Resolved by adjusting wiring or direction logic.

Previous issues addressed in earlier versions:

- Server instability due to RAM fragmentation
- Latency caused by WiFi sleep mode
- Voltage drops at high RPM causing resets

All fixes are retained in v3.

---

## 📁 Project Structure

orion_esp8266_motor_web_control_v3/
├── orion_esp8266_motor_web_control_v3.ino
├── secrets.example.h
├── .gitignore
└── README.md


---

## 🛰 Orion Robotics Lab Series

v3 represents the transition from single-motor validation to dual-motor rover base.

Next steps:

- Add Left / Right steering commands
- Differential speed turning
- Encoder-based RPM feedback
- Closed-loop PID control
- WebSocket migration