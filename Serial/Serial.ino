/*
  Serial통신
  아두이노 보드간, 아두이노와 IDE 사이의 통신을 지원한다.
  최초 동일한 baudrate 설정 후, 시리얼모니터에 입출력이 가능하다.
*/
const int RED = 13;
const int GREEN = 12;

void setup()
{
  //Serial 통신 초기화
  //baudrate 통신속도 지정
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop()
{
/*  //사용자 입력값이 있는 경우만 처리
  if(Serial.available())
  {
    int value = (int)Serial.read();
    Serial.print("inputValue : ");
    Serial.println(value);
    //개행문자는 조기리턴처리
    if(value == 13 || value == 10)
      return;
    digitalWrite(13, value==49?HIGH:LOW);
    
  }
  */  
  
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
//  Serial.println(HIGH);
  delay(5000); // Wait for 1000 millisecond(s)
  // turn the LED off by making the voltage LOW

  for(int i = 0; i < 5; i++){
    digitalWrite(RED, LOW);
    delay(500);
    digitalWrite(RED, HIGH);
    delay(500);
  }
    
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
//  Serial.println(LOW);
  delay(3000); // Wait for 1000 millisecond(s)

}
