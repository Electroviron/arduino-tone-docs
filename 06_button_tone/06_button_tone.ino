const int BUZZER_PIN = 8;
const int BUTTON_PIN = 4;

void PlayTone(int freq){
    tone(BUZZER_PIN, freq);
}

void setup(){
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop(){
    int BUTTON_PIN_VAL = digitalRead(BUTTON_PIN);

    if(BUTTON_PIN_VAL == LOW){
        PlayTone(500);
    }
    else{
        noTone(BUZZER_PIN);
    }
}

/*
 * Modify the code so that pressing the button plays a different frequency.

 * Try:

 * 200 Hz
 * 1000 Hz
 * 2000 Hz

 */