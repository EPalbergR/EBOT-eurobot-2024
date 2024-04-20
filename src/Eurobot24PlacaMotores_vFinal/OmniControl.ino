


void Omni(int angulo, int velocidad) {
  int anguloDesplazamiento = angulo - offsetZ;
  velocidadA = sin((0 - anguloDesplazamiento) * 0.01745329) * velocidad;
  velocidadB = sin((-120 - anguloDesplazamiento) * 0.01745329) * velocidad;
  velocidadC = sin((120 - anguloDesplazamiento) * 0.01745329) * velocidad;
}


void omniPID() {

  int vAnguloZ = PIDanguloZ(0, anguloZ - offsetZ, 1.5);
  int velocidad;
  int pulsos;

  pulsos = getPulsos('A');
  //Serial.print('A');
  //Serial.println(pulsos);
  velocidad = PIDvelocidad(pulsos, velocidadA, 0.75);
  //Serial.println(velocidad);
  motorStart("A", velocidadA + vAnguloZ);

  pulsos = getPulsos('B');
  //Serial.print('B');
  //Serial.println(pulsos);
  velocidad = PIDvelocidad(pulsos, velocidadB, 0.75);
  //Serial.println(velocidad);
  motorStart("B", velocidadB + vAnguloZ);

  pulsos = getPulsos('C');
  //Serial.print('C');
  //Serial.println(pulsos);
  velocidad = PIDvelocidad(pulsos, velocidadC, 0.75);
  //Serial.println(velocidad);
  motorStart("C", velocidadC + vAnguloZ);


}

void giroPID() {

  if (abs(velocidadGiro) < 10)velocidadGiro = 0;
  velocidadA = velocidadGiro;
  velocidadB = velocidadGiro;
  velocidadC = velocidadGiro;
  int velocidad;
  int pulsos;

  pulsos = getPulsos('A');
  //Serial.print('A');
  //Serial.println(pulsos);
  velocidad = PIDvelocidad(pulsos, velocidadA, 0.75);
  //Serial.println(velocidad);
  motorStart("A", velocidad );

  pulsos = getPulsos('B');
  //Serial.print('B');
  //Serial.println(pulsos);
  velocidad = PIDvelocidad(pulsos, velocidadB, 0.75);
  //Serial.println(velocidad);
  motorStart("B", velocidad );

  pulsos = getPulsos('C');
  //Serial.print('C');
  //Serial.println(pulsos);
  velocidad = PIDvelocidad(pulsos, velocidadC, 0.75);
  //Serial.println(velocidad);
  motorStart("C", velocidad );
}
