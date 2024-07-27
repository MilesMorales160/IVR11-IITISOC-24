#define m1p1 11
#define m1p2 10
#define m2p1 9
#define m2p2 8
#define E1 6
#define E2 5
#define steering A5
#define Max_adjustment 25
#define Input 400
#define left_front_sensor 18
#define right_front_sensor 19
#define left_back_sensor 20
#define right_back_sensor 21
#define diameter 7

long timerlf1 = 0, timerlf2 = 0, timerrf1 = 0, timerrf2 = 0, timerlb1 = 0, timerlb2 = 0, timerrb1 = 0, timerrb2 = 0;

int l = Input/2;
int r = Input - l;

float lf_speed;
float rf_speed;
float lb_speed;
float rb_speed;

int lf_speed8;
int rf_speed8;
int lb_speed8;
int rb_speed8;

void setup() {
  Serial.begin(384000);
  pinMode(m1p1, OUTPUT);
  pinMode(m1p2, OUTPUT);
  pinMode(m2p1, OUTPUT);
  pinMode(m2p2, OUTPUT);
  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(steering, INPUT);
  pinMode(speed_sensor, INPUT);
  pinMode(left_front_sensor,INPUT);
  pinMode(right_front_sensor,INPUT);
  pinMode(left_back_sensor,INPUT);
  pinMode(right_back_sensor,INPUT);
  attachInterrupt(digitalPinToInterrupt(left_front_sensor),fl1,RISING);
  attachInterrupt(digitalPinToInterrupt(right_front_sensor),fr1,RISING);
  attachInterrupt(digitalPinToInterrupt(left_back_sensor),fl2,RISING);
  attachInterrupt(digitalPinToInterrupt(right_back_sensor),fr2,RISING);
  /* digitalWrite(m1p1,HIGH);
    digitalWrite(m1p2,LOW);
    digitalWrite(m2p1,HIGH);
    digitalWrite(m2p2,LOW);
    analogWrite(E1,l);
    analogWrite(E2,r); */
}

void loop() {
  int val = analogRead(pot);
  power_distribute(val);
  Serial.println(val);
  Serial.println(preval);
}
void power_distribute(int val) {
  int steering_exact = val - 512;
  float steering_angle = steering_exact * 0.06;
  float turning_radius = (33 / sin(steering_angle * PI / 180)) + 1.75;
  float Max_adjustment = Input * 24 / turning_radius;
  int adjustment = map(abs(steering_exact), 0, 512, 0, Max_adjustment);
  if (steering_exact > 0) {
    l = 200 + adjustment;
    r = Input - l;
  }
  else {
    l = 200 - adjustment;
    r = Input - l;
  }
  l = constrain(l, 0, 255);
  r = constrain(r, 0, 255);
  analogWrite(E1, l);
  analogWrite(E2, r);
  analogWrite(E3,l);
  analogWrite(E4,r);
  Serial.println(steering_exact);
  Serial.print("left ");
  Serial.println(l);
  Serial.print("right");
  Serial.println(r);
  Serial.println(steering_angle);
}
void sense_slip(float Max_adjustment){
  float slip_percent = 255/(Input+25) + 3;
  float slip_threshold = Max_adjustment + Input*slip_percent/100;
  if(abs(lf_speed-rf_speed)>slip_threshold){
    int Speed = Input/2;
    analogWrite(E1,Speed);
    analogWrite(E2,Speed);
  }
  if(abs(lb_speed-rb_speed)>slip_threshold){
    int Speed = Input/2;
    analogWrite(E3,Speed);
    analogWrite(E4,Speed);
  }
}
void cal_speed(){
  if(timerlf1!=timerlf2){
    lf_speed = 252.0/millis();
    lf_speed8 = lf_speed*4.25;
  }
  if(timerrf1!=timerrf2){
    rf_speed = 252.0/millis();
    rf_speed8 = lf_speed*4.25;
  }
  if(timerlb1!=timerlb2){
    lb_speed = 252.0/millis();
    lb_speed8 = lf_speed*4.25;
  }
  if(timerrb1!=timerrb2){
    rb_speed = 252.0/millis();
    rb_speed8 = lf_speed*4.25;
  }
  Serial.println(lf_speed);
  Serial.println(rf_speed);
  Serial.println(lb_speed);
  Serial.println(rb_speed);
}
void fl1(){
   timerlf2 = millis();
}
void fr1(){
   timerrf2 = millis();
}
void fl2(){
   timerlb2 = millis();
}
void fr2(){
   timerrb2 = millis();
}
