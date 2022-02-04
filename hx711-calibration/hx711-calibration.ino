#include "HX711.h"

/* USER CONFIGURATION START */

// Specify which pins the HX711 is connected to:
const int hx_sck_pin = 13;
const int hx_do_pin = 14;

/* USER CONFIGURATION END */

HX711 scale;

double reference_g;
double reading;
double calib_value;

void setup() {
  Serial.begin(115200);
  Serial.println("Remove all weight from the scale and press any key.");
  while (Serial.available() == 0);
  while (Serial.available()) Serial.read();

  delay(1000);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale();
  scale.tare();
  
  Serial.println("Input the reference weight in grams: ");
  while (Serial.available() == 0);
  reference_g = Serial.parseFloat();
  while (Serial.available()) Serial.read();
  
  Serial.println("Place the reference weight onto the scale and press any key.");
  while (Serial.available() == 0);
  while (Serial.available()) Serial.read();

  delay(1000);  
  reading = scale.get_units(400);
  calib_value = reading/reference_g;
  
  Serial.println("The calibration value for the set_scale() function is: ");
  Serial.println(calib_value);
  
}

void loop() {
  yield();
}
