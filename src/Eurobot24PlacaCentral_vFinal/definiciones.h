#include <Servo.h>
#include <SPI.h>
#include "printf.h"
#include "RF24.h"
//#include <AsyncStepper.hpp>
#include <AccelStepper.h>


long tiempoAnterior = 0;

//RC
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
  int servos[6] = {90,90,90,40,1,1};
  int scara = 0;
  int altura = 0;
};


info recibido;

int offsetRobot = 0;

//Botones
bool button1Anterior = false;
bool button2Anterior = false;
bool button3Anterior = false;
bool button4Anterior = false;
bool bJyStckAnterior = false;
bool servosAnterior[6] = {90,90,90,50,1,1};
bool giroCW = false;
bool giroCCW = false;
int alturaAnterior=0;


//Motores paso a paso
int alturaActual = 0;
int anguloActual = 0;
float alturaAbsoluta = 0;
float anguloAbsoluto= 0;
float offSetAltura = 0;
