#include <Time.h>

int pinElectrovalvula = 7;
time_t t;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  setTime(11,07,00,24,8,2017);
  pinMode(pinElectrovalvula,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  t = now();
  reloj();
  
  // 
  if (hour(t)==19 && minute(t)==0) {
    digitalWrite(pinElectrovalvula,0);//0 ==> Regando
    Serial.print("Regando...");
    delay(1200000);
  }else{
    digitalWrite(pinElectrovalvula,1);//1 ==> No Regando
    }
  //
  
}


void reloj(){
  t = now();
  Serial.print(hour(t));
  Serial.print(":");
  Serial.print(minute(t));
  Serial.print(":");
  Serial.print(second(t));
  Serial.print("");
  Serial.print("==>> No regando...");
  Serial.println();
  delay(1000);



  
}

