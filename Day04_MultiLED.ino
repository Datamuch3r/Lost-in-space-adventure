#include "Arduino.h"

// LED pin constants
const byte CABIN_LIGHTS_PIN = 10;     // Pin for cabin lights (LED 1)
const byte STORAGE_LIGHTS_PIN = 11;   // Pin for storage lights (LED 2)
const byte COCKPIT_LIGHTS_PIN = 12;   // Pin for cockpit/exterior lights (LED 3)

// DIP switch pin constants
const byte CABIN_LIGHTS_SWITCH_PIN = 2;    // Switch 1
const byte STORAGE_LIGHTS_SWITCH_PIN = 3;  // Switch 2
const byte COCKPIT_LIGHTS_SWITCH_PIN = 4;  // Switch 3

void setup() {
  // Configure LED pins as OUTPUT
  pinMode(CABIN_LIGHTS_PIN, OUTPUT);
  pinMode(STORAGE_LIGHTS_PIN, OUTPUT);
  pinMode(COCKPIT_LIGHTS_PIN, OUTPUT);

  // Configure DIP switch pins as INPUT
  pinMode(CABIN_LIGHTS_SWITCH_PIN, INPUT);
  pinMode(STORAGE_LIGHTS_SWITCH_PIN, INPUT);
  pinMode(COCKPIT_LIGHTS_SWITCH_PIN, INPUT);
}

void loop() {
  // Cabin Lights
  if (digitalRead(CABIN_LIGHTS_SWITCH_PIN) == HIGH) {
    digitalWrite(CABIN_LIGHTS_PIN, HIGH);
  } else {
    digitalWrite(CABIN_LIGHTS_PIN, LOW);
  }

  // Storage Lights
  if (digitalRead(STORAGE_LIGHTS_SWITCH_PIN) == HIGH) {
    digitalWrite(STORAGE_LIGHTS_PIN, HIGH);
  } else {
    digitalWrite(STORAGE_LIGHTS_PIN, LOW);
  }

  // Cockpit Lights
  if (digitalRead(COCKPIT_LIGHTS_SWITCH_PIN) == HIGH) {
    digitalWrite(COCKPIT_LIGHTS_PIN, HIGH);
  } else {
    digitalWrite(COCKPIT_LIGHTS_PIN, LOW);
  }
}

