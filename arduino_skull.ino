const int trigPin = 11;
const int echoPin = 10;

const int ledLeftPin = 7;
const int ledRightPin = 8;

long duration, distance;

void setup()
{
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledLeftPin, OUTPUT);
  pinMode(ledRightPin, OUTPUT);
  
  Serial.begin(9600);
}
  
void loop()
{
  // Reset pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(3);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(12);
  digitalWrite(trigPin, LOW);

  // Check for distance
  duration = pulseIn(echoPin, HIGH);

 Serial.print("\nsensor = ");
  Serial.print(duration);
  
  distance = duration/58.2;
  if(distance < 30)
  {
    // Obstacle found
    digitalWrite(ledLeftPin, HIGH);
    digitalWrite(ledRightPin, HIGH);
  }
  else
  {
    digitalWrite(ledLeftPin, LOW);
    digitalWrite(ledRightPin, LOW);
  }

  delay(90);
}
