#include <SoftwareSerial.h>

// Motor 1 (left)
#define IN1 2
#define IN2 3

// Motor 2 (right)
#define IN3 4
#define IN4 5

// HC-05 on pins 9 (RX) and 10 (TX)
SoftwareSerial bluetoothSerial(9, 10); // RX, TX

void setup() {
  bluetoothSerial.begin(9600);  // Match HC-05 baud rate

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Start with motors stopped
  Stop();
}

void loop() {
  if (bluetoothSerial.available() > 0) {
    char command = bluetoothSerial.read();

    // optional: print debug over USB if you want later
    // Serial.println(command);
    
    switch (command) {
      case 'F':
        forward();
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
      case 'S':
        stop()
          break;
    }
  }
}

// ====== Movement functions using L298N pins ======

void forward() {
  // Left motor forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Right motor forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void back() {
  // Left motor backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Right motor backward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  // Spin left: left motor backward, right motor forward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  // Spin right: left motor forward, right motor backward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Stop() {
  // All low = coast/stop
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

