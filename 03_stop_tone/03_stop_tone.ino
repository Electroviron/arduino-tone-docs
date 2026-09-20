const int BUZZER_PIN = 8;

void setup() {
  tone(BUZZER_PIN, 1000);
  delay(2000);

  noTone(BUZZER_PIN);
}

void loop() {
}