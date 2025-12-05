#include <IRremote.hpp>
const int RemotePin = 8;
IRrecv irrecv(RemotePin);
decode_results results;
void setup() {
  Serial.begin(9600);
  IrReceiver.begin(RemotePin, ENABLE_LED_FEEDBACK); // Tells the IR sensor to start recieving signals
}

void loop() {
  if (IrReceiver.decode()) { // Turns the infared signal into the HEX code
    // Print the decoded 32-bit value in HEX
    Serial.print("Code: 0x");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);

    IrReceiver.resume();   // prepare for the next code
    delay(200);
  }
}
