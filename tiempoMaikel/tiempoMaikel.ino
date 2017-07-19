#include <Time.h>
int led2=2,led3=3,led4=4;

void setup()
  {   Serial.begin(115200);
      setTime(20,58,00,6,11,2014);
      pinMode(led3,OUTPUT);
       pinMode(led2,OUTPUT); 
       pinMode(led4,OUTPUT);
       digitalWrite(led2,HIGH);
       digitalWrite(led3,HIGH);
       digitalWrite(led4,HIGH);
      
  }
void loop()
  {  
    
    time_t t = now();

      Serial.print(day(t));
      Serial.print(+ "/") ;
      Serial.print(month(t));
      Serial.print(+ "/") ;
      Serial.print(year(t)); 
      Serial.print( " ") ;
      Serial.print(hour(t));  
      Serial.print(+ ":") ;
      Serial.print(minute(t));
      Serial.print(":") ;
      Serial.println(second(t));
      Serial.println(minute(t));
      if(minute(t)==59){
        
              digitalWrite(led2, LOW);
          delay(3000);
      digitalWrite(led2, HIGH);
      delay(3000);
        };
      /*delay(3000);
      digitalWrite(led2,LOW);
      delay(3000);
 
      digitalWrite(led3, HIGH);
                delay(3000);
      digitalWrite(led4, LOW);
      delay(3000);
      digitalWrite(led4, HIGH);*/
      
  }
  
