/*
  Stepper Motor Demonstration 4
  Stepper-Demo4.ino
  Demonstrates NEMA 17 Bipolar Stepper with A4988 Driver

  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/

// Define Constants
// Setting up Servo motor
#include <Servo.h>

Servo myservo; // create servo object to control a servo
int pos = 0;    // variable to store the servo position

// Connections to A4988
const int dirPin = 2;  // Direction
const int stepPin = 3; // Step

// Motor steps per rotation
const int STEPS_PER_REV = 200;
 
void setup() {
  //
 myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  
  // Setup the pins as Outputs for Stepper motor
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}
void loop() {
  //Putting some Servo motor code here for now
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  // Set Stepper motor direction clockwise
  digitalWrite(dirPin,HIGH); 
  
  // Spin Stepper motor one rotation slowly
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(2000); 
  }
  
  // Pause for one second
  delay(1000); 
  
  // Set Stepper motor direction counterclockwise
  digitalWrite(dirPin,LOW);
  
/*  // Spin motor two rotations quickly
  for(int x = 0; x < (STEPS_PER_REV * 2); x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(1000);
  }
 */
  // Pause for one second
  delay(1000);
}
