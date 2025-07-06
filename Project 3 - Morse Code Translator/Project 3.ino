int ledPin = 12;

char* letters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
"..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.","--.-",
".-.", "...", "-", "..-", ".--", "...-", ".--", "-..-", "-.--", "--.."}; // Array of all letters

char* numbers[] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."}; // Array of all numbers

int dotDelay = 200;

void setup(){
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  char ch; //initializes variable for a single letter/number
  if (Serial.available()){ // Checks if there any characters that have been input into the Serial monitor 
    ch = Serial.read(); //Reads one letter
    if (ch >= 'a' && ch <= 'z'){ // Checks if it is lowercase 
      flashSequence(letters[ch - 'a']);
    }
    else if (ch >= 'A' && ch <= 'Z'){ // Checks if it is uppercase
      flashSequence(letters[ch - 'A']);
    }
    else if (ch >= '0' && ch <='9'){ // Checks if it is a number
      flashSequence(numbers[ch - '0']);
    }
    else if (ch == ' '){ // Checks if it is empty/space
      delay(dotDelay * 4);
    }
  } 
}

void flashSequence(char* sequence){ // This function expects a string, but it doesn't have to be named sequence, that is just a placeholder name
  int i = 0;
  while (sequence[i] != NULL){ // In every string, there is a hidden NULL at the send to signal to the machine that that string has ended
    flashDotOrDash(sequence[i]);
    i++;
  }
  delay(dotDelay * 3);
}

void flashDotOrDash(char dotOrDash){
  digitalWrite(ledPin, HIGH);
  if (dotOrDash == '.'){
    delay(dotDelay);
  }
  else{ // Anything other than . is a -
    delay(dotDelay * 3);
  }
  digitalWrite(ledPin, LOW);
  delay(dotDelay);
}
