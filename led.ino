#define sensorMin 0
#define sensorMax 1023

void setup()
{
  Serial.begin(9600);
  
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  int sensorValue = analogRead(A0);
 
  Serial.println(sensorValue);
  
  if(sensorValue <= sensorMax/3)
  {
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
  else if(sensorValue <= 2 * sensorMax/3)
  { 
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }
  else
  {
    digitalWrite(11, LOW);
   	digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
  }
  delay(10); 
}