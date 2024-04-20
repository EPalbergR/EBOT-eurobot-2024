void motorSetup() {
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(PWMC, OUTPUT);
  pinMode(CIN1, OUTPUT);
  pinMode(ENCODERAinterrupt, INPUT_PULLUP);
  pinMode(ENCODERBinterrupt, INPUT_PULLUP);
  pinMode(ENCODERCinterrupt, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ENCODERAinterrupt), encoderA, RISING);
  attachInterrupt(digitalPinToInterrupt(ENCODERBinterrupt), encoderB, RISING);
  attachInterrupt(digitalPinToInterrupt(ENCODERCinterrupt), encoderC, RISING);
}

void motorStartA(int velocidad) {  //Este motor está invertido
  if (velocidad < 0) {
    digitalWrite(AIN1, 1);//atrás
  }  
  else {
    digitalWrite(AIN1, 0);//adelante
  }

  velocidad = abs(velocidad);
  velocidad = constrain(velocidad, 0, 100);
  velocidad = map(velocidad, 0, 100, 0, 255);

  analogWrite(PWMA, velocidad);
}
void motorStartB(int velocidad) {
  if (velocidad < 0) {
    digitalWrite(BIN1, 0);//atrás
  }
  else {
    digitalWrite(BIN1, 1);//adelante
  }
  velocidad = abs(velocidad);
  velocidad = constrain(velocidad, 0, 100);
  velocidad = map(velocidad, 0, 100, 0, 255);

  analogWrite(PWMB, velocidad);
}
void motorStartC(int velocidad) {
  if (velocidad < 0) {
    digitalWrite(CIN1, 0);//atrás
  }
  else {
    digitalWrite(CIN1, 1);//adelante
  }
  velocidad = abs(velocidad);
  velocidad = constrain(velocidad, 0, 100);
  velocidad = map(velocidad, 0, 100, 0, 255);

  analogWrite(PWMC, velocidad);
}
void motorStart(String motor, int velocidad) {
 /* if(abs(velocidad)>9){
    
  }*/
  for (int i = 0; i < motor.length(); i++) {
    if (motor.charAt(i) == 'A')motorStartA(velocidad);
    if (motor.charAt(i) == 'B')motorStartB(velocidad);
    if (motor.charAt(i) == 'C')motorStartC(velocidad);
  }
}

void motorSetSpeed(String motor, int velocidad) {
  for (int i = 0; i < motor.length(); i++) {
    if (motor.charAt(i) == 'A')velocidadA =velocidad;
    if (motor.charAt(i) == 'B')velocidadB =velocidad;
    if (motor.charAt(i) == 'C')velocidadC =velocidad;
  }
}
void motorStop(String motor) {
  for (int i = 0; i < motor.length(); i++) {
    if (motor.charAt(i) == 'A') {
      digitalWrite(PWMA, 0);
    } else if (motor.charAt(i) == 'B') {
      digitalWrite(PWMB, 0);
    }
    else{
      digitalWrite(PWMC, 0);
    }
  }
}



//attachInterrup con RISING
void encoderA() {
  if (!digitalRead(AIN1)) {
    pulsosA--;
  }
  else {
    pulsosA++;
  }
}


void encoderB() {
  if (!digitalRead(BIN1)) {
    pulsosB--;
  }
  else {
    pulsosB++;
  }
}

void encoderC() {
  if (!digitalRead(CIN1)) {
    pulsosC--;
  }
  else {
    pulsosC++;
  }
}


long motorGetDegrees(String motor) {
  if (motor == "B")return gradosB;
  //  if (motor == "A")return gradosA;
}

long motorCount (String motor) {
  return motorGetDegrees(motor);
}

void motorResetDegrees(String motor) {
  if (motor == "B")gradosB = 0;
  //  if (motor == "A")gradosA = 0;
}





int getPulsos (char motor) {

  int pulsos;
  if (motor == 'A') {
    pulsos = pulsosA;
    pulsosA = 0;
  }
  if (motor == 'B') {
    pulsos = pulsosB;
    pulsosB = 0;
  }
  if (motor == 'C') {
    pulsos = pulsosC;
    pulsosC = 0;
  }
  return pulsos;
}



float getRPM() {
  RPM =  ((pulsosA) / 462.00) * 600;
  Serial.println(pulsosA);
  pulsosA = 0;
  crono1 = millis();

  return RPM;
}
