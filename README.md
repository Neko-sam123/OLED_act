#ESP32 Activity - Web Server for Relay

pin 25,26,27,14,12,13 - ito lahat nagamit na pin tignan niyo sa code para saan yung pins

Sa code:
 - Yung "ssid" palitan niyo nung pangalan ng hotspot niyo
 - yung "password" din palitan niyo ng password na nilagay niyo sa hotspot niyo
 - set niyo sa 2.4 Ghz yung "set AP band" sa hotspot settings
 - nakadisconnect/nakaoff dapat wifi niyo para ma-set yung AP band
 - pag nakakonek na yung esp32 sa hotspot , or umilaw yung led na nilagay ko na indicator sa code, tignan nio sa Serial Monitor yung IP address ng esp32
 - dapat may isa pang device na nakakonek sa hotspot, bale dalawang device, isa para sa hotspot, isa para kumonnect din sa hotspot
 - para dun sa isang device na nakakonek sa hotspot sesearch mo yung IP address nung esp32 sa search bar ng google/chrome, yung IP address nalabas sa Serial Monitor pag wala reset nio lng yung esp32, pindutin yung left button tapos piprint nia uli yung IP address sa Serial Monitor
 - Tapos pag nakapasok kau sa web server ng esp32 makokontrol nio na yung mga device na nakakonek sa pins ng esp32
   
Note: pag di gumana edi wow
