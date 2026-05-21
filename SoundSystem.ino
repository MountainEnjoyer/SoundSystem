// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int Speaker1 = 13;
int HertzModule = 1;
int value = 0;
int Plus = 2;
int Moins = 3;
long Ecart = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(3, INPUT);
  pinMode(2, INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
}

void loop() {
  if ( digitalRead(Plus) == HIGH) {
    Ecart = Ecart + 10;
    Serial.println(Ecart);
  } 
  if ( digitalRead(Moins) == HIGH ) {
    Ecart = Ecart - 10;
    Serial.println(Ecart);
  }
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  Serial.println("l'Ecart est de ");
  Serial.println(Ecart);
  lcd.setCursor(0, 0);
  value = analogRead(HertzModule);
  tone(Speaker1, value);
  delay(Ecart);
  // print the number of seconds since reset:
  lcd.print(value);
  lcd.print(" Hertz");
  lcd.setCursor(0, 1);
  lcd.print("Ecart de ");
  lcd.print(Ecart);
  lcd.print("ms");

}