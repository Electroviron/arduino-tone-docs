const int BUZZER_PIN = 8;

void setup() {
}

void loop() {

  // Sweep upward
  for (int frequency = 200; frequency <= 1000; frequency += 10) {
    tone(BUZZER_PIN, frequency);
    delay(20);
  }

  // Sweep downward :)
  // Modify the program so that the pitch gradually decreases from 1000 Hz back to 200
  // write code here......
  
}