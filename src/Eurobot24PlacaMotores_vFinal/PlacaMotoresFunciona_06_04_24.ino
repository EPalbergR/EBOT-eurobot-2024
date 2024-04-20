#include <MPU6050_light.h>
#include <Wire.h>
#include"definiciones.h"          //Con "" si está en la propia carpeta del proyecto
#include <SoftwareSerial.h>

SoftwareSerial SerialBT (16, A1);
MPU6050 mpu(Wire);

int velocidadGeneral = 25;
int velocidadA = 25;
int velocidadB = 25;
int velocidadC = 25;
unsigned long crono2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //while(!Serial);//////////////////////////////////////////////////////////////////////////////////////////////
  motorSetup();
  setupMPU();
  SerialBT.begin(9600);
  Omni(0, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  serialBTControl();
  if (millis() > crono1 + 50) {
    loopMPU();
    //Serial.println(anguloZ);
    if (modoRobot) {
      omniPID();

    } else {
      giroPID();

    }
    crono1 = millis();
  }
  //Serial.println(modoRobot);

  /*
    if (millis() > crono2 + 1000) {
    Serial.println(indice);
    switch (indice){
      case 0:
        Omni(0, velocidadGeneral);
        break;
      case 1:
        Omni(90, velocidadGeneral);
        break;
      case 2:
        Omni(180, velocidadGeneral);
        break;
      case 3:
        Omni(-90, velocidadGeneral);
        indice = -1;
        break;
    }
    indice++;
    crono2 = millis();
    }*/
}
