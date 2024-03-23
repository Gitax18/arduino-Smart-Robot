
#include "AFMotor.h"

#define echoPin A5
#define trigPin A4

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void forward(void);
void backward(void);
void setSpeed(int spd);
void left(void);
void right(void);
void release(void);

/*
setSpeed(<speed>); -> set speed of the motor, takes values between 0-255
run(<dir>); starts the motor takes three parameters
  - FORWARD: makes motor run forward
  - BACKWARD: makes motor run reverse
  - RELEASE: stop the motor motion
*/


void setup() {
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 58.2;

  if (distance >= 10 || distance <= 0){
    forward();
  }
  else {
    release();
    left();
    delay(1000);
    release();
  }
}

void forward(void){
  setSpeed(255);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

void backward(void){
  setSpeed(255);

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}

void left(void){
  setSpeed(100);

  motor1.run(BACKWARD);
  motor2.run(FORWARD);
}

void right(void){
  setSpeed(100);

  motor1.run(FORWARD);
  motor2.run(BACKWARD);
}

void release(void){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  delay(100);
}

void setSpeed(int spd){
  motor1.setSpeed(spd);
  motor2.setSpeed(spd);
}



