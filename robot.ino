 #include<LiquidCrystal.h>
 
 #define m1a 8
 #define m1b 9
 #define m2a 10
 #define m2b 11
 
const int rs=13 , en=12 , d4=5 , d5=4 , d6=3 , d7 =2 ;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);


//#include <SoftwareSerial.h>
//
//SoftwareSerial mySerial(8, 9); // RX, TX


void setup()
{
     Serial.begin(115200);
     pinMode(m1a,OUTPUT);
     pinMode(m1b,OUTPUT);
     pinMode(m2a,OUTPUT);
     pinMode(m2b,OUTPUT);
     WIFI();
      Serial.print("AT+CIPSEND=0,20\r\n"); // MULTIPLE MODE SELECTION 
      delay(50);
      Serial.print("***AGRIBOT***"); 
      delay(50);  
      Serial.print("\n\r\r"); // MULTIPLE MODE SELECTION     
      delay(1000);
}

void loop() {
 SerialEvent();
}

char Serial_read(void)
{
      char ch;
      while(Serial.available() == 0);
      ch = Serial.read(); 
      return ch;
}

void WIFI(void)
{
  String BUFF, buff_1;
  char ch;

  Serial.print('A');
  delay(10);
  Serial.print('T');
  delay(10);
  Serial.print('E');
  delay(10);
  Serial.print('0');
  delay(10);
  Serial.print("\r\n");

  Serial.print("1");

  Serial.print(Serial.readString());
  delay(50);


  Serial.print("AT\r\n");
   Serial.print("2");
  Serial.print(Serial.readString());
  delay(50);

  Serial.print("AT+CWMODE=2\r\n");
   Serial.print("3");
  Serial.print(Serial.readString());
  delay(50);

  Serial.print("AT+CIPMUX=1\r\n");
   Serial.print("8");
  Serial.print(Serial.readString());
  delay(50);

  Serial.print("AT+CIPSERVER=1,80\r\n");
 Serial.print("9");
  Serial.print(Serial.readString());
  delay(50);

  Serial.print("AT+CIFSR\r\n");
  Serial.print("10");
  Serial.print(Serial.readString());
  delay(50);
}

char ch;
void SerialEvent()
{
  //Serial.println("1");
  if (Serial.available() > 0)
      {
          //Serial.println("1");
          if(Serial_read() == '$')
          {
             ch = Serial_read();
             // Serial.println("1");
             Serial.print(ch);
             
             if(ch=='F')                        //  for moving forward
             {   
                 rest();
                 delay(200);
                 digitalWrite(m1a,HIGH);            // right motors
                 digitalWrite(m1b,LOW);
                 digitalWrite(m2a,HIGH);            // left motors
                 digitalWrite(m2b,LOW);
                 Serial.print("AT+CIPSEND=0,14\r\n"); // MULTIPLE MODE SELECTION  
                 delay(50);
                 Serial.print("MOVING FORWARD"); 
                 delay(50);  
                 Serial.print("\n\r\r"); // MULTIPLE MODE SELECTION     
                 delay(200);
             }
             
             if(ch=='B'){                 //  for moving backward
                 rest();
                 delay(200);
                 digitalWrite(m1b,HIGH);        // right motors
                 digitalWrite(m1a,LOW);       
                 digitalWrite(m2b,HIGH);        // left motors
                 digitalWrite(m2a,LOW);
                 Serial.print("AT+CIPSEND=0,15\r\n"); // MULTIPLE MODE SELECTION  
                 delay(50);
                 Serial.print("MOVING BACKWARD"); 
                 delay(50);  
                 Serial.print("\n\r\r"); // MULTIPLE MODE SELECTION     
                 delay(200);
             }
             
             if(ch=='L'){                     //  for moving left
                 rest();
                 delay(200);
                 digitalWrite(m1a,HIGH);          // right motors
                 digitalWrite(m1b,LOW);
                 digitalWrite(m2b,HIGH);          // left motors
                 digitalWrite(m2a,LOW);
                 Serial.print("AT+CIPSEND=0,16\r\n"); // MULTIPLE MODE SELECTION  
                 delay(50);
                 Serial.print("MOVING LEFT SIDE"); 
                 delay(50);  
                 Serial.print("\n\r\r"); // MULTIPLE MODE SELECTION     
                 delay(200);
             }
             
             if(ch=='R'){                   //  for moving right  
                 rest();
                 delay(200);
                 digitalWrite(m1b,HIGH);      // right motors
                 digitalWrite(m1a,LOW);
                 digitalWrite(m2a,HIGH);       // left motors
                 digitalWrite(m2b,LOW);
                 Serial.print("AT+CIPSEND=0,17\r\n"); // MULTIPLE MODE SELECTION  
                 delay(50);
                 Serial.print("MOVING RIGHT SIDE"); 
                 delay(50);  
                 Serial.print("\n\r\r"); // MULTIPLE MODE SELECTION     
                 delay(200);
             }

             if(ch=='S'){                   //  for moving right  
                 rest();
                 delay(200);
                 Serial.print("AT+CIPSEND=0,7\r\n"); // MULTIPLE MODE SELECTION  
                 delay(50);
                 Serial.print("STOPPED"); 
                 delay(50);  
                 Serial.print("\n\r\r"); // MULTIPLE MODE SELECTION     
                 delay(200);
             }
      }
    }     
}

void rest(){
                 digitalWrite(m1a,LOW);
                 digitalWrite(m1b,LOW);
                 digitalWrite(m2a,LOW);
                 digitalWrite(m2b,LOW);
}
