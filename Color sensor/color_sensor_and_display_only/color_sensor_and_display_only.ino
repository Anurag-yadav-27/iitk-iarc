#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
int array[4]={1,0,1,1};
int speeed =(array[0]*8+array[1]*4+array[2]*2+array[3])/5;
int angle = ((array[0]*8+array[1]*4+array[2]*2+array[3])*10);

const int s0=3;
const int s1=4;
const int s2=5;
const int s3=6;
const int out=7;
const int vcc=8;
const int led=9;
int red,green,blue;
int x;
void setup() {
  pinMode(11,HIGH);
  pinMode(2,LOW);
  pinMode(13,LOW);
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
  Serial.begin(9600);
}
void lcd_display(int a)
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
//  if(a==-1)
//  {
//    lcd.setCursor(0,0);
//    lcd.print("MAT=");
//    for (int i=0;i<4;i++)
//    {   
//        lcd.setCursor(i+4,0);
//        lcd.print(array[i]);
//     }
//    lcd.setCursor(0,1);
//    lcd.print("speed=");
//    lcd.setCursor(6,1);
//    lcd.print(speeed);
//    lcd.setCursor(8,1);
//    lcd.print("angle=");
//    lcd.print(angle);
//    }
    if(a==0)
      {
          lcd.setCursor(0,0);
          lcd.print("red");
      }
    else if(a==1)
      {
          lcd.setCursor(0,0);
          lcd.print("green");
      }
    else if(a==2)
      {
          lcd.setCursor(0,0);
          lcd.print("blue");
      }
    else if(a==-1){
        lcd.setCursor(0,0);
        lcd.print("NOTHING");
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
          lcd.setCursor(0,0);
          lcd.print("RED");
          x=0;
         }
      else if(green<red && green<blue && green<200)
        {
          lcd.setCursor(0,0);
          lcd.print("GREEN");
          x=1;
        }
    else if(blue<red && blue<red && blue<200)
    {
        lcd.setCursor(0,0);
        lcd.print("BLUE");
        x=2;
    }
    else
    {
        lcd.setCursor(0,0);
        lcd.print("NOTHING");
        x=-1;
    }
    return x;
}
void loop() 
{
    int a;
    a=getdata();
    lcd_display(a);
}//remaining returnvalue of ......
