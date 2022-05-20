#include <SoftwareSerial.h>
//#include <ArduinoJson.h> 
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

#include <DHT.h> //humidity , temperature 
#define DHTPIN 0
#define DHTTYPE DHT11 // DHT21 DHT22
DHT dht(DHTPIN,DHTTYPE);
#include <MQ2.h> // smoke gas sensor


int Analog_Input=A0;
int lpg , co ,smoke;

MQ2 mq2(Analog_Input);

WiFiClient client;//each device that transmits and receives data from he WiFi
long myChannelNumber= 1722122 ; //32 bits(4 bytes) , extended size variable , int 2 bytes
const char myWriteAPIKey[]="FZ1DRW431LDNV8W4";

SoftwareSerial nodemcu(D3,D2);

String AP = "POCO X3 Pro";       // AP NAME ACCESS POINT 
String PASS = "hello999"; // AP PASSWORD

void setup(){
  Serial.begin(9600);//baud rate 
  nodemcu.begin(9600);
  while(!Serial) continue;

  WiFi.begin(AP,PASS); 
  while(WiFi.status()!=WL_CONNECTED){
    delay(200);
    Serial.print("..");
  } 
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);////////////

  ////////
  dht.begin();
  mq2.begin();
}

void loop(){

  delay(2000);
  float h= dht.readHumidity();
  float t= dht.readTemperature(); // as celsius
  float f= dht.readTemperature(true); // isFahrenheit = true 
  //isnan nan : Not A NUMBER
  //it returns true when it is not a number so we have to check if any reads failed and exit early to try again 
  if ( isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT module");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C\t");
  Serial.print(f);
  Serial.print(" *F\t");

  float* value = mq2.read(false);
//  lpg=mq2.readLPG();
  co=mq2.readCO();
  smoke=mq2.readSmoke();
//  Serial.print("LPG: ");
//  Serial.print(lpg);
  Serial.print(" CO: ");
  Serial.print(co);
  Serial.print(" Smoke: ");
  Serial.print(smoke);
  Serial.println();
  delay(1000);

    ThingSpeak.setField(1,t);
    ThingSpeak.setField(2,h);
    ThingSpeak.setField(3,co);
    ThingSpeak.setField(5,smoke);
  ThingSpeak.writeFields(myChannelNumber,myWriteAPIKey);
  delay(2000);

  

}
