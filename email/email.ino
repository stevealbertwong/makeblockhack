#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeOrion.h>

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
MeUltrasonicSensor ultrasonic_3(3);
int RxPin[]={0,0,13,2,0,A3};
int TxPin[]={0,0,12,8,1,A2};
SoftwareSerial mySerial(RxPin[4-1],TxPin[4-1]);
char iftttGetString[256];
int len=0;



void setup(){
    
}

void loop(){
    
    if((ultrasonic_3.distanceCm()) < (10)){
        mySerial.begin(9600);
        mySerial.println(F("AT+CWMODE=1"));
        delay(1000);
        mySerial.println("AT+CWJAP=\""+(String)"aaa"+"\"+\""+(String)11111111+"\"");
        delay(10000);
        sprintf(iftttGetString, "GET https://maker.ifttt.com/trigger/%s/with/key/%s","ABC","GXWQyKudcGxxnaHi8MIBA");
        mySerial.println(F("AT+CIPSTART=\"TCP\",\"maker.ifttt.com\",80"));
        delay(5000);
        len = strlen(iftttGetString)+2;
        mySerial.println("AT+CIPSEND="+(String)len);
        delay(3000);
        mySerial.println(iftttGetString);
        delay(5000);
        mySerial.println(F("AT+CIPCLOSE"));
    }
    
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    
}

