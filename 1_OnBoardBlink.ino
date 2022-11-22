//Declaring RLED as a red light 
#define RLED RED_LED
//Declaring GLED as a green light 
#define GLED GREEN_LED
  

void setup() {                
  pinMode(GLED, OUTPUT);     
  pinMode(RLED, OUTPUT);     
}


void loop() {
  digitalWrite(GLED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);               // wait for a half second
  digitalWrite(GLED, LOW);    // turn the LED off by making the voltage LOW
  delay(500);               // wait for a half second
  digitalWrite(RLED, HIGH);   
  delay(500);              
  digitalWrite(RLED, LOW);   
  delay(500);            
}
