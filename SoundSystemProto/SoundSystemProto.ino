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
int Rotation;
int LastRotation;

void setup() {
  Serial.begin(9600);
  pinMode(Speaker1, OUTPUT);

  pinMode(Moins, INPUT);
  pinMode(Plus, INPUT);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  // pinMode(CLK, INPUT_PULLUP);
  // pinMode(DT, INPUT_PULLUP);
  // LastRotation = digitalRead(CLK);

  //button settings
  // btn.onPress(pressHandler)
  // .onDoublePress(pressHandler) // default timeout
  // .onPressFor(pressHandler, 1000); // cutstom timeout for 1 second
}

// void pressHandler (BfButton *btn, BfButton::press_pattern_t pattern) {
//   switch (pattern) {
//     case BfButton::SINGLE_PRESS:
//       Serial.println("Single push");
//       break;
      
//     case BfButton::DOUBLE_PRESS:
//       Serial.println("Double push");
//       break;
      
//     case BfButton::LONG_PRESS:
//       Serial.println("Long push");
//       break;
//   }
// }

void loop() {
  // btn.read();


  // Rotation = digitalRead(CLK);
 
  //Encoder rotation tracking
  // if (Rotation != LastRotation){
  //   Serial.print("LastRotation : ");
  //   Serial.println(LastRotation);
  //   Serial.print("Rotation : ");
  //   Serial.println(Rotation);  
  //    if (digitalRead(DT) != Rotation) { 
  //      counter += 10;
  //      angle += 10;
  //    }
  //    else {
  //      counter -= 10;
  //      angle -= 10;
  //    }
  //    if (counter >= 500 ) {
  //      counter =500;
  //    }
  //    if (counter <= 0 ) {
  //      counter = 0;
  //    }
  //    Ecart = counter; 
  // }   
  // LastRotation = Rotation;

  if ( digitalRead(Plus) == 1) {
    Ecart = Ecart + 10;
  } 
  if ( digitalRead(Moins) == 1 && Ecart > 0) {
    Ecart = Ecart - 10;
  }

  // Serial.println("l'Ecart est de ");
  // Serial.println(Ecart);
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