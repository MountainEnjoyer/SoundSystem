// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int Speaker1 = 13;
int HertzModule = 1;
int value = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  value = analogRead(HertzModule);
  Serial.println(value);
  tone(Speaker1, value);
  delay(10);
  // print the number of seconds since reset:
  lcd.print(value);
  lcd.print(" Hertz");
  lcd.setCursor(0, 1);
  lcd.print("");
}