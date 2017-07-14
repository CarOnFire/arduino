//including library that supports servos
#include <Servo.h>

Servo hori; //defining servo for horizontal movement

//setting names for pins
int sw = 2;
int ypin = 1;
int laser = 12;
int buzzer = 11;

//variables to store data
int diff = 100; //joystick activation offset
int pos = 60; //position of the servo

//runs once
void setup() {
  hori.attach(9); //attaching servo output to pin 9
  //setting pin modes
  pinMode(laser,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(sw,INPUT);
  digitalWrite(sw,HIGH);
}

//runs forever
void loop() {
  //checking to see if the y position is 100 off to the left
  if(analogRead(ypin)>(512+diff)&&pos<180){ 
    //increase and move the servo's position by 1
    hori.write(pos+=1);
    delay(20);
  }
  //if movement is not 100 to left, then check right movement
  else if(analogRead(ypin)<(512-diff)&&pos>0){
    //decrease and move the servo's position by 1
    hori.write(pos-=1);
    delay(20);
  }
  
  //fire the turret if the switch is activated
  while(digitalRead(sw) == 0){
    fire();
    delay(20);
  }
}

//function to fire the laser and sound the buzzer
void fire(){
  digitalWrite(laser,HIGH);
  analogWrite(buzzer,10);
  delay(100);
  digitalWrite(laser,LOW);
  analogWrite(buzzer,0);
}

