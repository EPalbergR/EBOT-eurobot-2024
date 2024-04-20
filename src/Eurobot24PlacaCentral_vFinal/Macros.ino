void updateMacros() {
  // Modo normal
  if (recibido.button1 != button1Anterior) {    // ABAJO
    if (recibido.button1) {
      alturaAbsoluta -= 10;
      moverAlturaAbsoluto(alturaAbsoluta);

    }
    button1Anterior = recibido.button1;
  }
  if (recibido.button3 != button3Anterior) {    // ARRIBA
    if (recibido.button3) {
      alturaAbsoluta += 10;
      moverAlturaAbsoluto(alturaAbsoluta);
    }
    button3Anterior = recibido.button3;
  }
  if (recibido.button2 != button2Anterior) {    // IZQUIERDA
    if (recibido.button2) {
      anguloAbsoluto += 10;
      moverAnguloAbsoluto(anguloAbsoluto);
    }
    button2Anterior = recibido.button2;
  }
  if (recibido.button4 != button4Anterior) {    // DERECHA
    if (recibido.button4) {
      anguloAbsoluto -= 10;
      moverAnguloAbsoluto(anguloAbsoluto);
    }
    button4Anterior = recibido.button4;
  }
  moverAnguloAbsoluto(recibido.scara);

  if (recibido.altura != alturaAnterior) {
    alturaAbsoluta = recibido.altura;
    moverAlturaAbsoluto(alturaAbsoluta);
    alturaAnterior = recibido.altura;
    Serial.println(recibido.altura);
  }

  for (int i = 0; i < 6; i++) {
    if (recibido.servos[i] != servosAnterior[i]) {
      servos[i].write(recibido.servos[i]);
      servosAnterior[i] = recibido.servos[i];
    }
  }
}
