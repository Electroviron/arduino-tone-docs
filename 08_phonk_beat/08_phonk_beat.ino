/*
   ARDUINO VIRAL FUNK
   ------------------
   Original 5-minute evolving funk composition
   Uses only tone() and noTone()

   Passive buzzer:
       +  -> Arduino D9
       -  -> GND

   Board: Arduino Uno/Nano
*/

#define BUZZER 9

// Notes
#define C3  131
#define Cs3 139
#define D3  147
#define Ds3 156
#define E3  165
#define F3  175
#define Fs3 185
#define G3  196
#define Gs3 208
#define A3  220
#define As3 233
#define B3  247

#define C4  262
#define Cs4 277
#define D4  294
#define Ds4 311
#define E4  330
#define F4  349
#define Fs4 370
#define G4  392
#define Gs4 415
#define A4  440
#define As4 466
#define B4  494

#define C5  523
#define Cs5 554
#define D5  587
#define Ds5 622
#define E5  659
#define F5  698
#define Fs5 740
#define G5  784
#define Gs5 831
#define A5  880
#define As5 932
#define B5  988

#define C6  1047
#define D6  1175
#define E6  1319
#define F6  1397
#define G6  1568
#define A6  1760

// Tempo
const int BPM = 110;

// One 16th note
const unsigned long STEP = 60000UL / BPM / 4;


// --------------------------------------------------
// PLAY ONE NOTE
// --------------------------------------------------

void playNote(int note, int steps) {

  if (note == 0) {
    noTone(BUZZER);
    delay(STEP * steps);
  }
  else {
    tone(BUZZER, note);
    delay(STEP * steps);
    noTone(BUZZER);
  }
}


// --------------------------------------------------
// FUNK "KICK" / PERCUSSION EFFECT
// --------------------------------------------------

void click(int steps = 1) {

  tone(BUZZER, 90);
  delay(STEP / 3);

  noTone(BUZZER);
  delay(STEP * steps);
}


// --------------------------------------------------
// CHORD ROOTS
// Funk progression:
//
// Am7 -> Dm7 -> G7 -> Cmaj7
//
// Then variations are introduced.
// --------------------------------------------------

int roots[] = {
  A3,
  D3,
  G3,
  C4,
  F3,
  B3,
  E3,
  A3
};


// --------------------------------------------------
// SECTION 1
// GROOVE INTRO
// --------------------------------------------------

void sectionIntro() {

  for (int bar = 0; bar < 8; bar++) {

    int root = roots[bar % 4];

    playNote(root, 2);
    playNote(0, 1);

    playNote(root + 12, 1);
    playNote(0, 1);

    playNote(root, 1);
    playNote(root + 12, 1);

    playNote(0, 2);

    playNote(root + 24, 1);
    playNote(0, 1);

    playNote(root + 19, 1);
    playNote(root + 24, 1);

    playNote(0, 2);
  }
}


// --------------------------------------------------
// SECTION 2
// MAIN GROOVE
// --------------------------------------------------

void sectionMain() {

  int bass[] = {
    A3, A3, 0, A3,
    C4, 0, D4, 0,
    E4, 0, D4, C4,
    A3, 0, G3, 0
  };

  for (int bar = 0; bar < 24; bar++) {

    for (int i = 0; i < 16; i++) {

      int n = bass[i];

      // Every few bars, move the riff upward
      if (bar % 6 == 3 || bar % 6 == 4) {
        if (n > 0)
          n += 12;
      }

      // Occasional rhythmic changes
      if (bar % 8 == 7 && i == 14)
        n = E5;

      playNote(n, 1);
    }
  }
}


// --------------------------------------------------
// SECTION 3
// HIGH FUNK RIFF
// --------------------------------------------------

void sectionHigh() {

  int riff1[] = {
    E5, 0, G5, A5,
    0, G5, E5, 0,
    D5, E5, G5, 0,
    A5, G5, E5, 0
  };

  int riff2[] = {
    E5, G5, A5, 0,
    B5, A5, G5, E5,
    0, D5, E5, G5,
    A5, 0, E5, 0
  };

  for (int bar = 0; bar < 20; bar++) {

    int *riff;

    if (bar % 4 == 0 || bar % 4 == 1)
      riff = riff1;
    else
      riff = riff2;

    for (int i = 0; i < 16; i++) {

      int n = riff[i];

      // Make every 5th bar jump an octave
      if (bar % 5 == 4 && n != 0)
        n += 12;

      playNote(n, 1);
    }
  }
}


// --------------------------------------------------
// SECTION 4
// BREAKDOWN
// Lots of space.
// --------------------------------------------------

void sectionBreak() {

  int notes[] = {
    A4, 0, 0, E5,
    0, G5, 0, 0,
    D5, 0, E5, 0,
    G5, A5, 0, 0
  };

  for (int bar = 0; bar < 12; bar++) {

    for (int i = 0; i < 16; i++) {

      int n = notes[i];

      // Gradually raise the breakdown
      if (bar > 7 && n != 0)
        n += 12;

      playNote(n, 1);
    }
  }
}


// --------------------------------------------------
// SECTION 5
// BASS HEAVY
// --------------------------------------------------

void sectionBass() {

  int patterns[4][16] = {

    {
      A3, 0, A3, C4,
      0, A3, 0, E4,
      A3, 0, G3, 0,
      E3, G3, A3, 0
    },

    {
      D3, 0, D3, F3,
      0, A3, 0, D4,
      D3, 0, C4, A3,
      F3, 0, D3, 0
    },

    {
      G3, 0, G3, B3,
      0, D4, 0, G4,
      G3, 0, F3, D4,
      B3, 0, G3, 0
    },

    {
      C4, 0, C4, E4,
      0, G4, 0, C5,
      C4, 0, B3, G3,
      E4, 0, C4, 0
    }
  };

  for (int bar = 0; bar < 20; bar++) {

    int pattern = bar % 4;

    for (int i = 0; i < 16; i++) {

      int n = patterns[pattern][i];

      // Variation every 7 bars
      if (bar % 7 == 6 && n != 0)
        n += 12;

      playNote(n, 1);
    }
  }
}


// --------------------------------------------------
// SECTION 6
// CHAOTIC FUNK RIFF
// --------------------------------------------------

void sectionWild() {

  int scale[] = {
    A4, C5, D5, E5,
    G5, A5, C6, D6
  };

  unsigned long seed = 12345;

  for (int bar = 0; bar < 18; bar++) {

    for (int i = 0; i < 16; i++) {

      // Deterministic pseudo-random number
      seed = seed * 1103515245 + 12345;

      int r = (seed >> 16) & 0x7FFF;

      int n;

      // Lots of rhythmic space
      if (r % 5 == 0) {
        n = 0;
      }
      else {

        n = scale[r % 8];

        // Occasionally go down
        if (r % 9 == 0)
          n -= 24;

        // Occasionally jump high
        if (r % 13 == 0)
          n += 12;
      }

      playNote(n, 1);
    }
  }
}


// --------------------------------------------------
// SECTION 7
// FINAL GROOVE
// --------------------------------------------------

void sectionFinal() {

  int finalRiff[] = {

    A4, 0, C5, D5,
    E5, 0, G5, E5,

    D5, C5, A4, 0,
    G4, A4, C5, 0
  };

  for (int bar = 0; bar < 24; bar++) {

    for (int i = 0; i < 16; i++) {

      int n = finalRiff[i];

      // Build upward
      if (bar >= 8 && bar < 16 && n != 0)
        n += 12;

      // Final section gets even higher
      if (bar >= 16 && n != 0)
        n += 12;

      playNote(n, 1);
    }
  }
}


// --------------------------------------------------
// BIG ENDING
// --------------------------------------------------

void ending() {

  playNote(A4, 2);
  playNote(C5, 1);
  playNote(D5, 1);

  playNote(E5, 2);
  playNote(G5, 1);
  playNote(A5, 1);

  playNote(C6, 2);
  playNote(A5, 1);
  playNote(G5, 1);

  playNote(E5, 2);

  noTone(BUZZER);
  delay(400);

  playNote(A4, 4);

  noTone(BUZZER);
}


// --------------------------------------------------
// SETUP
// --------------------------------------------------

void setup() {

  pinMode(BUZZER, OUTPUT);

  delay(1000);

  // Intro
  sectionIntro();

  // Main groove
  sectionMain();

  // High-energy riff
  sectionHigh();

  // Breakdown
  sectionBreak();

  // Bass section
  sectionBass();

  // Wild variation
  sectionWild();

  // Final groove
  sectionFinal();

  // Ending
  ending();
}


// --------------------------------------------------
// LOOP
// --------------------------------------------------

void loop() {

  // Stay silent after the 5-minute performance.
  noTone(BUZZER);

}