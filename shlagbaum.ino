#include <Servo.h> 

/*
D2 button close
D9 servo
D3 button open
*/
 
Servo myservo; 
const int buttonClose = 2;
const int buttonOpen = 3;
int buttonCloseState = 0;
int buttonOpenState = 0;
int shlagbaumCloseState = 0;
int shlagbaumOpenState = 0;
 
void setup() 
{ 
  myservo.attach(9); 
  pinMode(buttonClose, INPUT);
  pinMode(buttonOpen, INPUT);   
  
  myservo.write(17); //close     
  delay(2000);    
  shlagbaumCloseState = 1;
  shlagbaumOpenState = 0;
} 
 
void loop() 
{   
  int buttonCloseState = digitalRead(buttonClose);
  int buttonOpenState = digitalRead(buttonOpen);

  if ((buttonCloseState == HIGH) & (shlagbaumOpenState==1) ) {  
      for (int angel = 107; angel > 17; angel--)  {
        myservo.write(angel);    //0..180              
        delay(10);      
      }    
    shlagbaumCloseState = 1;
    shlagbaumOpenState = 0;
  } 
  
  if ((buttonOpenState == HIGH) & (shlagbaumCloseState==1) ) {  
      for (int angel = 17; angel < 107; angel++)  {
        myservo.write(angel);    //0..180              
        delay(10);      
      }    
    shlagbaumCloseState = 0;
    shlagbaumOpenState = 1;
  }   
      
} 