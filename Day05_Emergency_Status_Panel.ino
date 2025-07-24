#include "Arduino.h"

// LED pins
const byte GREEN_LED_PIN = 10;
const byte YELLOW_LED_PIN = 11;
const byte RED_LED_PIN = 12;

// DIP switch pins
const byte SWITCH1_PIN = 2;
const byte SWITCH2_PIN = 3;
const byte SWITCH3_PIN = 4;

void setup() {
  // Set LED pins as OUTPUT
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);

  // Set switch pins as INPUT_PULLUP (because we don’t have 10k resistors)
  pinMode(SWITCH1_PIN, INPUT_PULLUP);
  pinMode(SWITCH2_PIN, INPUT_PULLUP);
  pinMode(SWITCH3_PIN, INPUT_PULLUP);
}

void loop() {
  // Read switch states (LOW means switch is ON due to INPUT_PULLUP)
  bool switch1 = digitalRead(SWITCH1_PIN) == LOW;
  bool switch2 = digitalRead(SWITCH2_PIN) == LOW;
  bool switch3 = digitalRead(SWITCH3_PIN) == LOW;

  int activeSwitches = switch1 + switch2 + switch3;

  // Status logic
  if (activeSwitches == 0) {
    // All systems normal
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);
  } else if (activeSwitches < 3) {
    // Warnings present
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
  } else {
    // Critical failure
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);
  }

  delay(100); // Just a short pause to keep things smooth
}
