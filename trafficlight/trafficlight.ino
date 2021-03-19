#define R 13
#define G 11

void setup(){
    pinMode(R, OUTPUT); 
    pinMode(G, OUTPUT);
}

void loop(){
    green();
    red();
}
void green(){
  digitalWrite(R, LOW);
  digitalWrite(G, HIGH);
  delay(5000);
    
  for(int i=0; i<3; i++){
    digitalWrite(G, LOW);
    delay(1000);
    digitalWrite(G, HIGH);
    delay(1000);
  }
  
  digitalWrite(G, LOW);
  delay(1000);
}   

void red(){
    digitalWrite(G, LOW);
    digitalWrite(R, HIGH);
    delay(3000);
}  
