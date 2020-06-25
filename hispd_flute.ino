const int PIN_SPD_A1_INPUT = 2;
const int PIN_SPD_A2_INPUT = 3;
const int PIN_SPD_B_INPUT = 4;
const int PIN_MOTOR_LEFT_A = 5;
const int PIN_MOTOR_LEFT_B = 6;
const int PIN_MOTOR_RIGHT_A = 7;
const int PIN_MOTOR_RIGHT_B = 8;
const int PIN_SENSOR_LEFT_INPUT = 9;
const int PIN_SENSOR_RIGHT_INPUT = 10;
const int PPR = 1000;

long count = 0;
int spd, b, sensorLeft, sensorRight;

void triggerSpdInputFalling() {
  b = digitalRead(PIN_SPD_B_INPUT);
  sensorLeft = digitalRead(PIN_SENSOR_LEFT_INPUT);
  sensorRight = digitalRead(PIN_SENSOR_RIGHT_INPUT);
  digitalWrite(LED_BUILTIN, spd);
//  Serial.println("0");
//  Serial.print("A: 0, B: ");
//  Serial.println(b);
  
  if(sensorLeft == sensorRight){
    digitalWrite(PIN_MOTOR_LEFT_A, 0);
    digitalWrite(PIN_MOTOR_LEFT_B, b);
    
    digitalWrite(PIN_MOTOR_RIGHT_A, 0);
    digitalWrite(PIN_MOTOR_RIGHT_B, b);
  }else{
    if(sensorLeft == 1){
      digitalWrite(PIN_MOTOR_LEFT_A, 0);
      digitalWrite(PIN_MOTOR_LEFT_B, b);
    }
    if(sensorRight == 1){
      digitalWrite(PIN_MOTOR_RIGHT_A, 0);
      digitalWrite(PIN_MOTOR_RIGHT_B, b);
    }
  }
}

void triggerSpdInputRising() {
  b = digitalRead(PIN_SPD_B_INPUT);
  sensorLeft = digitalRead(PIN_SENSOR_LEFT_INPUT);
  sensorRight = digitalRead(PIN_SENSOR_RIGHT_INPUT);
  digitalWrite(LED_BUILTIN, spd);
//  Serial.println("1");
//  Serial.print("A: 1, B: ");
//  Serial.println(b);
  
  if(sensorLeft == sensorRight){
    digitalWrite(PIN_MOTOR_LEFT_A, 1);
    digitalWrite(PIN_MOTOR_LEFT_B, b);
    
    digitalWrite(PIN_MOTOR_RIGHT_A, 1);
    digitalWrite(PIN_MOTOR_RIGHT_B, b);
  }else{
    if(sensorLeft == 1){
      digitalWrite(PIN_MOTOR_LEFT_A, 1);
      digitalWrite(PIN_MOTOR_LEFT_B, b);
    }
    if(sensorRight == 1){
      digitalWrite(PIN_MOTOR_RIGHT_A, 1);
      digitalWrite(PIN_MOTOR_RIGHT_B, b);
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
  pinMode(PIN_SPD_B_INPUT, INPUT_PULLUP); digitalWrite(PIN_SPD_B_INPUT, HIGH);
  pinMode(PIN_SENSOR_LEFT_INPUT, INPUT_PULLUP);
  pinMode(PIN_SENSOR_RIGHT_INPUT, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(PIN_SPD_A1_INPUT), triggerSpdInputFalling, FALLING); 
  attachInterrupt(digitalPinToInterrupt(PIN_SPD_A2_INPUT), triggerSpdInputRising, RISING); 
}

void loop() {}
