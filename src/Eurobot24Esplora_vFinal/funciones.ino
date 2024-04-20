void transmisorFn() {
  long ejeX = Esplora.readJoystickX() ;
  long ejeY = Esplora.readJoystickY();

  float velocidadRaw = sqrt(sq(ejeY) + sq(ejeX));
  velocidadRaw = constrain(velocidadRaw, 0, 512);
  codigo.velocidad = map(velocidadRaw, 0, 512, 0, 75);
  int angulo = (atan2(ejeY, ejeX) * RAD_TO_DEG * -1) - 90;
  if (angulo < 0) codigo.angulo = angulo + 360;
  else codigo.angulo = angulo;

  codigo.button1 = !Esplora.readButton(SWITCH_1);
  codigo.button2 = !Esplora.readButton(SWITCH_2);
  codigo.button3 = !Esplora.readButton(SWITCH_3);
  codigo.button4 = !Esplora.readButton(SWITCH_4);
  codigo.bJyStck = !Esplora.readJoystickButton();
  codigo.slider = Esplora.readSlider();

  if (Serial.available() > 0) {
    char dato = Serial.read();
    if (dato == 'C') {
      codigo.cambio = true;
    }
  }
  //Serial.println(codigo.velocidad);
  //Serial.println(codigo.angulo);
  if (codigo.velocidad != anterior.velocidad) {
    enviar = true;
  }
  if (codigo.angulo != anterior.angulo) {
    enviar = true;
  }
  if (codigo.cambio != anterior.cambio) {
    enviar = true;
  }
  if (codigo.button1 != anterior.button1) {
    enviar = true;
  }
  if (codigo.button2 != anterior.button2) {
    enviar = true;
  }
  if (codigo.button3 != anterior.button3) {
    enviar = true;
  }
  if (codigo.button4 != anterior.button4) {
    enviar = true;
  }
  if (codigo.bJyStck != anterior.bJyStck) {
    enviar = true;
  }
  if (codigo.slider != anterior.slider) {
    enviar = true;
  }
  if (codigo.servos != anterior.servos) {
    enviar = true;
  }
  if (codigo.scara != anterior.scara) {
    enviar = true;
  }





  if (enviar == true) {
    anterior = codigo;
    enviar = false;
    if (radio.write(&codigo, sizeof(codigo))) { //enviar la informacion

      // Serial.println("OK");
    }
    else {
      // Serial.println("FALLO");
    }
  }
  if (Serial1.available () > 0) {
    char dato = Serial1.read();
    //Serial.println(dato);
    //Serial.println("hello");
    if (dato == 'U') {
      Serial1.println('<');
      Serial1.println(codigo.velocidad);
      Serial1.println(codigo.angulo);
      Serial1.println(codigo.cambio);
      Serial1.println(codigo.button1);
      Serial1.println(codigo.button2);
      Serial1.println(codigo.button3);
      Serial1.println(codigo.button4);
      Serial1.println(codigo.bJyStck);
      Serial1.println(codigo.slider);
      Serial1.println('>');
    }
    if (dato == 'A') {
      int valor = Serial1.parseInt();
      codigo.scara = valor;
      Serial.print('A');
      Serial.println(codigo.scara);
    }
    if (dato == 'B') {
      int valor = Serial1.parseInt();
      codigo.servos[0] = valor;
      Serial.print('B');
      Serial.println(codigo.servos[0]);
    }
    if (dato == 'C') {
      int valor = Serial1.parseInt();
      codigo.servos[1] = valor;
      Serial.print('C');
      Serial.println(codigo.servos[1]);
    }
    if (dato == 'D') {
      int valor = Serial1.parseInt();
      codigo.servos[2] = valor;
      Serial.print('D');
      Serial.println(codigo.servos[2]);
    }
    if (dato == 'E') {
      int valor = Serial1.parseInt();
      codigo.servos[3] = valor;
      Serial.print('E');
      Serial.println(codigo.servos[3]);
    }
    if (dato == 'F') {
      int valor = Serial1.parseInt();
      codigo.servos[4] = valor;
      Serial.print('F');
      Serial.println(codigo.servos[4]);
    }
    if (dato == 'G') {
      int valor = Serial1.parseInt();
      codigo.servos[5] = valor;
      Serial.print('G');
      Serial.println(codigo.servos[5]);
    }
    if (dato == 'L') {
      levantar = 1;
    }
    if (dato == 'H') {
      int valor = Serial1.parseInt();
      codigo.altura = valor;
      Serial.print('H');
      Serial.println(codigo.altura);
    }
    if (dato == 'W') {
      int valor = Serial1.parseInt();
      codigo.velocidad=0;
      radio.write(&codigo, sizeof(codigo));
      delay(valor);
    }
  }
  if (codigo.cambio == true) {
    transmisor = !transmisor;
    radio.openReadingPipe(0, address);
    radio.startListening();
    codigo.cambio = false;
  }
}


void receptorFn() {
  if (radio.available()) {
    char lectura;
    radio.read(&lectura, sizeof(lectura));

    Serial.println(lectura);

    if (lectura == 'T') {
      transmisor = !transmisor;
      radio.openWritingPipe(address);
      radio.stopListening();
    }
  }
}
