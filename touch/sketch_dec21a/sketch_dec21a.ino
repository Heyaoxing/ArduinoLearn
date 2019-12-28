
int buzzer=9;
int buzzer10=10;
char codes[4];
String code_1="01111";
String code_2="00111";
String code_3="00011";
String code_4="00001";
String code_5="00000";
String code_6="10000";
String code_7="11000";
String code_8="11100";
String code_9="11110";
String code_0="11111";


char numbers[4];

void setup() {
  pinMode(buzzer10,INPUT);   //设置引脚为输出模式
  pinMode(buzzer,OUTPUT);
  Serial.begin(115200); //设置波特率为115200

}

int counter=0; 
 
void loop() {
  
  // put your main code here, to run repeatedly:

  if(analogRead(buzzer10)>0){
    digitalWrite(buzzer,HIGH);
    counter++;
  }else if(counter>0){
    digitalWrite(buzzer,LOW);
    process(counter);
    counter=0;
  }else{
    digitalWrite(buzzer,LOW);
  }

  delay(10);
}

int code_index=0;
void process(int i){
    char code='0';
    if(i>15){
       Serial.println("长编码"); 
       code='1';
    }else if(i>5&&i<15){
       Serial.println("短编码"); 
       code='0';
    }

    codes[code_index]= code;
    if(code_index==4){
      decoding();
      code_index=0; 
    }else{
      code_index++;
    }   
}

int num_index=0;
void decoding(){
     if(num_index==4){
         translation();
         num_index=0;
     }

      Serial.println("解码");    
      Serial.println(codes); 
     if(strcmp(codes,"01111")==0){
        numbers[num_index]='1';
        Serial.println("电码 1");
     }else if(strcmp(codes,"00111")==0){
         numbers[num_index]='2';
        Serial.println("电码 2");
     }else if(strcmp(codes,"00011")==0){
         numbers[num_index]='3';
        Serial.println("电码 3");
     }else if(strcmp(codes,"00001")==0){
         numbers[num_index]='4';
        Serial.println("电码 4");
     }else if(strcmp(codes,"00000")==0){
         numbers[num_index]='5';
        Serial.println("电码 5");
     }else if(strcmp(codes,"10000")==0){
         numbers[num_index]='6';
        Serial.println("电码 6");
     }else if(strcmp(codes,"11000")==0){
         numbers[num_index]='7';
        Serial.println("电码 7");
     }else if(strcmp(codes,"11100")==0){
         numbers[num_index]='8';
        Serial.println("电码 8");
     }else if(strcmp(codes,"11110")==0){
         numbers[num_index]='9';
        Serial.println("电码 9");
     }else if(strcmp(codes,"11111")==0){
         numbers[num_index]='0';
        Serial.println("电码 0");
     }else{
        Serial.println("解码失败");
     }
     num_index++;
}

void translation(){
   Serial.println("翻译");    
   Serial.println(numbers);
}
