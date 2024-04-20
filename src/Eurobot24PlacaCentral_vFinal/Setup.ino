void radioSetup() {
  if (transmisor == true)radio.openWritingPipe(address); //cadena de 5 numeros o letras
  else {
    radio.openReadingPipe(0, address);
  }
  radio.setChannel(125);//canal de 1(2400) a 125(2525)
  radio.setPALevel (RF24_PA_MAX); //nivel de potencia de la antena.RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH, RF24_PA_MAX
  radio.setDataRate (RF24_250KBPS); //velocidad
  radio.setRetries(1, 15); // intentos
  radio.powerUp();
  if (transmisor == true) {
    radio.stopListening(); //configurar modulo como transmisor
  }
  else {
    radio.startListening();
  }
}
void servoSetup() {
  for (int i = 0; i < 6; i++) {
    pinMode(pinesServo[i], OUTPUT);
    servos[i].attach(pinesServo[i],600,2400 );
    servos[i].write(recibido.servos[i]);
    delay(1000);
  }
  
}
