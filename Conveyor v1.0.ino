#include <Adafruit_GFX.h>
#include <gfxfont.h>
#include "pitches.h"
#include <LiquidCrystal.h>
#include "Adafruit_GFX.h"


const int sensorPin = A0;

int note1 = NOTE_G6;


int tones[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};

int counter=0;
int fo=0;
int industrial=0;
int products=0;

/*Visual Integers*/
int alpi=0;
int ercu=0;
int mert=0;
int merve=0;
int yakup=0;
int sis=0;


/*Sensor definitions*/
int sensorCounter = 0;
int sensorState = 0;
int state;
int lastState = HIGH;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(sensorPin, INPUT);

  pinMode(9,OUTPUT);
   Serial.begin(9600);
  lcd.begin(20, 4);
  /*Visual sets for scrolling texts*/
  lcd.setCursor(6,0);
  while("COUNTER"[counter]!=0) 
{
lcd.print("COUNTER"[counter]); 
delay(100);        
counter++;
}
 
  lcd.setCursor(8,1);
  while("FOR"[fo]!=0) 
{
lcd.print("FOR"[fo]); 
delay(100);        
fo++;
}

  lcd.setCursor(5,2);
  while("INDUSTRIAL"[industrial]!=0) 
{
lcd.print("INDUSTRIAL"[industrial]); 
delay(100);        
industrial++;
}

  lcd.setCursor(6,3);
  while("PRODUCTS"[products]!=0) 
{
lcd.print("PRODUCTS"[products]); 
delay(100);        
products++;
}
  
  delay(4500);

  
  lcd.clear();  
  lcd.setCursor(4,1);
  while("Alperen Dogu"[alpi]!=0) 
{
lcd.print("Alperen Dogu"[alpi]);
delay(100);       
alpi++;
}
  delay(1500);

  
  lcd.clear();
  lcd.setCursor(0,2);
  while("Ercument Bilal Baris"[ercu]!=0) 
{
lcd.print("Ercument Bilal Baris"[ercu]);
delay(100);       
ercu++;
}
  delay(1500);

  
  lcd.clear();
  lcd.setCursor(3,1);
  while("Mert Karaduman"[mert]!=0) 
{
lcd.print("Mert Karaduman"[mert]);
delay(100);       
mert++;
}
  delay(1500);

  
  lcd.clear();
  lcd.setCursor(4,2);
  while("Merve Dilsiz"[merve]!=0) 
{
lcd.print("Merve Dilsiz"[merve]);
delay(100);       
merve++;
}
  delay(1500);

  
  lcd.clear();
  lcd.setCursor(2,1);
  while("Yakup Emre Nacar"[yakup]!=0) 
{
lcd.print("Yakup Emre Nacar"[yakup]);
delay(100);       
yakup++;
}
  delay(1500);
  lcd.clear();

 while("SYSTEM STARTING..."[sis]!=0) 
{
lcd.print("SYSTEM STARTING..."[sis]);
delay(100);       
sis++;
}
  delay(3000);
  
  lcd.clear();

  digitalWrite(9,HIGH);
   
  delay(3000);
  lcd.setCursor(0,0);
  lcd.print("NUMBER OF COUNT: ");

  
 
}

void loop() {
  int state = digitalRead(sensorPin);
 
 
  if (lastState == LOW && state == HIGH)
  {
     sensorCounter++;
    
  }
  lastState = state;


  lcd.setCursor(17,0);
  lcd.print(sensorCounter);
  Serial.println(sensorCounter);

   
  if (sensorCounter == tones){
   int state = digitalRead(sensorPin);
    
    digitalWrite(9,LOW);
    tone(8, note1);
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("GET MATERIAL");
    lcd.setCursor(6,1);
    lcd.print("FROM AREA");
    
    delay(2000);
    noTone(8);
    lcd.clear();
    lcd.print("NUMBER OF COUNT:");
    
   
    
    lcd.setCursor(17,0);
    lcd.print(sensorCounter);
       
    digitalWrite(9,HIGH);
    
    
    
  }
  
 delay(100);
 
}
