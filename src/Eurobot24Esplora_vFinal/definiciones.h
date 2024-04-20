#include <SPI.h>
#include "printf.h"
#include "RF24.h"
#include <Esplora.h>

const byte address[6] = "00001";
struct info {
  float velocidad = 0;
  int angulo = 0;
  bool cambio = false;
  bool button1 = false;
  bool button2 = false;
  bool button3 = false;
  bool button4 = false;
  bool bJyStck = false;
  int slider = 0;
  int servos[6] = {90,90,90,50,1,1};
  int scara = 0;
  int altura=0;
};

info codigo;
info anterior;

int tiempoPasado=0;
bool enviar=false;
bool levantar=0;
long timerLevantar=0;
