/**
 * \par Copyright (C), 2012-2016, MakeBlock
 * @file    UltrasonicSensorTest.ino
 * @author  MakeBlock
 * @version V1.0.0
 * @date    2015/09/01
 * @brief   Description: this file is sample code for Me ultrasonic sensor module.
 *
 * Function List:
 * 1. double MeUltrasonicSensor::distanceCm(uint16_t MAXcm)
 *
 * \par History:
 * <pre>
 * <Author>     <Time>        <Version>      <Descr>
 * Mark Yan     2015/09/01    1.0.0          rebuild the old lib
 * </pre>
 */
#include "MeOrion.h"
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

MeUltrasonicSensor ultraSensor(PORT_4); /* Ultrasonic module can ONLY be connected to port 3, 4, 6, 7, 8 of base shield. */
MeEncoderMotor encoder_2_1(0x09,1);
MeEncoderMotor encoder_2_2(0x09,2);
MeLineFollower lineFinder(PORT_6); /* Line Finder module can only be connected to PORT_3, PORT_4, PORT_5, PORT_6 of base shield. */


MeDCMotor Hand(M2);
int HandSpeed = 250;

int distance;
int rightError;
int leftError;
int preSensorState = S1_IN_S2_IN;
int clean = 1; // TRUE
int Ldetector=0;
int Rdetector=0;

void setup()
{
  Serial.begin(9600);
  encoder_2_1.begin();
  encoder_2_1.runSpeed(0);

  encoder_2_2.begin();
  encoder_2_2.runSpeed(0);
}

void runStraight(){
    encoder_2_1.move(50,abs(50)); 
    encoder_2_2.move(50,abs(50)); // DISTANCE + speed
}

void backUp(){
    encoder_2_1.move(5,-30); 
    encoder_2_2.move(5,-30); 
    
}

void turnLeft(){
    encoder_2_1.runSpeed(0);
    encoder_2_2.move(50,abs(50)); 
    
}

void turnRight(){
    encoder_2_1.move(50,abs(50)); // 
    encoder_2_2.runSpeed(0);
    
}


void motorPIDcontrol(){
//  int lerror = Ldetector * 50;
//  int rerror = Rdetector * 50;
//  Serial.print("lerror : ");
//  Serial.print(lerror);
//  Serial.print("rerror : ");
//  Serial.print(rerror);
//  encoder_2_1.move(50,abs(50 + lerror)); 
//  encoder_2_2.move(50,abs(50 + rerror)); // DISTANCE + speed
//  encoder_2_1.runSpeed(0);
  encoder_2_1.move(50,abs(10)); 
  encoder_2_2.move(50,abs(1000)); 
  
}

void calculatePID()
{
  int sensorState = lineFinder.readSensors();
  switch(sensorState)
  {
    case S1_IN_S2_IN: {
      Serial.println("Sensor 1 and 2 are inside of black line");  
      if(Ldetector!=0){Ldetector=0;}
      if(Rdetector!=0){Rdetector=0;}
      break;
    }
    case S1_IN_S2_OUT: {
      Serial.println("Sensor 2 is outside of black line"); 
      if(Ldetector!=0){Ldetector=0;}
      Rdetector+=1;
//      delay(50);
      break;
    }
    case S1_OUT_S2_IN: {
      Serial.println("Sensor 1 is outside of black line");
      if(Rdetector!=0){Rdetector=0;}
      Ldetector+=1;
//      delay(50);
      break;
    }
    case S1_OUT_S2_OUT: {
      Serial.println("Sensor 1 and 2 are outside of black line");
     if(Ldetector!=0) Ldetector+=1;
     if(Rdetector!=0) Rdetector+=1;
     if(Ldetector==0&&Rdetector==0){backUp();}
//      delay(50);
      break;
    }  
    default: break;
  }  
}
  
  //int currSensorState = lineFinder.readSensors();
  
 // if (clean){
 //   int preSensorState = currSensorState;
 // } else{
    
 // }
  
  
  
//}


void loop()
{
  Serial.print("Distance : ");
  Serial.print(ultraSensor.distanceCm() );
  calculatePID();
  motorPIDcontrol();
  Serial.print("Ldetector : ");
  Serial.print(Ldetector);
  Serial.print("Rdetector : ");
  Serial.print(Rdetector);


   
//  encoder_2_1.move(100,abs(100)); // SPEED + DISTANCE
//  encoder_2_1.runTurns(5,100);
//  
//  distance = ultraSensor.distanceCm();
//  
//  if(distance < 10){
//    Serial.print("move ");
//    encoder_2_1.move(1000,abs(100));
//    Hand.run(250);
//    Hand.run(-HandSpeed); // hand close
//    
//  }
  
//  delay(2000); /* the minimal measure interval is 100 milliseconds */
//  Hand.run(-250); // hand open
//  Hand.run(0);
}
