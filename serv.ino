Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Servo setup
#define ARMSERVO 0
#define ROTATESERVO 1
// Servo min and max
#define SERVOMIN  100
#define SERVOMAX  1300

// Motor shooting speed
const int SHOOTING_SPEED = 150;
const int ROTATE_SPEED = 50;
const int SPEED_LEFT = 0;
const int SPEED_RIGHT = 2;

void setupServo() {
  pwm.begin();
  pwm.setPWMFreq(60);  
}


void rotateArm(int deg) {
  Serial.print("Rotating arm to deg: ");
  Serial.println(deg);
  rotateServo(deg, ARMSERVO);
}

void rotatePlatform(int deg) {
  Serial.print("Rotating platform to deg: ");
  Serial.println(deg);
  rotateServo(deg, ROTATESERVO);  
}


void rotateServo(int deg, int servo) {
  // Convert degrees to pulselength
  int pulselength = map(deg, 0, 180, SERVOMIN, SERVOMAX);

  //Move servo to set position
  for (uint16_t pulselen = SERVOMIN; pulselen < pulselength; pulselen++) {
    pwm.setPWM(servo, 0, pulselen);
  }
}

