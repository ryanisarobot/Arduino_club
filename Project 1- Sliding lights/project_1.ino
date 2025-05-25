int numbers[10] ={1, 2, 3 ,4 ,5 ,6, 7, 8, 9, 10};
#define POTENTIOMETER_PIN A1

void setup() {
  for(int x = 0; x < 10; x++){
    pinMode(numbers[x], OUTPUT);
  }
  pinMode(POTENTIOMETER_PIN, INPUT);
}

void loop() {
  for(int y = 0; y < 10; y++){
    digitalWrite(numbers[y], HIGH);
    if(y > 0){
    digitalWrite(numbers[y - 1], LOW);
    }
    unsigned long interval = analogRead(POTENTIOMETER_PIN) / 4;
    delay(interval);
  }
  for(int z = 9; z >= 0; z--){
    digitalWrite(numbers[z], HIGH);
    if(z < 9){
    digitalWrite(numbers[z + 1], LOW);
    }
    unsigned long interval = analogRead(POTENTIOMETER_PIN) / 4;
    delay(interval);
  }
}

