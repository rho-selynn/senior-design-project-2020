/* Testing Servo motor with Pixy2 camera
 *  by Roselynn Conrady and Tony Lehuy Nguyen
 *  Special shoutout to Abigail Dabu, Raven Tomas, and Christopher Rico Rodriguez
 *  11 Nov 2020
 */
#include <Servo.h>
#include <Pixy2.h>

Servo myservo; // create servo object
int pos = 0; // variable to store the servo position
Pixy2 pixy;

void setup() {
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
  if (pixy.ccc.blocks->m_signature == 4)
  {
    myservo.write(90); // moves servo 90 degrees
  }
  else
  {
    myservo.write(pos); // moves servo back to pos
  }
}
