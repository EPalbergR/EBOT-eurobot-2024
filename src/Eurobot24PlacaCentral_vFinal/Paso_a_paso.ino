/*
  void moverMotores (int altura, int angulo, int velSubir, int velGirar) {// Altura objetivo absoluta(mm), Angulo objetivo absoluto(mm), Velocidad Subir/Bajar (rpm), Velocidad Giro (rpm)
  subir.SetSpeedRpm(velSubir);
  girar.SetSpeedRpm(velGirar);

  int difAltura = altura - alturaActual;
  int gradosAltura = difAltura * 45;   // Teniendo en cuenta que el paso del eje roscado es 8mm/360º
  int difAngulo = angulo - anguloActual;
  int gradosAngulo = abs(difAngulo) * 4; // Relacion entre engranajes 4:1
  int gradosAlturaTotal = gradosAltura + difAngulo;

  if (gradosAlturaTotal >= 0) subir.RotateAngle(gradosAlturaTotal, AsyncStepper::CW);
  else subir.RotateAngle(abs(gradosAlturaTotal), AsyncStepper::CCW);
  if (difAngulo >= 0) girar.RotateAngle(gradosAngulo, AsyncStepper::CCW);
  else girar.RotateAngle(gradosAngulo, AsyncStepper::CW);

  }*/
/*
  void moverMotoresRelativo (int altura, int angulo, int velSubir, int velGirar) {// Altura objetivo relativa(mm), Angulo objetivo relativa(mm), Velocidad Subir/Bajar (rpm), Velocidad Giro (rpm)
  subir.SetSpeedRpm(velSubir);
  girar.SetSpeedRpm(velGirar);

  int gradosAltura = altura * 45;   // Teniendo en cuenta que el paso del eje roscado es 8mm/360º
  int gradosAngulo = abs(angulo) * 4; // Relacion entre engranajes 4:1
  int gradosAlturaTotal = gradosAltura + angulo;

  if (gradosAlturaTotal >= 0) subir.RotateAngle(gradosAlturaTotal, AsyncStepper::CW);
  else subir.RotateAngle(abs(gradosAlturaTotal), AsyncStepper::CCW);
  if (angulo >= 0) girar.RotateAngle(gradosAngulo, AsyncStepper::CCW);
  else girar.RotateAngle(gradosAngulo, AsyncStepper::CW);
  }
*/
void moverMotoresAbsoluto(int altura, int angulo) {
  if (altura != 0)subir.moveTo(altura * 25); // 25 pulsos = 1 mm Nota:Teniendo en cuenta que el paso del eje roscado es 8mm/360º
  if (angulo != 0){
    if(angulo>-40 and angulo<40)girar.moveTo(angulo * 4); // 200 pulsos = 360º Relacion entre engranajes 4:1
  }
}

void moverAlturaAbsoluto(float altura) { //altura en mm
  subir.moveTo((altura - offSetAltura) * 25);
}

void moverAnguloAbsoluto(float angulo) {
  angulo = constrain(angulo,-50,50);
  int pasos = (angulo / 360) * 200 * 4;
  girar.moveTo(pasos);
  offSetAltura = (angulo / 360) * 8;
  moverAlturaAbsoluto(alturaAbsoluta);
}


void updatePasoPaso() {
  subir.run();
  girar.run();
  //alturaActual = subir.GetAbsoluteStep() / 25;
  //anguloActual = (girar.GetAbsoluteStep() / 2.2) * -1;
}
