int ledPins[7] = {2, 3, 4, 5, 7, 8, 6};
int dicePatterns[7][7] = {
  {0, 0, 0, 0, 0, 0, 1}, // Displays 1
  {0, 0, 1, 1, 0, 0, 0}, // Displays 2
  {0, 0, 1, 1, 0, 0, 1}, // Displays 3
  {1, 0, 1, 1, 0, 1, 0}, // Displays 4
  {1, 0, 1, 1, 0, 1, 1}, // Displays 5
  {1, 1, 1, 1, 1, 1, 0}, // Displays 6
  {0, 0, 0, 0, 0, 0, 0}  // Displays blank
};

int switchPin = 9;
int blank = 6;

void setup(){

  for(int i = 0; i < 7; i++){ // Efficient way to set pins to output and turn off all LEDs
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
  pinMode(switchPin, INPUT); // Sets the button to be recognized as input
  randomSeed(analogRead(0)); // Sets the Arduino randomization to be truly randomized (other seeds will be biased)
}

void loop(){
  if(digitalRead(switchPin)){
    rollTheDice(); // What is rollTheDice? It's the function that we later define
  }
  delay(100);
}

void rollTheDice(){
  int result = 0;
  int lengthOfRoll = random(15, 25); // Random time it will take to roll
  for(int i = 0; i < lengthOfRoll; i++){ // This rolling animation attempts to make itself realistic
    result = random(0, 6);
    show(result);
    delay(50 + i * 10);
  }
  for (int j = 0; j < 3; j++){ // Flashes number once rolling animation is done
    show(blank);
    delay(500);
    show(result);
    delay(500);
  }
}

void show(int result){ // The reason we create seperate functions is simply due to convenience and not repeating this over and over
  for(int i = 0; i < 7; i++){
    digitalWrite(ledPins[i], dicePatterns[result][i]);
  }
}
