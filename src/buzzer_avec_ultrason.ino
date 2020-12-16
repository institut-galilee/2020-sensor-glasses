/*
 * Author: Elecrow Engle
 * Date:7/21/2017
 * IDE V1.8.2 
 * Email:engle@elecrow.com
 * Function:
 */

const int TrigPin = 2;
const int EchoPin = 3;
float cm;
#define buzzer 5
void setup(){
  Serial.begin(9600);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}
void loop(){
  digitalWrite(TrigPin, LOW);       
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  cm = pulseIn(EchoPin, HIGH) / 58.0; //The echo time is converted into cm
  cm = (int(cm * 100.0)) / 100.0;     //Keep two decimal places
  Serial.print("Distance\t=\t");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(500);
  if (75 <= cm && cm <= 100){
     tone(buzzer, 400, 100);
     
  }

  else if (50 <= cm && cm < 75){
     tone(buzzer, 400, 200);
  }

  else if (25 <= cm && cm < 50){
     tone(buzzer, 400, 400);
  }

  else if (0<= cm && cm < 25){
     tone(buzzer, 400, 800);
  }
    
}
