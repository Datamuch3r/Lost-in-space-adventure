#include "Arduino.h"

#define CABIN_LIGHTS_PIN 12 // This is the nickname for the pin connected to our LED

void setup() {
  pinMode(CABIN_LIGHTS_PIN, OUTPUT); // We will control our lander's lights as an OUTPUT.
}

void loop() {
  digitalWrite(CABIN_LIGHTS_PIN, HIGH); // This line turns the lander's light ON.
  delay(1000);                          // Wait for one second (1000 milliseconds) with the ligh ON.
  digitalWrite(CABIN_LIGHTS_PIN, LOW);  // This line turns the lander's light OFF.
  delay(100);                           // Wait for a tenth of a second (100 milliseconds) with the light OFF.
}
