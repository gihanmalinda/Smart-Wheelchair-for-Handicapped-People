
#include <LiquidCrystal.h>
#include <Wire.h>
LiquidCrystal lcd(23,25,27,29,31,33);

#define trig1 22
#define trig2 24
#define trig3 26
#define trig4 28
#define trig5 30
#define trig6 32
#define trig7 34
#define trig8 36

#define echo1 38
#define echo2 40
#define echo3 42
#define echo4 44
#define echo5 46
#define echo6 48
#define echo7 50
#define echo8 52

#define Redled 13

#define R 43
#define O 45
#define Y 47

#define test 8

int JoyStickX = A0;
int JoyStickY = A1;
int x,y;
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;

char Received; 
short t1,t2,t3,t4,t5,t6,t7,t8,cmt1,cmt2,cmt3,cmt4,cmt5,cmt6,cmt7,cmt8; 

char receivedChar;
boolean newData = false;

int z = 111;
int i = 222;



void setup() {

Serial.begin(9600);
Wire.begin();

lcd.begin(16,2);

pinMode(trig1,OUTPUT);
pinMode(trig2,OUTPUT);
pinMode(trig3,OUTPUT);
pinMode(trig4,OUTPUT);
pinMode(trig5,OUTPUT);
pinMode(trig6,OUTPUT);
pinMode(trig7,OUTPUT);
pinMode(trig8,OUTPUT);


pinMode(echo1,INPUT);
pinMode(echo2,INPUT);
pinMode(echo3,INPUT);
pinMode(echo4,INPUT);
pinMode(echo5,INPUT);
pinMode(echo6,INPUT);
pinMode(echo7,INPUT);
pinMode(echo8,INPUT);



pinMode(R,OUTPUT);
pinMode(O,OUTPUT);
pinMode(Y,OUTPUT);

pinMode(test,OUTPUT);

}
void loop() {
  sonic();
 
  if(Serial.available()){Received = Serial.read();}
     
    if(cmt1>0 || cmt2>2 || cmt3>0 || cmt4>0|| cmt5>0|| cmt6>0|| cmt7>0|| cmt8>0){
   
    if(Received=='A'){rangeOne();digitalWrite(R,LOW);digitalWrite(O,LOW);digitalWrite(Y,HIGH);}
    
    if(Received=='B'){rangeTwo();digitalWrite(R,LOW);digitalWrite(O,HIGH);digitalWrite(Y,LOW);}
    
    if(Received=='C'){rangeThree();digitalWrite(R,HIGH);digitalWrite(O,LOW);digitalWrite(Y,LOW);}
    
    }
  delay(100);
     
}

void sonic(){

 
    
//Sonic 1
  digitalWrite(trig1,LOW);
  delayMicroseconds(2);
  digitalWrite(trig1,HIGH);
  delayMicroseconds(2);
                       
   t1 =pulseIn(echo1,HIGH);
   cmt1 = t1/29/2;
   
  //Sonic 2
  digitalWrite(trig2,LOW);
  delayMicroseconds(2);
  digitalWrite(trig2,HIGH);
  delayMicroseconds(2);
 
   t2 = pulseIn(echo2,HIGH);
   cmt2 = t2/29/2; 

   //Sonic 3
  digitalWrite(trig3,LOW);
  delayMicroseconds(2);
  digitalWrite(trig3,HIGH);
  delayMicroseconds(2);
  
   t3 = pulseIn(echo3,HIGH);
   cmt3 = t3/29/2; 

  //Sonic 4
  digitalWrite(trig4,LOW);
  delayMicroseconds(2);
  digitalWrite(trig4,HIGH);
  delayMicroseconds(2);
  
   t4 = pulseIn(echo4,HIGH);
   cmt4 = t4/29/2; 

  //Sonic 5
  digitalWrite(trig5,LOW);
  delayMicroseconds(2);
  digitalWrite(trig5,HIGH);
  delayMicroseconds(2);
  
   t5 = pulseIn(echo5,HIGH);
   cmt5 = t5/29/2; 

  //Sonic 6
  digitalWrite(trig6,LOW);
  delayMicroseconds(2);
  digitalWrite(trig6,HIGH);
  delayMicroseconds(2);
  
   t6 = pulseIn(echo6,HIGH);
   cmt6 = t6/29/2; 

    //Sonic 7
  digitalWrite(trig7,LOW);
  delayMicroseconds(2);
  digitalWrite(trig7,HIGH);
  delayMicroseconds(2);
  
   t7 = pulseIn(echo7,HIGH);
   cmt7 = t7/29/2;

     //Sonic 8
  digitalWrite(trig8,LOW);
  delayMicroseconds(2);
  digitalWrite(trig8,HIGH);
  delayMicroseconds(2);
  
   t8 = pulseIn(echo8,HIGH);
   cmt8 = t8/29/2;
  
}

void rangeOne(){

  if(cmt1<10 || cmt2<10 || cmt3<10 || cmt4<10|| cmt5<10|| cmt6<10|| cmt7<10|| cmt8<10){

          
         
            if(cmt1<10 || cmt2<10){
            Serial.println("Front");
            lcd.setCursor(0,0);
            lcd.print("Front");
                  master2();
          }  
          
            if(cmt3<10 || cmt4<10){
            Serial.println("Right");
            lcd.setCursor(0,0);
            lcd.print("Right");
                  master2(); 
          } 

            if(cmt5<10 || cmt6<10){
            Serial.println("Back");
            lcd.setCursor(0,0);
            lcd.print("Back");
                 master2();
          } 
           
          /*  if(cmt7<10 || cmt8<10){
            Serial.println("Left");
            lcd.setCursor(0,0);
            lcd.print("Left");
               master2();   
          }  */
          
        }
        else{
           lcd.clear();
           
          } 
   
        if(cmt1<5 || cmt2<5 || cmt3<5|| cmt4<5|| cmt5<5|| cmt6<5|| cmt7<5|| cmt8<5){
            
            lcd.setCursor(0,1);
            lcd.print("STOP");
            Serial.println("STOP");
            master();
            
        }
    
  
}

void rangeTwo(){

   if(cmt1<20 || cmt2<2 || cmt3<20 || cmt4<20|| cmt5<20|| cmt6<20|| cmt7<20|| cmt8<20){
           
            if(cmt1<20 || cmt2<20){
            Serial.println("Front");
            lcd.setCursor(0,0);
            lcd.print("Front");        
            master2();
          } 
          
            if(cmt3<20 || cmt4<20){
            Serial.println("Right");
            lcd.setCursor(0,0);
            lcd.print("Right");
                 master2();
          }    

            if(cmt5<20 || cmt6<20){
            Serial.println("Back");
            lcd.setCursor(0,0);
            lcd.print("Back");
                   master2();
          }  
           
            if(cmt7<20 || cmt8<20){
            Serial.println("Left");
            lcd.setCursor(0,0);
            lcd.print("Left");
                   master2();
          } 
          
        }
        else{
           lcd.clear();
           
          } 
   
        if(cmt1<5 || cmt2<5 || cmt3<5|| cmt4<5|| cmt5<5|| cmt6<5|| cmt7<5|| cmt8<5){
            
            lcd.setCursor(0,1);
            lcd.print("STOP");  
            master();
        }         

  
}

void rangeThree(){

  if(cmt1<30 || cmt2<30 || cmt3<30 || cmt4<30|| cmt5<30|| cmt6<30|| cmt7<30|| cmt8<30){
           
            if(cmt1<30 || cmt2<30){
            Serial.println("Front");
            lcd.setCursor(0,0);
            lcd.print("Front");
                master2();
          }    
          
            if(cmt3<30 || cmt4<30){
            Serial.println("Right");
            lcd.setCursor(0,0);
            lcd.print("Right");
                  master2();
          }  

            if(cmt5<30 || cmt6<30){
            Serial.println("Back");
            lcd.setCursor(0,0);
            lcd.print("Back");
                master2(); 
          }  
           
            if(cmt7<30 || cmt8<30){
            Serial.println("Left");
            lcd.setCursor(0,0);
            lcd.print("Left");
                master2();
          }   
          
        }
        else{
           lcd.clear();
           
          } 
   
        if(cmt1<5 || cmt2<5 || cmt3<5|| cmt4<5|| cmt5<5|| cmt6<5|| cmt7<5|| cmt8<5){
            
            lcd.setCursor(0,1);
            lcd.print("STOP");
            master();
   
           Serial.println("Test");
        }        
        
}


void master(){

   Serial.println("Stop");
   Wire.beginTransmission(8); 
   Wire.write(z);              
   Wire.endTransmission(); 
   delay(100);
   return;   
}

void master2(){

   Serial.println("Other");
   Wire.beginTransmission(8); 
   Serial.println("Other2");
   Wire.write(i); 
   Wire.endTransmission(); 
   Serial.println("Other4");
  
   return;   
}



