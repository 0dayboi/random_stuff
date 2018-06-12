#include <NewPing.h>
#include <Servo.h>
#define TRIGGER_PIN  12  
#define ECHO_PIN     13  
#define MAX_DISTANCE 500 
//Servo Left : 115, Servo Right : 15, Servo Forward : 60
//M1 : LEFT, M2 : Right
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
Servo myservo;

int M1 = 6;
int M2 = 9;
int distance;

int right_dis;
int left_dis;


void setup() {
  Serial.begin(115200);
  myservo.attach(11);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  myservo.write(60);
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

