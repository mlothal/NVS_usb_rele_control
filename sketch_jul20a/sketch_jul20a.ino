const int outputPin = 2;
char receivedChar;

void setup() {
  Serial.begin(115200);
  pinMode(outputPin, OUTPUT);
  digitalWrite(outputPin, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    receivedChar = Serial.read();
    if (receivedChar == 'L') {// enciende las luces
      digitalWrite(outputPin, LOW);
      Serial.println("<=1=>");
    } else if (receivedChar == 'F') {    // apaga las luces
      digitalWrite(outputPin, HIGH);
      Serial.println("<=0=>");
    }
  }

  // Enviamos el estado actual de la salida L a través del puerto serie.
  if (digitalRead(outputPin) == HIGH) {
    Serial.println("<=0=>");
  } else {
    Serial.println("<=1=>");
  }

  // Un breve retraso para evitar enviar datos muy rápido a través del puerto serie.
  delay(500);
}
