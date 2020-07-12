#define servo 7
const int DCwater_pump = 8;

int trigPin1=3;
int echoPin1=4;

int trigPin2=5;
int echoPin2=6;

int ledred = 9;
int ledgreen = 2;


int count = 0;
int pos = 0;    // variable to store the servo position
int state_val = 0;

#include <Servo.h>
Servo myservo;    // create servo object to control a servo


void setup() {
  Serial.begin (9600);
  pinMode(ledred, OUTPUT);
  pinMode(ledgreen, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  digitalWrite(ledred, HIGH); 
  digitalWrite(ledgreen, HIGH); 
   myservo.attach(servo);     // attaches the servo on pin 9 to the servo object 
   myservo.write(0);         // Sets Servo to initially 0 degrees 
}

void loop() {
  //Remove this delay finally
  long duration1, distance1;

  
  
  digitalWrite(trigPin1, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;

   if (distance1 >= 500 || distance1 <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print ( "Sensor1  ");
    Serial.print ( distance1);
    Serial.println("cm");
  }

if (distance1 < 20)
 {
  digitalWrite(DCwater_pump,HIGH);
  Serial.println ( "Pump Turned on");
  Serial.println ( "Servo at 90 Degree");
  if (count == 0){
 myservo.write(70);
 count = 1;
   digitalWrite(ledred, HIGH); 
  digitalWrite(ledgreen, LOW); 
  }
  delay(120);
  digitalWrite(DCwater_pump,LOW);
  delay(1000);
}
else
{
   digitalWrite(DCwater_pump,LOW);
   Serial.println ( "Pump Turned off");
   count = 0;
  }
  
  delay(50);
long duration2, distance2;
  digitalWrite(trigPin2, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2= (duration2/2) / 29.1;

   if (distance2 >= 500 || distance2 <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print("Sensor2  ");
    Serial.print(distance2);
    Serial.println("cm");
  }
  if (distance2 < 70)
{
  delay(1000);
  myservo.write(00);
  Serial.println ( "Servo at 0 Degree");
    digitalWrite(ledred, LOW); 
  digitalWrite(ledgreen, HIGH); 
}
  delay(50);
}
