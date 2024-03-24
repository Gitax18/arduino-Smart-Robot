void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(2) == LOW){
    digitalWrite(9, HIGH);
    Serial.println("MOVE");
  }
  else{  
    digitalWrite(9, LOW);
    Serial.println("REVERSE");

  }
  delay(10);
}
