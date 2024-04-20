void enviarSerial() {
  int velocidad = (int)recibido.velocidad;
  if (recibido.button2) {
    int velocidadDir = -250;
    Serial1.print(String("G") + velocidadDir + String(","));
  }
  else if (recibido.button4) {
    int velocidadDir = 250;
    Serial1.print(String("G") + velocidadDir + String(","));
  }
  else if (velocidad != 0 or recibido.angulo != 0) {
    Serial1.print(String("P") + velocidad + String(",O") + recibido.angulo + String(","));
  }
}
