#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const int s0=3;
const int s1=4;
const int s2=5;
const int s3=6;
const int out=7;
const int vcc=8;
const int led=9;
const int mega_enable=11;
const int m1=12;
const int m2=13;
int red,green,blue;
int x;
void setup() {
 pinMode(mega_enable,OUTPUT);
 pinMode(m1,INPUT);
 pinMode(m2,INPUT);
  pinMode(A0,HIGH);
  pinMode(A1,LOW);
  pinMode(A2,LOW);
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(out,INPUT);
  pinMode(vcc,OUTPUT);
  pinMode(led,LOW);
 // Serial.begin(9600);
  digitalWrite(s0,HIGH);
  digitalWrite(s1,HIGH);
  digitalWrite(vcc,HIGH);
  Serial.begin(9600);
   
}
void lcd_display(int a)
{
    if(a==0)
      {
          lcd.setCursor(0,0);
          lcd.print("RED SIG STOP !!");
      }
    else if(a==1)
      {
          lcd.setCursor(0,0);
          lcd.print("green SIG GO! GO! GO!");
      }    
}

int getdata(){  
   lcd.init(); 
      lcd.backlight();
      digitalWrite(s2,LOW);
      digitalWrite(s3,LOW);
      red=pulseIn(out,LOW);
      Serial.print("red:");
      Serial.print(red);
      Serial.print(" ");
      digitalWrite(s2,LOW);
      digitalWrite(s3,HIGH);
      blue=pulseIn(out,LOW);
      Serial.print("blue:");
      Serial.print(blue);
      Serial.print(" ");
      digitalWrite(s2,HIGH);
      digitalWrite(s3,HIGH);
      green=pulseIn(out,LOW);
      Serial.print("green:");
      Serial.println(green);
      if(red<green && red<blue && red<200)
        { 
          x=0;
          digitalWrite(mega_enable,LOW);
         }
      else if(green<red && green<blue && green<200)
        {
          x=1;
          digitalWrite(mega_enable,HIGH);
        }
   else
    {
      x=-1;
        digitalWrite(mega_enable,HIGH);
    }
    return x;
}
void loop() 
{
    int a;
    a=getdata();
    Serial.print("m1=");
    Serial.print(digitalRead(m1) );
    Serial.print("    ");
    Serial.print("m2=");
    Serial.print(digitalRead(m2) );
    Serial.print("    ");
    if(a==0||a==1)    //TO DISPLAY THE RED AND GREEN COLOUR ONLY
    {
      lcd_display(a);
    }
    else                             //IF not red and green then line follower display
    {
     int d1=digitalRead(m1);
    int d2=digitalRead(m2);
      if(d1==0&&d2==0)
      {
        lcd.setCursor(6,0);
        lcd.print("stop");
      }
      else if(d1==0&&d2==1)
      {
        lcd.setCursor(6,0);
        lcd.print("LEFT");
      }
      else if(d1==1&&d2==0)
      {
        lcd.setCursor(6,0);
        lcd.print("RIGHT");
      }
      else if(d1==1&&d2==1)
      {
        lcd.setCursor(6,0);
        lcd.print("FORWARD");
      }
    }
}//remaining returnvalue of ......
