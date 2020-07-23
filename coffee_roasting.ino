/*
# L298N motor driver Arduino code for coffee roasting
#L298N for max. 2A DC motor
# Author: @programmer from kahvekulubu.net forum.
# Date: July 2020
*/
#define MOTOR_PWM 9
#define MOTOR1 6
#define MOTOR2 7
#define WAIT_TIME 60
#define MAX_SPEED 255
// Roasting time - second
#define ROASTING_TIME 600
#define CLOCK_WISE HIGH

void accelerate(){
 for(int i=0;i<=MAX_SPEED;i++) {
   analogWrite(MOTOR_PWM,i);
   delay(WAIT_TIME);  
 } 
}
void slowStop(){
 for(int i=MAX_SPEED;i>=0;i--) {
   analogWrite(MOTOR_PWM,i);
   delay(WAIT_TIME);  
 } 
}
void clockWise(){

  digitalWrite(MOTOR1, CLOCK_WISE);
  digitalWrite(MOTOR2, !CLOCK_WISE);
}
void counterClockWise()
{
  digitalWrite(MOTOR1, !CLOCK_WISE);
  digitalWrite(MOTOR2, CLOCK_WISE);
}
void disableMotor()
{
  digitalWrite(MOTOR1, LOW);
  digitalWrite(MOTOR2, LOW);
}
void setup() {
  disableMotor();
  clockWise();
  accelerate();
  for(int i=0;i<ROASTING_TIME;i++) {
    delay(1000);
  }
  slowStop();  
  disableMotor();
}
void loop() {
  for(;;){
    ;
  }
}
