# Self Driving Car

This is an Arduino based working model of self driving car.It can avoid objects from front and sides and can takes turns and move completely by self.

[Link to video demo](https://www.icloud.com/photos/#037dqVS932bm7bPKgmomV9PSQ)

## Working

The main heart of this robot car is arduino UNO microcontroller board. It also contains l293d motor driver shield which helps the car to move properly, and to avoid obstacle I am using Ultrasonic sound sensor, and infrared sensor to avoid side collison.
**Step by Step Working of the robot**

1. Power on.
2. Read the distance data from ultrasonic sensor.
3. If distance is not less than 10 cm, and no obstacle on any side then move forward.
4. If distance is not less than 10 cm, but obstacle is on any side then turn oppsite side.
5. if distance is less than equal to 10 cm, move backward and then left.
6. back to point 2.

## Circuit

Pin Connections:

-  **UltraSonic Sensor**
    - Trigger Pin: A4
    - Echo Pin: A5

- **Infrared Sensors**
    - Left side sensor: A2
    - Right side sensor: A3

- **L293d Motor driver shield**
    - Motors are connected to M1 and M2 pins.

**Circuit Schematics will be uploaded soon.**
