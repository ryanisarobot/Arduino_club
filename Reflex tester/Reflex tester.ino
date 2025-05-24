#define RED_PIN 4
#define GREEN_PIN 1
#define BLUE_PIN 2
#define BUTTON_PIN 8

unsigned long set_time;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  randomSeed(analogRead(0)); 
  double set_time = millis() + random(6000, 11000);
  Serial.println(set_time);
  
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  unsigned long time = millis();

  if(time >= 10 && time < 70){
    Serial.println("Welcome to reflex test. Once the light turns green, press the button as fast as you can. Get ready the lights will change any second.");
  }
  if(time >= set_time){
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(RED_PIN, LOW);

    if(buttonState == LOW){
      unsigned long reaction_time = time - set_time;
      Serial.println("You pressed the button in ");
      Serial.println(reaction_time);
      Serial.println(" ms");
    }
  }
}
