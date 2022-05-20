#include <SoftwareSerial.h>

#define RX 2
#define TX 3

//SSID AND KEY
const char SSID_ESP[]="B A K";
const char SSID_KEY[]="PrtscSysrq1.";
//String theseeker22_id="";
//String theseeker22_password="(6OIjIx?5P<26_I$";

String location_url = "/RECEIVER.php?unit=";

/*------------------------------------------------------------------------------
 * ---------------------------------------------------------------------
 * -------------------------------------------------------------------------------
 *-------------------------------------------------------------------------------*/


//urls
String  HOST_URL ="GET /RECEIVER.php?unit=";
const char* host = "theseaker22.000webhostapp.com\r\n";



//String API="L8393JYHDDAF0B0B";
//String HOST="api.thingspeak.com";
//String field="field1";
//String getData= "GET /update?api_key=" + API + "&" + field +"=";




/*------------------------------------------------------------------------------
 * ---------------------------------------------------------------------
 * -------------------------------------------------------------------------------
 *-------------------------------------------------------------------------------*/


//modes
const char CWMODE = '1';// 1=STATION 2=APMODE 3=BOTH
const char CIPMUX = '1';// 0=SINGLE CONNECTION 1 = MULTI 

SoftwareSerial ESP8266(RX,TX);//RX , TX

//WE WILL DEFINE THE FUNCTIONS THAT WILL BE USED IN THE ENTIRE CODE 
boolean setup_ESP();
boolean connect_ESP();
boolean read_ESP(const char keyword1[],int keyword1_size,int timeout_value, byte mode);//mode 1 for saving data
boolean timeout_check(int timeout_ms);
void timeout_start();
void serial_dump_ESP();
void connect_webhost();




// define global variables :
unsigned long timeout_start_value;
char scratch_data_from_ESP[20];
char ip_address[16];
char payload[150];
byte payload_size=0, counter=0;

String unit_id="1";
int sensor_value = 123;
int sensor_readBack = 0;
String URL_withPacket = "";                                                                                                  
String payload_end = " HTTP/1.1\r\n";


char d1_from_ESP[11];




// define keywords :

const char keyword_OK[]="OK";
const char keyword_Ready[]="Ready";//WIFI GOT IP
const char keyword_no_change[]="no change";
const char keyword_blank[] = "#&";
const char keyword_ip[] = "192.";
const char keyword_rn[]="\r\n";
const char keyword_quote[] = "\"";
const char keyword_carrot[] = ">";
const char keyword_sendok[] = "SEND OK";
const char keyword_linkdisc[] = "Unlink";

const char keyword_d1[] = "d1";
const char keyword_doublehash[] = "##";

//

void setup() {
  // Pin Modes for ESP tx and rx
  pinMode(RX,INPUT);
  pinMode(TX,OUTPUT);

  ESP8266.begin(115200);
  //ESP8266.listen();
  Serial.begin(9600);
  //delay(5000);

  //setup the esp
  setup_ESP();
}

void loop() {
  sensor_value=getSensorData();
  connect_webhost();
  // the robot and sensors code
  delay(5000);
}

int getSensorData(){
  return random(1000);
}
