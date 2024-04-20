#define PWMA 9 //motorA
#define AIN1 8
#define PWMB 5//motorB 
#define BIN1 6
#define PWMC 10//motorC
#define CIN1 15
#define ENCODERAinterrupt 7
#define ENCODERBinterrupt 1
#define ENCODERCinterrupt 0



int velocidadGiro = 0;
bool modoRobot = 1;
float anguloZ = 0;
float offsetZ = 0;
float offsetRobot = 0;
String motor = "ABC";
bool motorShield = 0;
volatile long gradosB = 0;
volatile long gradosC = 0;
volatile unsigned long tiempoAnteriorB = 0;
volatile unsigned long tiempoAnteriorC = 0;
volatile long pulsosA = 0;
volatile long pulsosB = 0;
volatile long pulsosC = 0;
volatile unsigned long tiempoEntrePulsosC = 0;
unsigned long crono1 = 0;
int indice = 0;
float RPM = 0.00;
int errorSuma = 0;
int errorAnterior = 0;
