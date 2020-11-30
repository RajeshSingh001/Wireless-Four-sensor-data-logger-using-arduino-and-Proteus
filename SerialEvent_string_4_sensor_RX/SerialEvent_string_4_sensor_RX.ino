/*
  Serial Event example
 
 When new serial data arrives, this sketch adds it to a String.
 When a newline is received, the loop prints the string and 
 clears it.
 
 A good test for this is to try it with a GPS receiver 
 that sends out NMEA 0183 sentences. 
 
 Created 9 May 2011
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/SerialEvent
 
 */
 #include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() 
{
  lcd.begin(20,4);
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

void loop()
{
  // print the string when a newline arrives:
  if (stringComplete)
  {
    lcd.setCursor(0,0);
    lcd.print(inputString[0]);
    lcd.print(inputString[1]);
    lcd.setCursor(0,1);
    lcd.print(inputString[2]);
    lcd.print(inputString[3]);
    lcd.setCursor(0,2);
    lcd.print(inputString[4]);
    lcd.print(inputString[5]);
    lcd.setCursor(0,3);
    lcd.print(inputString[6]);
    lcd.print(inputString[7]);
    
    if(inputString[0]==0x0A)
    {
     lcd.setCursor(0,0);
    lcd.print(inputString[1]);
    lcd.print(inputString[2]);
    lcd.setCursor(0,1);
    lcd.print(inputString[3]);
    lcd.print(inputString[4]);
    lcd.setCursor(0,2);
    lcd.print(inputString[5]);
    lcd.print(inputString[6]);
    lcd.setCursor(0,3);
    lcd.print(inputString[7]);
    lcd.print(inputString[8]); 
    }
    Serial.println(inputString); 
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent()
{
  while (Serial.available()>0)
  {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == 0x0D) 
    {
      stringComplete = true;
    } 
  }
}


