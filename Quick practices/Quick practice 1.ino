int LED_PINS[]{1, 2};

void setup() {
  for(int x = 0; x < 2; x++){
    pinMode(LED_PINS[x], OUTPUT);
  } 
  digitalWrite(LED_PINS[0], HIGH);
}

void loop() {
  unsigned long timePassed = millis();
  if(timePassed > 5000){
    digitalWrite(LED_PINS[1], HIGH);
    digitalWrite(LED_PINS[0], LOW);
  }
}
