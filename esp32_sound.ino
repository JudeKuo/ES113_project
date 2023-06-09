#include "Arduino.h"
#include "BluetoothSerial.h"     //手機藍芽聲控=>顯示指令
#include<SoftwareSerial.h>
BluetoothSerial BT;
//#define RXp2 16
//#define TXp2 17
HardwareSerial abc(1);     //9 10腳位
SoftwareSerial abc2(16,17);


/*
// Setting PWM properties
const int freq = 30000;
const int pwmChannelA = 0;
const int pwmChannelB = 0;
const int resolution = 8;
int dutyCycle = 200;
*/
void setup() {
  //bluetooth
  Serial.begin(115200);
  abc.begin(9600);
  abc2.begin(9600);
  BT.begin("zxc"); //Bluetooth device name
  
  

/*
  // configure LED PWM functionalitites
  ledcSetup(pwmChannelA, freq, resolution);
  ledcSetup(pwmChannelB, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(enable1PinA, pwmChannelA);
  ledcAttachPin(enable1PinB, pwmChannelB);
  Serial.begin(115200);
  // testing
  Serial.print("Testing DC Motor...");*/
}

void loop() {
  
if (BT.available()) {
    String value = BT.readString();
    Serial.println(value);
    if (value == "go"){
        Serial.println("go");
        abc.write("1");
        abc2.write("1"); 
        delay(100);      
    } 
    
    if (value == "stop") {
      Serial.println("stop");
      abc.write("-1");
      abc2.write("-1");  
      delay(100);         
    }
    if (value == "right") {
      Serial.println("right");
      abc.write("2");
      abc2.write("2");  
      delay(100);         
    }
    if (value == "left") {
      Serial.println("left");
      abc.write("-2");
      abc2.write("-2");  
      delay(100);         
    }
    /*    
    if (value == "back") {
      Serial.println("back");
      Serial.println("Moving Backward");
      dutyCycle =200;
      ledcWrite(pwmChannelA, dutyCycle);
      ledcWrite(pwmChannelB, dutyCycle);
      Serial.print("BACKward with duty cycle: ");
      Serial.println(dutyCycle);
      digitalWrite(MotorA_I1, LOW);
      digitalWrite(MotorA_I3, LOW);
      delay(2000);
    }*/
   }
}
