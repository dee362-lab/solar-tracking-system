#include<ESP32Servo.h>

//pin define
const int ldr1=26;
const int ldr2=25;
const int servopin=5;
int angle=0;


Servo myservo;

void setup() {
 
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  myservo.attach(servopin);
  myservo.write(90);

}

void loop() {
  
  int val1;
  int val2;
  val1=analogRead(ldr1);
  val2=analogRead(ldr2);
  Serial.println(val1);
  Serial.println(val2);

  //for rotating in east side 
  if(val1>val2){
  angle-=1;
  myservo.write(angle);
  }

  //for rotating in west side
  if(val1<val2){
    angle+=5;
    myservo.write(angle);
  }

  Serial.println(angle);
  delay(300);
}
