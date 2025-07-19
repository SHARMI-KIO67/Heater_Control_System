# Heater_Control_System
Temperature-based heater control system using ESP32-S3 and DS18B20 sensor, with relay control, overheat protection, LED indication, and buzzer alert. Simulated using Wokwi

# Temperature-Based Heater Control System with Overheat Protection

This project demonstrates a smart heater control system using an **ESP32-S3** microcontroller, a **DS18B20** temperature sensor, a **relay module**, an **LED**, and a **buzzer**. The system maintains a desired temperature range and ensures safety by automatically handling overheating conditions.

## Features

- Real-time temperature monitoring (DS18B20)
- Automatic heater control using a relay
- State-based logic (IDLE, HEATING, STABILIZING, TARGET_REACHED, OVERHEAT)
- LED indication for heater status
- Buzzer alert for overheat protection
- Auto-resume operation after cooldown

## Components Used

- ESP32-S3 Development Board  
- DS18B20 Temperature Sensor  
- Relay Module  
- LED  
- Buzzer  
- Wokwi Online Simulator

## System Working Principle

- If temperature is below the lower limit, the system turns on the heater (HEATING).
- Once it nears the target temperature, it switches to STABILIZING mode.
- When the target temperature is reached, the heater is turned off (TARGET_REACHED).
- If temperature exceeds the overheat limit, the system shuts off the heater and activates the buzzer (OVERHEAT).
- The system resumes normal operation once the temperature drops to a safe level.

## State Machine

- **IDLE**: Initial state when no heating action is required.
- **HEATING**: Temperature is below the lower threshold.
- **STABILIZING**: Temperature is nearing the target.
- **TARGET_REACHED**: Heater turns off at the desired temperature.
- **OVERHEAT**: System shuts down with a buzzer alert until temperature cools.

## 📷 Simulation

This project was built and tested in the [Wokwi Simulator](https://wokwi.com/).  
**[Click here to view the simulation](https://wokwi.com/projects/436929153257862145)** 

## Future Scope

- Add multiple heating profiles
- Bluetooth/Wi-Fi control and monitoring
- OLED or LCD display for real-time temperature
- Mobile app integration

## License

This project is developed for academic and internship purposes. You may reuse or modify it for educational use.

---



