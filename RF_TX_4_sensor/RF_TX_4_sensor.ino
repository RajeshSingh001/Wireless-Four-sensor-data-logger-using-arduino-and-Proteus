
#include<LiquidCrystal.h>;
//int buttonState = 0;// variable for reading the pushbutton status
LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  // initialize the LED pin as an output:   
  Serial.begin(9600);
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  lcd.print("Welcome to Data");
  lcd.setCursor(0,1);
  lcd.print("Transmission");
  delay(2000);
  lcd.clear(); 
}

void loop(){
  int sensorValue1 = analogRead(A0);
  int sensorValue2 = analogRead(A1);
  int sensorValue3 = analogRead(A2);
  int sensorValue4 = analogRead(A3);
  int TEMP1=sensorValue1/2;
  int TEMP2=sensorValue2/2;
   int TEMP3=sensorValue3/2;
    int TEMP4=sensorValue4/2;
  lcd.setCursor(0,0);
  lcd.print("TEMP1:");
  lcd.print(TEMP1);
  lcd.setCursor(0,1);
  lcd.print("TEMP2:");
  lcd.print(TEMP2);
  lcd.setCursor(0,2);
  lcd.print("TEMP3:");
  lcd.print(TEMP3);
  lcd.setCursor(0,3);
  lcd.print("TEMP4:");
  lcd.print(TEMP4);
  
  Serial.print(TEMP1);
  Serial.print(TEMP2);
  Serial.print(TEMP3);
  Serial.println(TEMP4);
  
  delay(200);
  
 }
