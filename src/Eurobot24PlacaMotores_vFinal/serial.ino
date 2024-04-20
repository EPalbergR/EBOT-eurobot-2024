void serialBTControl() {
  if (SerialBT.available() > 0) {
    char dato = SerialBT.read();
    Serial.println(dato);
    if (dato == 'S') { //Start
      motor = SerialBT.readStringUntil(' ');//modificar motor
      int velocidad = SerialBT.parseInt();//modificar velocidad
      motorStart(motor, velocidad);//encender motores
      SerialBT.println(String("start: ") + String(motor) + velocidad);
    }
    if (dato == 'V') { //Start
      motor = SerialBT.readStringUntil(' ');//modificar motor
      int velocidad = SerialBT.parseInt();//modificar velocidad
      motorSetSpeed(motor, velocidad);//encender motores
      SerialBT.println(String("setSpeed: ") + String(motor) + velocidad);
    }
    if (dato == 'B') {//Stop
      motor = SerialBT.readStringUntil(' ');//modificar motor
      motorStop(motor);
    }
    if (dato == 'P') {
      velocidadGeneral = SerialBT.parseInt();
    }
    if (dato == 'Z') {
      offsetZ = SerialBT.parseInt();
      offsetRobot = offsetZ;
      offsetZ = offsetZ + (int)anguloZ - (int)anguloZ % 360;
    }
    if (dato == 'O') {
      int angulo = SerialBT.parseInt();
      if (modoRobot == 0) {
        modoRobot = 1;
        motorStop("ABC");
        loopMPU();
        offsetZ = anguloZ;
        Serial.print("cambio");
        Serial.print(offsetZ);
      }
      Omni(angulo + 180, velocidadGeneral);
    }
    if (dato == 'G') {
      velocidadGiro = SerialBT.parseInt();
      if (modoRobot == 1) {
        modoRobot = 0;
        motorStop("ABC");
        Serial.print("cambio");
      }
    }

    /*
      if (dato == 'M') {//Move
      motor = SerialBT.readStringUntil(' ');//modificar motor
      velocidad = SerialBT.parseInt();//modificar velocidad

      String freno = SerialBT.readString();
      int parada = freno.toInt();
      motorStop(motor, parada);
      SerialBT.println(motor + freno);
      motorMove(motor, velocidad, 180, 1);
      }
    */
  }
}
