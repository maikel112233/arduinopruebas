#define DEBUG(a) Serial.print(a);
String text =  "12345";
void setup() {
  
 Serial.begin(9600);
 long value;
 value = text.toInt();
 DEBUG(value);

}

void loop() {
  // put your main code here, to run repeatedly:

}
