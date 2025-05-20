#define POTENTIOMETER_PIN A2
#define LED_1 1
#define LED_2 2
#define LED_3 3
#define LED_4 4
#define LED_5 5
#define LED_6 6
#define LED_7 7
#define LED_8 8
#define LED_9 9
#define LED_10 10
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(POTENTIOMETER_PIN, INPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);
  pinMode(LED_6, OUTPUT);
  pinMode(LED_7, OUTPUT);
  pinMode(LED_8, OUTPUT);
  pinMode(LED_9, OUTPUT);
  pinMode(LED_10, OUTPUT);
}

void loop() {
 Serial.println(analogRead(POTENTIOMETER_PIN));
  if(analogRead(POTENTIOMETER_PIN) < 80){
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, LOW);
  }
  if(81 < analogRead(POTENTIOMETER_PIN) && analogRead(POTENTIOMETER_PIN) < 161){
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, LOW);
  }
  if(162 < analogRead(POTENTIOMETER_PIN) && analogRead(POTENTIOMETER_PIN) < 242){
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, LOW);
  }
  if(243 < analogRead(POTENTIOMETER_PIN) && analogRead(POTENTIOMETER_PIN) < 323){
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, HIGH);
    digitalWrite(LED_5, LOW);
  }
  if(324 < analogRead(POTENTIOMETER_PIN) && analogRead(POTENTIOMETER_PIN) < 404){
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, HIGH);
    digitalWrite(LED_5, HIGH);
    digitalWrite(LED_6, LOW);
  }
  if(405 < analogRead(POTENTIOMETER_PIN) && analogRead(POTENTIOMETER_PIN) < 485){
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, HIGH);
    digitalWrite(LED_5, HIGH);
    digitalWrite(LED_6, HIGH);
    digitalWrite(LED_7, LOW);
  }
  if(486 < analogRead(POTENTIOMETER_PIN) && analogRead(POTENTIOMETER_PIN) < 566){
    digitalWrite(LED_4, LOW);
    digitalWrite(LED_5, HIGH);
    digitalWrite(LED_6, HIGH);
    digitalWrite(LED_7, HIGH);
    digitalWrite(LED_8, LOW);
  }
  if(567 < analogRead(POTENTIOMETER_PIN) && analogRead(POTENTIOMETER_PIN) < 647){
    digitalWrite(LED_5, LOW);
    digitalWrite(LED_6, HIGH);
    digitalWrite(LED_7, HIGH);
    digitalWrite(LED_8, HIGH);
    digitalWrite(LED_9, LOW);
  }
  if(648 < analogRead(POTENTIOMETER_PIN) && analogRead(POTENTIOMETER_PIN) < 728){
    digitalWrite(LED_6, LOW);
    digitalWrite(LED_7, HIGH);
    digitalWrite(LED_8, HIGH);
    digitalWrite(LED_9, HIGH);
    digitalWrite(LED_10, LOW);
  }
  if(729 < analogRead(POTENTIOMETER_PIN) && analogRead(POTENTIOMETER_PIN) < 809){
    digitalWrite(LED_7, LOW);
    digitalWrite(LED_8, HIGH);
    digitalWrite(LED_9, HIGH);
    digitalWrite(LED_10, HIGH);
  }
  if(810 < analogRead(POTENTIOMETER_PIN) && analogRead(POTENTIOMETER_PIN) < 890){
    digitalWrite(LED_8, LOW);
    digitalWrite(LED_9, HIGH);
    digitalWrite(LED_10, HIGH);
  }
  if(891 < analogRead(POTENTIOMETER_PIN) && analogRead(POTENTIOMETER_PIN) < 971){
    digitalWrite(LED_9, LOW);
    digitalWrite(LED_10, HIGH);
  }
  if(972 < analogRead(POTENTIOMETER_PIN) && analogRead(POTENTIOMETER_PIN) < 1023){
    digitalWrite(LED_10, LOW);
  }
}
