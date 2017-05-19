#include <SoftwareSerial.h>
#include <Servo.h>

#define echoPinFront 13 // Echo Pin of the sensor in the front
#define trigPinFront 12 // Trigger Pin of the sensor in the front
#define echoPinSide 4 // Echo Pin of the sensor on the right
#define trigPinSide 7 // Trigger Pin of the sensor on the right

#define ENA 11
#define IN1 10
#define IN2 9
#define ENB 3
#define IN3 6
#define IN4 5

int maximumRange_front = 15;// Maximum range in the front needed
int maximumRange_right = 5;// Maximum range on the right needed
long duration, distance_front, distance_right; 

long get_distance_front(){ //Function used to measure the distance in the front
 long duration;
 long distance_front;
 
 digitalWrite(trigPinFront, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPinFront, HIGH); //Emitting soundwave
 delayMicroseconds(10); 
 
 digitalWrite(trigPinFront, LOW);
 duration = pulseIn(echoPinFront, HIGH); //Receiving soundwave
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance_front = duration/58.2;

 return distance_front;
}

long get_distance_right(){ //Function used to measure the distance on the right
 long duration;
 long distance_right;
 
 digitalWrite(trigPinSide, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPinSide, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPinSide, LOW);
 duration = pulseIn(echoPinSide, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance_right = duration/58.2;

 return distance_right;
}

void setup() {
 Serial.begin (9600);
 pinMode(trigPinFront, OUTPUT);
 pinMode(echoPinFront, INPUT);
 pinMode(trigPinSide, OUTPUT);
 pinMode(echoPinSide, INPUT);
 pinMode(ENA, OUTPUT); //PWM
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(ENB, OUTPUT); //PWM
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
}

void loop() {
 distance_front = get_distance_front();
 distance_right = get_distance_right();
    analogWrite(ENA, 250);
    analogWrite(ENB, 250); 
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
 if(distance_front >= maximumRange_front){ 
    analogWrite(ENA, 250);
    analogWrite(ENB, 250); 
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
 }else if(distance_front < maximumRange_front && distance_right >= maximumRange_right){ 
    analogWrite(ENA, 200);
    analogWrite(ENB, 250); 
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3 , HIGH);
    digitalWrite(IN4, LOW);
 }else if(distance_front < maximumRange_front && distance_right < maximumRange_right){
    analogWrite(ENA, 200);
    analogWrite(ENB, 250); 
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH); 
 }
 delay(5); //Delay 5 ms before the next loop
}
