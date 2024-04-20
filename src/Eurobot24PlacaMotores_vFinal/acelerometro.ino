//This tab includes the functions to initalize MPU 6050 and update its data
// ================================================================
// ===                      INITIAL SETUP                       ===
// ================================================================

void setupMPU() {
  Wire.begin();
  mpu.begin();
  delay(1000);
  mpu.calcGyroOffsets();
  delay(1000);
  Serial.println(String("x: ") + mpu.getGyroXoffset() + String(" y: ") + mpu.getGyroYoffset() + String(" z: ") + mpu.getGyroZoffset());
  //mpu.setGyroOffsets(-1.59, 1.07, 0.25);
}

// ================================================================
// ===                    UPDATE MPU DATA                       ===
// ================================================================

void loopMPU() { //Updates MPU(angle) data
  mpu.update();
  anguloZ = mpu.getAngleZ() * (-1)/* - offsetMPU*/;
  //Serial.println(anguloZ);
  //anguloZ = ((int)anguloZ % 360) + (anguloZ - (int)anguloZ);
  //if(anguloZ < 0) anguloZ += 360;
  /*if (anguloZ > 180) {
    anguloZ = (anguloZ - 360);
  }
  if (anguloZ < -180) {
    anguloZ = (anguloZ + 360);
  }///// Forces the angle to 180 <---> -180*/
}
