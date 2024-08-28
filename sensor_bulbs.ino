int inByte = 0;
char buffer[40];
int index = 0;
int index2 = 0;
int index3 = 0;

// set up the ambient light sensor
int lightSensorPin = A0;
int lightValue = 0;

// define the sensor and button pin
int sensorPin = 8;

// set up the bulb pins
int bulb1Pin = 9;
int bulb2Pin = 10;
int bulb3Pin = 11;

int bulb1Brightness = 0;
int bulb2Brightness = 0;
int bulb3Brightness = 0;
int allOn = 0;


void setup() {
  pinMode(sensorPin, INPUT);
  // set up the mode of the bulbs 
  pinMode(bulb1Pin, OUTPUT);
  pinMode(bulb2Pin, OUTPUT);
  pinMode(bulb3Pin, OUTPUT);
  Serial.begin(9600);
}
 
void loop() 
{
  //bulb1
  //receive from max
  index = 0;
  do
  {
    buffer[index] = Serial.read();
    if(buffer[index]!=-1) index = index+1;
  }while(buffer[index-1]!=32);

  //value from max
  bulb1Brightness = atoi(buffer); 
  analogWrite(bulb1Pin, bulb1Brightness);

  //bulb2
  //receive from max
  index2 = 0;
  do
  {
    buffer[index2] = Serial.read();
    if(buffer[index2]!=-1) index2 = index2+1;
  }while(buffer[index2-1]!=32);

  //value from max
  bulb2Brightness = atoi(buffer); 
  analogWrite(bulb2Pin, bulb2Brightness);

  //bulb3
  //receive from max
  index3 = 0;
  do
  {
    buffer[index3] = Serial.read();
    if(buffer[index3]!=-1) index3 = index3+1;
  }while(buffer[index3-1]!=32);

  //value from max
  bulb3Brightness = atoi(buffer); 
  analogWrite(bulb3Pin, bulb3Brightness);
  
  
  //send to max
  lightValue = analogRead(lightSensorPin);
  //value to max
  Serial.println(lightValue); 
  delay(5);
}
