#include "ESP8266WiFi.h"
#include <SPI.h>
#include <SD.h>

int incomingByte = 0;
String dataRecived="";
String fileName="";
String lastData="";
int numberNetwork=0;
const int chipSelect = D2;
void setup() {
  pinMode(D1,OUTPUT);
  digitalWrite(D1,LOW);
  Serial.begin(9600);//abro el puerto serie
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  numberNetwork=WiFi.scanNetworks(false,true);//escaneo bloqueante de redes wifi, incluyendo las ocultas
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
}
File dataFile;

void loop() {
   
  
  
  if(Serial.available())
  {
    dataRecived="";
  }
  while(Serial.available())//chequeo si llego informacion por serial, y si llego vacio el buffer
  {
    String temp=Serial.readString();

      dataRecived=dataRecived+temp;
      //dataRecived.remove((dataRecived.length())-1); // descomentar si se maneja por consola
   
     
       
      
  }
  if(dataRecived!="")
  {
    Serial.println(dataRecived);

    if(dataRecived == "m") {
      numberNetwork=WiFi.scanNetworks(false,true);
     // Serial.println(fileName);
      digitalWrite(D1,HIGH);
      for(int i=0;i<numberNetwork; i++)//itero en todas las redes que hay y las guardo en un archibo
      {
        
        //dataFile=SD.open((fileName+String(".csv")).c_str(), FILE_WRITE);//abro o creo el archivo csv en modo escritura
        dataFile=SD.open(fileName.c_str(), FILE_WRITE);
        dataFile.println(WiFi.SSID(i)+","+String(WiFi.RSSI(i))+","+String(WiFi.channel(i)));
        //Serial.println(WiFi.SSID(i)+","+String(WiFi.RSSI(i))+","+String(WiFi.channel(i)));
        dataFile.close();
      }
      digitalWrite(D1,LOW);
                
    
  
    }else if(lastData=="sn"){
      
      fileName=dataRecived+String(".csv");
    }

 
    lastData=dataRecived;
    dataRecived="";
    
  }
  
  
  

}
