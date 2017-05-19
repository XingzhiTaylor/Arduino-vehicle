#include <SoftwareSerial.h>

#define ENA 11
#define IN1 9
#define IN2 10
#define ENB 3
#define IN3 5
#define IN4 6

char getstr;
void setup()
{
  Serial.begin(9600);
  pinMode(IN1,OUTPUT); 
  pinMode(IN2,OUTPUT); 
  pinMode(IN3,OUTPUT); 
  pinMode(IN4,OUTPUT);
}
void loop()
{
  getstr=Serial.read();
  if(getstr=='2')
  {
    //Forward
    analogWrite(ENA, 250);
    analogWrite(ENB, 250);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }else if(getstr=='4'){
    //Leftward
    analogWrite(ENA, 100);
    analogWrite(ENB, 100);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }else if(getstr=='6'){
    //Rightward
    analogWrite(ENA, 100);
    analogWrite(ENB, 100);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }else if(getstr=='8'){
    //Backward
    analogWrite(ENA, 250);
    analogWrite(ENB, 250);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }else{
    //Stop
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
  }
}
