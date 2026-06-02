// include the library code:
#include <LiquidCrystal.h>

// Pin's Numbers
int Speaker1 = 13;
int HertzModule = 1;
int Plus = 2;
int Moins = 4;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Variables
int value = 0;
int Ecart = 0;

void setup() {
  Serial.begin(9600);
  pinMode(Speaker1, OUTPUT);

  pinMode(Moins, INPUT);
  pinMode(Plus, INPUT);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}


void loop() {
  if ( digitalRead(Plus) == 1) {
    Ecart = Ecart + 10;
  } 
  if ( digitalRead(Moins) == 1 && Ecart > 0) {
    Ecart = Ecart - 10;
  }

  lcd.setCursor(0, 0);
  if ( (analogRead(HertzModule) - value >= 4 || analogRead(HertzModule) - value <= (4) ) ) {
    value = map(analogRead(HertzModule), 0, 1023, 20, 20000);
  }


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
 
}