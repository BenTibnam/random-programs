//    Left motor truth table 
//  ENA         IN1               IN2         Description  
//  LOW   Not Applicable    Not Applicable    Motor is off
//  HIGH        LOW               LOW         Motor is stopped (brakes) 
//  HIGH        HIGH              LOW         Motor is on and turning forwards 
//  HIGH        LOW               HIGH        Motor is on and turning backwards 
//  HIGH        HIGH              HIGH        Motor is stopped (brakes) 

//    Right motor truth table 
//  ENB         IN3             IN4         Description  
//  LOW   Not Applicable   Not Applicable   Motor is off
//  HIGH        LOW             LOW         Motor is stopped (brakes) 
//  HIGH        LOW             HIGH        Motor is on and turning forwards 
//  HIGH        HIGH            LOW         Motor is on and turning backwards 
//  HIGH        HIGH            HIGH        Motor is stopped (brakes)  

//    The direction of the car's movement 
//  Left motor    Right motor     Description  
//  stop(off)     stop(off)       Car is stopped 
//  forward       forward         Car is running forwards 
//  forward       backward        Car is turning right 
//  backward      forward         Car is turning left 
//  backward      backward        Car is running backwards 

//define the L298n IO pin 
const int ENA = 5;
const int ENB = 6;
const int IN1 = 7;
const int IN2 = 8;
const int IN3 = 9;
const int IN4 = 11;

void forward(){
  digitalWrite(ENA, HIGH); // enable L298n A channel
  digitalWrite(ENB, HIGH); // enable L298n B channel
  digitalWrite(IN1, HIGH); // setting IN1 to the hight level
  digitalWrite(IN2, LOW);  // setting IN2 to the low level
  digitalWrite(IN3, LOW);  // setting IN3 to the low level
  digitalWrite(IN4, HIGH); // setting IN4 to hight level 
}

void back(){
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void left(){
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);  
}

void right(){
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);  
}

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

}

void loop() {
  forward();
  delay(400);
  back();
  delay(400);
  left();
  delay(400);
  right();
  delay(400);
}
