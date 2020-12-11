/* Testing Servo motor with Pixy2 camera
 *  by Roselynn Conrady, Theresa Escolano, and Tony Nguyen
 *  Special shoutout to Abigail Dabu, Raven Tomas, and Christopher Rico Rodriguez
 *  11 Nov 2020
 */
#include <Servo.h>
#include <Pixy2.h>

Servo myservo; // create servo object
int posPink = 60; // variable to store the servo position
int posBlue = 0;
Pixy2 pixy; 

void setup() {
  // put your setup code here, to run once:
  myservo.attach(10); // attaches the servo on pion 9 to the servo object
  Serial.begin(115200);
  pixy.init(); // initializes Pixy2
}

void loop() {
  // put your main code here, to run repeatedly:
  pixy.ccc.getBlocks(); // grabs Pixy blocks

  // accessing "m_signature" variable from Pixy2.h
  if (pixy.ccc.blocks->m_signature == 2) // pink marker bands
  { 
    //delay(1000);  
    myservo.write(posPink); // moves servo 60 degrees
   //delay(1300); // uncomment if you're using continous stepper motor movement
  }
  else if(pixy.ccc.blocks->m_signature == 1)// blue marker bands
  {
    //delay(1000);
    myservo.write(posBlue); // moves servo back to pos
  }
}
