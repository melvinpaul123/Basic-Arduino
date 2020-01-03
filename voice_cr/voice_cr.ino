#include <AFMotor.h>

//initial motors pin
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor1(1, MOTOR12_1KHZ);

String voice; 

void setup() 
{       
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
}

void loop(){
    while (Serial.available()){ //Check if there is an available byte to read
     delay(10); //Delay added to make thing stable 
    char c = Serial.read(); //Conduct a serial read
    if (c == '#') {break;} //Exit the loop when the # is detected after the word
    voice += c; //Shorthand for voice = voice + c
  }
  if (voice.length() > 0){
    if(voice == "forward"){
      forward();
      }
    else if(voice == "backward"){
      backward();
      }
    else if(voice == "right") {
      right();
    }
    else if(voice == "left") {
      left();
    }
    else if(voice =="stop") {
      Stop();
    }
  voice=""; //Reset the variable after initiating
  }
}

void forward()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(255);//Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  delay(600);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void backward()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  delay(600);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void left()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(FORWARD);  //rotate the motor clockwise
  delay(600);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void right()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  delay(600);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
} 

void Stop()
{
  motor1.setSpeed(0); //Define minimum velocity
  motor1.run(RELEASE); //stop the motor when release the button
  motor2.setSpeed(0); //Define minimum velocity
  motor2.run(RELEASE); //stop the motor when release the button
}
