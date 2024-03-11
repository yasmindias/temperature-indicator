// C++ code for Arduino
//
/*
    This circuit reads an analog input from a 
  temperature sensor, places the read voltage in a 
  scale from 0 to 9 (where 0 is the min  temperature 
  and 9 is the max temperature), "converts" the scale 
  number to binary and sends this number to the CD4511 
  decoder, which in turn shows the number on the 7-segment
  display.

  The circuit:
  * Temperature sensor attached to analog input 0
  * center pin of the sensor to the analog pin
  * one side pin (either one) to ground
  * the other side pin to +5V
  * CD4511 IC (BCD to 7-segment decoder)
  * 7-segment cathode display
  * 150Ω Resistor
*/

int sensorValue = 0;
unsigned const int Input1 = 4;
unsigned const int Input2 = 7;
unsigned const int Input3 = 6;
unsigned const int Input4 = 5;


void setup()
{
  //monitor para debug
  //Serial.begin(9600);
  
  //pino de entrada para do sensor de temperatura
  pinMode(A0, INPUT); //min: 20 max: 358
  
  //pinos de saída para o decodificador do display
  pinMode(Input1, OUTPUT);
  pinMode(Input2, OUTPUT);
  pinMode(Input3, OUTPUT);
  pinMode(Input4, OUTPUT);
}

void sendToDecoder(int val1, int val2, int val3, int val4) {
  digitalWrite(Input4, val1);
  digitalWrite(Input3, val2);
  digitalWrite(Input2, val3);
  digitalWrite(Input1, val4);
}

void loop()
{
  // read the value from the sensor
  sensorValue = analogRead(A0);
  
  //Serial.println(sensorValue);

  if(sensorValue == 20) {
    sendToDecoder(LOW, LOW, LOW, LOW); //0
  }
  
  if(sensorValue >= 21 && sensorValue <= 59) {
    sendToDecoder(LOW, LOW, LOW, HIGH); //1
  }
  
  if(sensorValue >= 60 && sensorValue <= 98) {
    sendToDecoder(LOW, LOW, HIGH, LOW); //2
  }
  
  if(sensorValue >= 99 && sensorValue <= 137) {
    sendToDecoder(LOW, LOW, HIGH, HIGH); //3
  }
  
  if(sensorValue >= 138 && sensorValue <= 176) {
    sendToDecoder(LOW, HIGH, LOW, LOW); //4
  }
  
  if(sensorValue >= 177 && sensorValue <= 215) {
    sendToDecoder(LOW, HIGH, LOW, HIGH); //5
  }
  
  if(sensorValue >= 216 && sensorValue <= 254) {
    sendToDecoder(LOW, HIGH, HIGH, LOW); //6
  }
  
  if(sensorValue >= 255 && sensorValue <= 293) {
    sendToDecoder(LOW, HIGH, HIGH, HIGH); //7
  }
  
  if(sensorValue >= 294 && sensorValue <= 357) {
    sendToDecoder(HIGH, LOW, LOW, LOW); //8
  }
  
  if(sensorValue == 358) {
    sendToDecoder(HIGH, LOW, LOW, HIGH); //9
  }
  
  delay(sensorValue); // Wait for sensorValue millisecond(s)
}