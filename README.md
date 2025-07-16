
# 8051 Reaction Time Tester

## ✅ Overview

This project is a **Reaction Time Tester** built using the **8051 microcontroller**. It measures how quickly a user can respond to a visual cue displayed on an LCD screen. The system uses **Timer0**, **external interrupt**, and an LCD interface.

## ⚙️ Features

- Random delay before triggering the "GO!" signal.
- Measures time with millisecond precision.
- Displays reaction time on a 16x2 LCD.
- Uses push button input on port P3.2.
- Code written in embedded C using Keil IDE.

## 🧰 Hardware Requirements

- AT89C51 / 8051 Microcontroller
- 16x2 LCD display
- Push button (connected to P3.2)
- Resistors, capacitors, crystal oscillator
- Power supply (5V)

## 📁 Project Files

- `reaction.c` – Main source code in embedded C.
- `reaction_time_tester.uvproj` – Keil µVision project file.

## 🔧 How It Works

1. LCD displays `"Reaction Test"`, then prompts `"Wait..."`.
2. After a random delay (2–5 seconds), `"GO!"` appears.
3. Timer0 starts counting as soon as `"GO!"` is displayed.
4. User presses a button; timer stops.
5. The elapsed time is shown in `s.ms` format (e.g., `1.235 s`).
6. System resets after 5 seconds and repeats.

## 🛠️ How to Run

1. Open the `.uvproj` file in Keil µVision IDE.
2. Compile and flash the code to your 8051 microcontroller.
3. Connect the LCD and push button as per code:
   - LCD Data Pins: Port 2
   - RS: P3.5, RW: P3.6, EN: P3.7
   - Button: P3.2
4. Power the circuit and start testing reaction times!


## 📜 License

This project is open source and free to use for educational purposes.
