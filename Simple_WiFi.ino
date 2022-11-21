//Importing library
#include <SPI.h>
#include <WiFi.h>

//Enter your Hotspot name and password
char ssid[]="SSID";
char password[]="PASSWORD";
IPAddress ip;

void setup()
{
  //Initialize Serial Port
  Serial.begin(9600); 
  Serial.print("Attempting to connect to Network named: ");
  Serial.println(ssid);
  
  //Connect to WiFI
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED)
  {
    // print dots while we wait to connect
    Serial.print(".");
    delay(300);
  }
  //If you are connected print the IP Address
  ip=WiFi.localIP();
  Serial.print("\nIP Address: ");
  Serial.println(ip);
  Serial.print("\nPaste this link in your browser : http://");
  Serial.println(ip);
 }
 
void loop(){
  while ( WiFi.status() != WL_CONNECTED)
  {
    // print dots while we wait to connect
    Serial.println("\nConnection Error");
    delay(1000);
  }
 }
