# Self Driving Car 

This is an Arduino based working model of self driving car. Right now the second phase of this robot is completed and it is working properly, it can avoid objects and takes turns and move completely by self.
The development of third phase is under development and soon we will be able to avoid edges to prevent robot from falling.

## Working 
The main heart of this robot car is arduino UNO microcontroller board. It also contains l293d motor driver shield which helps the car to move properly, and to avoid obstacle I am using Ultrasonic sound sensor, and in next phase I will implement infrared sensor to avoid edges.
**Step by Step Working of the robot(PHASE 2)**
1. Power on
2. Read the distance data from ultrasonic sensor.
3. If distance is not less than 15 cm, move forward.
4. if distance is less than equal to 15 cm, move backward and then left.
5. back to point 2.

**Circuit Schematics will be uploaded soon.**