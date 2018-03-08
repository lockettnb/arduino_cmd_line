/*
  Blink
  Turns on an LED on/off 
 
 */
#include "Arduino.h"

void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards
  pinMode(13, OUTPUT);     
}

void loop() {
  int i;

  // slow blink
  digitalWrite(13, HIGH);   // set the LED on
  delay(2500);              // wait for a second
  digitalWrite(13, LOW);    // set the LED off
  delay(2500);              // wait for a second

  // fast blink
  for(i=0; i<=75; i++){
    digitalWrite(13, HIGH);   // set the LED on
    delay(100);              // wait for a second
    digitalWrite(13, LOW);    // set the LED off
    delay(100);              // wait for a second
  }

  // relax and pause
  digitalWrite(13, LOW);    // set the LED off
  delay(1000);      
}


int main() {
   init();
   setup();
   while(1)
      loop();
}



