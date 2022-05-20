void connect_webhost(){

  URL_withPacket = HOST_URL;//pull in the base URL
  URL_withPacket += String(unit_id);
  URL_withPacket += "&id=";
  URL_withPacket += String(sensor_value);//sensor value
  URL_withPacket += payload_end;
  URL_withPacket += "Host: ";
  URL_withPacket += host;
  URL_withPacket += "\r\n";
 // URL_withPacket += "Connection: close\r\n\r\n";   
  
/*
URL_withPacket=getData;
URL_withPacket+=String(sensor_value);
*/
//add more strings 


  //build the payload url
  counter=0;
  payload_size=0;
  for ( int i=0 ; i< (URL_withPacket.length());i++){ //lenght of a string 
    payload[payload_size+i]=URL_withPacket[i];
    counter++;
  }
  payload_size=counter+payload_size;

  if( connect_ESP()){

    // parse the returned data _d156##  , 56 is the value of d1

    if(read_ESP(keyword_d1,sizeof(keyword_d1),5000,0)){
          if(read_ESP(keyword_doublehash,sizeof(keyword_doublehash),5000,1)){
            for(int i=1; i<=(scratch_data_from_ESP[0]-sizeof(keyword_doublehash)+1); i++)
             d1_from_ESP[i] = scratch_data_from_ESP[i];
             d1_from_ESP[0] = (scratch_data_from_ESP[0]-sizeof(keyword_doublehash)+1); 

    if(read_ESP(keyword_linkdisc,sizeof(keyword_linkdisc),5000,0)){
              // delay(10);
              Serial.println("FOUND DATA & DISCONNECTED");
              serial_dump_ESP();
              }

       Serial.print("data sensor d1 = ");
       Serial.print(d1_from_ESP[1]);
       Serial.print(d1_from_ESP[2]);
       Serial.print(":");
       Serial.print(d1_from_ESP[3]);
       Serial.print(d1_from_ESP[4]);  
       Serial.println("");
      
          }// ##
    }// d1
    
  }//IF CONNECT ESP


  
}//connect to webhost
