void scanWiFi(){
  WiFiDetail="";
  int number = WiFi.scanNetworks();
  for (int wifinum = 0; wifinum < number; wifinum++){
    WiFiDetail += "<p>";
    WiFiDetail += WiFi.SSID(wifinum);
    WiFiDetail +=" (";
    WiFiDetail += WiFi.RSSI(wifinum);
    WiFiDetail += ")";
    WiFiDetail += "</p>";
  } 
}
