
void setup() {
  pinMode(0, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  delay(500);
  digitalWrite(0, HIGH);
  digitalWrite(6, LOW);
  Serial.println("Hello World");
  delay(200);
  digitalWrite(0, LOW);
  digitalWrite(6, HIGH);
  delay(300);
}
