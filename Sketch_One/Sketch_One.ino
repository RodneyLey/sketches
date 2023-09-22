int LED = 13;
int counter = 0;
void setup() {
  // put your setup code here, to run once:
pinMode (LED, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  counter +=1; // adding one everytime
  Serial.print("Blink Number # ");
  Serial.println(counter);
digitalWrite (LED, HIGH);
delay (1000);
digitalWrite (LED, LOW);
delay(500);

}
