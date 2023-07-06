#include <Keyboard.h>

#include <DHT.h>


#define TriggerPin 7
#define EchoPin 8
#define TempPin 12
#define dhtModel DHT11
#define RedPin 9
#define GreenPin 6
#define BluePin 5


DHT dhtObj(TempPin, dhtModel);

float distance,correctedDistance;
float timeTaken;
float tempVal,humidVal;
const int buzzer=11;
int readingno=1;
void setup() {
  // put your setup code here, to run once:
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
 
  dhtObj.begin();
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Reading No. : ");
  Serial.println(readingno);
  Serial.println();
  digitalWrite(TriggerPin, LOW);
  delayMicroseconds(5);
  digitalWrite(TriggerPin, HIGH);
  delayMicroseconds(10);
  timeTaken = pulseIn(EchoPin, HIGH);
  distance = (timeTaken*0.0331)/2;
  Serial.print("calculated_Distance:");
  Serial.println(distance);

  tempVal = dhtObj.readTemperature();
  humidVal = dhtObj.readHumidity();
  Serial.print("Temperature:");
  Serial.println(tempVal);
 
  Serial.print("Relative_Humidity:");
  Serial.println(humidVal);

  correctedDistance = ((timeTaken)*((331+(0.606*tempVal)+(0.01243*humidVal))*0.0001))/2;
  Serial.print("Actual_Distance:");
  Serial.println(correctedDistance);
 
  
 
  if(correctedDistance<=10)
  {
    digitalWrite(buzzer, HIGH);   
    delay(1000); 
  }
  else
  {
    digitalWrite(buzzer, LOW);    
    delay(1000);
  }
  RGBIndicator(round(correctedDistance));
  readingno++;
  Serial.println("--------------------------------");
  Serial.println("--------------------------------");
}

void RGBIndicator(int objectDistance)
{
  if(objectDistance <= 10)
  {
    analogWrite(RedPin, 255);
    analogWrite(BluePin, 0);
    analogWrite(GreenPin, 0);
  }
  else if(objectDistance >10 and objectDistance <=20)
  {
    analogWrite(RedPin, 0);
    analogWrite(BluePin, 255);
    analogWrite(GreenPin, 0);
  }
  else
  {
    analogWrite(RedPin, 0);
    analogWrite(BluePin, 0);
    analogWrite(GreenPin, 255);
  }
}
