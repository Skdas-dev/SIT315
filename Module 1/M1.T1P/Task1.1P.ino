#define echoPin 2
#define trigPin 3 
#define LED 13
// defines variables
long duration; 
int distance;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);

}
void loop() {
  // set trigPin to active for 2 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);
  // read the echoPin, 
  //return the sound wave travel time
  duration = pulseIn(echoPin, HIGH);
  // calculate distance (speed of sound wave divided by 2)
  distance = duration * 0.034 / 2; 
  //print distance on serial monitor
  //parameters for LED
  //if distance is less or equal to 25cm, turn LED on
  //else, turn LED off
  if(distance <= 25)
  {
    Serial.println("Motion detected");
    digitalWrite(LED, HIGH);
  }else
  {
    Serial.println("No motion detected");
    digitalWrite(LED,LOW);
    delay(500);
  }
  
  }
//source: https://create.arduino.cc/projecthub/abdularbi17/ultrasonic-sensor-hc-sr04-with-arduino-tutorial-327ff6
