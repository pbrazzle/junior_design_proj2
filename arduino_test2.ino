#define out1 13
#define out2 11
#define out3 10
#define in 12

void setup() {
  // put your setup code here, to run once:
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(out3, OUTPUT);
  pinMode(in, INPUT);
  digitalWrite(out1, LOW);
  digitalWrite(out2, LOW);
  digitalWrite(out3, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(out3, LOW);
  delay(1000);
  if (digitalRead(in) == HIGH) digitalWrite(out1, HIGH);
  delay(1000);
  digitalWrite(out1, LOW);
  delay(1000);
  if (digitalRead(in) == HIGH) digitalWrite(out2, HIGH);
  delay(1000);
  digitalWrite(out2, LOW);
  delay(1000);
  if (digitalRead(in) == HIGH) digitalWrite(out3, HIGH);
  delay(1000);
}
