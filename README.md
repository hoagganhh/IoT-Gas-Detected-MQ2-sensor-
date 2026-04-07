# Smart Gas Leakage Detection System (ESP32 + MQ-2)

## 📌 Overview

This project is a **smart gas leakage detection system** built using the ESP32 and MQ-2 sensor.
It monitors gas concentration in real time and provides:

* Local alerts (LED + Buzzer)
* Interaction (user can control system via chat Blynk apps)

---

## Hardware Components

* ESP32 (NodeMCU-32S)
* MQ-2 Gas Sensor
* Buzzer Module
* LED + Resistor (220Ω)
---

## Pin Configuration

| Component          | ESP32 Pin |
| ------------------ | --------- |
| MQ-2 Analog Output | GPIO 36   |
| LED                | GPIO 2    |
| Buzzer             | GPIO 27   |

---

## Software & Libraries

* WiFi.h
* BlynkSimpleEsp32.h
* ArduinoJson.h

---

## Features

### Real-time Gas Monitoring

Continuously reads gas sensor values and converts them into percentage.

### Auto Calibration

System automatically calibrates baseline value in clean air at startup.

### Smart Alert System

* LED + Buzzer activate instantly when gas exceeds threshold

## System Workflow

1. ESP32 connects to WiFi
2. Sensor performs **calibration (baseline calculation)**
3. System continuously:

   * Reads sensor value
   * Calculates gas percentage
   * Compares with threshold

4. If gas exceeds threshold:
   * Activate LED & Buzzer

## Core Algorithm

### 1. Calibration (Noise Filtering)

```
cleanAirValue = average(100 sensor readings)
```

### 2. Differential Measurement

```
diff = currentValue - cleanAirValue
```

## 🔐 Security

* Only authorized `CHAT_ID` can control the system
* Prevents unauthorized access to bot commands

---

## ⏱️ Non-Blocking Architecture

* Uses `millis()` instead of `delay()` for network tasks
* Ensures stable WiFi + real-time sensor reading

---

## 📱 Telegram Setup

1. Create bot using **@BotFather**
2. Get:

   * `BOT_TOKEN`
   * `CHAT_ID`
3. Replace in code:

```cpp
#define BOT_TOKEN "your_token"
#define CHAT_ID "your_chat_id"
```

---

## ▶️ How to Run

1. Install required libraries in Arduino IDE
2. Select board: **ESP32 Dev Module**
3. Upload code
4. Open Serial Monitor (115200 baud)
5. Wait for calibration (~10 seconds)
6. Start interacting via Telegram

---

## 🧪 Testing

* Use lighter gas to simulate leakage
* Observe:

  * LED ON
  * Buzzer ON
  * Telegram alert

---

## 📈 Future Improvements

* Add AI-based prediction
* Integrate multiple sensors (temperature, humidity)
* Cloud data logging
* Mobile app dashboard

---

## 👨‍💻 Author

* Nguyen Hoang Anh
* Ho Chi Minh City University of Technology

---

## 📌 Notes

* MQ-2 sensor requires warm-up time for stable readings
* Ensure proper ventilation when testing with gas

---
