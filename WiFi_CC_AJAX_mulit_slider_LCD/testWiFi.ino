bool testWifi(void){
  Serial.println("Waiting for wifi connection");
  for(int t=0;t<30; t++){
    if(WiFi.status()== WL_CONNECTED){
      Serial.println("WiFi conected");
      return true;
      }
      delay(500);
    Serial.print('*');
    }
  Serial.println("");
  Serial.print("WiFi connection failed successfully, ESP8266 is out of patience.");
     return false;
  }
