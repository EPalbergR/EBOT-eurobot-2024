#define AIN1 1
#define AIN2 2
#define ENCB 10
#define BIN1 3
#define BIN2 4
#define disparador 6

volatile long gradosB = 0;
volatile long pulsosB = 0;

void setup() {
  Serial.begin(9600);
  //pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  //pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  //pinMode(ENCB, INPUT_PULLUP);

  pinMode(disparador, INPUT_PULLUP);
  while (digitalRead(disparador) == 0) {
  }
  delay(94000);
  analogWrite(AIN1, 255);
  digitalWrite(AIN2, 0);
  analogWrite(BIN1, 245);
  digitalWrite(BIN2, 0);
  delay(3700);
  analogWrite(AIN1, 255);
  digitalWrite(AIN2, 1);
  analogWrite(BIN1, 255);
  digitalWrite(BIN2, 1);
}

void loop() {
  // put your main code here, to run repeatedly:

}
