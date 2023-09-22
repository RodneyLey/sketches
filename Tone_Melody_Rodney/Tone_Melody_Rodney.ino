/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
*/

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_G3, NOTE_G3, NOTE_G3, NOTE_C4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_G4, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_FS4, NOTE_GS4, NOTE_D4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4, 8, 8
};
// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status
void setup() {
  // initialize the SPEAKER pin as an output:
  pinMode(8, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(2, INPUT);
}

 void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(2);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn SPEAKER on:
    for (int thisNote = 0; thisNote < 8; thisNote++) {
    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
    }
  } 
  else {
    // turn SPEAKER off:
    digitalWrite(8, LOW);
  }
  
}
