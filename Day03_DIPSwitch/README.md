# Day 3 – DIP Switch Control: The Power Is Yours 🕹️🔦

Today I wielded true power — not just *when* the LED blinked, but *if* it blinked at all. Using a DIP switch wired to my HERO board, I turned the blinking LED into a manually-controlled beacon of cabin dominance.

---

## 🔧 Objective

Control the blinking LED using a physical switch connected to the HERO board.  
Switch ON → LED ON  
Switch OFF → LED OFF

---

## 🧪 What I Used

- 1x HERO Board
- 1x Breadboard
- 1x LED (any color)
- 1x 220Ω Resistor
- 1x DIP switch (3-position module)
- 1x Pull-down Resistor (1kΩ or 220Ω)
- Jumper wires
- Arduino IDE

---

## 🔌 Wiring Summary

- **Pin 12** → 220Ω Resistor → **LED Anode**
- **LED Cathode** → GND
- **Pin 2** → one side of DIP switch
- **Other side of DIP switch** → GND
- **Pull-down resistor** between Pin 2 and GND

---

## 💾 The Code

```cpp
#include "Arduino.h"

#define CABIN_LIGHTS_PIN 12
#define CABIN_LIGHTS_SWITCH_PIN 2

void setup() {
  pinMode(CABIN_LIGHTS_PIN, OUTPUT);
  pinMode(CABIN_LIGHTS_SWITCH_PIN, INPUT);
}

void loop() {
  if (digitalRead(CABIN_LIGHTS_SWITCH_PIN) == HIGH) {
    digitalWrite(CABIN_LIGHTS_PIN, HIGH);
  } else {
    digitalWrite(CABIN_LIGHTS_PIN, LOW);
  }
}
