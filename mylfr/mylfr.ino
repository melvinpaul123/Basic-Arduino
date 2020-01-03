#include <AFMotor.h>

#define MAX_SPEED 100 // sets speed of DC  motors
#define MAX_SPEED_OFFSET 20

AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor1(1, MOTOR12_1KHZ);

int LeftSensor = A4;
int RightSensor = A5;
int L_sensor_val = 0;
int R_sensor_val = 0;
int speedSet = 0;

int threshold = 500;

void setup(){
  delay(2000);
  //motor1.setSpeed(70);
  //motor2.setSpeed(70);
}
void loop(){
  L_sensor_val = analogRead(LeftSensor);
  R_sensor_val = analogRead(RightSensor);

  if(L_sensor_val>threshold && R_sensor_val>threshold){
    motor2.run(FORWARD);
    motor1.run(FORWARD);
    for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
   {
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    delay(5);
   }
  }
  if(L_sensor_val<threshold && R_sensor_val<threshold){
    motor2.run(RELEASE);
    motor1.run(RELEASE);
  }
  if(L_sensor_val<threshold && R_sensor_val>threshold){
    motor2.run(FORWARD);
    motor1.run(BACKWARD);
  }
  if(L_sensor_val>threshold && R_sensor_val<threshold){
    motor2.run(BACKWARD);
    motor1.run(FORWARD);
  }
}
