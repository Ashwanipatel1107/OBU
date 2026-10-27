#include<NewPing.h>
#include<AFMotor.h>

#define RIGHT A2           
#define LEFT A3
#define TRIGGER_PIN A4
#define ECHO_PIN A5                        
#define MAX_DISTANCE 200
#define maxSpeed 120

unsigned int distance = 0;
unsigned int Right_Value = 0;
unsigned int Left_Value = 0; 

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

AF_DCMotor Motor1(1,MOTOR12_1KHZ);
AF_DCMotor Motor2(2,MOTOR12_1KHZ);
AF_DCMotor Motor3(3,MOTOR12_1KHZ);
AF_DCMotor Motor4(4,MOTOR34_1KHZ);

void setup() {
  Serial.begin(9600);
  pinMode(RIGHT, INPUT); 
  pinMode(LEFT, INPUT);
}

void loop() {
  delay(50);  
  distance = sonar.ping_cm();
  Serial.print("distance");                   
  Serial.println(distance);

  Right_Value = digitalRead(RIGHT);  
  Left_Value = digitalRead(LEFT);
  Serial.print("RIGHT");                      
  Serial.println(Right_Value); 
  Serial.print("LEFT");                       
  Serial.println(Left_Value);

if(((distance > 3) && (distance < 15)) || (Right_Value==1)&&(Left_Value==1) ){     
  //Move Forward:
  Motor1.setSpeed(maxSpeed);
    //define motor1 speed:
  Motor1.run(FORWARD);   //rotate motor1 clockwise:
  Motor2.run(FORWARD);   //rotate motor2 clockwise:


  Motor4.setSpeed(maxSpeed);  //define motor4 speed:
  Motor4.run(FORWARD);   //rotate motor4 clockwise:
  Motor3.run(FORWARD);   //rotate motor3 clockwise:
  
}else if((Right_Value==0) && (Left_Value==1)) {   //If the condition is 'true' then the statement below will execute:
  
  //Turn Left                                                
  Motor1.setSpeed(maxSpeed);  //define motor1 speed:
  Motor2.setSpeed(maxSpeed);
  Motor1.run(BACKWARD);   //rotate motor1 cloclwise:
  Motor2.run(BACKWARD);   //rotate motor2 cloclwise:

  Motor4.setSpeed(maxSpeed);  //define motor4 speed:
  Motor3.setSpeed(maxSpeed);
  Motor4.run(FORWARD);  //rotate motor4 anticlockwise:
  Motor3.run(FORWARD);  //rotate motor3 anticlockwise:
  delay(150);
  
}else if((Right_Value==1)&&(Left_Value==0)) {     //If the condition is 'true' then the statement below will execute:
  

  
  //Turn Right
  Motor1.setSpeed(maxSpeed);  //define motor1 speed:
  Motor2.setSpeed(maxSpeed);
  Motor1.run(FORWARD);  //rotate motor1 anticlockwise:
  Motor2.run(FORWARD);  //rotate motor2 anticlockwise:

  Motor4.setSpeed(maxSpeed);  //define motor4 speed:
  Motor3.setSpeed(maxSpeed);
  Motor4.run(BACKWARD);   //rotate motor4 clockwise:
  Motor3.run(BACKWARD);   //rotate motor3 clockwise:
  delay(150);
  
}else if(distance > 15 || distance <=3) {                          //If the condition is 'true' then the statement below will execute:
  
  //Stop
  Motor1.setSpeed(0);    //define motor1 speed:
  Motor2.setSpeed(0);
  Motor1.run(RELEASE);   //stop motor1:
  Motor2.run(RELEASE);   //stop motor1:

  Motor4.setSpeed(0);    //define motor4 speed:
  Motor3.setSpeed(0);
  Motor4.run(RELEASE);   //stop motor4:
  Motor3.run(RELEASE);   //stop motor1:
}

}
