//Assigning 33rd pin as LED,PD6
#define LED 33

void setup() {                
  pinMode(LED, OUTPUT);     
}

void loop() {
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);               // wait for a half second
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(500);               // wait for a half second         
}
