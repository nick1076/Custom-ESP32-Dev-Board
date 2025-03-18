
void setup() {
  pinMode(0, OUTPUT);
  Serial.begin(9600);
  digitalWrite(0, HIGH);
  
}

void loop() {
  delay(500);
  Serial.println("Hello World");
}
