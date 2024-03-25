
#include "AFMotor.h"

#define echoPin A5
#define trigPin A4
#define IRRight A3
#define IRLeft A2


AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void forward(void);
void backward(void);
void setSpeed(int spd);
void left(void);
void right(void);
void release(void);

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(IRLeft, INPUT);
  pinMode(IRRight, INPUT);
}

void loop() {
  // Read Distance from front
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 58.2;

    
  // Motor control code
  if (distance >= 10 || distance <= 0){
    if(digitalRead(IRLeft) == LOW){
      // release();
      // delay(500);
      right();
      delay(500);
    }
    else if(digitalRead(IRRight) == LOW){
      left();
      delay(500);
    }
    forward();
  }
  else {
    backward();
    delay(500);
    release();
    left();
    delay(500);
  }
}


// *********** FUNCTIONS **********
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
}

void setSpeed(int spd){
  motor1.setSpeed(spd);
  motor2.setSpeed(spd);
}
