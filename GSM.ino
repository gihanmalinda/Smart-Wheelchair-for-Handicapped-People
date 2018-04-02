#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 9);
int button = 6;
int btnstatus = 0;

void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  pinMode(button,INPUT);
  delay(100);
}


void loop()
{

      if(Serial.available()>0){

        if(Serial.read() == 's'){

          Serial.println(digitalRead(button));
          Serial.println(btnstatus);
          Serial.println("msg");
  
          SendMessage();
          delay(20000);
      }
      }    
   
}


 void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+94719230169\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Alert!!! Patient just pressed the emergency button of the wheelchair. Please contact him/her immediately");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}



