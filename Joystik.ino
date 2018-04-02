#include <Wire.h>

int JoyStickX = A0;
int JoyStickY = A1;
int x,y;
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
char receivedChar;

int testLed = 2;

void setup() {

 pinMode(8,OUTPUT);
 pinMode(9, OUTPUT);
 pinMode (JoyStickX, INPUT);
 pinMode (JoyStickY, INPUT);
 pinMode (led1, OUTPUT); // left Front
 pinMode (led3, OUTPUT); // right Front
 pinMode (led2, OUTPUT); // left back
 pinMode (led4, OUTPUT); // right back
 pinMode(testLed, OUTPUT);
 Wire.begin(8);                
 Wire.onReceive(receiveEvent);
 Serial.begin(9600);
 
}

void loop() {
  
  Joystick();
  voice();
  
}

void Joystick(){
  
  x = analogRead(JoyStickX);
  y = analogRead(JoyStickY);
  Serial.print("X axis = ");
  Serial.print(x);
  Serial.print("              Y axis = ");
  Serial.print(y,DEC);
  Serial.println(" ");

//Neutral
  if(x<532&&x>528 && y>516&&y<519){
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    }

//forward
  if(x>1021&&x<1024 && y>516&&y<519){
    digitalWrite(led1,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led4,LOW);
    }

//Back
  if(x==0 && y<519&&y>516){
    digitalWrite(led1,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led4,HIGH);
    }

//Left
  if(x>527&&x<531 && y==0){
    
    digitalWrite(led1,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led4,HIGH);
    
    
    }

//Right
  if(x>528&&x<531 && y>1021&&y<1024){
    digitalWrite(led1,LOW);
    
    digitalWrite(led3,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led4,LOW);
    }
delay(100);
  
}

void voice(){

    if (Serial.available() > 0) {

    receivedChar = Serial.read();
    //Listen
    if(receivedChar == '8'){

     digitalWrite(testLed,HIGH);   
     delay(500);
     digitalWrite(testLed,LOW);
 
    }
    // Foreword
    if(receivedChar == '7'){

     digitalWrite(led1,HIGH);    digitalWrite(led3,HIGH);    digitalWrite(led2,LOW);    digitalWrite(led4,LOW);
     delay(1000);
 
    }
    //backword
    if(receivedChar == '6'){

      digitalWrite(led1,LOW);    digitalWrite(led3,LOW);    digitalWrite(led2,HIGH);    digitalWrite(led4,HIGH);
      delay(1000);
    }
    //left
    if(receivedChar == '5'){

      digitalWrite(led1,HIGH);    digitalWrite(led3,LOW);    digitalWrite(led2,LOW);    digitalWrite(led4,HIGH);
      delay(1000);
    }
    //right
    if(receivedChar == '4'){

     digitalWrite(led1,LOW);    digitalWrite(led3,HIGH);    digitalWrite(led2,HIGH);    digitalWrite(led4,LOW);
     delay(1000); 
    }
    //stop
    if(receivedChar == '3'){

     digitalWrite(led1,LOW);    digitalWrite(led2,LOW);    digitalWrite(led3,LOW);    digitalWrite(led4,LOW);
      delay(1000);
    }

    if(receivedChar == '2'){

     digitalWrite(9,HIGH);    
     delay(1000);
     digitalWrite(9,LOW);
    }
    
  }

  //receiveEvent(10);
}

void receiveEvent(int howMany) {
  x = Wire.read();
  Serial.println(x+"test");
  if (x==111) {
    Serial.println(x);        
    digitalWrite(testLed,HIGH);
    
   WCstop();
  }
  if (x==222 ){
    digitalWrite(testLed,LOW);
    }
  }

void WCstop(){

    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  delay(2000);
  
}

