#include "SR04.h"

#define echoPin 8
#define trigPin 9

int redPin = 2;
int greenPin = 3;
int bluePin = 4;
int buttonPin = 7;

int preScan = 0;
long randNumber;
long dis;
SR04 sr04 = SR04(echoPin,trigPin);

void setup()
{
//Serial.begin(9600);
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);
pinMode(buttonPin, INPUT_PULLUP); 
}

void loop()
{
  preScan = 0;
  dis=sr04.Distance();
  Serial.print(dis);
  Serial.println("cm");
  if (dis <= 20) { 
    preScan = 1;
  }
  if (digitalRead(buttonPin) == LOW){
    randNumber = random(1,150000);
    if (randNumber <= 1500 || preScan == 1) {
      setColor(255, 0, 0);
    }
    else if (randNumber <= 10000+1500) {
      setColor(255, 255, 0);
    }
    else if (randNumber <= 20000+10000+1500) {
      setColor(0, 0, 255);
    }
    else if (randNumber <= 40000+20000+10000+1500) {
      setColor(0, 255, 0);
    }
    else {
      setColor(255, 255, 255);
    }
    delay(5000);
    setColor(0, 0, 0);
  }
}

void setColor(int RED, int GREEN, int BLUE)
{
  analogWrite(redPin, RED);
  analogWrite(greenPin, GREEN);
  analogWrite(bluePin, BLUE);  
}
