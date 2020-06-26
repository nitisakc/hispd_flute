const int PIN_SPD_A1_INPUT = 2;         //encoder A
const int PIN_SPD_A2_INPUT = 3;         //encoder A
const int PIN_SPD_B1_INPUT = 18;        //encoder B
const int PIN_SPD_B2_INPUT = 19;        //encoder B
const int PIN_MOTOR_LEFT_A = 5;         //Motor Left A
const int PIN_MOTOR_LEFT_B = 6;         //Motor Left B
const int PIN_MOTOR_RIGHT_A = 7;        //Motor Right A
const int PIN_MOTOR_RIGHT_B = 8;        //Motor Right B
const int PIN_SENSOR_LEFT_INPUT = 9;    //Sensor Left
const int PIN_SENSOR_RIGHT_INPUT = 10;  //Sensor Right
const int PPR = 1000;                   //Encoder PPR

long count = 0;
int spd, b, sensorLeft, sensorRight;

void triggerSpdInputFallingA() {
  sensorLeft = digitalRead(PIN_SENSOR_LEFT_INPUT);
  sensorRight = digitalRead(PIN_SENSOR_RIGHT_INPUT);

  if(sensorLeft == sensorRight){ท 
    digitalWrite(PIN_MOTOR_LEFT_A, 0);
    digitalWrite(PIN_MOTOR_RIGHT_A, 0);
  }else{
    if(sensorLeft == 1){
      digitalWrite(PIN_MOTOR_LEFT_A, 0);
    }
    if(sensorRight == 1){
      digitalWrite(PIN_MOTOR_RIGHT_A, 0);
    }
  }
}

void triggerSpdInputRisingA() {
  sensorLeft = digitalRead(PIN_SENSOR_LEFT_INPUT);
  sensorRight = digitalRead(PIN_SENSOR_RIGHT_INPUT);
  
  if(sensorLeft == sensorRight){
    digitalWrite(PIN_MOTOR_LEFT_A, 1);
    digitalWrite(PIN_MOTOR_RIGHT_A, 1);
  }else{
    if(sensorLeft == 1){
      digitalWrite(PIN_MOTOR_LEFT_A, 1);
    }
    if(sensorRight == 1){
      digitalWrite(PIN_MOTOR_RIGHT_A, 1);
    }
  }
}

void triggerSpdInputFallingB() {
  sensorLeft = digitalRead(PIN_SENSOR_LEFT_INPUT);
  sensorRight = digitalRead(PIN_SENSOR_RIGHT_INPUT);

  if(sensorLeft == sensorRight){
    digitalWrite(PIN_MOTOR_LEFT_B, 0);
    digitalWrite(PIN_MOTOR_RIGHT_B, 0);
  }else{
    if(sensorLeft == 1){
      digitalWrite(PIN_MOTOR_LEFT_B, 0);
    }
    if(sensorRight == 1){
      digitalWrite(PIN_MOTOR_RIGHT_B, 0);
    }
  }
}

void triggerSpdInputRisingB() {
  sensorLeft = digitalRead(PIN_SENSOR_LEFT_INPUT);
  sensorRight = digitalRead(PIN_SENSOR_RIGHT_INPUT);
  
  if(sensorLeft == sensorRight){
    digitalWrite(PIN_MOTOR_LEFT_B, 1);
    digitalWrite(PIN_MOTOR_RIGHT_B, 1);
  }else{
    if(sensorLeft == 1){
      digitalWrite(PIN_MOTOR_LEFT_B, 1);
    }
    if(sensorRight == 1){
      digitalWrite(PIN_MOTOR_RIGHT_B, 1);
    }
  }
}

void setup() {
//  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PIN_MOTOR_LEFT_A, OUTPUT);
  pinMode(PIN_MOTOR_LEFT_B, OUTPUT);
  pinMode(PIN_MOTOR_RIGHT_A, OUTPUT);
  pinMode(PIN_MOTOR_RIGHT_B, OUTPUT);
  
  pinMode(PIN_SPD_A1_INPUT, INPUT_PULLUP); digitalWrite(PIN_SPD_A1_INPUT, HIGH);
  pinMode(PIN_SPD_A2_INPUT, INPUT_PULLUP); digitalWrite(PIN_SPD_A2_INPUT, HIGH);
  pinMode(PIN_SPD_B1_INPUT, INPUT_PULLUP); digitalWrite(PIN_SPD_B1_INPUT, HIGH);
  pinMode(PIN_SPD_B2_INPUT, INPUT_PULLUP); digitalWrite(PIN_SPD_B2_INPUT, HIGH);
  pinMode(PIN_SENSOR_LEFT_INPUT, INPUT_PULLUP);
  pinMode(PIN_SENSOR_RIGHT_INPUT, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(PIN_SPD_A1_INPUT), triggerSpdInputFallingA, FALLING); 
  attachInterrupt(digitalPinToInterrupt(PIN_SPD_A2_INPUT), triggerSpdInputRisingA, RISING); 
  attachInterrupt(digitalPinToInterrupt(PIN_SPD_B1_INPUT), triggerSpdInputFallingB, FALLING); 
  attachInterrupt(digitalPinToInterrupt(PIN_SPD_B2_INPUT), triggerSpdInputRisingB, RISING); 
}

void loop() {}
