 #include "definiciones.h"

RF24 radio(9, 10); // CE, CSN       MISO 14, SCLK 15, MOSI 16
//AsyncStepper subir(200, A0, A1);     //pasos por vuelta, dirPin, stepPin
//AsyncStepper girar(200, A2, A3);   //pasos por vuelta, dirPin, stepPin

AccelStepper subir = AccelStepper(1, A1, A0);
AccelStepper girar = AccelStepper(1, A3, A2);

Servo servos[6];
const byte pinesServo[6] = {2,3,4,5,6,7}; //Añadimos uno más porque el último objeto no funciona




bool transmisor = false;
long timer = 0;



void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  radio.begin();
  radioSetup();
  subir.setMaxSpeed(1000 );
  subir.setSpeed(800);
  subir.setAcceleration(500.00);
  girar.setMaxSpeed(1500);
  girar.setSpeed(800);
  girar.setAcceleration(1000.00);
  servoSetup();
  //subir.ResetAbsoluteStep();
  //moverMotores(0, 1080, 25, 100);
  //subir.moveTo(1000);

  
}

void loop() {
 
  receptorFn();

  if (millis() > tiempoAnterior + 20) {
    //Serial1.println(recibido.modo);
    enviarSerial();
    updateMacros();
    tiempoAnterior = millis();
  }
  updatePasoPaso();
}
