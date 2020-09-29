#include <LiquidCrystal.h>
#include "DHT.h"

#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE); 

LiquidCrystal lcd(12,11,5,4,3,2);
int Gas1 = 9;
int Gas2 = 8;
int Buzzer = 6;


void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode (Buzzer , OUTPUT);
  lcd.begin(16,2);
 

}

void loop() {
   float h = dht.readHumidity();
   float t = dht.readTemperature();
  
  if(h>=75)
  {
    lcd.setCursor(0,0);
    lcd.print("Humidity HIGH");
    Serial.print("Humidity = ");
    Serial.println(h);
    tone (Buzzer,1000);
    delay (1000);
    noTone(Buzzer);
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("Humidity LOW");
    Serial.print("Humidity = ");
    Serial.println(h);
    
  }
  delay(1000);
  lcd.clear();
   if(t>=25)
  {
    lcd.setCursor(0,0);
    lcd.print("Temperature HIGH ");
    Serial.print("Temperature = ");
    Serial.println(t);
    tone (Buzzer,1000);
    delay (1000);
    noTone(Buzzer);
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("Temperature LOW ");
    Serial.print("Temperature = ");
    Serial.println(t);
    
  }
  
  delay(1000);
  lcd.clear();
  
  if (digitalRead(Gas1) == HIGH) {
  lcd.setCursor(0,0);
  lcd.print("Smoke and Methane detected!RUN! ");
  Serial.println("Smoke and Methane detected!RUN!");
 tone (Buzzer,1000);
    delay (1000);
    noTone(Buzzer);
  }
  else
  {
  lcd.setCursor(0,0);
  lcd.print("NO SMOKE");
  Serial.println("NO SMOKE");
  
  }
   delay(2000);
  lcd.clear();
  if (digitalRead(Gas2) == HIGH) {
  lcd.setCursor(0,0);
  lcd.print("TOXIC GAS DETECTED!");
  Serial.println("TOXIC GAS DETECTED!");
  tone (Buzzer,1000);
    delay (1000);
    noTone(Buzzer);
  }
  else
  {
  lcd.setCursor(0,0);
  lcd.print("NO GAS DETECTED");
  Serial.println("NO GAS DETECTED");
  
  }
   delay(2000);
  lcd.clear();
  
}
