// Including libraries
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <RH_ASK.h>
#include <SPI.h>
#include <SoftwareSerial.h>

// Globals for rotate and shooting
int gridX = 0;
int gridY = 0;

void setup() {
  Serial.begin(9600);
  setupServo();
  setupComm();
  setupBackend();
}

void loop() {
  checkMessage();
  testMessage();
  delay(5000);
}
