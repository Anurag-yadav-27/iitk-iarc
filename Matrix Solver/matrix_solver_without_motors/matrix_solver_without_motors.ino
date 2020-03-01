int IR_1=22;
int IR_2=23;
int IR_3=24;
int IR_4=25;
int IR_5=26;
int IR_6=27;
int power_1=28;
int power_2=29;
int power_3=30;
int power_4=31;
int power_5=32;
int power_6=33;
int ground_1=34;
int ground_2=35;
int ground_3=36;
int ground_4=37;
int ground_5=38;
int ground_6=39;
int arr[4];

void setup() {
  // put your setup code here, to run once:
      pinMode(IR_1,INPUT);
      pinMode(IR_2,INPUT);
      pinMode(IR_3,INPUT);
      pinMode(IR_4,INPUT);
      pinMode(IR_5,INPUT);
      pinMode(IR_6,INPUT);
      pinMode(power_1,OUTPUT);
      pinMode(power_2,OUTPUT);
      pinMode(power_3,OUTPUT);
      pinMode(power_4,OUTPUT);
      pinMode(power_5,OUTPUT);
      pinMode(power_6,OUTPUT);
      pinMode(ground_1,OUTPUT);
      pinMode(ground_2,OUTPUT);
      pinMode(ground_3,OUTPUT);
      pinMode(ground_4,OUTPUT);
      pinMode(ground_5,OUTPUT);
      pinMode(ground_6,OUTPUT);
      Serial.begin(9600);
}

void matrix(){
  arr[0]=digitalRead(IR_2);
  arr[1]=digitalRead(IR_5);
  delay(100);
  arr[2]=digitalRead(IR_5);
  arr[3]=digitalRead(IR_2);
  for (byte i = 0; i < 4; i = i + 1) 
    {
      Serial.println(arr[i]);
    }
  }
      
  

void loop() {
  // put your main code here, to run repeatedly:
      digitalWrite(power_1,HIGH);
      digitalWrite(power_2,HIGH);
      digitalWrite(power_3,HIGH);
      digitalWrite(power_4,HIGH);
      digitalWrite(power_5,HIGH);
      digitalWrite(power_6,HIGH);
      digitalWrite(ground_1,LOW);
      digitalWrite(ground_2,LOW);
      digitalWrite(ground_3,LOW);
      digitalWrite(ground_4,LOW);
      digitalWrite(ground_5,LOW);
      digitalWrite(ground_6,LOW);
      if((digitalRead(IR_1)==0)&&(digitalRead(IR_6)==0)&&(digitalRead(IR_2)==digitalRead(IR_3))&&(digitalRead(IR_4)==digitalRead(IR_5)==1)){
       matrix();
        }
}

























      
    
