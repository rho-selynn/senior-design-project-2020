/* Marker Band Sorter
 *  December 5, 2020
 *  by Roselynn Conrady and Tony Nguyen
 *  San Diego State University - Department of Mechanical Engineering
 *  Senior Design Project
 *  
 *  
 *  The purpose of this code is to operate 2 servo motors, 1 bipolar stepper motor, and a Pixy2 camera
 *  cellphone vibrator needs to be at 4.22V
 */

#include <Servo.h>
#include <Pixy2.h>

#define dirPin 2
#define stepPin 3
// 1 full rotation is 1600 steps for the NEMA 23 stepper motor
// 1050 for the original sorter
#define stepsPerRevolution 529 

Servo feederServo;
Servo sorterServo;
Pixy2 pixy;
int prevMarkerBand;
//int pinkMarkerBand = pixy.ccc.blocks->m_signature == 2;
//int blueMarkerBand = pixy.ccc.blocks->m_signature == 1;
int posBlue = 0;
int posPink = 60;

void setup() {
  // attaching the servo objects to pin 9 and 10
  feederServo.attach(9);
  sorterServo.attach(10);
  Serial.begin(115200);
  Serial.println("Starting...\n");
  // declare pins as outputs for the stepper motor
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  // initialize pixy object
  pixy.init();
  
}
void loop() {
  delay(600); // to pause 600ms under the camera
  feedMarkerBand();
  delay(1100);
  turnOnStepperMotor();
  /*pixy.ccc.getBlocks(); // grabs Pixy blocks
  //accessing "m_signature" variable from Pixy2.h
  if (pixy.ccc.blocks->m_signature == 2){
   sorterServo.write(posPink); // moves servo 60 degrees 
  }
  else if (pixy.ccc.blocks->m_signature == 1){
    sorterServo.write(posBlue); // moves servo back to pos
  }
  */

}

void feedMarkerBand(){
  // mid size marker bands
  /*feederServo.write(30);
  delay(100);
  feederServo.write(72);
    delay(100);
*/
// larger size marker bands
 feederServo.write(30);
 delay(100);
 feederServo.write(90);
 delay(100);

}

void turnOnStepperMotor(){
  // set the spinning direction clockwise
  digitalWrite(dirPin, HIGH);
  // spin the motor
  // need to figure out how many steps
  for (int i = 0; i < stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);
  }
}
