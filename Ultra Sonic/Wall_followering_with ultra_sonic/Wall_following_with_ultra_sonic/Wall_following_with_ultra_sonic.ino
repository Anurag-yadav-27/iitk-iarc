const int trig_pin1=4;
const int echo_pin1=5;
int int1=6;
int int2=9;
int int3=12;
int int4=13;
int motor1_enable=10;
int motor2_enable=11;
const int trig_pin2=7;
const int echo_pin2=8;
void setup(){
  Serial.begin(9600);
  pinMode(3,HIGH);
  pinMode(trig_pin1,OUTPUT);
  pinMode(echo_pin1,INPUT);
  pinMode(int1,OUTPUT);
  pinMode(trig_pin2,OUTPUT);
  pinMode(echo_pin2,INPUT);
  pinMode(int2,OUTPUT);
  pinMode(int3,OUTPUT);
  pinMode(int4,OUTPUT);
  pinMode(motor1_enable,OUTPUT);
  pinMode(motor2_enable,OUTPUT);
}
int first_uv(){
  digitalWrite(trig_pin1,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin1,HIGH);
  delayMicroseconds(8);

  float duration1,distance1;
  duration1=pulseIn(echo_pin1,HIGH);
  distance1=(duration1*0.0343)/2;
  Serial.print("distance1: ");
  Serial.println(distance1);
  delay(1000);
  return distance1;
}
int second_uv(){
  digitalWrite(trig_pin2,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin2,HIGH);
  delayMicroseconds(8);

  float duration2,distance2;
  duration2=pulseIn(echo_pin2,HIGH);
  distance2=(duration2*0.0343)/2;
  Serial.print("distance2: ");
  Serial.println(distance2);
  delay(1000);
  return distance2;
}
void loop(){
  float distance1,distance2;
  distance1=first_uv();
  distance2=second_uv();
  digitalWrite(int1,HIGH);
  digitalWrite(int2,LOW);
  digitalWrite(int3,HIGH);
  digitalWrite(int4,LOW);
  if(6<=distance1<=10 && 6<=distance2<=10)
  { Serial.print("distance 1 ==:");
  Serial.print(distance1);
  Serial.print("      ");
  Serial.print("distance2=");
  Serial.println(distance2);
    if(distance1>distance2){
      analogWrite(motor1_enable,150);
      analogWrite(motor2_enable,125);
      Serial.println("taking slight right");
    }
    else if(distance1<distance2){
      analogWrite(motor2_enable,150);
      analogWrite(motor1_enable,125);
      Serial.println("taking slight left");
    }
    else{
      analogWrite(motor1_enable,125);
      analogWrite(motor2_enable,125);
      Serial.println("no error");
    }
  }
}
