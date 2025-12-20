// Soil Moisture Alarm - Simple
const int sensorPin = A0;
const int buzzerPin = 8;
const int ledPin = 9;
int sensorValue = 0;

// Adjust threshold after testing
int threshold = 600; // higher = drier

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.print("Moisture: ");
  Serial.println(sensorValue);

  if (sensorValue > threshold) { // soil dry
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
  }
  delay(1000);
}
