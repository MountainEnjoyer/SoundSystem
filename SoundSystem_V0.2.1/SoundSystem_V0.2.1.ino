// Pin's Numbers
#define Speaker 11

// Variables
int speed1;
int speed2;
int speed3;
int speed4;

int freq1;
int freq2;
int freq3;
int freq4;

// formatted string to pass data to python
String formatted_str;


void setup() {
  Serial.begin(9600);
}


void loop() {
  //bpm
  speed1 = map(analogRead(A0), 0, 1023, 0, 999);
  speed2 = map(analogRead(A2), 0, 1023, 0, 999);
  speed3 = map(analogRead(A4), 0, 1023, 0, 999);  
  speed4 = map(analogRead(A6), 0, 1023, 0, 999);


  //freq
  freq1 = map(analogRead(A1), 0, 1023, 0, 999);
  freq2 = map(analogRead(A3), 0, 1023, 0, 999);
  freq3 = map(analogRead(A5), 0, 1023, 0, 999);
  freq4 = map(analogRead(A7), 0, 1023, 0, 999);


  if(speed1 < 20 && speed2 < 20 && speed3 < 20 && speed4 < 20) {
    noTone(Speaker);
  }
  if ( speed1 > 40) {
    if ( freq1 > 40) {
      tone(Speaker, freq1);
    }
  }
  delay(speed1);
  if ( speed2 > 40) {
    if ( freq2 > 40) {
      tone(Speaker, freq2);
    }
  }
  delay(speed2);
  if ( speed3 > 40) {
    if ( freq3 > 40) {
      tone(Speaker, freq3);
    }
  }
  delay(speed3);
  if ( speed4 > 40) {
    if ( freq4 > 40) {
      tone(Speaker, freq4);
    }
  }
  delay(speed4);

  formatted_str = String(speed1) + '-' + String(freq1) + '/' + String(speed2) + '-' + String(freq2) + '/' + String(speed3) + '-' + String(freq3) + '/' + String(speed4) + '-' + String(freq4) + '/';
  Serial.println(formatted_str); 

}