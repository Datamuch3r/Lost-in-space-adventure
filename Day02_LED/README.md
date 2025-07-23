# Day 2 – External LED: Lighting the Cabin 🌕🔧

Today’s mission was to move beyond the safety of the onboard LED and bring actual light to my stranded spacecraft. I wired an external LED to my HERO board using a 220Ω resistor to avoid frying it — both the LED and my hopes.

---

## 🔧 Objective

Control a separate LED connected to pin 12 on the HERO board and make it blink using Arduino code. This simulates turning on cabin lights to illuminate the repair bay.

---

## 🧪 What I Used

- 1x HERO Board (Arduino Uno compatible)
- 1x Breadboard
- 1x LED (any color)
- 1x 220Ω Resistor
- Jumper wires (male-to-male)
- Arduino IDE

---

## 🔌 Circuit Summary

- **Pin 12** → 220Ω Resistor → **LED Anode (long leg)**
- **LED Cathode (short leg)** → GND
- Used breadboard power rails for neat wiring

---

## 💾 The Code

```cpp
#define CABIN_LIGHTS_PIN 12

void setup() {
  pinMode(CABIN_LIGHTS_PIN, OUTPUT);
}

void loop() {
  digitalWrite(CABIN_LIGHTS_PIN, HIGH);  // LED ON
  delay(1000);                           // wait 1 second
  digitalWrite(CABIN_LIGHTS_PIN, LOW);   // LED OFF
  delay(100);                            // wait 0.1 seconds
}
