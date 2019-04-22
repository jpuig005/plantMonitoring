#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

/////////////2/////////////
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "d5a911672acd418988a76dd7d62d5ebb"; //This needs to be your own!

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "WOKO"; // This is your wifi "Name"
char pass[] = "surftheworld4U!";// this is your wifi password

BlynkTimer timer;


#define DHTTYPE DHT11   // DHT Shield uses DHT 11
#define DHTPIN D8       // DHT Shield uses pin D4

DHT dht(DHTPIN, DHTTYPE);   //Define Temperature & Humidity Sensor


float h = 0;
float t = 0;
float l = 0;
float m = 0;

void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(D2, OUTPUT);
  pinMode(D6, OUTPUT);

  digitalWrite(D2, LOW);
  digitalWrite(D6, LOW);

  Blynk.begin(auth, ssid, pass);
  timer.setInterval(5000L, sendSensor);
}

void sendSensor()
{

  //Reading from the temp-hum sensor:
  h = dht.readHumidity();
  t = dht.readTemperature(false);

  int hAsInt = int(h); // converts to int removing unessisary decimal points
  int tAsInt = int(t);
  //Reading from the light sensor:
  digitalWrite(D2, HIGH);
  delay(100);
  l = analogRead(A0);

  int lAsInt = int(l);

  int lightPerc = map(lAsInt, 8, 500, 100, 0);
  delay(200);
  digitalWrite(D2, LOW);
  delay(100);
  digitalWrite(D6, HIGH);
  delay(100);
  m = analogRead(A0);

  int mAsInt = int(m); 

  int moisturePerc = map(mAsInt, 300, 507, 100, 0);
  delay(200);
  digitalWrite(D6, LOW);
  
  
  if (isnan(h) || isnan(t) || isnan(l) || isnan(m)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  //Read the moisture sensor
  
  Blynk.virtualWrite(V1, tAsInt);
  Blynk.virtualWrite(V2, hAsInt);
  Blynk.virtualWrite(V3, lightPerc);
  Blynk.virtualWrite(V4, moisturePerc);
}

void loop()
{
   Blynk.run();
   timer.run();
}
