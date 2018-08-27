int latchPin = 8;
int clockPin = 12;
int dataPin = 11;
//int numToDisplay = 0;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    int numToDisplay = Serial.parseInt();
    Serial.println(numToDisplay);
    Serial.println("OK");
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, numToDisplay);
    digitalWrite(latchPin, HIGH);
    delay(50);
  }
}
