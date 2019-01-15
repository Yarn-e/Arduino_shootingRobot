SoftwareSerial sSerial(3,2);

void setupBackend() {
  sSerial.begin(9600);  
}


void testMessage() {
  sSerial.write("cannonrot");
  Serial.print("Test");
}
