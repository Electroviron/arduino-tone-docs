const int BUZZER_PIN = 8;
const int LED_PIN = 3;

void setup(){
    pinMode(LED_PIN, OUTPUT);

    // Start a continuous 750 Hz tone
    tone(BUZZER_PIN, 750);
}

void loop(){

   // blink LED
   digitalWrite(LED_PIN, HIGH);
   delay(1000);

   digitalWrite(LED_PIN, LOW);
   delay(1000);
}


/*
 * CHALLENGE:
 *
 * Make the tone match the LED.
 
 * When the LED turns ON:
 *   --> Play the tone
 
 * When the LED turns OFF:
 *   --> Stop the tone
 
 * Hint:
 * You will need to use both tone() and noTone()
 * inside the loop().
 */