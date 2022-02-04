## PASTA HX711-to-USB bridge 

This is a repository which contains Arduino code for a bridge which forwards HX711 data to a PC over a USB connection, based on the *NodeMCU ESP-32S* board, as used in the papers "Repurposing a digital kitchen scale for neuroscience research: a complete hardware and software cookbook for PASTA" and "griPASTA: A hacked kitchen scale for quantification of grip strength in rodents"

#### Papers:

 * Virag D, Homolak J, Kodvanj I, Babic Perhoc A, Knezovic A, Osmanovic Barilar J, et al. *Repurposing a digital kitchen scale for neuroscience research: a complete hardware and software cookbook for PASTA.* Sci Rep 2021;11:2963. https://doi.org/10.1038/s41598-021-82...
 * Homolak J, Virag D, Kodvanj I, Matak I, Perhoc AB, Knezovic A, et al. *A hacked kitchen scale-based system for quantification of grip strength in rodents.* 2021. https://doi.org/10.1101/2020.07.23.21...

#### How-to videos:

 * [Cooking PASTA: hardware how-to](https://www.youtube.com/watch?v=JPkPoqzhAT8)
 * [Fast PASTA: converting an HX711 module to 80 SPS](https://www.youtube.com/watch?v=0cxS-a837bY)

----

#### How to set up PASTA bridge

1. Download and install [bogde's HX711 library](https://github.com/bogde/HX711): Download the latest release, open the Arduino IDE, go to `Sketch > Include library > Add ZIP library` and select the downloaded ZIP.
2. Clone or download this repository as a ZIP archive and unpack it.
3. Load the `hx711-calibration.ino` sketch, set the `hx_sck_pin` and `hx_do_pin` variables according to the Arduino pins that you have connected the HX711 board to, and upload the sketch to your Arduino board.
4. Run the serial monitor (`Tools > Serial Monitor`), set it to 115200 baud, reset the Arduino board using the onboard reset button and follow the on-screen instructions. Note the calibration value.
5. Load the pasta-bridge.ino sketch, set the `hx_sck_pin` and `hx_do_pin` variables and set `calibration_value` to the calibration value you just obtained. Finally, upload the sketch.

#### Requires:

* [bogde's HX711 library](https://github.com/bogde/HX711)
