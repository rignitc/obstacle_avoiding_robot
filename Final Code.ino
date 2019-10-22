/* 
 *  Obstacle Avoidance Robot
 *  Organisation : Robotics Interest Group, NITC
 *  Year 2018
 */

// Define all pin
#define trigPin 12
#define echoPin 13
const int motorA1= 3;     
const int motorA2= 5;       
const int motorB1=8;    
const int motorB2=10;     
int enA = 7;
int enB = 6;

#include <Servo.h>                                          // library for using servo

Servo myservo;                                              // Creating myservo object

int pos = 90;                                               // define position in degrees
float duration, distance, dist;  

 
 
 float distcal()
{
  // for calculating distance

  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344; 
  return distance;
}


void lookleft()
{                                  
    myservo.write(180);                
}

void lookright()
{  
    myservo.write(0); 
}

void lookstraight()
{
    myservo.write(90); 
}


void forward(){
  // Moves robot forward
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH); 
}

void left(){
  // Moves robot left
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
  delay(1200);
}

void right(){
  // Moves robot right
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH); 
  delay(1200);
}

void uturn(){
  // Moves robot uturn
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
   delay(2580);
}

void stop(){
  // Stops the robot
  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}
 
void setup() 
{ 
  myservo.write(pos);                                     // moves the servo to initial position 
  Serial.begin (9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myservo.attach(2);                                      // Servo is in pin 2
  
  pinMode(motorA1,OUTPUT);
  pinMode(motorA2,OUTPUT);
  pinMode(motorB1,OUTPUT);
  pinMode(motorB2,OUTPUT);
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  
} 
 
void loop() 
{ 
  forward();
  dist=distcal();
   if(dist<=15 )
  {
   stop();
   lookright();
   delay(1000);
   dist=distcal();
   delay(1000);
     if(dist<=15)
       {
        lookleft();
        delay(1000);
        dist=distcal();
        delay(1000);
        if(dist<=15)
         {
          lookstraight();
          uturn();
         }
        else
         {
          lookstraight();
          left();
         }
       }
      else
       {
        right();
        lookstraight();       
       }
      } 
   else
     {
      lookstraight();
      forward();
     }
}
