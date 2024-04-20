int PIDvelocidad(int lectura, int Vpwm, float kp) {
  float media = Vpwm * 1;
  float error = media - lectura;
  float proporcional = error * kp;
  int VpwmSalida = proporcional + Vpwm;
  if (abs(VpwmSalida - Vpwm) > 10)VpwmSalida = Vpwm - 10 * (Vpwm / abs(Vpwm)) ;
  if (Vpwm == 0)VpwmSalida = 0;
  return VpwmSalida;
}

int PIDanguloZ(int media,int lectura, float kp) {
  float error = media - lectura;
  float proporcional = error * kp;
  int output = proporcional;
  if(abs(output)<5)output = 0;
  if(abs(output)>30)output = 30 * (output / abs(output)) ;
  return output;
}
