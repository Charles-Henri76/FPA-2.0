#define CW  0
#define CCW 1
#include <HCSR04.h>
#include <Servo.h> 
// Motor definitions to make life easier:
#define MOTOR_A 0
#define MOTOR_B 1
Servo servoMoteur;
int i;
int Distance;
const byte triggerPin = 8;
const byte echoPin = 7;
UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);
const byte PWMA = 3;  // PWM control (speed) for motor A
const byte PWMB = 5; // PWM control (speed) for motor B
const byte DIRA = 2; // Direction control for motor A
const byte DIRB = 4; // Direction control for motor B
const byte vitesse_voit=9.42478*0.03;
void setup() {
  i=1;
  servoMoteur.write(90);
  Serial.begin(9600);
  setupArdumoto();
  servoMoteur.attach(9);
  delay(5000);
  // put your setup code here, to run once:
 }


void loop() {
  // put your main code here, to run repeatedly:
  Distance=distanceSensor.measureDistanceCm();

  if (i==1){
    AvancerDroit();
    delay(1500);
    Arret();
    QuartTourDroite();
    AvancerDroit();
    delay(1500);
    Arret();
    ReculerDroit();
    delay(1500);
    Arret();
    delay(10000);
  }
  if (Distance>40 and i==0){
    servoMoteur.write(90);
    digitalWrite(DIRA,CW);
    digitalWrite(DIRB,CCW);
    analogWrite(PWMA,255); //roue autre coté
    analogWrite(PWMB,173); //roue coté pile
  }
  
  if (Distance<40 and i==0){
    analogWrite(PWMA,0);
    analogWrite(PWMB,0);
    delay(5000);
    servoMoteur.write(180);
    analogWrite(PWMB,120);
    analogWrite(PWMA,0);
    delay(350);
    analogWrite(PWMB,0);
    analogWrite(PWMA,0);
    delay(200);
    analogWrite(PWMA,255); //roue autre coté
    analogWrite(PWMB,173); //roue coté pile
    delay(400);
    analogWrite(PWMB,0);
    analogWrite(PWMA,120);
    delay(350);
    analogWrite(PWMA,255); //roue autre coté
    analogWrite(PWMB,173); //roue coté pile
    delay(400);
    analogWrite(PWMB,0);
    analogWrite(PWMA,120);
    delay(350);
    analogWrite(PWMA,255); //roue autre coté
    analogWrite(PWMB,173); //roue coté pile
    delay(400);
    analogWrite(PWMB,120);
    analogWrite(PWMA,0);
    delay(350);
    analogWrite(PWMA,255); //roue autre coté
    analogWrite(PWMB,173); //roue coté pile
    delay(4000);
  }
  Serial.println(Distance);
}

void Arret(){
    analogWrite(PWMB,0);
    analogWrite(PWMA,0);
    delay(1000);
}

void QuartTourDroite(){
    digitalWrite(DIRB,CCW);
    analogWrite(PWMB,130);
    analogWrite(PWMA,0);
    delay(350);
}

void AvancerDroit(){
    digitalWrite(DIRA,CW);
    digitalWrite(DIRB,CCW);
    analogWrite(PWMA,255); //roue autre coté
    analogWrite(PWMB,173); //roue coté pile
}

void ReculerDroit(){
    digitalWrite(DIRA,CCW);
    digitalWrite(DIRB,CW);
    analogWrite(PWMA,255); //roue autre coté
    analogWrite(PWMB,173); //roue coté pile
}

void QuartTourGauche(){
    analogWrite(PWMB,0);
    analogWrite(PWMA,250);
    delay(415);
    analogWrite(PWMB,0);
    analogWrite(PWMA,0);
    delay(500);
}

void setupArdumoto()
{
  // All pins should be setup as outputs:
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);

  // Initialize all pins as low:
  digitalWrite(PWMA, LOW);
  digitalWrite(PWMB, LOW);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, LOW);
}
