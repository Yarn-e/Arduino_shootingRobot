/**
 * Move the cannon structure left or right
 * 
 * @param int direction
 * @param int speed
 *   The speed.
 * @param int duration
 *   How long the cannon has to move left/right
 */
void rotateCannon(int deg) {
  rotateArm(deg);

  // SEND TO BACKEND CANON ROTATED
  sSerial.write("cannonrot");
}

/**
 * Move the cannon arm upwards or downwards
 * 
 * @param int direction
 * @param int speed
 *   The speed.
 * @param int duration
 *   How long the cannon has to move up/down
 */
void moveCannonArm(int deg) {
  rotatePlatform(deg);

  // SEND TO BACKEND CANNON MOVED ITS ARM
  sSerial.write("cannonarm");
}
