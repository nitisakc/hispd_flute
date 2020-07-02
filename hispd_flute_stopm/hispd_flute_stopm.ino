const int PIN_SENSOR_LEFT_INPUT   = 2;      //Sensor Left
const int PIN_SENSOR_RIGHT_INPUT  = 3;      //Sensor Right
const int PIN_SENSOR_BYPASS_INPUT = 4;      //Sensor Bypass
const int PIN_SENSOR_LEFT_OUTPUT  = 6;      //Servo Control Left
const int PIN_SENSOR_RIGHT_OUTPUT = 7;      //Servo Control Right

/*
The high input from the sensor is the detection of objects.
Output low value to stop the motor.

    Sensor        |        Motor
Left   |   Right  |   Left   |   Right
  0    |     0    |     1    |     1
  1    |     1    |     1    |     1
  0    |     1    |     1    |     0
  1    |     0    |     0    |     1
  
 */

int left, right, bypass;

void triggerInput() {
  bypass  = digitalRead(PIN_SENSOR_BYPASS_INPUT);
  left    = digitalRead(PIN_SENSOR_LEFT_INPUT);
  right   = digitalRead(PIN_SENSOR_RIGHT_INPUT);

  if(bypass == LOW && left != right){
    digitalWrite(PIN_SENSOR_LEFT_OUTPUT, !left);
    digitalWrite(PIN_SENSOR_RIGHT_OUTPUT, !right);
  }else{
    digitalWrite(PIN_SENSOR_LEFT_OUTPUT, HIGH);
    digitalWrite(PIN_SENSOR_RIGHT_OUTPUT, HIGH);
  }
}


void setup() {
  pinMode(PIN_SENSOR_LEFT_OUTPUT, OUTPUT);  digitalWrite(PIN_SENSOR_LEFT_OUTPUT, HIGH);
  pinMode(PIN_SENSOR_RIGHT_OUTPUT, OUTPUT); digitalWrite(PIN_SENSOR_RIGHT_OUTPUT, HIGH);
  pinMode(PIN_SENSOR_LEFT_INPUT, INPUT);    digitalWrite(PIN_SENSOR_LEFT_INPUT, LOW);
  pinMode(PIN_SENSOR_RIGHT_INPUT, INPUT);   digitalWrite(PIN_SENSOR_RIGHT_INPUT, LOW);
  pinMode(PIN_SENSOR_BYPASS_INPUT, INPUT);  digitalWrite(PIN_SENSOR_BYPASS_INPUT, LOW);
  
  attachInterrupt(digitalPinToInterrupt(PIN_SENSOR_LEFT_INPUT), triggerInput, CHANGE); 
  attachInterrupt(digitalPinToInterrupt(PIN_SENSOR_RIGHT_INPUT), triggerInput, CHANGE); 
}

void loop() {
}
