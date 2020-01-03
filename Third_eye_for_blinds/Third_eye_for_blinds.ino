int trigPin=2;
int echoPin=3;
int buzz=11;
void setup() {
     Serial.begin(9600);
     Serial.println("Device Started");
     pinMode(trigPin,OUTPUT);
     pinMode(echoPin,INPUT);
     pinMode(buzz,OUTPUT);
}

void loop() {
     Serial.println(getDistanceFromSensor(trigPin,echoPin));
     int cm=getDistanceFromSensor(trigPin,echoPin);
     if(cm<=50 && cm>0)   
     {   
      int d= map(cm, 1, 100, 20, 2000);   
      digitalWrite(buzz, HIGH);   
      delay(100);   
      digitalWrite(buzz, LOW);   
      delay(d);  
  }
}

long int getDistanceFromSensor(int trig, int echo){
  long duration,distance;
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance=(duration/2)/29.1;
  if(distance>400){
    distance=400;}
  return distance;
  }
