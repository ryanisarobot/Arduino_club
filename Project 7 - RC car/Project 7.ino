#include<IRremote.h> // Libary that gives us teh functions and 
const int RemotePin = 8; // What pin we will set the inputs that the IR sensor recieves to go to
IRrecv irrecv(RemotePin); // This is teh instance of the class that we will define as "our specific IR sensor"
decode_results results; // Holds all information decodes from IR sensor
int in1 = 2;
int in2 = 3;
int in3 = 4;
int in4 = 5;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Simply starts up the IR module
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
    
}

void loop() {
  
    if(irrecv.decode(&results)) // The function inside checks if there has been a signal and returns TRUE or FALSE
      {
        if (results.value==0xFF629D)//Press UP Button, this code is the hex code for the specific up button
        { 
          Forward();
        }
        else if (results.value==0xFFA857)//Press Down Button
        { 
          Backward();
        }
         else if (results.value==0xFF22DD)//Press Left Button
        { 
          Left();
        }
        else if (results.value==0xFFC23D)//Press Right Button
        { 
          Right();
        }
        else if (results.value==0xFF02FD)//Stop
        { 
          Stop();
        }
      irrecv.resume(); // Returns that it is done processing and is ready for a new input
    }
    }
   
 // Movement functions

void Backward()
  {
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  }
 void Forward()
  {
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  }
 void Stop()
  {
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  }
  int Left()
    {
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    }
  int Right()
    {
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    }
