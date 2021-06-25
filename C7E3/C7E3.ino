#define PIN_DIODE 13

String msg = "";

void setup() {
  Serial.begin(9600);
  pinMode(PIN_DIODE,OUTPUT);
}

void loop() {

  while(Serial.available())
  {
    delay(10);
    char rcvByte = Serial.read();  
    msg += rcvByte;
  }

  if(msg.length() > 0){
    Serial.print(msg);
    if(msg == "on"){
      digitalWrite(PIN_DIODE,HIGH);
    } else if(msg == "off") {
      digitalWrite(PIN_DIODE,LOW);
    }
    msg = "";
  }
}
