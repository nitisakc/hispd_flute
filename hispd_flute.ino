const int PIN_SPD_A1_INPUT = 2;         //Encode A
const int PIN_SPD_A2_INPUT = 3;         //Encode A
const int PIN_MOTOR_A = 6;              //Motor A
const int PIN_MOTOR_B = 7;              //Motor B
const int PIN_SENSOR_A_INPUT = 18;      //Sensor on the same side as the motor.
const int PIN_SENSOR_B_INPUT = 19;      //Sensors opposite the motor.

int sensorA, sensorB;

void triggerSpdInputFalling() {
  sensorA = digitalRead(PIN_SENSOR_A_INPUT);
  sensorB = digitalRead(PIN_SENSOR_B_INPUT);
  
  if(sensorA == sensorB || sensorA == 1){
    digitalWrite(PIN_MOTOR_A, 0);
    digitalWrite(PIN_MOTOR_B, 0);
  }
}

void triggerSpdInputRising() {
  sensorA = digitalRead(PIN_SENSOR_A_INPUT);
  sensorB = digitalRead(PIN_SENSOR_B_INPUT);
  
  if(sensorA == sensorB || sensorA == 1){
    digitalWrite(PIN_MOTOR_A, 1);
    digitalWrite(PIN_MOTOR_B, 1);
  }
}

void setup() {
  pinMode(PIN_MOTOR_A, OUTPUT);
  pinMode(PIN_MOTOR_B, OUTPUT);
  
  pinMode(PIN_SPD_A1_INPUT, INPUT_PULLUP); digitalWrite(PIN_SPD_A1_INPUT, HIGH);
  pinMode(PIN_SPD_A2_INPUT, INPUT_PULLUP); digitalWrite(PIN_SPD_A2_INPUT, HIGH);
  pinMode(PIN_SENSOR_A_INPUT, INPUT_PULLUP);
  pinMode(PIN_SENSOR_B_INPUT, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(PIN_SPD_A1_INPUT), triggerSpdInputFalling, FALLING); 
  attachInterrupt(digitalPinToInterrupt(PIN_SPD_A2_INPUT), triggerSpdInputRising, RISING); 
}

void loop() {}
