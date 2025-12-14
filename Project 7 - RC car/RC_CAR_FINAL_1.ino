#include<IRremote.hpp> // Libary that gives us teh functions and
const int RemotePin = 8; // What pin we will set the inputs that the IR sensor recieves to go to
int in1 = 2;
int in2 = 3;
int in3 = 4;
int in4 = 5;
unsigned long timesincelastinput = 0;
const unsigned long delaytime = 200;

void setup() {
Serial.begin(9600);
IrReceiver.begin(RemotePin, ENABLE_LED_FEEDBACK);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
timesincelastinput = millis(); // initialize baseline
}

void loop() {
  if(IrReceiver.decode()) // The function inside checks if there has been a signal and returns TRUE or FALSE
  {
    unsigned long code = IrReceiver.decodedIRData.decodedRawData;

    if (code==0xB946FF00)//Press UP Button, this code is the hex code for the specific up button
    {
      Forward();
    }
    else if (code==0xEA15FF00)//Press Down Button
    {
      Backward();
    }
    else if (code==0xBB44FF00)//Press Left Button
    {
      Left();
    }
    else if (code==0xBC43FF00)//Press Right Button
    {
      Right();
    }
    else if (code==0xBA45FF00)//Stop
    {
      Stop();
    }
    timesincelastinput = millis();
    IrReceiver.resume(); // Returns that it is done processing and is ready for a new input
  }
  else if (millis() - timesincelastinput > delaytime)
  {
    Stop();
    timesincelastinput = millis();
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
void Left()
{
digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
}
void Right()
{
  // LEFT
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
  // RIGHT
digitalWrite(in3,LOW);
digitalWrite(in4,HIGH);
}