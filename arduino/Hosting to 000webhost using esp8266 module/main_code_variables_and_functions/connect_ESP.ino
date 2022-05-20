boolean connect_ESP(){

  Serial.println("CONNECTING");
  ESP8266.print("AT+CIPSTART=,\"TCP\",\"theseaker22.000webhostapp.com\",80\r\n"); // to change

  if(read_ESP(keyword_OK,sizeof(keyword_OK),5000,0)){
  serial_dump_ESP();  
  Serial.println("CONNECTED");
  ESP8266.print("AT+CIPSEND=0,");
  ESP8266.print(payload_size);
  serial_dump_ESP();
  ESP8266.print("\r\n");
  
  if(read_ESP(keyword_carrot,sizeof(keyword_carrot),5000,0)){
  Serial.println("READY TO SEND carrot received ");
  for(int i=0; i<payload_size; i++)//print the payload to the ESP
  ESP8266.print(payload[i]);
  
  if(read_ESP(keyword_sendok,sizeof(keyword_sendok),5000,0)){
  Serial.println("SENT");
  return 1;
  }
  else //haven't got 'send ok '
  Serial.println("FAILED TO SEND");
  }
  else // haven't got the carrot >
  Serial.println("FAILED TO get >");
  
  
  }
  else{
    Serial.println("FAILED TO CONNECT");
    setup_ESP(); //re setup the esp8266
    
  }
  
  
}
