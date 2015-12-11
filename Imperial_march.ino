/*
Imperial march from Star Wars
  
Circuit:
 * Speaker (+) on digital pin 8 (p2.0 on msp430 launchpad)
 * (-) on GND (ground) pin
 
Personally I used a speaker from an old Motorola gsm
 
Created on 11 December 2015
 
Credits:
 Agostino Pellegrino - agopel@gmail.com
 Based on "Melody" code by Tom Igoe (from Arduino examples - https://www.arduino.cc/en/Tutorial/toneMelody)


Feel free to use or modify this code quoting authors

--------------------------------------------------
SOS - La Scuola Open Source 
Open Source School
--------------------------------------------------
Join us:
Web: www.lascuolaopensource.xyz
FB: http://www.facebook.com/scuolaopensource/
TW: http://twitter.com/lascuolaos
eMail: info@lascuolaopensource.xyz
--------------------------------------------------
 */

 #include "pitches.h"
 #define LED RED_LED
 
// notes in the melody:
int melody[] = {
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4, 0,
  NOTE_E5, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_C5, NOTE_GS4, NOTE_F4, NOTE_C5, NOTE_A4, 0,
  NOTE_A5, NOTE_A4, NOTE_A4, NOTE_A5, NOTE_GS5, NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_FS5, 0, 
  NOTE_AS4, NOTE_DS5, NOTE_D5, NOTE_CS5, NOTE_C5, NOTE_B4, NOTE_C5, 0,
  NOTE_F4, NOTE_GS4, NOTE_F4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_E5, 
  NOTE_A5, NOTE_A4, NOTE_A4, NOTE_A5, NOTE_GS5, NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_FS5, 0, 
  NOTE_AS4, NOTE_DS5, NOTE_D5, NOTE_CS5, NOTE_C5, NOTE_B4, NOTE_C5, 0,
  NOTE_F4, NOTE_GS4, NOTE_F4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_E5
  
  };

//notes duration in ms (milliseconds)
int noteDurations[] = {
  500, 500, 500, 350, 150, 500, 350, 150, 650, 150, 
  500, 500, 500, 350, 150, 500, 350, 150, 650, 150, 
  500, 300, 150, 400, 200, 200, 125, 125, 250, 250,
  250, 400, 200, 200, 125, 130, 250, 250,
  125, 500, 375, 125, 500, 375, 125, 650,
  500, 300, 150, 400, 200, 200, 125, 125, 250, 250,
  250, 400, 200, 200, 125, 130, 250, 250,
  125, 500, 375, 125, 500, 375, 125, 650 };

void setup() {
  //inizialize led output
  pinMode(LED, OUTPUT);
  
  // iterate over the notes of the melody
  for (int thisNote = 0; thisNote < 72; thisNote++) {
    //turn led ON
    digitalWrite(LED, HIGH);
    
    tone(8, melody[thisNote],noteDurations[thisNote]);
    
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDurations[thisNote] * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
    //turn led OFF
    digitalWrite(LED, LOW);  
  }
}

void loop() {
  //put some code here if you want to repat the melody
}
