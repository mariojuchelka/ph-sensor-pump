Dieses Projekt ist ein einfacher, aber effektiver pH-Controller, der mit einem Arduino, einem pH-Sensor, einem OLED-Display und einer Dosierpumpe arbeitet. Der Controller misst kontinuierlich den pH-Wert einer Flüssigkeit, zeigt ihn an und dosiert bei Bedarf eine pH-senkende Lösung, um den gewünschten Bereich zu halten.

Hauptanwendungen

Hydroponische Systeme: Aufrechterhaltung optimaler pH-Werte für Pflanzen.

Aquaristik: Kontrolle des pH-Werts in Aquarien.

Wasseraufbereitung: Regulierung des pH-Werts in chemischen oder industriellen Prozessen.

Laboranwendungen: Präzise Steuerung des pH-Werts in Experimenten.

Funktionsweise

Der pH-Sensor misst die Spannung, die proportional zum aktuellen pH-Wert der Flüssigkeit ist.

Der Arduino liest die Daten vom Sensor und wandelt sie in einen pH-Wert um.

Der OLED-Bildschirm zeigt den gemessenen pH-Wert in Echtzeit an.

Überschreitet der pH-Wert einen voreingestellten Schwellenwert (z. B. 6.5), aktiviert der Arduino das Relaismodul, um die Dosierpumpe einzuschalten.

Die Pumpe gibt eine kleine Menge einer pH-senkenden Lösung ab, und der Prozess wiederholt sich, bis der gewünschte Bereich erreicht ist.

Vorteile

Automatisierung: Kein manuelles Überprüfen oder Nachjustieren des pH-Werts erforderlich.

Kostengünstig: Aufbau mit erschwinglichen Komponenten.

Erweiterbar: Kann leicht mit zusätzlichen Sensoren (z. B. Temperatur, EC) ergänzt werden.

Falls weitere Details oder spezifische Anpassungen benötigt werden, lass es mich wissen!








Anschlussplan

Arduino Uno Pins

A0: Signal des pH-Sensors

D3: Steuerpin des Relaismoduls

A4 (SDA): Datenleitung des OLED-Displays

A5 (SCL): Taktleitung des OLED-Displays

pH-Sensor

Signal: An A0 des Arduino

VCC: An 5V des Arduino

GND: An GND des Arduino

OLED-Display

SDA: An A4 des Arduino

SCL: An A5 des Arduino

VCC: An 5V des Arduino

GND: An GND des Arduino

Relaismodul

IN: An D3 des Arduino

VCC: An 5V des Arduino

GND: An GND des Arduino

Dosierpumpe

Eingang (+): Mit dem Ausgang des Relaismoduls verbunden

Eingang (-): Mit dem Netzteil-GND verbunden

Netzteil

+12V: An den Relaisausgang (gemeinsamer Anschluss)

GND: Direkt an die Pumpe und das Relais-GND anschließen
