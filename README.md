# Reverse Parking Radar with AT89C51

This repository contains the complete source code and documentation for the **Reverse Parking Radar** project, developed using the **AT89C51** microcontroller. The system is designed to measure proximity to obstacles and provide visual and auditory feedback, simulating a parking radar.

---

## Project Overview

The main goal of this project is to design and implement a prototype of a proximity detection system that can aid in parking vehicles by detecting obstacles. The system utilizes an **HC-SR04 ultrasonic sensor**, a **buzzer**, and an **LCD display**, all controlled by the AT89C51 microcontroller.

### Features:
- Measures obstacle distances.
- Displays real-time distances on a screen.
- Provides auditory feedback through a buzzer, with sound intensity proportional to distance.
- Designed as a modular and extendable system for various applications.

---

## Project Structure

```
.
├── doc/                        # Documentation folder
├── README.md                   # Project documentation
├── buzzer.h                    # Header file for buzzer functionality
├── lcd.h                       # Header file for LCD management
└── main.c                      # Main code controlling the system
```

---

## Components Used

1. **Microcontroller**: AT89C51.
2. **Ultrasonic Sensor**: HC-SR04 for obstacle detection.
3. **LCD Display**: For visualizing measured distances.
4. **Buzzer**: For auditory proximity alerts.
5. Power supply and connecting wires.

---

## How It Works

1. **Distance Measurement**: The HC-SR04 sensor sends an ultrasonic pulse and measures the echo time, which is then used to calculate the distance.
2. **Data Processing**: The microcontroller processes the signal and calculates the distance using the formula:
   ```
   Distance = (Echo Time * Speed of Sound) / 2
   ```
3. **Alerts**:
   - The LCD displays the calculated distance in real-time.
   - The buzzer emits sound based on the proximity to the obstacle.

---

## Results and Observations

- The system accurately measures distances and provides timely feedback.
- The LCD operates flawlessly, offering clear and precise readings.
- The buzzer functions as intended, but its sound output is relatively low. A more powerful buzzer is recommended for noisy environments.
- The current implementation works for short distances (~20 cm). For larger distances (up to 2 meters), a more advanced sensor is advised.

---

## Future Enhancements

This project serves as a foundation for various extensions and improvements:
1. **Improved Detection**:
   - Replace the HC-SR04 with a sensor capable of detecting longer distances.
   - Use multiple sensors for multi-angle detection.
2. **Enhanced Alerts**:
   - Integrate LEDs for visual indicators.
   - Use a loudspeaker or higher-powered buzzer.
3. **Connectivity**:
   - Add Bluetooth or Wi-Fi modules for remote monitoring.
   - Develop a companion mobile app for data analysis and visualization.
4. **Additional Features**:
   - Integrate a camera for visual assistance.
   - Expand the system for industrial or robotics applications.

---

## References

1. [STC89CXX Datasheet](#)
2. [Keil Manual](#)
3. [HC-SR04 Sensor Documentation](#)

---

### Contributors

- Guillaume FAIVRE
- Clément CHANDEZON
- Quentin CHARDON DU RANQUET
- Ruth Aurora RUIZ CARRILLO

---

## Report
The final report can be accessed via this link:
[INSERER LE LIEN]
