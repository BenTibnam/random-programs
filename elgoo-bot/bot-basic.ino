// ENA | VS expansion board: 5
// ENB | VS expansion board: 6
// IN1 | VS expansion board: 7
// IN2 | VS expansion board: 8
// IN3 | VS expansion board: 9
// IN4 | VS expansion board: 11

//Here are some handy tables to show the various modes of operation. 
//  ENB         IN3             IN4         Description  
//  LOW   Not Applicable   Not Applicable   Motor is off
//  HIGH        LOW             LOW         Motor is stopped (brakes) 
//  HIGH        LOW             HIGH        Motor is on and turning forwards 
//  HIGH        HIGH            LOW         Motor is on and turning backwards 
//  HIGH        HIGH            HIGH        Motor is stopped (brakes)      

// Kit code comes from: https://www.amazon.com/Elegoo-EL-KIT-012-Tracking-Ultrasonic-Bluetooth/dp/B0746DVP1J/ref=sr_1_1?ie=UTF8&qid=1528247050&sr=8-1 
const int ENB = 6;
const int IN3 = 9;
const int IN4 = 11;

// init the car
void setup(){
  pinMode(IN3, OUTPUT);   // set IO pin mode OUTPUT
  pinMode(IN4, OUTPUT);   // set IO pin mode OUTPUT
  pinMode(ENB, OUTPUT);   // set IO pin mode OUTPUT
  digitalWrite(ENB, HIGH);
}

// main loop
void loop(){
  /*
  * Whole program is just to run the right wheels
  */
  
  // Move forward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(500);
  
  // Stopping
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(500);
  
  // moving backwards
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(500);

  // stopping
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(500);
}
