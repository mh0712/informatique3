boolean setup_ESP(){
  // send an AT to check if there is response
  ESP8266.print("AT\r\n");
  //sizeof() returns the number of bytes
  if ( read_ESP(keyword_OK,sizeof(keyword_OK),5000,0)) //wait for a ok response for 5 sec
    Serial.println("ESP working");
  else
    Serial.println("ESP not working");
  serial_dump_ESP(); // to get rid of what is left or still coming from the ESP

  //resert the module to start everything fresh

  ESP8266.print("AT+RST\r\n");
  if(read_ESP(keyword_Ready,sizeof(keyword_Ready),5000,0))
    Serial.println('ESP RESET OK');
   else
    Serial.println('ESP RESET FAILED');
  serial_dump_ESP();

  ESP8266.print("AT+CWMODE=");
  ESP8266.print(CWMODE);
  ESP8266.print("\r\n");
  if ( read_ESP(keyword_OK,sizeof(keyword_OK),1000,0))
    Serial.println("ESP CWMODE SET");
  else
    Serial.println("ESP CWMODE SET FAILED");
  serial_dump_ESP();

  //set SSID and password

  ESP8266.print("AT+CWJAP=\"");
  ESP8266.print(SSID_ESP);
  ESP8266.print("\",\"");
  ESP8266.print( SSID_KEY );
  ESP8266.print("\"\r\n");
  if ( read_ESP(keyword_OK,sizeof(keyword_OK),10000,0))
    Serial.println("ESP SSID SET");
  else
    Serial.println("ESP SSID SET FAILED");
  serial_dump_ESP();  

/*
  // check for the ip adress and store it 
  Serial.println("Checking for an ip adress ");
  ESP8266.print("AT+CIFSR\r\n");
  if ( read_ESP(keyword_rn,sizeof(keyword_rn),10000,0)){// we look for the first \r\n after that will be the ip adress
    if ( read_ESP(keyword_rn,sizeof(keyword_rn),1000,1)){
      for ( int i=1 ; i<=(scratch_data_from_ESP[0]-sizeof(keyword_rn)+1);i++)
        ip_address[i]=scratch_data_from_ESP[i];
      ip_address[0]=(scratch_data_from_ESP[0]-sizeof(keyword_rn)+1);
      Serial.print("IP ADDRESS = ");
      for(int i=1; i<=ip_address[0]; i++)//send out the ip address
      Serial.print(ip_address[i]);
      Serial.println("");
    }
  }//if read mode=0
  else
    Serial.println("IP ADRESS FAIL ");
  serial_dump_ESP();
*/
  ESP8266.print("AT+CIPMUX=");
  ESP8266.print(CIPMUX);
  ESP8266.print("\r\n");
  if ( read_ESP(keyword_OK,sizeof(keyword_OK),5000,0))
    Serial.println("ESP CIPMUX SET");
  else
    Serial.println("ESP CIPMUX SET FAILED");
  serial_dump_ESP();   
  


  
}//setup ESP
