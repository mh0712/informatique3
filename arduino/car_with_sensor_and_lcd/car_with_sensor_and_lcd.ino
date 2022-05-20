#define in1 5
#define in2 6
#define in3 10
#define in4 11
int ventA=8;
int ventB=9;
const int sensorMin=0 , sensorMax=1024; //analogRead() this funcions return a value between 0 and 1023 
const int sfm=3;
char state;
int x=0;
int pm=255;

//#include <Wire.h>
//#include <LiquidCrystal_I2C.h>

//LiquidCrystal_I2C lcd(0x27,20,4);
void setup() {
                      // initialize the lcd 
//  lcd.init();
//  // Print a message to the LCD.
//  lcd.backlight();
 
  
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);  
  pinMode(sfm,OUTPUT);
  pinMode(ventA, OUTPUT);  
  pinMode(ventB,OUTPUT);  
  Serial.begin(9600);
  digitalWrite(ventA,LOW);
  digitalWrite(ventB,LOW);
  x=0;
}
void loop() {
  if (Serial.available() > 0) {
    state = Serial.read();
    Serial.println(state);
    Stop();
    switch (state) {
      case 'F':
        forward();
        break;
      case 'G':
        forwardleft();
        break;  
      case 'I':
        forwardright();
        break;  
      case 'J':
        backright();
        break;
      case 'H':
        backleft();
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;

        
//      case '1':
//        pm=0.1*pm;
//        break;
//      case '2':
//        pm=0.2*pm;
//        break;
//      case '3':
//        pm=0.3*pm;
//        break;
//      case '4':
//        pm=0.4*pm;
//        break;
//      case '5':
//        pm=0.5*pm;
//        break;
//      case '6':
//        pm=0.6*pm;
//        break;
//      case '7':
//        pm=0.7*pm;
//        break;
//      case '8':
//        pm=0.8*pm;
//        break;
//      case '9':
//        pm=0.9*pm;
//        break;   
//      case 'q':
//        pm=1*pm;
//        break; 
                     
    }
    
  }
  int sensorReading = analogRead(A0);//flame sensor 
  int range = map ( sensorReading , sensorMin , sensorMax , 0 , 3 );

  // range value :

  switch ( range ){
    case 0 :
//      lcd.clear();
//      lcd.setCursor(2,1);
//      lcd.print(" ** Close fire ** ");
//      lcd.setCursor(0,2);
//      lcd.print("We all are gonna die");
      digitalWrite(sfm,HIGH);//buzzer set to high
 //     digitalWrite(ventA,HIGH);
  //    digitalWrite(ventB,LOW);
      x=1;
      break;
    case 1 :
//      lcd.clear();
//      lcd.setCursor(0,1);
//      lcd.print(" ** Distant fire ** ");
//      lcd.setCursor(0,2);
//      lcd.print("   OWWW SHITTTT   ");
      digitalWrite(sfm,LOW);
      x=0;
      break;
    case 2 :
      digitalWrite(sfm,LOW);
//      lcd.clear();
//      lcd.setCursor(2,1);
//      lcd.print(" ** No fire ** ");
//      lcd.setCursor(2,2);
//      lcd.print("wassup nig**ria");
      x=0;
      break;
      
  }
  delay(1); // delay between reads  
  if (x==1){
     digitalWrite(ventA,HIGH);
     digitalWrite(ventB,LOW); 
     delay(1);
  }
  else{
     digitalWrite(ventA,LOW);
     digitalWrite(ventB,LOW);
     delay(1); 
  }
  delay(1);
}

void forward() {
  analogWrite(in1, pm);//in2 low
  analogWrite(in3, pm);//in4 low
}
void forwardleft() {
  analogWrite(in1, 20*pm);
  analogWrite(in3, 60*pm);
}
void forwardright() {
  analogWrite(in1, 60*pm);
  analogWrite(in3, 20*pm);
}
void back() {
  analogWrite(in2, pm);
  analogWrite(in4, pm);
}
void backright() {
  analogWrite(in2, 20*pm);
  analogWrite(in4, 60*pm);
}
void backleft() {
  analogWrite(in2, 60*pm);
  analogWrite(in4, 20*pm);
}
void left() {
  analogWrite(in4, 60*pm);
  analogWrite(in1, 60*pm);
}
void right() {
  analogWrite(in3, 60*pm);
  analogWrite(in2, 60*pm);
}
void Stop() {
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
}
