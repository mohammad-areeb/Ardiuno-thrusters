#include<Servo.h>
int pinServoD=9;
int pinServoL=3;
int pinServoR=5;//servo is attached to this pin
char x;
int w=0;
int l=0;
int r=0;


Servo depth;
Servo right;
Servo left;

void setup()
{
 
  Serial.begin(9600);
  depth.attach(pinServoD);
  left.attach(pinServoL);
  right.attach(pinServoR);
  depth.writeMicroseconds(1000);
  right.writeMicroseconds(1000);
  left.writeMicroseconds(1000);
  delay(8000);
}

void loop()
{
 
   x=Serial.read();
   if(x=='w' && r<300 && l<300)
   {
      l=l+50;
      r=r+50;} //moving backward 
   else if (x=='s')
     { 
      r=r-50;
      l=l-50;}//moving forward 
      
   else if(x=='u' && w<300)
   {
      w=w+50;} //going up 
   else if (x=='p' && w>(-300))
     { 
      w=w-50;} //going down 

   else if(x=='a' && r<300)
   {
      r=r+100;}  //left turn 
   else if (x=='d' && l>(-300))
     { 
      l=l+100;}  //right turn    
   else if (x=='r')
   {
    w=0;
    r=0;
    l=0;
   }
    
   depth.writeMicroseconds(1500 +w);
   right.writeMicroseconds(1500 +r);
   left.writeMicroseconds(1500 +l);
   Serial.println(w);
   Serial.println(r);
   Serial.println(l);
   Serial.println("repeat w, r, l");
  
   
}
 
 
