
Automatisierter pH-Controller
Beschreibung
Dieses Projekt verwendet einen Arduino Uno, einen pH-Sensor, ein OLED-Display, ein Relaismodul und eine Pumpe, um den pH-Wert einer Flüssigkeit automatisch zu überwachen und zu regulieren. Es ist ideal für hydroponische Systeme, Aquarien oder Wasseraufbereitungssysteme.

Funktionsweise
Der pH-Sensor misst kontinuierlich den pH-Wert der Flüssigkeit.
Ein OLED-Display zeigt den aktuellen pH-Wert sowie den Durchschnittswert (geglättet) in Echtzeit an.
Falls der gemessene pH-Wert über 6.5 liegt, aktiviert der Arduino ein Relaismodul, das die Pumpe steuert.
Die Pumpe gibt eine kleine Menge einer pH-senkenden Lösung ab, bis der gewünschte Bereich erreicht ist.


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
