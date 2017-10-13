#include <Wire.h>
#include "RTClib.h"

int pinElectrovalvula = 7;
char daysOfTheWeek[7][12] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};


// RTC_DS1307 rtc;
RTC_DS3231 rtc;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  delay(1000);
  pinMode(pinElectrovalvula,OUTPUT);

 
   if (!rtc.begin()) {
      Serial.println(F("Couldn't find RTC"));
      while (1);
   }
 
   if (rtc.lostPower()) {
      rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
   }
}

void loop() {
  // put your main code here, to run repeatedly:
  DateTime now = rtc.now();
  reloj();
  
  // ---------------------------------
  if (now.hour()==17 && now.minute()==0) {
    digitalWrite(pinElectrovalvula,0);//0 ==> Regando
    Serial.print("Regando...");
    delay(600000);
  }else{
    digitalWrite(pinElectrovalvula,1);//1 ==> No Regando
    }
  //----------------------------------
  
}


void reloj(){
  DateTime now = rtc.now();
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    
  Serial.print("==>> No regando...");
  Serial.println();
  delay(1000);



  
}

