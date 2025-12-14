int in1=2, in2=3, in3=4, in4=5;

void setup() {
  pinMode(in1,OUTPUT); pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT); pinMode(in4,OUTPUT);
}

void loop() {
  // try one direction
  digitalWrite(in1,LOW);  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH); digitalWrite(in4,LOW);
  delay(2000);

  // stop
  digitalWrite(in1,LOW); digitalWrite(in2,LOW);
  digitalWrite(in3,LOW); digitalWrite(in4,LOW);
  delay(1000);

  // try opposite direction
  digitalWrite(in1,HIGH); digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);  digitalWrite(in4,HIGH);
  delay(2000);

  // stop
  digitalWrite(in1,LOW); digitalWrite(in2,LOW);
  digitalWrite(in3,LOW); digitalWrite(in4,LOW);
  delay(1000);
}
