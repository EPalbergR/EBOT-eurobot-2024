void radioSetup() {
  if (transmisor == true)radio.openWritingPipe(address); //cadena de 5 numeros o letras
  else {
    radio.openReadingPipe(0, address);
  }
  radio.setChannel(125);//canal de 1(2400) a 125(2525)
  radio.setPALevel (RF24_PA_MIN); //nivel de potencia de la antena.RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH, RF24_PA_MAX
  radio.setDataRate (RF24_250KBPS);
  radio.setRetries(1, 15);
  radio.powerUp();
  if (transmisor == true) {
    radio.stopListening(); //configurar modulo como transmisor
  }
  else {
    radio.startListening();
  }
}
