const int PIN_SENSOR_LEFT_INPUT         = 2;      //Sensor Left
const int PIN_SENSOR_RIGHT_INPUT        = 3;      //Sensor Right
const int PIN_SENSOR_BYPASS_INPUT       = 4;      //Sensor Bypass

const int PIN_SENSOR_LOWER_LEFT_INPUT   = 18;     //Sensor Left
const int PIN_SENSOR_LOWER_RIGHT_INPUT  = 19;     //Sensor Right
const int PIN_SENSOR_LOWER_BYPASS_INPUT = 5;      //Sensor Bypass

const int PIN_MOTOR_LEFT_OUTPUT         = 6;      //Servo Control Left
const int PIN_MOTOR_RIGHT_OUTPUT        = 7;      //Servo Control Right

const int PIN_MOTOR_LOWER_LEFT_OUTPUT   = 8;      //Servo Control Left
const int PIN_MOTOR_LOWER_RIGHT_OUTPUT  = 9;      //Servo Control Right

const int PIN_KICK_OUTPUT               = 20;      //

int left, right, bypass, leftLower, rightLower, bypassLower;

void triggerInput() {
//  bypass  = digitalRead(PIN_SENSOR_BYPASS_INPUT);
  left    = digitalRead(PIN_SENSOR_LEFT_INPUT);
  right   = digitalRead(PIN_SENSOR_RIGHT_INPUT);
  
//  bypassLower  = digitalRead(PIN_SENSOR_LOWER_BYPASS_INPUT);
  leftLower    = digitalRead(PIN_SENSOR_LOWER_LEFT_INPUT);
  rightLower   = digitalRead(PIN_SENSOR_LOWER_RIGHT_INPUT);

  if(left == right == leftLower == rightLower == HIGH){
    digitalWrite(PIN_MOTOR_LEFT_OUTPUT, HIGH);
    digitalWrite(PIN_MOTOR_RIGHT_OUTPUT, HIGH);
    digitalWrite(PIN_MOTOR_LOWER_LEFT_OUTPUT, HIGH);
    digitalWrite(PIN_MOTOR_LOWER_RIGHT_OUTPUT, HIGH);
  }else{
    digitalWrite(PIN_MOTOR_LEFT_OUTPUT, !left);
    digitalWrite(PIN_MOTOR_RIGHT_OUTPUT, !right);
    digitalWrite(PIN_MOTOR_LOWER_LEFT_OUTPUT, !leftLower);
    digitalWrite(PIN_MOTOR_LOWER_RIGHT_OUTPUT, !rightLower);
  }
}

void setup() {
  //UPPER
  pinMode(PIN_SENSOR_LEFT_INPUT, INPUT);                digitalWrite(PIN_SENSOR_LEFT_INPUT, LOW);
  pinMode(PIN_SENSOR_RIGHT_INPUT, INPUT);               digitalWrite(PIN_SENSOR_RIGHT_INPUT, LOW);
  pinMode(PIN_SENSOR_BYPASS_INPUT, INPUT);              digitalWrite(PIN_SENSOR_BYPASS_INPUT, LOW);
  //LOWER
  pinMode(PIN_SENSOR_LOWER_LEFT_INPUT, INPUT);          digitalWrite(PIN_SENSOR_LOWER_LEFT_INPUT, LOW);
  pinMode(PIN_SENSOR_LOWER_RIGHT_INPUT, INPUT);         digitalWrite(PIN_SENSOR_LOWER_RIGHT_INPUT, LOW);
  pinMode(PIN_SENSOR_LOWER_BYPASS_INPUT, INPUT);        digitalWrite(PIN_SENSOR_LOWER_BYPASS_INPUT, LOW);
  //MOTOR
  pinMode(PIN_MOTOR_LEFT_OUTPUT, OUTPUT);               digitalWrite(PIN_MOTOR_LEFT_OUTPUT, HIGH);
  pinMode(PIN_MOTOR_RIGHT_OUTPUT, OUTPUT);              digitalWrite(PIN_MOTOR_RIGHT_OUTPUT, HIGH);
  pinMode(PIN_MOTOR_LOWER_LEFT_OUTPUT, OUTPUT);         digitalWrite(PIN_MOTOR_LOWER_LEFT_OUTPUT, HIGH);
  pinMode(PIN_MOTOR_LOWER_RIGHT_OUTPUT, OUTPUT);        digitalWrite(PIN_MOTOR_LOWER_RIGHT_OUTPUT, HIGH);
  //KICKER
  pinMode(PIN_KICK_OUTPUT, OUTPUT);                     digitalWrite(PIN_KICK_OUTPUT, HIGH);
  
  attachInterrupt(digitalPinToInterrupt(PIN_SENSOR_LEFT_INPUT), triggerInput, CHANGE); 
  attachInterrupt(digitalPinToInterrupt(PIN_SENSOR_RIGHT_INPUT), triggerInput, CHANGE); 
  attachInterrupt(digitalPinToInterrupt(PIN_SENSOR_LOWER_LEFT_INPUT), triggerInput, CHANGE); 
  attachInterrupt(digitalPinToInterrupt(PIN_SENSOR_LOWER_RIGHT_INPUT), triggerInput, CHANGE); 
}

void loop() {
}
