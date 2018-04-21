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

//MeDCMotor Holder(M1);
MeEncoderMotor encoder_1_1(0x09,1);
MeDCMotor Hand(M2);
int HandSpeed = 250;
int HolderSpeed = 250;

int distance;
int pickedUp = 1;


void runStraight(){
    encoder_2_1.move(50,abs(50)); 
    encoder_2_2.move(50,abs(50)); // DISTANCE + speed
    
}

void backUp(){
    encoder_2_1.move(10,-30); 
    encoder_2_2.move(10,-30); 
    
}

void turnLeft(){
//    encoder_2_1.runSpeed(0);
    encoder_2_1.move(50,-100); 
    encoder_2_2.move(50,abs(100)); 
    
}

void turnRight(){
    encoder_2_1.move(50,abs(100)); // 
//    encoder_2_2.runSpeed(0);
    encoder_2_2.move(50,-100); 
    
}

void Holder_up()
{
  encoder_1_1.move(150,-100); 

  
}
void Holder_down()
{
  encoder_1_1.move(250,200); 

}

void Holder_stop(){
  encoder_1_1.runSpeed(0);
}

void Hand_close()
{
  Hand.run(-HandSpeed);

}
void Hand_open()
{
  Hand.run(HandSpeed);

}

void Hand_stop(){
  Hand.run(0);
}


void setup()
{
  Serial.begin(9600);
  encoder_1_1.begin();
  encoder_1_1.runSpeed(0);
  
  encoder_2_1.begin();
  encoder_2_1.runSpeed(0);

  encoder_2_2.begin();
  encoder_2_2.runSpeed(0);
}


void loop()
{
//  Serial.print("Distance : ");
//  Serial.print(ultraSensor.distanceCm() );
//  
//  distance = ultraSensor.distanceCm();
//  if(distance < 17){
//    delay(2000);
//    Holder_down();
//    delay(4000);
//      
//    Holder_stop();
//    
//    Hand_close();
//    delay(2000);
////    Hand_open();
////    delay(1000);
////    Hand_stop();
////    delay(1000);
//    Holder_up();
//
//    delay(5000);
////    Holder_stop();
//
//    pickedUp = 1;          
//  }

    delay(5000);
    Holder_down();
    delay(2000);
      
    Holder_stop();
    
//    Hand_close();
    delay(2000);
    Hand_open();
//    delay(1000);
//    Hand_stop();
//    delay(1000);
//    Holder_up();

    delay(1000);
//    Holder_stop();
  


//    runStraight();
//
//    int sensorState = lineFinder.readSensors();
//    switch(sensorState)
//    {
//      case S1_IN_S2_IN: {
//        Serial.println("Sensor 1 and 2 are inside of black line"); 
//        runStraight(); 
//        
//        break;
//      }
//      case S1_IN_S2_OUT: {
//        Serial.println("Sensor 2 is outside of black line"); 
//        
//        turnRight();
//        delay(50);
//        break;
//      }
//      case S1_OUT_S2_IN: {
//        Serial.println("Sensor 1 is outside of black line");
//        turnLeft();
//        delay(50);
//        break;
//      }
//      case S1_OUT_S2_OUT: {
//        Serial.println("Sensor 1 and 2 are outside of black line");
//        backUp();
//        delay(50);
//        break;
//      }
//      default: break;
//    }    
//    
}

