#include "HX711.h"

// To use with other boards, simply update the pin definitions.
#define HX_DO_PIN 18
#define HX_SCK_PIN 19

HX711 scale;

void setup() {
  Serial.begin(115200);
  scale.begin(HX_DO_PIN, HX_SCK_PIN);
  scale.set_scale(0.f);
  scale.tare();
}

void loop() {
  Serial.println(scale.get_units());
  delay(10);
}
