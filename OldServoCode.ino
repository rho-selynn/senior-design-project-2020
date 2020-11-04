/* Machine Vision Controlled Servo
 *  by Roselynn Conrady
 *  modified 13 April 2020
 *  
 *  Utilizing serial communication to use Keyence machine
 *  vision camera to move a servo based on the reported
 *  quality of marker bands
 * 
 */

#include <Servo.h>

int incomingData; // incoming serial data
int failPos = 0; // variable to store quality fail servo position
int passPos = 180; // variable to store quality passing servo position
Servo myservo; //create servo object to control a servo

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //opens serial port, sets data rate to 9600 bps
  myservo.attach(9); // attaches the servo on pin 9 to the servo object
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    incomingData = Serial.read(); // read incoming data
    if (incomingData == 1) {
      myservo.write(passPos);//tell servo to go to passing servo position
      delay(15); //waits 15ms for the servo to reach the position
    }
    else {
      myservo.write(failPos); //tell servo to go to quality fail servo position 
      delay(15); //waits 15ms for the servo to reach the position
    }
  }
}
