# VR Haptic Glove (ESP32 + Unity)

This project is my Final Year Engineering Project (PFE).  
It consists of a **VR Haptic Glove** that tracks finger motion and provides **haptic feedback** in virtual environments.  

## ✨ Features
- Finger tracking with **potentiometers**.
- Real-time data acquisition using **ESP32**.
- **UDP communication** between ESP32 and Unity.
- **Force feedback** using servomotors.
- **Tactile feedback** using vibration motors.
- Hand visualization in **Unity 3D**.

## 🛠️ Components
- ESP32-WROOM-32D
- 5x Potentiometers (finger tracking)
- 2x Servomotors (force feedback)
- 5x Mini vibration motors
- Power bank (5V, 10,000mAh)
- Unity 3D

## 🔗 System Architecture
![Block Diagram](images/block_diagram.png)

## 📂 Code
- `esp32_udp_sender.ino` → Reads potentiometers and sends values over UDP.
- `unity_udp_listener.cs` → Receives data in Unity and animates hand model.

## 📷 Prototype
![Glove Prototype](images/glove_prototype.jpg)

## 🚀 Future Work
- Add more precise force feedback control
- Optimize vibration feedback
- Improve Unity hand rigging
