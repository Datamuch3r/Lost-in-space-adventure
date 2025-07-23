#include "Arduino.h"  // include information about our HERO

#define CABIN_LIGHTS_PIN 12         // Control our lander's lights using HERO's pin 12
#define CABIN_LIGHTS_SWITCH_PIN 2   // Connect our DIP switch to pin 2

void setup() {
  pinMode(CABIN_LIGHTS_PIN, OUTPUT);      // Set light pin as OUTPUT
  pinMode(CABIN_LIGHTS_SWITCH_PIN, INPUT); // Set switch pin as INPUT
}

void loop() {
  if (digitalRead(CABIN_LIGHTS_SWITCH_PIN) == HIGH) {
    digitalWrite(CABIN_LIGHTS_PIN, HIGH); // If switch is ON, turn light ON
  } else {
    digitalWrite(CABIN_LIGHTS_PIN, LOW);  // If switch is OFF, turn light OFF
  }
}
