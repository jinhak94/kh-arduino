/*
  pulldown저항
    저항을 접지부에 연결
    기본값 0, 누르면 1
    
    pullup저항
    저항을 전원부에 연결
    기본값 1, 누르면 0
*/

const int PULLDOWN = 10;
const int PULLUP = 8;
const int PULLUP_BUILTIN = 6;

void setup()
{
  Serial.begin(9600);
  pinMode(PULLDOWN , INPUT);
  pinMode(PULLUP, INPUT);
  pinMode(PULLUP_BUILTIN, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  int pdVal = digitalRead(PULLDOWN);
  Serial.print("pd = ");
  Serial.print(pdVal);
  
  int puVal = digitalRead(PULLUP);
  Serial.print(", pu = ");
  Serial.print(puVal);
  
  int pubVal = digitalRead(PULLUP_BUILTIN);
  Serial.print(", pub = ");
  Serial.println(pubVal);
  
  digitalWrite(LED_BUILTIN, puVal);
  delay(100);
}
