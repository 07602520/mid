#include "SevSeg.h"
SevSeg sevseg;
int i=0;
void setup() {
  Serial.begin(9600);
  Serial.println("33 04052520 04050760");
   byte numDigits = 4;
  byte digitPins[] = {5,4, 3, 2};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins,segmentPins);
  
}
void loop() {
  int i;
  if(Serial.available())
  {
      i=Serial.parseInt();
      if(i<=9999 && i>0)
       {
          Serial.println(i);
          sevseg.setNumber(i);
          sevseg.refreshDisplay();
        }
      else
        {
          Serial.println("range error");
        }
  }
    else
      {
  sevseg.refreshDisplay();
  
  }
}

