// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int Speaker1 = 13;
int HertzModule = 1;
int value = 0;
int Plus = 2;
int Moins = 4;
int Ecart = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(4, INPUT);
  pinMode(2, INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  Serial.println("l'Ecart est de ");
  Serial.println(Ecart);
  lcd.setCursor(0, 0);
  value = analogRead(HertzModule);

  if (Ecart > 0 ){
    tone(Speaker1, value);
    delay(Ecart);
    noTone(Speaker1);
    delay(Ecart);
  } else { 
    tone(Speaker1, value);
  }
  // print the number of seconds since reset:
  lcd.print(value);
  lcd.print(" Hertz");
  lcd.setCursor(0, 1);
  lcd.print("Ecart de ");
  lcd.print(Ecart);
  lcd.print("ms");
  if ( digitalRead(Plus) == 1) {
    Ecart = Ecart + 20;
  } 
  if ( digitalRead(Moins) == 1 && Ecart > 0) {
    Ecart = Ecart - 20;
  }
}