int val;//定义变量val
int ledpin=13;//定义数字接口13
void setup()
{
    Serial.begin(9600);//设置波特率为9600。
}
void loop()
{
    delay(500);
    Serial.println("Hello World!");//显示“Hello World！”字符串
}
