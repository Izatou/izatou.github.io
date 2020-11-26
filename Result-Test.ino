
#include <Servo.h>

const int echoPin = 2;
const int trigPin = 3;
int ledPin = 6;
int flag=0;

long duration;
int distance;
 
int servoPin = 5;
 
Servo servo;  
 
 
void setup()
  {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  analogWrite(ledPin, 100);
  Serial.begin(9600); 
  servo.attach(servoPin);
}
 
 
void loop(){
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance= duration*0.034/2;
delay(10);
if(distance<10) {   
   analogWrite(ledPin, 100);
   if (flag==1){
   servo.write(100);     
   delay(1000);    
   servo.write(90); 
   flag=0;
   }
   Serial.print("Jarak =  ");
   Serial.print(distance);
   Serial.println(" ~ AWAS!! ");}
   
else {
   analogWrite(ledPin, 0);
   if (flag==0){flag=1;
   servo.write(80);
   delay(1000);         
   servo.write(90);     
   }
   Serial.print("Jarak =  ");
   Serial.print(distance);
   Serial.println(" ~ AMAN");
   }
}
