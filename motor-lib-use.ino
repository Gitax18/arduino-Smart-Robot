
#include "AFMotor.h"

#define SPD 255

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

/*
setSpeed(<speed>); -> set speed of the motor, takes values between 0-255
run(<dir>); starts the motor takes three parameters
  - FORWARD: makes motor run forward
  - BACKWARD: makes motor run reverse
  - RELEASE: stop the motor motion
*/


void setup() {
  // put your setup code here, to run once:


}

void loop() {
  // put your main code here, to run repeatedly:
  motor1.setSpeed(SPD);
  motor2.setSpeed(SPD);
  motor3.setSpeed(SPD);
  motor4.setSpeed(SPD);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
