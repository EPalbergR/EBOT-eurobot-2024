
void transmisorFn() {
  char dato = 'T';
  radio.write(&dato, sizeof(dato));
  transmisor = !transmisor;
  radio.openReadingPipe(0, address);
  radio.startListening();
}


void receptorFn() {
  if (radio.available()) {

    radio.read(&recibido, sizeof(recibido));

    if (recibido.cambio == true) {
      transmisor = !transmisor;
      radio.openWritingPipe(address);
      radio.stopListening();
    }
  }
}
