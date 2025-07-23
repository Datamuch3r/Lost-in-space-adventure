# Day 4 – Light Domination: Full Cabin Control 🏰✨

With my DIP switch fully understood, I expanded its reach across the ship. Three switches. Three LEDs. Total control over the cabin, storage, and cockpit lights. I may still be stranded, but now I’m stranded... in style.

---

## 🔧 Objective

Wire and program three LEDs, each controlled by its own DIP switch.  
Switch ON → LED ON  
Switch OFF → LED OFF

---

## 🧪 What I Used

- 1x HERO Board
- 1x Breadboard
- 3x LEDs (use different colors for fun!)
- 3x 220Ω Resistors
- 1x DIP switch (3 switches)
- 3x Pull-down Resistors
- Jumper wires
- Arduino IDE

---

## 🔌 Wiring Summary

Each LED:
- Pin (10, 11, 12) → Resistor → LED Anode
- LED Cathode → GND

Each DIP Switch:
- Pin (2, 3, 4) → one side of switch
- Other side → GND
- Pull-down resistor from pin to GND

---

## 💾 The Code

```cpp
#include "Arduino.h"

const byte CABIN_LIGHTS_PIN = 10;
const byte STORAGE_LIGHTS_PIN = 11;
const byte COCKPIT_LIGHTS_PIN = 12;

const byte CABIN_LIGHTS_SWITCH_PIN = 2;
const byte STORAGE_LIGHTS_SWITCH_PIN = 3;
const byte COCKPIT_LIGHTS_SWITCH_PIN = 4;

void setup() {
  pinMode(CABIN_LIGHTS_PIN, OUTPUT);
  pinMode(STORAGE_LIGHTS_PIN, OUTPUT);
  pinMode(COCKPIT_LIGHTS_PIN, OUTPUT);

  pinMode(CABIN_LIGHTS_SWITCH_PIN, INPUT);
  pinMode(STORAGE_LIGHTS_SWITCH_PIN, INPUT);
  pinMode(COCKPIT_LIGHTS_SWITCH_PIN, INPUT);
}

void loop() {
  digitalWrite(CABIN_LIGHTS_PIN, digitalRead(CABIN_LIGHTS_SWITCH_PIN));
  digitalWrite(STORAGE_LIGHTS_PIN, digitalRead(STORAGE_LIGHTS_SWITCH_PIN));
  digitalWrite(COCKPIT_LIGHTS_PIN, digitalRead(COCKPIT_LIGHTS_SWITCH_PIN));
}
