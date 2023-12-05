int Switch = 1;

void setup(){
  pinMode (Switch, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  
  digitalWrite(Switch, LOW);
  delay(60000);
  if (Switch == LOW){
    Serial.print("Switch is OFF");
  }

  digitalWrite(Switch, HIGH);
  delay(5000);
  if (Switch == HIGH){
    Serial.print("Switch is ON");
  }
}

