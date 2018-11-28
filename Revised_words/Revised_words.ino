#include <SparkFun_ADXL345.h>
#include "Keyboard.h"
ADXL345 adxl = ADXL345();
int interruptPin = 8;  
unsigned long currentTime, previousTime = 0;

float sensorValues[8];
const int pinkeyPin = A4; 
const int ringPin = A3;
const int middlePin = A2;
const int indexPin = A1;
const int thumbPin = A0;

const float voltage = 4.98; 
const float resistance = 47500.0;


int fingerADC[5]; 
float fingerV1R1 [5][2];

void setup() {
  Keyboard.begin(); 
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Sign Language Glove by Aswin Visva and Sultan Emaish");
  adxl.powerOn(); 
  adxl.setRangeSetting(16);
  adxl.setSpiBit(0);
  adxl.setActivityXYZ(1, 0, 0);       
  adxl.setActivityThreshold(75);     
  adxl.setInactivityXYZ(1, 0, 0);    
  adxl.setInactivityThreshold(75);    
  adxl.setTimeInactivity(10);       
  adxl.setTapDetectionOnXYZ(0, 0, 1); 
  adxl.setTapThreshold(225);         
  adxl.setTapDuration(15);        
  adxl.setDoubleTapLatency(80);  
  adxl.setDoubleTapWindow(200); 
  adxl.setFreeFallThreshold(7);  
  adxl.setFreeFallDuration(30);  
  adxl.InactivityINT(1);
  adxl.ActivityINT(1);
  adxl.FreeFallINT(1);
  adxl.doubleTapINT(1);
  adxl.singleTapINT(1);
  pinMode(pinkeyPin, INPUT);
  pinMode(ringPin, INPUT);
  pinMode(middlePin, INPUT);
  pinMode(indexPin, INPUT);
  pinMode(thumbPin, INPUT);
}

void loop() {
  readSensors();
  if (sensorValues[0]< -55 && sensorValues[0]> -70 && sensorValues[1]> 5 && sensorValues[1]< 25 && sensorValues[2]> 128 && sensorValues[2]< 146 && sensorValues[3] > 100000 && sensorValues[3] < 150000 && sensorValues[4] > 100000 && sensorValues[4] < 150000 && sensorValues[5] > 100000 && sensorValues[5] < 145000 && sensorValues[6] > 130000&& sensorValues[6] < 170000&& sensorValues[7] > 110000 && sensorValues[7] < 140000) {
          previousTime = millis(); 
       Serial.println("'Hello' triggered");
          delay(500);
          while((millis() - previousTime) < 1000) {
            readSensors();
          if (sensorValues[0]< -50 && sensorValues[0]> -70 && sensorValues[1]> -25 && sensorValues[1]< -10 && sensorValues[2]> 135 && sensorValues[2]< 155 && sensorValues[3] > 100000 && sensorValues[3] < 150000 && sensorValues[4] > 100000 && sensorValues[4] < 150000 && sensorValues[5] > 100000 && sensorValues[5] < 145000 && sensorValues[6] > 130000&& sensorValues[6] < 170000&& sensorValues[7] > 110000 && sensorValues[7] < 140000) {
            currentTime = millis();
            
            
            Keyboard.print("Hello"); 
            Keyboard.press(0xB0);
            Keyboard.releaseAll();
            delay(1500);
            for(int i = 0; i < 5; i++) {
                Keyboard.press(0xB2);
                Keyboard.releaseAll();
            }
            break;
            
          }
          }
       }
       
if (sensorValues[0]< -35 && sensorValues[0]> -55 && sensorValues[1]< -30 && sensorValues[1]> -50 && sensorValues[2]> 130 && sensorValues[2]< 150 && sensorValues[3] > 80000 && sensorValues[3] < 120000 && sensorValues[4] > 90000 && sensorValues[4] < 120000 && sensorValues[5] > 100000 && sensorValues[5] < 130000 && sensorValues[6] > 130000 && sensorValues[6] < 160000&& sensorValues[7] > 120000 && sensorValues[7] < 150000) {
        Keyboard.print("My"); 
        Keyboard.press(0xB0);
        Keyboard.releaseAll();
        delay(1500);
        for(int i = 0; i < 10; i++) {
             Keyboard.press(0xB2);
             Keyboard.releaseAll();
            }
       }

       if (sensorValues[0]< -20 && sensorValues[0]> -40 && sensorValues[1]< -30 && sensorValues[1]> -65 && sensorValues[2]> 135 && sensorValues[2]< 160 && sensorValues[3] > 260000 && sensorValues[3] < 300000 && sensorValues[4] > 200000 && sensorValues[4] < 240000 && sensorValues[5] > 90000 && sensorValues[5] < 120000 && sensorValues[6] > 100000&& sensorValues[6] < 130000&& sensorValues[7] > 170000 && sensorValues[7] < 210000) {
          Keyboard.print("Name"); 
        Keyboard.press(0xB0);
        Keyboard.releaseAll();
        delay(1500);
        for(int i = 0; i < 10; i++) {
             Keyboard.press(0xB2);
             Keyboard.releaseAll();
            }
       }

if (sensorValues[0]< -40 && sensorValues[0]> -70 && sensorValues[1]< 10 && sensorValues[1]> -5 && sensorValues[2]> 130 && sensorValues[2]< 160 && sensorValues[3] > 70000 && sensorValues[3] < 220000 && sensorValues[4] > 170000 && sensorValues[4] < 235000 && sensorValues[5] > 200000 && sensorValues[5] < 360000 && sensorValues[6] > 250000&& sensorValues[6] < 297000&& sensorValues[7] > 90000 && sensorValues[7] < 150000) {
          previousTime = millis(); 
       Serial.println("'Is' triggerd");
          delay(500);
          while((millis() - previousTime) < 1000) {
            readSensors();
          if (sensorValues[0]< -40 && sensorValues[0]> -70 && sensorValues[1]< -5 && sensorValues[1]> -35 && sensorValues[2]> 130 && sensorValues[2]< 170 && sensorValues[3] > 70000 && sensorValues[3] < 220000 && sensorValues[4] > 170000 && sensorValues[4] < 235000 && sensorValues[5] > 200000 && sensorValues[5] < 360000 && sensorValues[6] > 250000&& sensorValues[6] < 297000&& sensorValues[7] > 90000 && sensorValues[7] < 150000) {
            currentTime = millis();
            
            
            Keyboard.print("Is or Are"); 
            Keyboard.press(0xB0);
            Keyboard.releaseAll();
            delay(2000);
            for(int i = 0; i < 20; i++) {
                Keyboard.press(0xB2);
                Keyboard.releaseAll();
            }
            break;
            
          }
          }
       }

       if (sensorValues[0]< -20 && sensorValues[0]> -40 && sensorValues[1]< 20 && sensorValues[1]> -10 && sensorValues[2]> 160 && sensorValues[2]< 180 && sensorValues[3] > 70000 && sensorValues[3] < 100000 && sensorValues[4] > 70000 && sensorValues[4] < 100000 && sensorValues[5] > 80000 && sensorValues[5] < 110000 && sensorValues[6] > 250000 && sensorValues[6] < 290000 && sensorValues[7] > 70000 && sensorValues[7] < 110000) {
       Keyboard.print("Aswin"); 
            Keyboard.press(0xB0);
            Keyboard.releaseAll();
            delay(1500);
            for(int i = 0; i < 10; i++) {
                Keyboard.press(0xB2);
                Keyboard.releaseAll();
            }
       }

       if (sensorValues[0]< -20 && sensorValues[0]> -45 && sensorValues[1]< 5 && sensorValues[1]> -20 && sensorValues[2]> 155 && sensorValues[2]< 175 && sensorValues[3] > 70000 && sensorValues[3] < 95000 && sensorValues[4] > 206000 && sensorValues[4] < 250000 && sensorValues[5] > 210000 && sensorValues[5] < 265000 && sensorValues[6] > 260000 && sensorValues[6] < 320000 && sensorValues[7] > 90000 && sensorValues[7] < 130000) {
       Keyboard.print("And"); 
            Keyboard.press(0xB0);
            Keyboard.releaseAll();
            delay(1500);
            for(int i = 0; i < 10; i++) {
                Keyboard.press(0xB2);
                Keyboard.releaseAll();
            }
       }

       if (sensorValues[0]< -45 && sensorValues[0]> -65 && sensorValues[1]< -10 && sensorValues[1]> -45 && sensorValues[2]> 135 && sensorValues[2]< 155 && sensorValues[3] > 280000 && sensorValues[3] < 330000 && sensorValues[4] > 210000 && sensorValues[4] < 248000 && sensorValues[5] > 225000 && sensorValues[5] < 275000 && sensorValues[6] > 90000 && sensorValues[6] < 120000 && sensorValues[7] > 140000 && sensorValues[7] < 175000) {
       Keyboard.print("He or She"); 
            Keyboard.press(0xB0);
            Keyboard.releaseAll();
            delay(2000);
            for(int i = 0; i < 10; i++) {
                Keyboard.press(0xB2);
                Keyboard.releaseAll();
            }
       }

        if (sensorValues[0]< -20 && sensorValues[0]> -45 && sensorValues[1]< 15 && sensorValues[1]> -15 && sensorValues[2]> 160 && sensorValues[2]< 185 && sensorValues[3] > 180000 && sensorValues[3] < 266000 && sensorValues[4] > 160000 && sensorValues[4] < 220000 && sensorValues[5] > 80000 && sensorValues[5] < 110000 && sensorValues[6] > 90000 && sensorValues[6] < 120000&& sensorValues[7] > 70000 && sensorValues[7] < 110000) {
          Keyboard.print("Sultan"); 
            Keyboard.press(0xB0);
            Keyboard.releaseAll();
            delay(1500);
            for(int i = 0; i < 10; i++) {
                Keyboard.press(0xB2);
                Keyboard.releaseAll();
            }
       }
       if (sensorValues[0]< -20 && sensorValues[0]> -45 && sensorValues[1]< -30 && sensorValues[1]> -50 && sensorValues[2]> 135 && sensorValues[2]< 155 && sensorValues[3] > 280000 && sensorValues[3] < 330000 && sensorValues[4] > 210000 && sensorValues[4] < 248000 && sensorValues[5] > 225000 && sensorValues[5] < 275000 && sensorValues[6] > 90000 && sensorValues[6] < 120000 && sensorValues[7] > 140000 && sensorValues[7] < 175000) {
        Keyboard.print("You"); 
            Keyboard.press(0xB0);
            Keyboard.releaseAll();
            delay(1500);
            for(int i = 0; i < 10; i++) {
                Keyboard.press(0xB2);
                Keyboard.releaseAll();
            }
       }
       
 if (sensorValues[0]< -60 && sensorValues[0]> -75 && sensorValues[1]> -10 && sensorValues[1]< 20 && sensorValues[2]> 125 && sensorValues[2]< 145 && sensorValues[3] > 79000 && sensorValues[3] < 115000 && sensorValues[4] > 80000 && sensorValues[4] < 120000 && sensorValues[5] > 90000 && sensorValues[5] < 135000 && sensorValues[6] > 115000 && sensorValues[6] < 145000 && sensorValues[7] > 120000 && sensorValues[7] < 141000) {
          previousTime = millis(); 
Serial.println("'Goodbye' Triggered");
          delay(500);
          while((millis() - previousTime) < 1000) {
            readSensors();
          if (sensorValues[0]< -55 && sensorValues[0]> -75 && sensorValues[1]> -10 && sensorValues[1]< 20 && sensorValues[2]> 125 && sensorValues[2]< 147 && sensorValues[3] > 260000 && sensorValues[3] < 370000 && sensorValues[4] > 220000 && sensorValues[4] < 290000 && sensorValues[5] > 240000 && sensorValues[5] < 300000 && sensorValues[6] > 299000 && sensorValues[6] < 320000 && sensorValues[7] > 100000 && sensorValues[7] < 160000) {
            currentTime = millis();
   
            
            Keyboard.print("Goodbye"); 
            Keyboard.press(0xB0);
            Keyboard.releaseAll();
            delay(1500);
            for(int i = 0; i < 10; i++) {
                Keyboard.press(0xB2);
                Keyboard.releaseAll();
            }
            
          }
          }
       }

       if (sensorValues[0]< -55 && sensorValues[0]> -70 && sensorValues[1]> -5 && sensorValues[1]< 12 && sensorValues[2]> 137 && sensorValues[2]< 160 && sensorValues[3] > 265000 && sensorValues[3] < 310000 && sensorValues[4] > 210000 && sensorValues[4] < 241000 && sensorValues[5] > 200000 && sensorValues[5] < 270000&& sensorValues[6] > 100000 && sensorValues[6] < 120000&& sensorValues[7] > 120000 && sensorValues[7] < 190000) {
          previousTime = millis(); 
Serial.println("'Where' Triggered");
          delay(500);
          while((millis() - previousTime) < 1000) {
            readSensors();
          if (sensorValues[0]< -55 && sensorValues[0]> -75 && sensorValues[1]< -5 && sensorValues[1]> -25 && sensorValues[2]> 137 && sensorValues[2]< 160 && sensorValues[3] > 265000 && sensorValues[3] < 310000 && sensorValues[4] > 210000 && sensorValues[4] < 241000 && sensorValues[5] > 200000 && sensorValues[5] < 270000&& sensorValues[6] > 100000 && sensorValues[6] < 120000&& sensorValues[7] > 120000 && sensorValues[7] < 190000) {
            currentTime = millis();
   
            
             Keyboard.print("Where"); 
            Keyboard.press(0xB0);
            Keyboard.releaseAll();
            delay(1500);
            for(int i = 0; i < 10; i++) {
                Keyboard.press(0xB2);
                Keyboard.releaseAll();
            }
            
          }
          }
       }

       if (sensorValues[0]< -30 && sensorValues[0]> -45 && sensorValues[1]< -20 && sensorValues[1]> -40 && sensorValues[2]> 100 && sensorValues[2]< 130 && sensorValues[3] > 80000 && sensorValues[3] < 130000 && sensorValues[4] > 80000 && sensorValues[4] < 110000 && sensorValues[5] > 80000 && sensorValues[5] < 130000 && sensorValues[6] > 120000&& sensorValues[6] < 150000&& sensorValues[7] > 100000 && sensorValues[7] < 145000) {
          Keyboard.print("What"); 
            Keyboard.press(0xB0);
            Keyboard.releaseAll();
            delay(1500);
            for(int i = 0; i < 10; i++) {
                Keyboard.press(0xB2);
                Keyboard.releaseAll();
            }

       }

       if (sensorValues[0]< -55 && sensorValues[0]> -70 && sensorValues[1]< -3 && sensorValues[1]> -25 && sensorValues[2]> 125 && sensorValues[2]< 145 && sensorValues[3] > 70000 && sensorValues[3] < 105000 && sensorValues[4] > 80000 && sensorValues[4] < 109000  && sensorValues[5] > 80000 && sensorValues[5] < 140000&& sensorValues[6] > 109000 && sensorValues[6] < 135000&& sensorValues[7] > 90000 && sensorValues[7] < 135000) {
          previousTime = millis(); 
Serial.println("'Why' Triggered");
          delay(500);
          while((millis() - previousTime) < 1000) {
            readSensors();
          if (sensorValues[0]< -55 && sensorValues[0]> -70 && sensorValues[1]< -3 && sensorValues[1]> -25 && sensorValues[2]> 125 && sensorValues[2]< 145 && sensorValues[3] > 70000 && sensorValues[3] < 105000   && sensorValues[4] > 80000 && sensorValues[4] < 109000 && sensorValues[5] > 200000 && sensorValues[5] < 240000 && sensorValues[6] > 109000 && sensorValues[6] < 135000&& sensorValues[7] > 90000 && sensorValues[7] < 135000) {
            currentTime = millis();
   
            
            Keyboard.print("Why"); 
            Keyboard.press(0xB0);
            Keyboard.releaseAll();
            delay(1500);
            for(int i = 0; i < 10; i++) {
                Keyboard.press(0xB2);
                Keyboard.releaseAll();
            }
            
          }
          }
       }

       if (sensorValues[0]< -15 && sensorValues[0]> -30 && sensorValues[1]< -22 && sensorValues[1]> -43 && sensorValues[2]> 100 && sensorValues[2]< 120 && sensorValues[3] > 230000 && sensorValues[3] < 290000 && sensorValues[4] > 150000 && sensorValues[4] < 220000 && sensorValues[5] > 180000 && sensorValues[5] < 240000&& sensorValues[6] > 220000 && sensorValues[6] < 296000&& sensorValues[7] > 120000 && sensorValues[7] < 166000) {
          previousTime = millis(); 
Serial.println("'How' Triggered");
          delay(500);
          while((millis() - previousTime) < 1000) {
            readSensors();
          if (sensorValues[0]< -20 && sensorValues[0]> -40 && sensorValues[1]< 12 && sensorValues[1]> -7 && sensorValues[2]> 160 && sensorValues[2]< 185 && sensorValues[3] > 230000 && sensorValues[3] < 290000 && sensorValues[4] > 150000 && sensorValues[4] < 220000 && sensorValues[5] > 180000 && sensorValues[5] < 240000&& sensorValues[6] > 220000 && sensorValues[6] < 296000&& sensorValues[7] > 120000 && sensorValues[7] < 166000) {
            currentTime = millis();
   
            
            Keyboard.print("How"); 
            Keyboard.press(0xB0);
            Keyboard.releaseAll();
            delay(1500);
            for(int i = 0; i < 10; i++) {
                Keyboard.press(0xB2);
                Keyboard.releaseAll();
            }
       
            break;
            
          }
          }
       }
if (sensorValues[0]< -55 && sensorValues[0]> -75 && sensorValues[1]> -20 && sensorValues[1]< 10 && sensorValues[2]> 130 && sensorValues[2]< 150 && sensorValues[3] > 250000 && sensorValues[3] < 335000 && sensorValues[4] > 200000 && sensorValues[4] < 260000 && sensorValues[5] > 230000 && sensorValues[5] < 299000 && sensorValues[6] > 280000 && sensorValues[6] < 345000&& sensorValues[7] > 120000 && sensorValues[7] < 220000) {
          previousTime = millis(); 
Serial.println("'Yes' Triggered");
          delay(500);
          while((millis() - previousTime) < 1000) {
            readSensors();  
          if (sensorValues[0]< -50 && sensorValues[0]> -65 && sensorValues[1]> -20 && sensorValues[1]< 7 && sensorValues[2]> 150 && sensorValues[2]< 170 && sensorValues[3] > 250000 && sensorValues[3] < 335000 && sensorValues[4] > 200000 && sensorValues[4] < 260000 && sensorValues[5] > 230000 && sensorValues[5] < 299000 && sensorValues[6] > 280000 && sensorValues[6] < 345000&& sensorValues[7] > 120000 && sensorValues[7] < 220000) {
            currentTime = millis();
   
            
           Keyboard.print("Yes"); 
            Keyboard.press(0xB0);
            Keyboard.releaseAll();
            delay(1500);
            for(int i = 0; i < 10; i++) {
                Keyboard.press(0xB2);
                Keyboard.releaseAll();
            }
            break;
            
          }
          }
       }
       if (sensorValues[0]< -55 && sensorValues[0]> -75 && sensorValues[1]> -25 && sensorValues[1]< 0 && sensorValues[2]> 130 && sensorValues[2]< 145 && sensorValues[3] > 70000 && sensorValues[3] < 100000  && sensorValues[4] > 70000 && sensorValues[4] < 103000 && sensorValues[5] > 80000 && sensorValues[5] < 110000 && sensorValues[6] > 90000 && sensorValues[6] < 120000&& sensorValues[7] > 100000 && sensorValues[7] < 155000) {
          previousTime = millis(); 
Serial.println("'Thank You' Triggered");
          delay(500);
          while((millis() - previousTime) < 1000) {
            readSensors();
          if (sensorValues[0]< -40 && sensorValues[0]> -65 && sensorValues[1]> -30 && sensorValues[1]< -10 && sensorValues[2]> 107 && sensorValues[2]< 130 && sensorValues[3] > 70000 && sensorValues[3] < 100000  && sensorValues[4] > 70000 && sensorValues[4] < 103000 && sensorValues[5] > 80000 && sensorValues[5] < 110000 && sensorValues[6] > 90000 && sensorValues[6] < 120000&& sensorValues[7] > 100000 && sensorValues[7] < 155000) {
            currentTime = millis();
   
            
             Keyboard.print("Thank You"); 
            Keyboard.press(0xB0);
            Keyboard.releaseAll();
            delay(1500);
            for(int i = 0; i < 10; i++) {
                Keyboard.press(0xB2);
                Keyboard.releaseAll();
            }
            break;
            
          }
          }
       }

       if (sensorValues[0]< -40 && sensorValues[0]> -60 && sensorValues[1]> -50 && sensorValues[1]< -20 && sensorValues[2]> 135 && sensorValues[2]< 155 && sensorValues[3] > 280000 && sensorValues[3] < 360000 && sensorValues[4] > 220000 && sensorValues[4] < 280000 && sensorValues[5] > 240000 && sensorValues[5] < 310000 && sensorValues[6] > 300000 && sensorValues[6] < 360000 && sensorValues[7] > 140000 && sensorValues[7] < 230000) {
                   
            Keyboard.print("Sorry"); 
            Keyboard.press(0xB0);
            Keyboard.releaseAll();
            delay(1500);
            for(int i = 0; i < 10; i++) {
                Keyboard.press(0xB2);
                Keyboard.releaseAll();
            }

          }

  if (sensorValues[0]< -50 && sensorValues[0]> -65 && sensorValues[1]> -11 && sensorValues[1]< 10 && sensorValues[2]> 140 && sensorValues[2]< 165 && sensorValues[3] > 240000 && sensorValues[3] < 300000 && sensorValues[4] > 200000 && sensorValues[4] < 245000 &&  sensorValues[5] > 90000 && sensorValues[5] < 120000 && sensorValues[6] > 110000 && sensorValues[6] < 140000 && sensorValues[7] > 90000 && sensorValues[7] < 120000) {
          previousTime = millis(); 
Serial.println("'No' Triggered");
          delay(500);
          while((millis() - previousTime) < 1000) {
            readSensors();
          if (sensorValues[0]< -50 && sensorValues[0]> -65 && sensorValues[1]> -11 && sensorValues[1]< 10 && sensorValues[2]> 140 && sensorValues[2]< 165 && sensorValues[3] > 260000 && sensorValues[3] < 340000 && sensorValues[4] > 190000 && sensorValues[4] < 235000 &&  sensorValues[5] > 125000 && sensorValues[5] < 150000 && sensorValues[6] > 150000 && sensorValues[6] < 175000 && sensorValues[7] > 90000 && sensorValues[7] < 120000) {
            currentTime = millis();
               

            Keyboard.print("No"); 
            Keyboard.press(0xB0);
            Keyboard.releaseAll();
            delay(1500);
            for(int i = 0; i < 10; i++) {
                Keyboard.press(0xB2);
                Keyboard.releaseAll();
            }

            
          }
          }
       }

       if (sensorValues[0]< -55 && sensorValues[0]> -68& sensorValues[1]> 0 && sensorValues[1]< 15 && sensorValues[2]> 130 && sensorValues[2]< 150&&  sensorValues[4] > 75000 && sensorValues[4] < 83000 &&  sensorValues[5] > 80000 && sensorValues[5] < 92000 && sensorValues[6] > 100000 && sensorValues[6] < 125000 && sensorValues[7] > 140000 && sensorValues[7] < 155000) {
          previousTime = millis(); 
Serial.println(".........");
          delay(500);
          while((millis() - previousTime) < 1000) {
            readSensors();
          if (sensorValues[0]< -58 && sensorValues[0]> -70 && sensorValues[1]> -25 && sensorValues[1]< 0 && sensorValues[2]> 130 && sensorValues[2]< 150 &&  sensorValues[4] > 70000 && sensorValues[4] < 100000 &&  sensorValues[5] > 80000 && sensorValues[5] < 110000 && sensorValues[6] > 100000 && sensorValues[6] < 125000 && sensorValues[7] > 120000 && sensorValues[7] < 150000) {
            currentTime = millis();
   
            
            Serial.println("Will");
            break;
            
          }
          }
       }

       if (sensorValues[0]< -55 && sensorValues[0]> -68 && sensorValues[1]> -30 && sensorValues[1]< -14 && sensorValues[2]> 120 && sensorValues[2]< 145 && sensorValues[3] > 90000 && sensorValues[3] < 130000 &&  sensorValues[4] > 90000 && sensorValues[4] < 130000 &&  sensorValues[5] > 95000 && sensorValues[5] < 130000 && sensorValues[6] > 135000 && sensorValues[6] < 170000 && sensorValues[7] > 140000 && sensorValues[7] < 180000) {
          previousTime = millis(); 
Serial.println("'Good' Triggered");
          delay(500);
          while((millis() - previousTime) < 1000) {
            readSensors();
          if (sensorValues[0]< -20 && sensorValues[0]> -50 && sensorValues[1]< -20 && sensorValues[1]> -40 && sensorValues[2]> 100 && sensorValues[2]< 125 && sensorValues[3] > 100000 && sensorValues[3] < 150000 &&  sensorValues[4] > 100000 && sensorValues[4] < 186000 &&  sensorValues[5] > 100000 && sensorValues[5] < 185000 && sensorValues[6] > 140000 && sensorValues[6] < 180000 && sensorValues[7] > 140000 && sensorValues[7] < 180000) {
            currentTime = millis();
   
            
           Keyboard.print("Good"); 
            Keyboard.press(0xB0);
            Keyboard.releaseAll();
            delay(1500);
            for(int i = 0; i < 10; i++) {
                Keyboard.press(0xB2);
                Keyboard.releaseAll();
            }
            
          }
          }
       }
if (sensorValues[0]< -60 && sensorValues[0]> -70 && sensorValues[1]> -20 && sensorValues[1]< 10 && sensorValues[2]> 125 && sensorValues[2]< 150 && sensorValues[3] > 230000 && sensorValues[3] < 320000 &&  sensorValues[4] > 200000 && sensorValues[4] < 260000 &&  sensorValues[5] > 220000 && sensorValues[5] < 280000 && sensorValues[6] > 100000 && sensorValues[6] < 125000 && sensorValues[7] > 120000 && sensorValues[7] < 170000) {
          previousTime = millis(); 
Serial.println("'Go' Triggered");
          delay(500);
          while((millis() - previousTime) < 2000) {
            readSensors();
          if (sensorValues[0]< -20 && sensorValues[0]> -40 && sensorValues[1]< 3 && sensorValues[1]> -25 && sensorValues[2]> 160 && sensorValues[2]< 180 && sensorValues[3] > 230000 && sensorValues[3] < 320000 &&  sensorValues[4] > 200000 && sensorValues[4] < 245000 &&  sensorValues[5] > 220000 && sensorValues[5] < 280000 && sensorValues[6] > 100000 && sensorValues[6] < 125000 && sensorValues[7] > 125000 && sensorValues[7] < 170000) {
            currentTime = millis();
   
            
             Keyboard.print("Go or Went"); 
            Keyboard.press(0xB0);
            Keyboard.releaseAll();
            delay(2000);
            for(int i = 0; i < 10; i++) {
                Keyboard.press(0xB2);
                Keyboard.releaseAll();
            }
            
          }
          }
       }

       if (sensorValues[0]< -55 && sensorValues[0]> -75 && sensorValues[1]> -20 && sensorValues[1]< 20 && sensorValues[2]> 130 && sensorValues[2]< 150 && sensorValues[3] > 260000 && sensorValues[3] < 360000 && sensorValues[4] > 200000 && sensorValues[4] < 260000 && sensorValues[5] > 240000 && sensorValues[5] < 300000 && sensorValues[6] > 300000 && sensorValues[6] < 350000 && sensorValues[7] > 100000 && sensorValues[7] < 130000) {
          previousTime = millis(); 
        Serial.println("'ASL' Triggered'");
          delay(500);
          while((millis() - previousTime) < 2000) {
            readSensors();
          if (sensorValues[0]< -55 && sensorValues[0]> -75 && sensorValues[1]> -30 && sensorValues[1]< 20 && sensorValues[2]> 130 && sensorValues[2]< 150 && sensorValues[3] > 230000 && sensorValues[3] < 320000 && sensorValues[4] > 200000 && sensorValues[4] < 250000 && sensorValues[5] > 220000 && sensorValues[5] < 260000 && sensorValues[6] > 90000 && sensorValues[6] < 130000 && sensorValues[7] > 70000 && sensorValues[7] < 110000) {
            currentTime = millis();
   
            
             Keyboard.print("ASL"); 
            Keyboard.press(0xB0);
            Keyboard.releaseAll();
            delay(2000);
            for(int i = 0; i < 10; i++) {
                Keyboard.press(0xB2);
                Keyboard.releaseAll();
            }
            
          }
          }
       }
       

       if (sensorValues[0]< -50 && sensorValues[0]> -70 && sensorValues[1]< 5 && sensorValues[1]> -12 && sensorValues[2]> 138 && sensorValues[2]< 156 && sensorValues[4] >190000 && sensorValues[4] < 220000 && sensorValues[5] > 200000 && sensorValues[5] < 230000 && sensorValues[6] > 245000&& sensorValues[6] < 300000&& sensorValues[7] > 80000 && sensorValues[7] < 110000) {
          previousTime = millis(); 
            Serial.println("Yesterday"); 
            delay(500);

       }

       if (sensorValues[0]< -20 && sensorValues[0]> -35 && sensorValues[1]< 10 && sensorValues[1]> -12 && sensorValues[2]> 160 && sensorValues[2]< 185 && sensorValues[4] >70000 && sensorValues[4] < 100000 && sensorValues[5] > 80000 && sensorValues[5] < 110000 && sensorValues[6] > 100000&& sensorValues[6] < 120000&& sensorValues[7] > 145000 && sensorValues[7] < 155000) {
          previousTime = millis(); 
            Serial.println("Today"); 
            delay(500);

       }

       if (sensorValues[0]< -30 && sensorValues[0]> -50 && sensorValues[1]> -60 && sensorValues[1]< -35 && sensorValues[2]> 140 && sensorValues[2]< 155 && sensorValues[4] > 210000 && sensorValues[4] < 250000 && sensorValues[5] > 220000 && sensorValues[5] < 260000 && sensorValues[6] > 280000&& sensorValues[6] < 320000&& sensorValues[7] > 80000 && sensorValues[7] < 100000) {
          previousTime = millis(); 
            Serial.println("Help"); 
            delay(500);

       }

}

void readSensors() 
{
  int x,y,z; 
  previousTime = 0;
  currentTime = 0;
  adxl.readAccel(&x, &y, &z);
  
  fingerADC[0] = analogRead(pinkeyPin);
  fingerADC[1] = analogRead(ringPin);
  fingerADC[2] = analogRead(middlePin);
  fingerADC[3] = analogRead(indexPin);
  fingerADC[4] = analogRead(thumbPin);

  fingerV1R1[0][0] = fingerADC[0] * voltage/1023.0;
  fingerV1R1[1][0] = fingerADC[1] * voltage/1023.0;
  fingerV1R1[2][0] = fingerADC[2] * voltage/1023.0;
  fingerV1R1[3][0] = fingerADC[3] * voltage/1023.0;
  fingerV1R1[4][0] = fingerADC[4] * voltage/1023.0;

  fingerV1R1[0][1] = resistance * (voltage/fingerV1R1[0][0]-1.0); 
  fingerV1R1[1][1] = resistance * (voltage/fingerV1R1[1][0]-1.0); 
  fingerV1R1[2][1] = resistance * (voltage/fingerV1R1[2][0]-1.0); 
  fingerV1R1[3][1] = resistance * (voltage/fingerV1R1[3][0]-1.0); 
  fingerV1R1[4][1] = resistance * (voltage/fingerV1R1[4][0]-1.0); 

  sensorValues[0] = x;
  sensorValues[1] = y;
  sensorValues[2] = z;
  sensorValues[3] = fingerV1R1[0][1];
  sensorValues[4] = fingerV1R1[1][1];
  sensorValues[5] = fingerV1R1[2][1];
  sensorValues[6] = fingerV1R1[3][1];
  sensorValues[7] = fingerV1R1[4][1];

  return;
}

