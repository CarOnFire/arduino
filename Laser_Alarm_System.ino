//values for pins
int sensor = 1;
int buzzer = 11;
int switch = 10;

//value to store data
int sensorValue = 0;

//runs once to set up outputs and inputs
void setup() {
  pinMode(buzzer,OUTPUT);
  pinMode(switch,INPUT);
  digitalWrite(switch,HIGH); //setting the pin to be high, so when it is connected to ground, value will change

  //setting frequency for the serial monitor
  Serial.begin(9600);
}

//runs without stopping
void loop() {
  //displays the value of the sensor
  sensorValue = analogRead(sensor);
  Serial.println(sensorValue);

  //checking to see if there is enough light on the sensor
  if(sensorValue < 200){
    //when there isnt enough light and the switch is not activated, make alarm sounds
    while(digitalRead(switch) == 1 ){
      alarm(); //alarm sound
    }
  }
}

//function to beep the buzzer
void alarm(){
  analogWrite(buzzer,100);
  delay(1000); //keep buzzer on for 1 second
  analogWrite(buzzer,0);
  delay(500); //500 second delay between beeps
}

