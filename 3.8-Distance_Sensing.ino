int echoPin = 7;
int trigPin = 8;

long duration, cm, inches;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 
  digitalWrite(trigPin,LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
 
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
 
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74;
 
 
 
 
 
 
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
 
  delay(250);
  if (cm<10) {
    analogWrite(11, 255);
    analogWrite(10, 0);
    analogWrite(6, 0);
  }
  else if (cm>10 && cm<30) {
    analogWrite(11, 255);
    analogWrite(10, 255);
    analogWrite(6, 0);
  }
  else {
    analogWrite(11, 0);
    analogWrite(10, 255);
    analogWrite(6, 0);
  }
}
