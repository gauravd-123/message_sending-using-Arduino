
#include <SoftwareSerial.h>

SoftwareSerial sim800l(0, 1); // RX,TX for Arduino and for the module it's TXD RXD, they should be inverted

#define button1 7    //Button pins, on the other pin it's wired with GND
#define button2 6
#define button3 5
#define button4 4
#define button5 3

bool button_State; //Button state


void setup()
{
 
  pinMode(button1, INPUT_PULLUP); //The button is always on HIGH level, when pressed it goes LOW
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);
  sim800l.begin(9600);   //Module baude rate, this is on max
  Serial.begin(9600);   
  delay(1000);
}
 
void loop()
{
  

  button_State = digitalRead(button1);   //constantly reading the button State
 
  if (button_State == LOW) {            //And if it's pressed
    Serial.println("\nButton 1 pressed");   //Shows this message on the serial monitor
    delay(200);                         //Small delay to avoid detecting the button press many times
    
    SendSMS1();                          //function is called

 }
 
  if (sim800l.available()){            //Displays on the serial monitor if there's a communication from the module
    Serial.write(sim800l.read()); 
  }


  button_State = digitalRead(button2);   
 
  if (button_State == LOW) {            
    Serial.println('\n');
    Serial.println("\nButton 2 pressed");   
    delay(200);                         
    
    SendSMS2();                          

 }
 
  if (sim800l.available()){            
    Serial.write(sim800l.read()); 
  }

  button_State = digitalRead(button3);   
 
  if (button_State == LOW) {            
    Serial.println('\n');
    Serial.println("\nButton 3 pressed");   
    delay(200);                         
    
    SendSMS3();                          

 }
 
  if (sim800l.available()){            
    Serial.write(sim800l.read()); 
  }

  button_State = digitalRead(button4);   
 
  if (button_State == LOW) {            
    Serial.println('\n');
    Serial.println("\nButton 4 pressed");   
    delay(200);                         
    
    SendSMS4();                          

 }
 
  if (sim800l.available()){            
    Serial.write(sim800l.read()); 
  }

  button_State = digitalRead(button5);   
 
  if (button_State == LOW) {            
    Serial.println('\n');
    Serial.println("\nButton 5 pressed");   
    delay(200);                         
    
    SendSMS5();                          

 }
 
  if (sim800l.available()){            
    Serial.write(sim800l.read()); 
  }
}



void SendSMS1()
{
  
  Serial.println("\nSending SMS...");               //Show this message on serial monitor
  sim800l.print("AT+CMGF=1\r");                   //Set the module to SMS mode
  delay(100);
  sim800l.print("AT+CMGS=\"+919969459522\"\r");  //Your phone number with country code
  delay(500);
  sim800l.print("Welcome APML");       //This is the text to send to the phone number
  delay(500);
  sim800l.print((char)26);// (required according to the datasheet)
  delay(500);
  sim800l.println();
  Serial.println("Text Sent as 'Welcome APML' ");
  delay(500);

}

void SendSMS2()
{
  
  Serial.println("\nSending SMS...");               
  sim800l.print("AT+CMGF=1\r");                   
  delay(100);
  sim800l.print("AT+CMGS=\"+919969459522\"\r");  
  delay(500);
  sim800l.print("Vehicle Started");       
  delay(500);
  sim800l.print((char)26);
  delay(500);
  sim800l.println();
  Serial.println("Text Sent as 'Vehicle Started' ");
  delay(500);

}

void SendSMS3()
{
  
  Serial.println("\nSending SMS...");               
  sim800l.print("AT+CMGF=1\r");                   
  delay(100);
  sim800l.print("AT+CMGS=\"+919969459522\"\r");  
  delay(500);
  sim800l.print("Vehicle Problem");       
  delay(500);
  sim800l.print((char)26);
  delay(500);
  sim800l.println();
  Serial.println("Text Sent as 'Vehicle Problem' ");
  delay(500);

}

void SendSMS4()
{
  
  Serial.println("\nSending SMS...");               
  sim800l.print("AT+CMGF=1\r");                   
  delay(100);
  sim800l.print("AT+CMGS=\"+919969459522\"\r");  
  delay(500);
  sim800l.print("Vehicle Problem Resolved");       
  delay(500);
  sim800l.print((char)26);
  delay(500);
  sim800l.println();
  Serial.println("Text Sent as 'Vehicle Problem Resolved' ");
  delay(500);

}

void SendSMS5()
{
  
  Serial.println("\nSending SMS...");               
  sim800l.print("AT+CMGF=1\r");                   
  delay(100);
  sim800l.print("AT+CMGS=\"+919969459522\"\r");  
  delay(500);
  sim800l.print("Vehicle Reached");       
  delay(500);
  sim800l.print((char)26);// (required according to the datasheet)
  delay(500);
  sim800l.println();
  Serial.println("Text Sent as 'Vehicle Reached' ");
  delay(500);

}
