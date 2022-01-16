# wifi-remote-arduino(esp8266)
this code run on esp8266 wemos D1R1, with arduino LCD shield
at first, it will try to connect to a wifi using ssid and password store in its eeprom,

if connected, it launch a website there, IP is displayed on LCD

if cannot conntect to wifi, it will become access point, LCD will display 'A' after the IP address to indicate it is in access point mode,
user can connect to a wifi named "ESP8266", password "NOTESP8266" which the esp8266 launch the same website there.

the website have 2 mode, control and config.

control mode page have 3 slide bars, slide the bars and change the value on LCD. it also have a checkbox "to config".
the esp8266 can read the live value of the slide bar whenever they are moved. the value is shown on the LCD.

in config mode, user can enter wifi ssid and password, check the "save" checkbox, and click "submit" to save wifi data in eeprom, after that, it will restart, 
and try to connect to that wifi
config mode also have a checkbox "to control".

this origionally intended to control servo motors, thats why the slide bar value are from 0 to 180.

by the way, the control mode webpage have some fancy javascript to change background color according to slide bar value
I also slip some small delay() inside, to prevent esp8266 from lagging(cuz that happen)
