// 433mhz transmitter setup
RH_ASK driver;

void setupComm() {
  // Initialise 433mhz
  if (!driver.init()) {
    Serial.println("init failed");
  }
}

/**
   Decode the recieved message and shoot at the new position
*/
void decodeMessageAndShoot(String message) {
  int firstNumber = message.indexOf(':');
  int secondNumber = message.indexOf(':', firstNumber + 1);

  String xToShootTo = message.substring((firstNumber) + 1, (firstNumber + 6));
  String yToShootTo = message.substring((secondNumber) + 1, (secondNumber + 6));

  sSerial.write("robotinpos");
  shootAtPos(xToShootTo.toInt(), yToShootTo.toInt());
}

/**
   Convert the current position to a uniform length

   @param String pos
     The position that needs converting

   @return String pos
     The converted position
*/
String convertPosToRightLength(String pos) {
  while (pos.length() != 4) {
    pos = "0" + pos;
  }
  return pos;
}

/**
   Send the new position that the moving robot has to move to.

   @param int xpos
     The current X position
   @param int ypos
     The current Y position
*/
void sendMovingCarNewPos(int xpos, int ypos) {
  Serial.println("Sending data");
  String message = "X:" + convertPosToRightLength(String(xpos)) + " Y:" + convertPosToRightLength(String(ypos));
  const char *msg = message.c_str();
  Serial.println(message);
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  delay(1000);
}

void checkMessage() {
  uint8_t buf[44];
  uint8_t buflen = sizeof(buf);
  if (driver.recv(buf, &buflen)) // Non-blocking
  {
    //If we get a message, this means our robot has moved to the right position
    decodeMessageAndShoot(buf);
  }
}

