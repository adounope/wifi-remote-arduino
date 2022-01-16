void configHTML(){ 
  if(headerGET.indexOf("controlMode")<0){
     if (headerGET.indexOf("WiFiSSID") >= 0) {
       WiFiSSID=headerGET.substring(pos1+1, pos2);
       Serial.println(WiFiSSID);
     }
     if (headerGET.indexOf("WiFiPASS") >= 0) {
       WiFiPASS=headerGET.substring(pos3+1, pos4);
       Serial.println(WiFiPASS);
       if(headerGET.indexOf("save")>= 0){
         WiFiEEPROMsave();
       }
     }
    if(headerGET.indexOf("reboot")>= 0){ESP.reset();}
  }
  if(WiFi.status()!=WL_CONNECTED){
    scanWiFi();
  } 
  Serial.println("configHTML activated");
  client.println("<!DOCTYPE html><html>");
  client.println("<head><meta charset=\"utf-8\"><meta name='viewport' content='width=device-width, initial-scale=1'>");  //utf-8 related to emoji
  client.println("<link rel=\"icon\" href=\"data:,\">");
  client.println("<style>html {display: inline-block; margin: 0px auto; text-align: center;}");
  client.println("button.SBUTT{width:80px; height:40px;} input.CTCBOX{width:40px; height:40px;} input.save{width:40px; height:40px;}</style>");
  client.println("<title>&#x1F602&#x1F602&#x1F602</title></head><body>");
  client.println(WiFiDetail);
  client.println("<form method=GET>");
  client.println("<input type='text' name='WiFiSSID' placeholder='WiFiSSID'>");
  client.println("<br><input type='password' name='WiFiPASS' placeholder='WiFiPASS'>");
  client.println("<div>Local IP=");
  client.println(WiFi.localIP());
  client.println("</div>");
  client.println("<span><h1>SAVE</h1><input type='checkbox' name='save' class='save'></input>");
  client.println("<button type='submit' class='SBUTT'>SUBMIT</button></span>");
  client.println("<div><h1>TO CONTROL</h1><input type='checkbox' class='CTCBOX' name='controlMode'></input></div>");
  client.println("</form></body></html>");
}
