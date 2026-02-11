#define PWMA D5
#define AIN1 D6
#define AIN2 D7
#define STBY D8

void setup() {
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(STBY, OUTPUT);

  digitalWrite(STBY, HIGH);   // ativar driver
}

void loop() {

  // ===== Frente =====
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 800);   // velocidade (0-1023)
  delay(5000);

  // Pequena pausa para proteger engrenagens
  analogWrite(PWMA, 0);
  delay(300);

  // ===== Trás =====
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, 800);
  delay(5000);

  // Pequena pausa
  analogWrite(PWMA, 0);
  delay(300);
}
