
int LED_PINS[]{1, 2};

void setup() {
  for(int x = 0; x < 2; x++){
    pinMode(LED_PINS[x], OUTPUT);
  } 
  digitalWrite(1, HIGH);
}

void loop() {
  unsigned long timePassed = millis();
  if(timePassed > 10000){
    digitalWrite(2, HIGH);
    digitalWrite(1, LOW);
  }
}
