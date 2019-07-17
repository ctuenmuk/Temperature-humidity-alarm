#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 8
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

 LiquidCrystal lcd(12,11,5,4,3,2);


 float hum;
 float temp;
 const int buzzer = 9;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16,2);
  lcd.print("Humidity:");
  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  if (temp > 30.00) {
  tone(buzzer,5000,5000);
  delay(1000);
  }
  if (hum > 60.00) {
  tone(buzzer,10000,10000);
  delay(100);
  }
  
  lcd.setCursor(9,1);
  lcd.print( temp); 
  lcd.print((char)223); 
  lcd.print("C");
  lcd.setCursor(9,0);
  lcd.print(hum);
  lcd.print(" %");
  delay(2000);
}
