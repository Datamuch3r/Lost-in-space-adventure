When your ship is stranded on an alien planet and systems are failing left and right, it's critical to know the status of your survival gear at a glance. This project creates an **Emergency Status Panel** using LEDs and DIP switches to visually indicate the ship’s condition.

---

## 💡 What It Does

This panel uses **3 DIP switches** as input and lights up one of **3 LEDs** to show your current system status:

- 🟢 **Green LED**: All systems normal (all switches OFF)
- 🟡 **Yellow LED**: Some systems failing (1–2 switches ON)
- 🔴 **Red LED**: Total system failure (all 3 switches ON)

---

## 🧰 Hardware Required

- HERO board (Arduino UNO compatible)
- Breadboard
- 3 DIP switches (on a single 3-position module)
- 3 LEDs (red, yellow, green)
- 3 × 220Ω resistors
- Jumper wires (male-to-male)
- USB cable for uploading code

---

## ⚙️ Pin Connections

| Component     | HERO Pin | Notes                 |
|---------------|----------|------------------------|
| DIP Switch 1  | D2       | Uses INPUT_PULLUP      |
| DIP Switch 2  | D3       | Uses INPUT_PULLUP      |
| DIP Switch 3  | D4       | Uses INPUT_PULLUP      |
| Green LED     | D10      | Status: Normal         |
| Yellow LED    | D11      | Status: Warning        |
| Red LED       | D12      | Status: Critical       |

> ⚠️ The DIP switch common pins go to **GND**, and use **internal pull-ups** in code. No 10kΩ resistors needed.

---

## 🛠️ Setup Instructions

1. Plug the LEDs into the breadboard with their long leg (anode) to the appropriate HERO pin and short leg (cathode) through a 220Ω resistor to GND.
2. Connect each DIP switch terminal to D2, D3, D4.
3. Connect the opposite terminals of all DIP switches to GND.
4. Upload the code below using the Arduino IDE.

---

## 🧠 Code

```cpp
#include "Arduino.h"

const byte GREEN_LED_PIN = 10;
const byte YELLOW_LED_PIN = 11;
const byte RED_LED_PIN = 12;

const byte SWITCH1_PIN = 2;
const byte SWITCH2_PIN = 3;
const byte SWITCH3_PIN = 4;

void setup() {
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);

  pinMode(SWITCH1_PIN, INPUT_PULLUP);
  pinMode(SWITCH2_PIN, INPUT_PULLUP);
  pinMode(SWITCH3_PIN, INPUT_PULLUP);
}

void loop() {
  bool switch1 = digitalRead(SWITCH1_PIN) == LOW;
  bool switch2 = digitalRead(SWITCH2_PIN) == LOW;
  bool switch3 = digitalRead(SWITCH3_PIN) == LOW;

  int activeSwitches = switch1 + switch2 + switch3;

  if (activeSwitches == 0) {
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);
  } else if (activeSwitches < 3) {
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
  } else {
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);
  }

  delay(100);
}
