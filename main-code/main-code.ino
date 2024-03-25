
#include "AFMotor.h"

#define echoPin A5
#define trigPin A4
#define IR1 A3
#define IR2 A2
#define IR3 9
#define IR4 10

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void forward(void);
void backward(void);
void setSpeed(int spd);
void left(void);
void right(void);
void release(void);
void checkForwardEdge(int ir1, int ir2);
void checkBackwardEdge(int ir3, int ir4);


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
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

  // Check edge from front
  checkForwardEdge(IR1,IR2);
  checkBackwardEdge(IR3,IR4);

  // Motor control code
  if (distance >= 10 || distance <= 0){
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

void checkForwardEdge(int ir1, int ir2){
  if(digitalRead(ir1) == HIGH || digitalRead(ir2) == HIGH){
    Serial.println("EDGE FORWARD");
    backward();
    delay(500);
    release();
    right();
    delay(500);
  }

}

void checkBackwardEdge(int ir3, int ir4){
  if(digitalRead(ir3) == HIGH || digitalRead(ir4) == HIGH){
    Serial.println("EDGE BACKWARD");
    forward();
    delay(500);
    release();
    right();
    delay(500);
  }
}
