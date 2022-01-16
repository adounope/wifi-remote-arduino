void loop() {
  client = server.available();
  if(!client){return;}
  Serial.println("New Client.");
  currentTime = millis();
  previousTime = currentTime;
  while(client.connected() && currentTime - previousTime <= timeoutTime){
    currentTime = millis();
    if (client.available()) {
      line = client.readStringUntil('\r');
      //     Serial.print(line);
      header += line;
      if(header.indexOf("Host:")<0){
        headerGET = header ;
      }
      if (line[0] == '\n' && line.length()==1) {
        delay(15);
        pos1 = headerGET.indexOf('=');
        pos2 = headerGET.indexOf('&');
        pos3 = headerGET.indexOf('=', pos1+1);
        pos4 = headerGET.indexOf('&', pos2+1);
        pos5 = headerGET.indexOf('=', pos3+1);
        pos6 = headerGET.indexOf('&', pos4+1);
        if(headerGET.indexOf("configMode")>=0){
          launchConfigState=true;
        }
        if(headerGET.indexOf("controlMode")>=0){
          launchConfigState=false;
        }
        delay(5);
        client.println("HTTP/1.1 200 OK");
        client.println("Content-type:text/html");
        client.println("Connection: close");
        client.println();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(launchConfigState==false){
  if(headerGET.indexOf("val")>=0) {
    valueString1 = headerGET.substring(pos1+1, pos2);//decode 
    valueString2 = headerGET.substring(pos3+1, pos4);//decode 
    valueString3 = headerGET.substring(pos5+1, pos6);//decode 
  }
  else{
   controlHTML();
      }
      Serial.println("controlHTML activated");
            Serial.print("   SLIDER 1 = ");
            Serial.print(valueString1); 
            v1=valueString1.toInt();
            v1D=v1%10;
            v1T=(v1%100-v1D)/10;
            v1H=(v1-v1%100)/100;
            lcd.setCursor(2,0);
            lcd.print(v1D);
            lcd.setCursor(1,0);
            lcd.print(v1T);
            lcd.setCursor(0,0);
            lcd.print(v1H);
            
            Serial.print("   SLIDER 2 = ");
            Serial.print(valueString2);
            v2=valueString2.toInt();
            v2D=v2%10;
            v2T=(v2%100-v2D)/10;
            v2H=(v2-v2%100)/100;
            lcd.setCursor(9,0);
            lcd.print(v2D);
            lcd.setCursor(8,0);
            lcd.print(v2T);
            lcd.setCursor(7,0);
            lcd.print(v2H);

            Serial.print("   SLIDER 3 = ");
            Serial.print(valueString3);
            v3=valueString3.toInt();
            v3D=v3%10;
            v3T=(v3%100-v3D)/10;
            v3H=(v3-v3%100)/100;
            lcd.setCursor(15,0);
            lcd.print(v3D);
            lcd.setCursor(14,0);
            lcd.print(v3T);
            lcd.setCursor(13,0);
            lcd.print(v3H);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     else{
     configHTML();
   }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            client.println();   // HTTP的完結空行           
            break;   // While迴路中斷
      }
      }
      }
      // 清除header
          Serial.println("");
        Serial.println("//////////");
    Serial.println(headerGET);
     Serial.println("//////////");
    header = "";
    headerGET="";
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");  
}
