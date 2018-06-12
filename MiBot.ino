/* Written By : 0dayboi
* This code is used for arduino obstacle aviodance robot with servo motor, the ultrasound sensor connected to the servo motor will check
* both right side and left side and decide where to turn. To use this code you must have intermediate knowleadge about arduino, servo motor
* arduino (i did with uno), L928H Motor Drive (Works with any motor drive), 2x DC Motors, Ultrasound Sensor.
*/


#include <NewPing.h>
#include <Servo.h>
#define TRIGGER_PIN  12  
#define ECHO_PIN     13  
#define MAX_DISTANCE 500 
//Servo Left : 115, Servo Right : 15, Servo Forward : 60 (I Did this my way, but you can change this)
//M1 : LEFT, M2 : Right
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
Servo myservo;

int M1 = 6;
int M2 = 9;
int distance;

int right_dis;
int left_dis;


void setup() {
  Serial.begin(115200); //Begin Serial
  myservo.attach(11);   //Define the pin of servo motor
  pinMode(M1, OUTPUT);  //Define that motor pins are going for output.
  pinMode(M2, OUTPUT);
  myservo.write(60); //make the servo straight, 60 degree angle was for me , you can make however you want.
}

void loop() {
  delay(100);
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  unsigned int uS = sonar.ping(); 
  distance = uS / US_ROUNDTRIP_CM;
  Serial.println(distance); 

  if (distance < 30 && distance > 0) {
    myservo.write(15); //turn right
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
    delay(750);
    uS = sonar.ping();
    delay(100); 
     distance = uS / US_ROUNDTRIP_CM;
    right_dis = distance;
    delay(50);
    myservo.write(115); //turn left
    delay(750);
      uS = sonar.ping(); 
       delay(100); 
     distance = uS / US_ROUNDTRIP_CM;
    left_dis = distance;
    delay(50);
    myservo.write(60);
     if (left_dis > 35 && left_dis > 0) { //deciding where to trun
        TurnLeft();
     }else if (right_dis > 35 && right_dis > 0 ) {
        TurnRight();
     }else {
       TurnAround();
     }
      
  }
}

void ClearValues() {
  right_dis = 0;
  left_dis = 0;
}

void TurnAround() {
  Serial.println("Around");
digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  delay(600);
  ClearValues();
}
 
void TurnRight() {
  Serial.println("RIGHT");
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  delay(250);
   ClearValues();
}

void TurnLeft() {
  Serial.println("LEFT");
   digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  delay(250);
   ClearValues();
  }

