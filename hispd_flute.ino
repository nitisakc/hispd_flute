const int PIN_SPD_A_INPUT = 2;
const int PIN_SPD_B_INPUT = 3;
const int PIN_MOTOR_LEFT = 4;
const int PIN_MOTOR_RIGHT = 5;
const int PIN_SENSOR_LEFT_INPUT = 18;
const int PIN_SENSOR_RIGHT_INPUT = 19;
const int PPR = 400;

long count = 0;
int spd, b, sensorLeft, sensorRight;

void triggerSpdInput() {
  spd = digitalRead(PIN_SPD_A_INPUT);
//  b = digitalRead(PIN_SPD_B_INPUT);
  sensorLeft = digitalRead(PIN_SENSOR_LEFT_INPUT);
  sensorRight = digitalRead(PIN_SENSOR_RIGHT_INPUT);
  
  digitalWrite(LED_BUILTIN, spd);
  Serial.println(count++ / (PPR * 2));
  
  if(sensorLeft == sensorRight){
    digitalWrite(PIN_MOTOR_LEFT, spd);
    digitalWrite(PIN_MOTOR_RIGHT, spd);
  }else{
    digitalWrite(PIN_MOTOR_LEFT, sensorLeft == 0 ? sensorLeft : spd);
    digitalWrite(PIN_MOTOR_RIGHT,  sensorRight == 0 ? sensorRight : spd);
  }
}

void triggerSpdInputFalling() {
  sensorLeft = digitalRead(PIN_SENSOR_LEFT_INPUT);
  sensorRight = digitalRead(PIN_SENSOR_RIGHT_INPUT);
  digitalWrite(LED_BUILTIN, spd);
  Serial.println("0");
  
  if(sensorLeft == sensorRight){
    digitalWrite(PIN_MOTOR_LEFT, 0);
    digitalWrite(PIN_MOTOR_RIGHT, 0);
  }else{
    digitalWrite(PIN_MOTOR_LEFT, sensorLeft == 0 ? sensorLeft : spd);
    digitalWrite(PIN_MOTOR_RIGHT,  sensorRight == 0 ? sensorRight : spd);
  }
}

void triggerSpdInputRising() {
  sensorLeft = digitalRead(PIN_SENSOR_LEFT_INPUT);
  sensorRight = digitalRead(PIN_SENSOR_RIGHT_INPUT);
  digitalWrite(LED_BUILTIN, spd);
  Serial.println("1");
  
  if(sensorLeft == sensorRight){
    digitalWrite(PIN_MOTOR_LEFT, 1);
    digitalWrite(PIN_MOTOR_RIGHT, 1);
  }else{
    digitalWrite(PIN_MOTOR_LEFT, sensorLeft == 0 ? sensorLeft : spd);
    digitalWrite(PIN_MOTOR_RIGHT,  sensorRight == 0 ? sensorRight : spd);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PIN_MOTOR_LEFT, OUTPUT);
  pinMode(PIN_MOTOR_RIGHT, OUTPUT);
  
  pinMode(PIN_SPD_A_INPUT, INPUT_PULLUP); digitalWrite(PIN_SPD_A_INPUT, HIGH);
  pinMode(PIN_SPD_B_INPUT, INPUT_PULLUP); digitalWrite(PIN_SPD_B_INPUT, HIGH);
  pinMode(PIN_SENSOR_LEFT_INPUT, INPUT_PULLUP);
  pinMode(PIN_SENSOR_RIGHT_INPUT, INPUT_PULLUP);
  
//  attachInterrupt(digitalPinToInterrupt(PIN_SPD_A_INPUT), triggerSpdInput, CHANGE); 
  attachInterrupt(digitalPinToInterrupt(PIN_SPD_A_INPUT), triggerSpdInputFalling, FALLING); 
  attachInterrupt(digitalPinToInterrupt(PIN_SPD_B_INPUT), triggerSpdInputRising, RISING); 
}

void loop() {}
