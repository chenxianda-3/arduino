volatile float dist;
float checkdistance_A2_A3() {
  digitalWrite(A2, LOW);
  delayMicroseconds(2);
  digitalWrite(A2, HIGH);
  delayMicroseconds(10);
  digitalWrite(A2, LOW);
  float distance = pulseIn(A3, HIGH) / 58.00;
  delay(10);
  return distance;
}
void setup(){
  dist = 0;
  pinMode(A2, OUTPUT);//超声波测距输出口
  pinMode(A3, INPUT);//超声波测距输入口
  Serial.begin(9600);
  pinMode(4, OUTPUT);//蜂鸣器管脚口
}

void loop(){
  dist = checkdistance_A2_A3();
  Serial.print("hello");
  Serial.println(dist);
  delay(1000);
  if (dist < 8) {     //设置距离小于8cm就预警，这是测试用的
    Serial.print("hello");//检错
    tone(4,100,1000);
  }
}
