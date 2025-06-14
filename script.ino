#include "DHT.h"
#define DHTPIN D1
#define DHTTYPE DHT11


#include <FirebaseESP8266.h>



DHT dht(DHTPIN, DHTTYPE);
#include <ESP8266WiFi.h>



// Insert your network credentials
#define WIFI_SSID "projectnetwork"
#define WIFI_PASSWORD "projectnetwork"
#define FIREBASE_HOST "project-network-389c5-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "uIJIcO7aNWVrwsykJ1IQfJVX0Cs7cSxgRRljNMkK"

//Define Firebase Data object
FirebaseData fbdo;

//unsigned long sendDataPrevMillis = 0;
//int count = 0;


void setup(){
  pinMode(DHTPIN, INPUT);
  dht.begin();
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println();

Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}

void loop(){
 delay(1000);
  float h = dht.readHumidity();

  float t = dht.readTemperature();
  
Firebase.setFloat(fbdo, F("Humidity"), h);
Firebase.setFloat(fbdo, F("Temp"), t);
Firebase.setString(fbdo, F("DS"),"ON");
}
