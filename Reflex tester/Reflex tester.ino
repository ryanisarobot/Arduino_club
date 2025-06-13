#define RED_PIN 7
#define GREEN_PIN 4
#define BLUE_PIN 2
#define BUTTON_PIN 8

unsigned long set_time;
bool testStarted = false; // Track if the reaction test has officially started

void setup() {
  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  randomSeed(analogRead(0));
  set_time = millis() + random(6000, 11000);

  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  Serial.println("Reaction time test starts soon...");
}

void loop() {
  unsigned long time = millis();
  int buttonState = digitalRead(BUTTON_PIN);

  if (!testStarted && time >= 500) {
    Serial.println("Get ready! Press the button as fast as you can when the light turns GREEN.");
    testStarted = true;
  }

  // Trigger the green light after the random set_time
  if (testStarted && time >= set_time) {
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(RED_PIN, LOW);

    if (buttonState == LOW) { 
      unsigned long reaction_time = time - set_time;
      Serial.print("Your reaction time: ");
      Serial.print(reaction_time);
      Serial.println(" ms");

      delay(2000); // Short pause before restarting test
      restartTest();
    }
  }
}

void restartTest() {
  Serial.println("Restarting...");
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  set_time = millis() + random(6000, 11000);
  testStarted = false;
}

