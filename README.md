# Water Quality Monitoring System

## Overview
The Water Quality Monitoring System is an IoT-based project that continuously monitors key water quality parameters in real-time. It ensures accurate measurement of Total Dissolved Solids (TDS) and temperature, providing instant alerts in case of contamination. This system is highly adaptable and can be deployed in various settings such as households, communities, and industries.

## Features
- **Real-Time Monitoring:** Continuous tracking of water quality parameters.
- **Data Accuracy:** Measures Total Dissolved Solids (TDS) and temperature with high precision.
- **Alert Mechanism:** Notifies users when water quality deviates from safe standards.
- **User-Friendly Interface:** Displays data in a clear and accessible manner.
- **Versatility:** Can be adapted for different use cases.

## Components Used
- **Sensors:** TDS sensor and temperature sensor.
- **Microcontroller:** ESP32 to process sensor data.
- **Display:** OLED screen for real-time data visualization.
- **Alert System:** Uses an LED, buzzer, or notification (SMS/email) for alerts.
- **Resistors:** Ensures proper sensor connections.

## Software & Implementation
1. **Microcontroller Programming:**
   - ESP32 collects data from sensors.
   - Converts raw data into meaningful values.
   - Displays data on an OLED screen.

2. **Alert Mechanism:**
   - Compares sensor readings with predefined standards.
   - Triggers an alert when water quality is unsafe.
   - Sends notifications through SMS/email.

3. **Data Processing & Transmission:**
   - Data is logged for future analysis.
   - Can be integrated with a web-based dashboard for remote monitoring.

## Installation & Setup
1. **Hardware Setup:**
   - Connect the TDS and temperature sensors to ESP32.
   - Attach the display module.
   - Ensure the alert system is properly wired.

2. **Software Setup:**
   - Install the required libraries in Arduino IDE:
     ```cpp
     #include <Wire.h>
     #include <WiFi.h>
     #include <OneWire.h>
     #include <DallasTemperature.h>
     #include <Adafruit_GFX.h>
     #include <Adafruit_SSD1306.h>
     ```
   - Configure WiFi settings and API key for cloud integration.

3. **Run the System:**
   - Upload the code to ESP32.
   - Monitor real-time water quality readings on the OLED screen.
   - Receive alerts for unsafe conditions.

## Testing
- Tested with different water samples to validate accuracy.
- Ensured alerts trigger correctly when thresholds are exceeded.
- Verified data logging and remote monitoring features.

## Enhancements (Optional)
- **Data Logging:** Store historical water quality data.
- **Web Interface:** Monitor readings remotely.
- **Machine Learning Integration:** Predict future trends based on data.

## Usefulness
- **Early Detection of Contamination:** Ensures safe and clean drinking water.
- **Prevention of Health Risks:** Avoids waterborne diseases by timely alerts.
- **Data-Driven Decision Making:** Helps in long-term water management.
- **Versatility:** Usable for homes, communities, and industries.

## Advantages
- **24/7 Monitoring:** Ensures continuous assessment of water quality.
- **Automated Alerts:** No need for manual checks.
- **Safe Water Assurance:** Helps users trust their water source.
- **Scalability:** Can be expanded for large-scale water management.


