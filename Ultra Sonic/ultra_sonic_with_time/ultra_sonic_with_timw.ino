unsigned int t1;
unsigned int t2;
unsigned int t3;

int trigpin_first=12;
int echopin_first=13;
int trigpin_second=10;
int echopin_second=9;
//int echopin_first=9;
int first_power=8;
int second_power=7;
int first_ground=6;
int second_ground=5;
float pingtime_first;
float targetdistance_first;
float pingtime_second;
float targetdistance_second;
float speedofsound=776.5;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigpin_first,OUTPUT);
  pinMode(echopin_first,INPUT);
  pinMode(trigpin_second,OUTPUT);
  pinMode(echopin_second,INPUT);
  pinMode(first_power,OUTPUT);
  pinMode(first_ground,OUTPUT);
  pinMode(second_power,OUTPUT);
  pinMode(second_ground,OUTPUT);
}
int distance_first(){
      digitalWrite(trigpin_first,LOW);
      delayMicroseconds(2000);
      digitalWrite(trigpin_first,HIGH);
      delayMicroseconds(15);
      digitalWrite(trigpin_first,LOW);
      pingtime_first=pulseIn(echopin_first,HIGH);
      pingtime_first=pingtime_first/1000000;
      pingtime_first=pingtime_first/3600;

      targetdistance_first=speedofsound*pingtime_first;
      targetdistance_first=targetdistance_first/2;
      targetdistance_first=targetdistance_first*63360;
      return targetdistance_first;
}
int distance_second(){
      digitalWrite(trigpin_second,LOW);
      delayMicroseconds(2000);
      digitalWrite(trigpin_second,HIGH);
      delayMicroseconds(15);
      digitalWrite(trigpin_second,LOW);
      pingtime_second=pulseIn(echopin_second,HIGH);
      pingtime_second=pingtime_second/1000000;
      pingtime_second=pingtime_second/3600;

      targetdistance_second=speedofsound*pingtime_second;
      targetdistance_second=targetdistance_second/2;
      targetdistance_second=targetdistance_second*63360;
      return targetdistance_second;
}
void loop() {
  // put your main code here, to run repeatedly:
      digitalWrite(first_ground,LOW);
      digitalWrite(second_ground,LOW);
      digitalWrite(first_power,HIGH);
      digitalWrite(second_power,HIGH);
      t1=millis();
      Serial.print("first call distance:");
      Serial.println(distance_first());
      t2=millis();
      Serial.print("second call distance:");
      Serial.println(distance_second());
      t3=millis();
      Serial.print("t2-t1 = ");
      Serial.println(t2-t1);
      Serial.print("t3-t2 = ");
      Serial.println(t3-t2);
      delay(1000);
}
