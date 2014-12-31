/**
  Stupid pin outs:
 
  Green: Ground
  Black+Blue: Pin 6
  Black:      Pin 5
  Red:        Pin 3  */

int lred = 3;
int lgreen = 5;
int lblue = 6;

void setup() {
  pinMode(lred, OUTPUT);
  pinMode(lgreen, OUTPUT);
  pinMode(lblue, OUTPUT);
  Serial.begin(9600);
}
 
void loop() {
  if (Serial.available() > 0) {
    byte pin = Serial.read();
    int rVal = Serial.parseInt();
    Serial.write(rVal);
    Serial.flush();
    
    int outPin = lred;
    
    switch(pin) {
      case 'R':
        outPin = lred;
        break;
      case 'B':
        outPin = lblue;
        break;
      case 'G':
        outPin = lgreen;
        break;
    }
    
    analogWrite(outPin, rVal);
  }
}
