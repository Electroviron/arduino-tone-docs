const int BUZZER_PIN = 8;

void setup() {
}

void loop() {

  // C Major Scale
  tone(BUZZER_PIN, 262);  // C
  delay(500);

  tone(BUZZER_PIN, 294);  // D
  delay(500);

  tone(BUZZER_PIN, 330);  // E
  delay(500);

  tone(BUZZER_PIN, 349);  // F
  delay(500);

  tone(BUZZER_PIN, 392);  // G
  delay(500);

  tone(BUZZER_PIN, 440);  // A
  delay(500);

  tone(BUZZER_PIN, 494);  // B
  delay(500);

  tone(BUZZER_PIN, 523);  // C
  delay(500);

  noTone(BUZZER_PIN);
  delay(1000);
}