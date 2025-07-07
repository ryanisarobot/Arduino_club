#include <Keypad.h>

char* secretCode = "2010"; // Enter your own 4 digit code
int position = 0;

const byte rows = 4;
const byte cols = 3; // Lines 6 and 7 are just to set the matrix's dimensions
char keys[rows][cols] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[rows] = {7, 2, 3, 5};
byte colPins[cols] = {6, 8, 4};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols); // If you don't recognize this function it's because it was imported as part of the library, it basically simplifies the process of connecting each number on the pad too the pins

int redPin = 13;
int greenPin = 12;

void setup() {

pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
setLocked(true);

}

void loop() {

  char key = keypad.getKey(); // Again another function from the library that gets the input from the keypad
  if (key == '*' || key == '#'){
    position = 0;
    setLocked(true); // If you look ahead, it may seem odd that we are inputing "false" (on line 43) or "true", but these translate into 0 and 1 respectively
  }

  else if (key == secretCode[position]){
    position++; // Moves along the input, as long as it has been so far corrct
    if (position == 4){
      setLocked(false); 
    }
  }
  else{
    position = 0;
    setLocked(true);
  }
  delay(100);
}

void setLocked(int locked){
  if(locked){ // This may not make sense, but in this coding language any non-zero that is input into an if statement passes the conditional
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
  }
  else{
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
  }
}
