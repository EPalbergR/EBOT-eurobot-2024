#include "definiciones.h"
RF24 radio(7, 8); // CE, CSN
bool transmisor = true;
void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);
  radio.begin();
  radioSetup();
}
void loop() {

  if (transmisor == true) {
    transmisorFn();
  }


  if (transmisor == false) {
    receptorFn();

  }
  if (levantar == 1) {
    if (millis() > timerLevantar) {
      if (codigo.servos[2] < 170) {
        codigo.servos[2] += 2;
        timerLevantar = millis()+50;
      }
      else {
        levantar = 0;
      }
    }
  }
}
