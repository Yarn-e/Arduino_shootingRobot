/**
 * Shoot the cannon at the new x,y position
 * 
 * @param int xToShoot
 *   The x position to shoot to
 * @param int yToShoot
 *   The y position to shoot to
 */
void shootAtPos(int xToShoot, int yToShoot) {
    //gridX = rotateCannonToX(xToShoot);
    //gridY = moveCannonToY(yToShoot);
    
    ShootBall();
}

/**
 * Shoot the ball.
 */
void ShootBall() {
  delay(2000);

  sSerial.write("ballshot");
}
