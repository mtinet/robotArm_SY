#include <Servo.h>

Servo servo1;  
Servo servo2;  
Servo servo3;  
Servo servo4;  

int CdS = A4; 
int IRSensor = A5; 


void setup() {
  Serial.begin(9600);
  
  pinMode(CdS, INPUT);
  pinMode(IRSensor, INPUT);
  
  servo1.attach(3); 
  servo2.attach(5); 
  servo3.attach(6); 
  servo4.attach(9);  

  servo1.write(90);  //초기값 세팅
  servo2.write(0); 
  servo3.write(90); 
  servo4.write(90);  
  delay(1000);

  Serial.println("Initialized Complete. RobotArm Started");
  Serial.println("If you want to stop the RobotArm? Send 's' on your serial monitor.");
}  
  

void loop() {
  int CdSValue = analogRead(CdS); 
  Serial.println(CdSValue);
  if (CdSValue > 103) {
    run();
  } else {
    start1();
  }
}

// 초기화 함수
void start1(){
  servo1.write(90);  //초기값 세팅
  servo2.write(0); 
  servo3.write(90); 
  servo4.write(90);  
  delay(1000);  
}

// 실행 함수
void run() {
  int sensorStatus = digitalRead(IRSensor); 
  if (sensorStatus == 1)
  {
    Serial.println("black!"); 
    catch1();
    right1();
  }
  else  {
    Serial.println("white!");
    catch1();
    left1();
  }
}

// 로봇암이 병뚜껑을 잡는 동작
void catch1(){
  servo1.write(90);  //초기값 세팅
  servo2.write(0); 
  servo3.write(90); 
  servo4.write(90);  
  delay(1000);  
  servo1.write(110);  //내려가고
  servo2.write(10); 
  servo3.write(145); 
  servo4.write(90);  
  delay(1000); 
  servo1.write(160);  //90보다 크면 잡는거
  servo2.write(10); 
  servo3.write(145); 
  servo4.write(90);
  delay(1000);  
  servo1.write(160);  //초기값 세팅
  servo2.write(10); 
  servo3.write(90); 
  servo4.write(90); 
  delay(1000);
}

// 로봇암이 오른쪽 상자에 병뚜껑을 놓는 동작
void right1(){
  servo1.write(160);  //오른쪽으로 돌아서
  servo2.write(0); 
  servo3.write(90); 
  servo4.write(0);  
  delay(1000);   
  servo1.write(160);  //각도를 조금 숙이고
  servo2.write(0); 
  servo3.write(130); 
  servo4.write(0);  
  delay(500);
  servo1.write(90);  //집게 벌려 내려놓고
  servo2.write(0); 
  servo3.write(130); 
  servo4.write(0);
  delay(1000);
  servo1.write(90);  //초기값 세팅
  servo2.write(0); 
  servo3.write(90); 
  servo4.write(90);  
}

// 로봇암이 왼쪽 상자에 병뚜껑을 놓는 동작
void left1(){
  servo1.write(160);  //왼쪽으로 돌아서
  servo2.write(0); 
  servo3.write(90); 
  servo4.write(180);  
  delay(1000);   
  servo1.write(160);  //각도를 조금 숙이고
  servo2.write(0); 
  servo3.write(130); 
  servo4.write(180);  
  delay(500);
  servo1.write(90);  //집게벌려 내려놓고
  servo2.write(0); 
  servo3.write(130); 
  servo4.write(180);
  delay(1000);
  servo1.write(90);  //초기값 세팅
  servo2.write(0); 
  servo3.write(90); 
  servo4.write(90);       
}
