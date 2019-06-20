# arduino
物联网实践课
Arduino-超声波测距仪-实现近距离蜂鸣器报警

本次实验是要实现当有物体接近超声波测距仪10cm是蜂鸣器就发出警报。

一、实验准备
硬件准备：arduino uno 电板 、USB 数据线、HC-SR04超声波测距仪、无源蜂鸣器低平触发器MH-FMD、面包板、连接线若干
软件准备：arduino
拓展：YFROBOT库


二、编写代码
实验要用到的YFROBOT库：链接：https://pan.baidu.com/s/1bz9_rOo1wNBvGzTbCNmMew
提取码：7pao


代码：

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


三、接线

超声波测距仪连接：超声波测距仪四个接口，GND连接面包板的GND（自己定义），VCC连接面包板的电源（自己定义），TRIG连接管脚接口A2，ECHO连接管脚接口A3
面包板：与蜂鸣器、超声波测距仪相连，面包板的GND连开发板的GND,面包板的电源连开发板的5v
蜂鸣器:与面包板的GND、电源相连，再连arduino uno 电板连接管脚接口4


解释：VCC 指电源，GND指地接，TRIG是控制端（输入），ECHO是返回端（输出）。
之后编译上传。

四、实验结果
测试结果视频链接：https://v.qq.com/x/page/p0886mmr3v2.htmlvuid24=o5NErfA9MrmlQP6bOrcXcQ%3D%3D&ptag=2_7.1.8.19675_copy













