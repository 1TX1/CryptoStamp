/*
 * Components:
 * (1)  Arduino (in my case: Elegoo Mega2560 R3)
 * (1)  RGB LED
 * (1)  Push Button
 * (1)  Ultrasonic Sensor Module
 * (3)  220 Ohm Resistor
 * (12) Wires
 */

#include "SR04.h"

#define echoPin 8
#define trigPin 9

int redPin = 2;
int greenPin = 3;
int bluePin = 4;
int buttonPin = 7;

int ledOnDelay = 0;
int preScan = 0;
long randNumber;
long distance;
SR04 sr04 = SR04(echoPin,trigPin);

void setup()
{
Serial.begin(9600);
randomSeed(analogRead(0));
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);
pinMode(buttonPin, INPUT_PULLUP); 
}

void loop()
{
  preScan = 0;
  distance=sr04.Distance();
  Serial.print(distance);
  Serial.println("cm");
  if (distance <= 20) { 
    preScan = 1;
  }
  if (digitalRead(buttonPin) == LOW){
    randNumber = random(150000);
    Serial.print(randNumber);
    Serial.print('\n');
    if (randNumber < 1500 || preScan == 1) {
      setColor(255, 0, 0);
      ledOnDelay = 3000;
    }
    else if (randNumber < 10000+1500) {
      setColor(255, 255, 0);
      ledOnDelay = 2500;
    }
    else if (randNumber < 20000+10000+1500) {
      setColor(0, 0, 255);
      ledOnDelay = 2000;
    }
    else if (randNumber < 40000+20000+10000+1500) {
      setColor(0, 255, 0);
      ledOnDelay = 1500;
    }
    else {
      setColor(255, 255, 255);
      ledOnDelay = 1000;
    }
    delay(ledOnDelay);
    setColor(0, 0, 0);
  }
}

void setColor(int RED, int GREEN, int BLUE)
{
  analogWrite(redPin, RED);
  analogWrite(greenPin, GREEN);
  analogWrite(bluePin, BLUE);  
}
