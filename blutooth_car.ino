/*
              Author:DIYelex
              date: 3/8/2019
*/

#include <SoftwareSerial.h> // TX RX software library for bluetooth
SoftwareSerial mySerial(2, 3);  // Connect the TXD pin of BT module to pin 2 of the Arduino and the RXD pin of BT module to pin 3 of Arduino.
int Rightmotor1 = 4; //pin 1 of Rightmotor 
int Rightmotor2 = 5; //pin2 of Rightmotor 
int leftmotor1 = 6;//pin1 of leftmotor 
int leftmotor2 = 7;//pin2 of leftmotor 
int en1=9; //enable pin for Rightmotor 
int en2=10; // enable pin for leftmotor
String readString;
void setup()
{
  pinMode(Rightmotor1,OUTPUT);  // attach Right Motor 1st wire to pin 4
  pinMode(Rightmotor2,OUTPUT); // attach Right Motor 1st wire to pin 5
  pinMode(leftmotor1,OUTPUT);// attach Right Motor 1st wire to pin 6
  pinMode(leftmotor2,OUTPUT);// attach Right Motor 1st wire to pin 7
  pinMode(en1,OUTPUT);  //attach motor drivers rightmotor enable pin to PWM pin 9 of arduino
  pinMode(en2,OUTPUT);//attach motor drivers leftmotor enable pin to PWM pin 10 of arduino
 
  Serial.begin(9600); //Setup usb serial connection to computer
  mySerial.begin(9600);//Setup Bluetooth serial connection to android
}

void loop()
{
  while(mySerial.available()){ 
    delay(50);
    char data = mySerial.read();//store the data come from bluetooth to char data
    readString+=data;
  }

  if(readString.length() > 0) {
    Serial.println(readString); ///Print the data to serial monitor which is given by bluetooth

    if(readString == "Forward"){ //if forward received do following 
      
      digitalWrite(Rightmotor1, HIGH);  ////////////FORWARD ////////////////////////
      digitalWrite(Rightmotor2, LOW);
      digitalWrite(leftmotor1, HIGH);
       digitalWrite(leftmotor2, LOW);
       analogWrite(en1,200);// for controlling speed of Rightmotor vary the value from 0 to 255
       analogWrite(en2,200);// for controlling speed of leftmotor vary the value from 0 to 255
        
     }
    
    if(readString == "Back"){  //if Back received do following 
       
      digitalWrite(Rightmotor1, LOW);  ////////////BACK/////////////////////////////
      digitalWrite(Rightmotor2, HIGH);
      digitalWrite(leftmotor1, LOW);
       digitalWrite(leftmotor2, HIGH);
       analogWrite(en1,200);
       analogWrite(en2,200);
       
     }
    

    if(readString == "Left"){  //if left received do following 
       digitalWrite(Rightmotor1, HIGH);/////////////LEFT////////////////////////////
      digitalWrite(Rightmotor2, LOW);
      digitalWrite(leftmotor1, LOW);
       digitalWrite(leftmotor2, HIGH);
       analogWrite(en1,80);
       analogWrite(en2,80);
       
     }
    

    if(readString == "Right"){   //if Right received do following 
      digitalWrite(Rightmotor1, LOW);/////////////RIGHT////////////////////////
      digitalWrite(Rightmotor2, HIGH);
      digitalWrite(leftmotor1, HIGH);
       digitalWrite(leftmotor2, LOW);
       analogWrite(en1,80);
       analogWrite(en2,80);
       
    }

    if(readString == "Stop"){  //if stop received do following 
      digitalWrite(Rightmotor1, LOW); ///////////stop/////////////////
      digitalWrite(Rightmotor2, LOW);
      digitalWrite(leftmotor1, LOW);
       digitalWrite(leftmotor2, LOW);
       
    }

    readString = "";
  }
}
