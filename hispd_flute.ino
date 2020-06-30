const int PIN_SPD_A1_INPUT = 2;         //encode A
const int PIN_SPD_A2_INPUT = 3;         //encode A
const int PIN_MOTOR_LEFT_A = 4;         //Motor Left A
const int PIN_MOTOR_LEFT_B = 5;         //Motor Left B
const int PIN_MOTOR_RIGHT_A = 6;        //Motor Right A
const int PIN_MOTOR_RIGHT_B = 7;        //Motor Right B
const int PIN_SENSOR_LEFT_INPUT = 18;   //Sensor Left
const int PIN_SENSOR_RIGHT_INPUT = 19;  //Sensor Right
const int PPR = 1000;

long count = 0;
int spd, b, sensorLeft, sensorRight;

void triggerSpdInputFalling() {
  sensorLeft = digitalRead(PIN_SENSOR_LEFT_INPUT);
  sensorRight = digitalRead(PIN_SENSOR_RIGHT_INPUT);
  
  if(sensorLeft == sensorRight){
    digitalWrite(PIN_MOTOR_LEFT_A, 0);
    digitalWrite(PIN_MOTOR_LEFT_B, 0);
    digitalWrite(PIN_MOTOR_RIGHT_A, 0);
    digitalWrite(PIN_MOTOR_RIGHT_B, 0);
  }else{
    if(sensorLeft == 1){
      digitalWrite(PIN_MOTOR_LEFT_A, 0);
      digitalWrite(PIN_MOTOR_LEFT_B, 0);
    }
    if(sensorRight == 1){
      digitalWrite(PIN_MOTOR_RIGHT_A, 0);
      digitalWrite(PIN_MOTOR_RIGHT_B, 0);
    }
  }
}

void triggerSpdInputRising() {
  sensorLeft = digitalRead(PIN_SENSOR_LEFT_INPUT);
  sensorRight = digitalRead(PIN_SENSOR_RIGHT_INPUT);
  
  if(sensorLeft == sensorRight){
    digitalWrite(PIN_MOTOR_LEFT_A, 1);
    digitalWrite(PIN_MOTOR_LEFT_B, 1);
    digitalWrite(PIN_MOTOR_RIGHT_A, 1);
    digitalWrite(PIN_MOTOR_RIGHT_B, 1);
  }else{
    if(sensorLeft == 1){
      digitalWrite(PIN_MOTOR_LEFT_A, 1);
      digitalWrite(PIN_MOTOR_LEFT_B, 1);
    }
    if(sensorRight == 1){
      digitalWrite(PIN_MOTOR_RIGHT_A, 1);
      digitalWrite(PIN_MOTOR_RIGHT_B, 1);
    }
  }
}

void setup() {
//  Serial.begin(115200);
//  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PIN_MOTOR_LEFT_A, OUTPUT);
  pinMode(PIN_MOTOR_LEFT_B, OUTPUT);
  pinMode(PIN_MOTOR_RIGHT_A, OUTPUT);
  pinMode(PIN_MOTOR_RIGHT_B, OUTPUT);
  
  pinMode(PIN_SPD_A1_INPUT, INPUT_PULLUP); digitalWrite(PIN_SPD_A1_INPUT, HIGH);
  pinMode(PIN_SPD_A2_INPUT, INPUT_PULLUP); digitalWrite(PIN_SPD_A2_INPUT, HIGH);
  pinMode(PIN_SENSOR_LEFT_INPUT, INPUT_PULLUP);
  pinMode(PIN_SENSOR_RIGHT_INPUT, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(PIN_SPD_A1_INPUT), triggerSpdInputFalling, FALLING); 
  attachInterrupt(digitalPinToInterrupt(PIN_SPD_A2_INPUT), triggerSpdInputRising, RISING); 
}

void loop() {}
