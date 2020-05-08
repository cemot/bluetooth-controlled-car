 #include <SoftwareSerial.h> // TX RX software library for bluetooth
SoftwareSerial mySerial(2, 3);  // Connect the TXD pin of BT module to pin 2 of the Arduino and the RXD pin of BT module to pin 3 of Arduino.
int Rightmotor1 = 4; //pin 1 of Rightmotor 
int Rightmotor2 = 5; //pin2 of Rightmotor 
int leftmotor1 = 6;//pin1 of leftmotor 
int leftmotor2 = 7;//pin2 of leftmotor 
int en1=9; //enable pin for Rightmotor 
int en2=10; // enable pin for leftmotor
int dataIn,m;
int wheelSpeed;
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
 if (mySerial.available() > 0) {
    dataIn = mySerial.read(); 
    delay(20);
    Serial.println(dataIn);// Read the data
   
    if (dataIn == 1) { //forward
      m = 1;
    }
    if (dataIn == 2) {  //left
      m = 2;
    }
    if (dataIn == 3) {   //right
      m = 3;
    }
    if (dataIn == 4) {   //back
      m = 4;
    }
    if (dataIn == 5) {  //stop
      m = 5;
    }
       // Set speed
    if (dataIn >= 6) {
      wheelSpeed = dataIn * 5;
    }
  }
  if (m == 1) {
    Forward();
  }
  if (m == 2) {
    Left();
  }
  if (m == 3) {
    Right();
  }
  if (m == 4) {
   Backward();
  }
  if (m == 5) {
    Stop_motor();
  }
}
  
void Forward() {
  digitalWrite(Rightmotor1, HIGH);  ////////////FORWARD ////////////////////////
      digitalWrite(Rightmotor2, LOW);
      digitalWrite(leftmotor1, HIGH);
       digitalWrite(leftmotor2, LOW);
     analogWrite(en1,wheelSpeed);
       analogWrite(en2,wheelSpeed);
}
void Backward() {
 digitalWrite(Rightmotor1, LOW);  ////////////BACK/////////////////////////////
      digitalWrite(Rightmotor2, HIGH);
      digitalWrite(leftmotor1, LOW);
       digitalWrite(leftmotor2, HIGH);
        analogWrite(en1,wheelSpeed);
       analogWrite(en2,wheelSpeed);
}
void Right() {
  digitalWrite(Rightmotor1, LOW);/////////////RIGHT////////////////////////
      digitalWrite(Rightmotor2, HIGH);
      digitalWrite(leftmotor1, HIGH);
       digitalWrite(leftmotor2, LOW);
        analogWrite(en1,wheelSpeed);
       analogWrite(en2,wheelSpeed);
}
void Left() {
 digitalWrite(Rightmotor1, HIGH);/////////////LEFT////////////////////////////
      digitalWrite(Rightmotor2, LOW);
      digitalWrite(leftmotor1, LOW);
       digitalWrite(leftmotor2, HIGH);
        analogWrite(en1,wheelSpeed);
       analogWrite(en2,wheelSpeed);
}
void Stop_motor() {
 digitalWrite(Rightmotor1, LOW);/////////////stop////////////////////////////
      digitalWrite(Rightmotor2, LOW);
      digitalWrite(leftmotor1, LOW);
       digitalWrite(leftmotor2, LOW);
        analogWrite(en1,wheelSpeed);
       analogWrite(en2,wheelSpeed);
}
