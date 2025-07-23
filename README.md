# Day 1 – Blink: First Contact with the HERO 🛠️💡

Welcome to Day 1 of *30 Days Lost in Space*! Today marks the first flicker of hope — literally. Using my HERO board and the power of Arduino code, I made an LED blink. It’s a small light... but a giant leap for this marooned Explorer.

---

## 🔧 Objective

Make the onboard LED (connected to pin 13) blink on and off every second. This proves that the HERO board is functioning, code uploads are working, and I'm not completely doomed.

---

## 🧪 What I Used

- 1x HERO Board (Arduino Uno compatible)
- USB data cable
- Arduino IDE

---

## 🧠 What I Learned

- How to connect and recognize the HERO board in the Arduino IDE
- How to load and upload a basic sketch (`File > Examples > 01.Basics > Blink`)
- The difference between `setup()` and `loop()`
- Using `pinMode()` to set a pin as an output
- Controlling an LED with `digitalWrite()` and timing it with `delay()`

---

## 💾 The Code

```cpp
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // initialize pin 13 as output
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // LED ON
  delay(1000);                      // wait 1 second
  digitalWrite(LED_BUILTIN, LOW);   // LED OFF
  delay(1000);                      // wait 1 second
}
