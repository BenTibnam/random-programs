const int IN1 = 7;
const int IN2 = 8;
const int IN3 = 9;
const int IN4 = 11;
const int ENA = 5;
const int ENB = 6;

void setup() {
  pinMode(IN1, OUTPUT);   // set IO pin mode OUTPUT
  pinMode(IN2, OUTPUT);   // set IO pin mode OUTPUT
  pinMode(IN3, OUTPUT);   // set IO pin mode OUTPUT
  pinMode(IN4, OUTPUT);   // set IO pin mode OUTPUT
  pinMode(ENA, OUTPUT);   // set IO pin mode OUTPUT
  pinMode(ENB, OUTPUT);   // set IO pin mode OUTPUT
  digitalWrite(ENA, HIGH);  // enabling ENA
  digitalWrite(ENB, HIGH);  // enabling ENB
}

void loop() {
  /*
   * moving the left motors
   */

   // forward
   digitalWrite(IN1, HIGH);
   digitalWrite(IN2, LOW);
   delay(500);

   // stopping
   digitalWrite(IN1, LOW);
   digitalWrite(IN2, LOW);
   delay(500);

   // backward
   digitalWrite(IN1, LOW);
   digitalWrite(IN2, HIGH);
   delay(500);

   // stopping
   digitalWrite(IN1, LOW);
   digitalWrite(IN2, LOW);
   delay(500);

   /*
    * moving the right motors
    */

    // backward
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(500);

    // stopping
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(500);

    // forward
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(500);

    // stopping
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(500);
}
