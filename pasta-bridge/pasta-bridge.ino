#include "HX711.h"

/* USER CONFIGURATION START */

// Specify which pins the HX711 is connected to:
const int hx_sck_pin = 13;
const int hx_do_pin = 14;

// Specify the calibration value obtained by running
// the hx711_calibration.ino sketch:
const double calibration_value = 251.79;

/* USER CONFIGURATION END */

HX711 scale;

void setup() {
  Serial.begin(115200);
  scale.begin(hx_do_pin, hx_sck_pin);
  scale.set_scale(calibration_value);
  scale.tare();
}

void loop() {
  while (!scale.is_ready());
  Serial.println(scale.get_units());
}
