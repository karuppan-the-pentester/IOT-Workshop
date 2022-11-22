//Assigning PB5r pin as Nuzzer
#define Buzzer 2

void setup() {                
  pinMode(Buzzer, OUTPUT);     
}

void loop() {
  digitalWrite(Buzzer, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);               // wait for a half second
  digitalWrite(Buzzer, LOW);    // turn the LED off by making the voltage LOW
  delay(500);               // wait for a half second         
}
