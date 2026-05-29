// include the library code:
#include <LiquidCrystal.h>

// download the library ButtonFever for the RotaryEncoder
#include <BfButton.h>

// Pin's Numbers
int Speaker1 = 13;
int HertzModule = 1;
int Plus = 2;
int Moins = 4;
int btnPin = 50;
int DT = 51;
int CLK = 52;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
BfButton btn(BfButton::STANDALONE_DIGITAL, btnPin, true, LOW);

// Variables
int value = 0;
int Ecart = 0;

int counter = 0;
int angle = 0;
int aState;
int aLastState;

void setup() {
  Serial.begin(9600);
  pinMode(Speaker1, OUTPUT);
  pinMode(CLK, INPUT_PULLUP);
  pinMode(DT, INPUT_PULLUP);
  pinMode(Moins, INPUT);
  pinMode(Plus, INPUT);
  aLastState = digitalRead(CLK);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  //button settings
  btn.onPress(pressHandler)
  .onDoublePress(pressHandler) // default timeout
  .onPressFor(pressHandler, 1000); // cutstom timeout for 1 second
}

void pressHandler (BfButton *btn, BfButton::press_pattern_t pattern) {
  switch (pattern) {
    case BfButton::SINGLE_PRESS:
      Serial.println("Single push");
      break;
      
    case BfButton::DOUBLE_PRESS:
      Serial.println("Double push");
      break;
      
    case BfButton::LONG_PRESS:
      Serial.println("Long push");
      break;
  }
}

void loop() {
  btn.read();


  aState = digitalRead(CLK);
 
  //Encoder rotation tracking
  if (aState != aLastState){     
     if (digitalRead(DT) != aState) { 
       counter ++;
       angle ++;
     }
     else {
       counter--;
       angle --;
     }
     if (counter >=100 ) {
       counter =100;
     }
     if (counter <=-100 ) {
       counter =-100;
     }
     Serial.println(counter); 
  }   
  aLastState = aState;

  // Serial.println("l'Ecart est de ");
  // Serial.println(Ecart);
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
    Ecart = Ecart + 10;
  } 
  if ( digitalRead(Moins) == 1 && Ecart > 0) {
    Ecart = Ecart - 10;
  }
}