#include "ESP8266WiFi.h"
int incomingByte = 0;
String dataRecived="";
String fileName="";
String lastData="";

void setup() {

  Serial.begin(115200);//abro el puerto serie
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

}

void loop() {
 // int numberNetwork=WiFi.scanNetworks(false,true);//escaneo bloqueante de redes wifi, incluyendo las ocultas
  if(Serial.available())
  {
    dataRecived="";
  }
  while(Serial.available())//chequeo si llego informacion por serial, y si llego vacio el buffer
  {
       dataRecived=dataRecived+Serial.readString();
       
      
  }
  if(dataRecived!="")
  {

    if(strcmp(dataRecived.c_str(), "sn")>0)
    {
      
      Serial.println("llego sn");
      
    }else if(strcmp(dataRecived.c_str(), "m")>0)
    {
      
      Serial.println("llego m");
    }else if(strcmp(dataRecived.c_str(), "s")>0)
    {
      
      Serial.println("llego s");
    }else if(strcmp(lastData.c_str(), "sn")>0){
      fileName=dataRecived;
      Serial.println(fileName);
    }

 
    lastData=dataRecived;
    dataRecived="";
    
  }
  
  
  

}
