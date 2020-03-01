const int s0=4;
const int s1=5;
const int s2=6;
const int s3=7;
const int out=8;
const int vcc=9;
const int led=3;
int red,green,blue;
void setup() {
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(out,INPUT);
  pinMode(vcc,OUTPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  digitalWrite(s0,HIGH);
  digitalWrite(s1,HIGH);
  digitalWrite(vcc,HIGH);
  digitalWrite(led,LOW);
}
void getdata(){
  digitalWrite(s2,LOW);
  digitalWrite(s3,LOW);
  red=pulseIn(out,LOW);
  Serial.print("red:");
  Serial.print(red);
  Serial.print(" ");
  delay(500);
  digitalWrite(s2,LOW);
  digitalWrite(s3,HIGH);
  blue=pulseIn(out,LOW);
  Serial.print("blue:");
  Serial.print(blue);
  Serial.print(" ");
  delay(500);
  digitalWrite(s2,HIGH);
  digitalWrite(s3,HIGH);
  green=pulseIn(out,LOW);
  Serial.print("green:");
  Serial.println(green);
  delay(500);
}
void loop() {
  getdata();
  if(red<green && red<blue && red<300){
    Serial.print("Red");
    Serial.println(" ");
  }
//  else if(blue<red && blue<green && blue<300){
//    Serial.print("Blue");
//    Serial.println(" ");
//  }
  else if(green<red && green<blue && green<300){
    Serial.print("Green");
    Serial.println(" ");
  }
  else{
    Serial.print("Not required color");
    Serial.println(" ");
  }
  delay(500);

}//remaining returnvalue of ......
