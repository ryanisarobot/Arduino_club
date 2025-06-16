// Variable to store the pin that the first LED is at
int currentLED = 4;

// Sets the delay between change in LEDs
int delayTime = 40;

// Stores direction of travel or LEDs
int dir = 1;

// Stores the last time we changed something
long timeChanged = 0;

// Array that holds LED pins (byte is for small range of numbers)
byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

void setup() {
  // Sets all the pins to output, very efficiently
  for (int i = 0; i < 10; i++){
    pinMode(ledPin[i], OUTPUT);
  }

  // Even though the time for setup is small, to get the most accuracy, we should still do this
  timeChanged = millis();
}

void loop() {
  // Check to see if the time interval between light changes has been met
  if ((millis() - timeChanged) > delayTime){

    // Turns off all LEDs
    for (int i = 0; i < 10; i++){
      digitalWrite(ledPin[i], LOW);
    }

    // Light the current LED
    digitalWrite(ledPin[currentLED], HIGH);

    // Increase the LED sequence (up or down)
    currentLED += dir;

    // Checks if LED is at the end of the row, if so go the other way
    if (currentLED == 13){
      dir = -1;
    }
    if(currentLED == 4){
      dir = 1;
    }
    // Resets timer so that we wait another delayTime until we change LEDs again
    timeChanged = millis();

    delayTime = analogRead(0);
    delay(5)
  }
}
