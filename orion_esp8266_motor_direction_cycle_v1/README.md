# 🔄 Orion ESP8266 Motor Direction Cycle v1

Timed motor direction test using ESP8266 (NodeMCU) and TB6612 motor driver.

This project runs a simple motor cycle:

- 5 seconds forward  
- 5 seconds backward  
- Continuous loop  

> ⚡ Focus: Hardware validation, wiring verification, and motor driver testing.

---

## 🧠 Features

- ESP8266 motor control
- TB6612 H-bridge driver
- Timed direction switching
- Continuous cycle operation
- Hardware debugging validation project

---

## 📦 Hardware Used

- NodeMCU ESP8266
- TB6612FNG Motor Driver Module
- N20 DC Gear Motor (300RPM)
- 7.4V (2S) battery

---

## 🔌 Wiring Summary

### Battery → TB6612

 - Battery + → VM
 - Battery - → GND


### NodeMCU → TB6612

 - 5V → VCC
 - GND → GND
 - D5 → PWMA
 - D6 → AIN1
 - D7 → AIN2
 - STBY → 3.3V


### Motor → TB6612

 - M1 → A01
 - M2 → A02


⚠️ All grounds must be connected together.

---

# 🛠 Problems Encountered & Solutions

## 1️⃣ Motor Did Not Rotate

**Symptom:**
- Encoder worked correctly.
- Motor did not spin.

**Cause:**
Ground connections were not properly shared.

**Solution:**

All grounds must be connected:

 - Battery GND
 - TB6612 GND
 - NodeMCU GND
 - Encoder GND


Without a common ground, the driver cannot interpret control signals.

---

## 2️⃣ USB Randomly Disconnecting

**Symptom:**
- NodeMCU kept reconnecting to the PC.
- Serial monitor dropped repeatedly.

**Cause:**
Motor current spikes affecting power stability.

**Solution:**
- Ensure solid ground wiring.
- Avoid abrupt direction switching.
- Add small delay between direction changes.
- Optionally add a large capacitor (470µF–1000µF) across VM and GND.

---

## 3️⃣ STBY Pin Issue (GPIO15 / D8)

**Symptom:**
Motor not activating even with correct wiring.

**Cause:**
D8 (GPIO15) has special boot behavior and internal pull-down resistor.

**Solution:**
Connect STBY directly to 3.3V instead of using D8.

---

## 4️⃣ TB6612 LED Not Lighting

**Cause:**
Incorrect VCC wiring or missing ground reference.

**Solution:**
Ensure:

 - VCC → 5V (NodeMCU VIN/5V)
 - GND → Common ground


---

# 🚀 How It Works

The motor:

1. Rotates forward for 5 seconds  
2. Stops briefly  
3. Rotates backward for 5 seconds  
4. Repeats continuously  

This project validates:

- Power wiring
- Ground reference integrity
- Direction control
- Driver activation

---

## 📁 Project Structure

    orion_esp8266_motor_direction_cycle_v1/
    ├── orion_esp8266_motor_direction_cycle_v1.ino
    └── README.md


---

## 🛰 Orion Project Series

Part of the Orion ESP8266 robotics experimentation series.
