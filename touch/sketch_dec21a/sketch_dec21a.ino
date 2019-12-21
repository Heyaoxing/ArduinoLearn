
void setup() {
  pinMode(A5,INPUT);   //设置引脚 A5 为输出模式
  Serial.begin(9600); //设置波特率为9600
}
 
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(A5)); //串口输出 A5读取到的值
  delay(200);   //延时200毫秒

}
