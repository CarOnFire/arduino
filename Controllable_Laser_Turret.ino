#include <Servo.h>

Servo hori;
int sw = 2;
int ypin = 1;
int laser = 12;
int buzzer = 11;
int diff = 100;
int pos = 60;

void setup() {
  // put your setup code here, to run once:
  hori.attach(9);
  pinMode(laser,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(sw,INPUT);
  digitalWrite(sw,HIGH);
}

void loop() {
  if(analogRead(ypin)>(512+diff)){
    hori.write(pos+=1);
    delay(20);
  }
  else if(analogRead(ypin)<(512-diff)&&pos>0){
    hori.write(pos-=1);
    delay(20);
  }
  while(digitalRead(sw) == 0){
    fire();
    delay(20);
  }
}

void fire(){
  digitalWrite(laser,HIGH);
  analogWrite(buzzer,10);
  delay(100);
  digitalWrite(laser,LOW);
  analogWrite(buzzer,0);
}

