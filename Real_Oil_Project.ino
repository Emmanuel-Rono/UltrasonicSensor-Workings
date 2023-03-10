
const int trigPin = 5;
const int echoPin = 16;
// defines variables
long duration;
int distance;
int x;
void setup() {
  pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);   // Sets the echoPin as an Input
  Serial.begin(9600);        // Starts the serial communication
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Oil level: ");
  Serial.println(distance);
  if (distance<=100)
  {
    Serial.println("Oil level is at bar");
    Serial.println("Sending alert to Mechanic .");
    for(x=1;x<=100;x++);{Serial.print("..");}
  }
  delay(5000);
}