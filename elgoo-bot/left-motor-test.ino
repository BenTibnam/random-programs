// Find kit here: https://www.amazon.com/Elegoo-EL-KIT-012-Tracking-Ultrasonic-Bluetooth/dp/B0746DVP1J/ref=sr_1_1?ie=UTF8&qid=1528247050&sr=8-1

//  Left motor truth table
// ENA    IN1   IN2   Description
// LOW    N/A   N/A   Motor OFF
// HIGH   LOW   LOW   Motors STOPPED
// HIGH   HIGH  LOW   Motor is on and turning forwards
// HIGH   LOW   HIGH  Motor is on and turning backwards
// HIGH   HIGH  HIGH  Motors STOPPED

// define IO pins
const int ENA = 5;
const int IN1 = 7;
const int IN2 = 8;

void setup() {
  pinMode(IN1, OUTPUT); // set IO pin mode OUTPUT
  pinMode(IN2, OUTPUT); // set IO pin mode OUTPUT
  pinMode(ENA, OUTPUT);
  digitalWrite(ENA, HIGH); // enabling the left motor;  
}

void loop() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(500);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(500);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(500);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  delay(500);
}
