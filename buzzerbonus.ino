#include <pitches.h>

int melody1[] {NOTE_E7, NOTE_G6}; 
int melody2[] {NOTE_C7, NOTE_G6, NOTE_C7};
int melody3[] {NOTE_G7, NOTE_G6, NOTE_G7, NOTE_G6};
int duration = 500; // 500 milliseconds = 0.5 second
int buzzer = 13;

void setup() {
}
void loop() {
  for (int thisNote = 0; thisNote < 2; thisNote++) {
    for (int thisNote = 0; thisNote < 3; thisNote++) {
      for (int thisNote = 0; thisNote < 4; thisNote++) {
        // Play each note in the melodies
        tone(buzzer, melody1[thisNote], duration);
        delay(3000); // Wait for 3 seconds between notes
        tone(buzzer, melody2[thisNote], duration);
        delay(3000); // Wait for 3 seconds between notes
        tone(buzzer, melody3[thisNote], duration);
        delay(3000); // Wait for 3 seconds between notes
      }
    }
  }
  // After all notes in the melody are played, it restarts after 1.25 seconds.
  delay(4000);
}

