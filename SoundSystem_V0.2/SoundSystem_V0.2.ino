// Pin's Numbers
#define Speaker 11

// Variables
int speed;
int freq1;
int freq2;
int freq3;
int freq4;
int freq5;
int freq6;
int freq7;


void setup() {
  Serial.begin(9600);
}


void loop() {
  //freq
  freq1 = map(analogRead(A1), 0, 1023, 30, 800);
  freq2 = map(analogRead(A2), 0, 1023, 30, 800);  
  freq3 = map(analogRead(A3), 0, 1023, 30, 800);
  freq4 = map(analogRead(A4), 0, 1023, 30, 800);
  freq5 = map(analogRead(A5), 0, 1023, 30, 800);
  freq6 = map(analogRead(A6), 0, 1023, 30, 800);
  freq7 = map(analogRead(A7), 0, 1023, 30, 800);
  //bpm
  speed = map(analogRead(A0), 0, 1023, 0, 1000);

  tone(Speaker, freq1);
  delay(speed);
  tone(Speaker, freq2);
  delay(speed);
  tone(Speaker, freq3);
  delay(speed);
  tone(Speaker, freq4);
  delay(speed);
  tone(Speaker, freq5);
  delay(speed);
  tone(Speaker, freq6);
  delay(speed);
  tone(Speaker, freq7);
  delay(speed);

}