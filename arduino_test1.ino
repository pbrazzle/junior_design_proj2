#define newLED 13
#define in 12

void setup() {
  // put your setup code here, to run once:
  pinMode(newLED, OUTPUT);
  pinMode(in, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(in) == HIGH){
    digitalWrite(newLED, HIGH);
  }
  delay(1000);
  digitalWrite(newLED, LOW);
  delay(1000);
}
