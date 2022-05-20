// this function gets a keyword to look for 
// -- keyword1[] is the keyword we are lookin for , return "1" if found
// -- keyword1_size is the size of that keyword in bytes - sizeof() -
// -- timeout_value is the max time of waiting to find the keyword
// -- mode : 1 -> save every byte received to 'save_data_from_esp[]'

boolean read_ESP(const char keyword1[],int keyword1_size,int timeout_value, byte mode){
  timeout_start_value=millis();
  char data_in[20];//an array (buffer) to check the keyword
  int scratch_length=1;// length of 'scratch_data_from_ESP[]' array 
  keyword1_size --; // bcz we get an extra null character from the sizeof()

//fill the array , length must be equal to the keyword1 size not more

for ( byte i=0 ; i<keyword1_size;i++){
  //end the funcion if the time passed is greatr than the timeout_value

      // lock step 
      while(!ESP8266.available()){ //wait until we get a response from te esp
        if((millis()-timeout_start_value)>timeout_value){
          Serial.println("timeout");
          serial_dump_ESP();
          return 0  ; // to end the function
          
        }
      }// we get out of this loop when we get a serial response 
      
  //we will save the data to the array 'data_in[]'

  data_in[i]=ESP8266.read();// return the oldest character in the buffer and removes it from the buffer 
  //and repeats the same thing until Serial.available()return 0

    if(mode==1){//this will save all of the data to the scratch_data_from
    scratch_data_from_ESP[scratch_length]=data_in[i];//starts at 1
    scratch_data_from_ESP[0]=scratch_length;// [0] is used to hold the length of the array
    scratch_length++;//increment the length
    }//mode 1
    
}//for loop



while(1){//stay here until the keyword is found or a timeout occurs  
  for ( byte i=0 ; i<keyword1_size;i++){
    if ( keyword1[i]!= data_in[i])
    break;
    if (i==(keyword1_size-1)){
    return 1;
    }
   }//for

   //if the response had a lot of stuffs before the keyword was received 
   //so we hav to start deleting the old data in the buffer and save the new data 
   //we delete one character at a time
   // we roll the data in and out of the buffer at the same time

   for ( byte i=0 ; i<(keyword1_size-1);i++){
    data_in[i]=data_in[i+1]; 
   }


  
  while(!ESP8266.available()){ //wait until we get a response from te esp
    if((millis()-timeout_start_value)>timeout_value){
      Serial.println("timeout");
      serial_dump_ESP();
      return 0 ; // to end the function  
    }
  }// we get out of this loop when we get a serial response   

  data_in[keyword1_size-1]=ESP8266.read();

   
  if(mode==1){//continue to save everything if thsi is set
  scratch_data_from_ESP[scratch_length]=data_in[keyword1_size-1];
  scratch_data_from_ESP[0]=scratch_length;
  scratch_length++;
  }//mode 1

  
   
}// while 1

  


}//read until
