#include <virtuabotixRTC.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Creation of the Real Time Clock Object
virtuabotixRTC myRTC(10, 9, 8);

const int led_pin = 2;
const int buzzer = 7;
const int water_sensor = A5;
int water_lvl = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  pinMode(buzzer,OUTPUT);
  pinMode(led_pin,OUTPUT);
  myRTC.setDS1302Time(55, 59, 20, 6, 9, 10, 2021);
  noTone(buzzer);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  myRTC.updateTime();
  water_lvl = analogRead(water_sensor);
  int hours = myRTC.hours;
  int minutes = myRTC.minutes;
  int seconds = myRTC.seconds;
  lcd.clear();
  lcd.print(“time”);
  lcd.setCursor(0,1);
  lcd.print(hours);
  lcd.print(“:”);
  lcd.print(minutes);
  lcd.print(“:”);
  lcd.print(seconds);
  Serial.println(water_lvl);

  
  if((hours == 21 && minutes == 0 && seconds == 0)||( hours == 21 && minutes == 0 && seconds == 50)){
do{
      myRTC.updateTime();
      water_lvl = analogRead(water_sensor);
      int hours = myRTC.hours;
      int minutes = myRTC.minutes;
      int seconds = myRTC.seconds;
      lcd.clear();
      lcd.print(“time”);
      lcd.setCursor(0,1);
      lcd.print(hours);
      lcd.print(“:”);
      lcd.print(minutes);
      lcd.print(“:”);
      lcd.print(seconds);
      Serial.println(water_lvl);
      digitalWrite(led_pin,HIGH);
       delay(1000);
       
}while(water_lvl <= 550);
    
  if(water_lvl >=550){
int I = 0;
do{
      digitalWrite(led_pin,LOW);
      i++;
      tone(buzzer, 450);
      delay(200);
      noTone(buzzer);
      delay(200);
      lcd.clear();
      lcd.print(“Bath tub is full.”);
      lcd.setCursor(0,1);
      lcd.print(“Time to shower!!!”);
}while(i<20);
delay(1000);
  }
  }
  delay(1000);
}
