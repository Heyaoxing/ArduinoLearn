const int tx = 1;
const int rx = 0;
void setup()
{
   //  Serial.begin(115200);//设置波特率为9600。
     pinMode(rx,INPUT_PULLUP); 
     pinMode(tx,INPUT_PULLUP); 
}
void loop()
{
    delay(500);
    Serial.println("Hello World!");//显示“Hello World！”字符串
}
