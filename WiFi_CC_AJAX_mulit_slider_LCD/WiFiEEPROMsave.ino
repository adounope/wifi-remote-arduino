void WiFiEEPROMsave(){
  for (int i = 0; i < 96; ++i) {
    EEPROM.write(i, 0);
  }
  for (int i = 0; i < WiFiSSID.length(); ++i){
    EEPROM.write(i, WiFiSSID[i]);
    Serial.print("Wrote: ");
    Serial.println(WiFiSSID[i]);
  }
  for (int i = 0; i < WiFiPASS.length(); ++i){
    EEPROM.write(32 + i, WiFiPASS[i]);
    Serial.print("Wrote: ");
    Serial.println(WiFiPASS[i]);
  }
  EEPROM.commit();
  Serial.println("saving wifi data");
  ESP.reset();
}
