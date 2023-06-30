// Pino conectado ao sensor de chama 
const int flamePin = 2;
// Pino conectado ao buzzer
const int buzzerPin = 7;
// Pino conectado ao laser 
const int laserPin = 11;

void setup() {
  // Iniciando comunicação no serial
  Serial.begin(9600);

  // Configurando o pino do sensor de chama como entrada
  pinMode(flamePin, INPUT);

  // Configurando os pinos do buzzer e laser como saídas
  pinMode(buzzerPin, OUTPUT);
  pinMode(laserPin, OUTPUT);
}

void loop() {
  // Lendo o valor registrado pelo sensor de chama
  int flameValue = digitalRead(flamePin);

  // Verificando se a chama é detectada 
  if (flameValue == HIGH) {
    Serial.println("FOGO!");
    // Ligando o buzzer e  o laser
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(laserPin, HIGH);
    tone(buzzerPin, 1000); // Tocar um som com frequência de 1000 Hz
  } else {
    Serial.println("Sem fogo.");
    // Desligar o buzzer e o laser
    digitalWrite(buzzerPin, LOW);
    digitalWrite(laserPin, LOW);
    noTone(buzzerPin); // Parar o som
  }

  delay(1000); // Delay por um segundo
}