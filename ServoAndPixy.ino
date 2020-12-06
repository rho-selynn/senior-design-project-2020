/* Testing Servo motor with Pixy2 camera
 *  by Roselynn Conrady and Tony Lehuy Nguyen
 *  Special shoutout to Abigail Dabu, Raven Tomas, and Christopher Rico Rodriguez
 *  11 Nov 2020
 */
#include <Servo.h>
#include <Pixy2.h>

//#define txPin 13 // tried to transmit to another Arduino via a wired connection, didn't work

Servo myservo; // create servo object
int pos = 0; // variable to store the servo position
Pixy2 pixy; 
int state = LOW;

void setup() {
  //pinMode(txPin, OUTPUT);
  // put your setup code here, to run once:
  myservo.attach(9); // attaches the servo on pion 9 to the servo object
  Serial.begin(115200);
  Serial.print("Starting...\n");
  
  pixy.init(); // initializes Pixy2
}

void loop() {
  // put your main code here, to run repeatedly:
  pixy.ccc.getBlocks(); // grabs Pixy blocks

  // accessing "m_signature" variable from Pixy2.h
  if (pixy.ccc.blocks->m_signature == 2) // pink marker bands
  { 
    //delay(1000);  
    myservo.write(60); // moves servo 60 degrees
   //delay(1300); // uncomment if you're using continous stepper motor movement
   delay(1000);
  }
  else if(pixy.ccc.blocks->m_signature == 1)// blue marker bands
  {
    //delay(1000);
    myservo.write(pos); // moves servo back to pos
    delay(1000);
  }
}
