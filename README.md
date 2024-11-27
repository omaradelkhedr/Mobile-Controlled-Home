
# **Mobile Controlled Home**

![SmartHomeDPart](https://github.com/user-attachments/assets/6f3cb4b8-e80b-4984-b60b-79b6b341aaa4)


## **Introduction**
The **Mobile Controlled Home** project implements a smart home system that enables users to control home appliances remotely using a mobile application. By integrating hardware and software components, this system enhances security, comfort, and energy efficiency. It is designed to provide low cost, flexibility, ease of use, and reliability.  

## **Features**
- **Remote Device Control**: Manage devices like LEDs, AC, and motors using mobile commands.
- **Security Mechanisms**: Username and password authentication with alarms for unauthorized access.
- **Temperature Monitoring**: Display the real-time temperature through a connected sensor.
- **Power Management**: Alerts users to minimize electricity waste.
- **Modular Design**: Divided into MCAL, HAL, and application layers for better readability and maintainability.

---

## **Project Structure**
The project is divided into three layers:  
1. **Application Layer (APP)**:
   - Main program logic and flow.
   - Handles user commands and authentication.
2. **Hardware Abstraction Layer (HAL)**:
   - Interfaces with devices like LEDs, motors, and temperature sensors.
3. **Microcontroller Abstraction Layer (MCAL)**:
   - Low-level interaction with microcontroller peripherals (DIO, USART, ADC, Timer).

---


**Project Flowchart:**


![Project Flowchart](https://github.com/user-attachments/assets/c6d59b95-ee2f-4bf7-8d72-c8aaf2725b39)


## **Technologies Used**
- **Programming Language**: C
- **Microcontroller Features**: USART, ADC, Timer, DIO
- **Development Environment**: Eclipse, Proteus
- **Hardware Components**:
  - Temperature sensor
  - LEDs
  - Relay (for AC control)
  - Buzzer
  - Motor

---

## **Setup Instructions**
1. **Hardware Requirements**:
   - Microcontroller: Atmega32.
   - Modules: LEDs, temperature sensor, motor, relay, buzzer.

2. **Software Requirements**:
   - IDE: Eclipse or any other C compiler.
   - Simulation: Proteus for circuit simulation.

3. **How to Use**:
   - Use a mobile application to send USART commands to the microcontroller.
   - Login with a valid username and password.
   - Control devices using pre-defined commands (e.g., turn LEDs on/off, adjust intensity).

---

## **Commands**
Below are the supported commands:
| **Command**           | **Function**                         |
|-----------------------|-------------------------------------|
| `LOG_OUT`             | Logout from the system.             |
| `LED_ON`              | Turn on the LED.                    |
| `LED_OFF`             | Turn off the LED.                   |
| `DOOR_LOCK`           | Lock the door.                      |
| `DOOR_UNLOCK`         | Unlock the door.                    |
| `LED_INTENSITY25`     | Set LED brightness to 25%.          |
| `LED_INTENSITY50`     | Set LED brightness to 50%.          |
| `LED_INTENSITY75`     | Set LED brightness to 75%.          |
| `AC_ON_OFF`           | Toggle the AC state.                |
| `GET_TEMP`            | Display the current temperature.    |

---

## **Examples of Users and Their Passwords**
Here is a list of sample users and their passwords to demonstrate the authentication mechanism:

| **Username**         | **Password**       |
|-----------------------|--------------------|
| Omar Adel            | FirstPassword     |
| Ahmed Abdelhamid     | SecondPassword    |
| Mayar Wael           | ThirdPassword     |
| Omar Khedr           | FourthPassword    |
| Ahmed Shokry         | FifthPassword     |
| Mayar Heweidy        | SixthPassword     |
| Omar Adel Khedr      | SeventhPassword   |
| Ahmed Shokry         | EigthPassword     |
| Mayar Wael Kamal     | NinthPassword     |
| Khedr                | TenthPassword     |

---

## **Team Contributions**
- **Omar Adel Khedr**: ADC, Buzzer, LED, AC.
- **Ahmed Abdelhamid**: Timer, Motor, Temperature Sensor.
- **Mayar Wael**: DIO, UART.

---

## **Acknowledgements**
This project was developed as part of a group effort to create a functional and user-friendly smart home system. Special thanks to all team members for their valuable contributions.

---
