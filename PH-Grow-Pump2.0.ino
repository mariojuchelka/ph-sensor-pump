#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Display-Konfiguration
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1 // Reset-Pin (nicht genutzt)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pins definieren
const int pHSensorPin = A0; // pH-Sensor an Analog-Pin A0
const int pumpRelayPin = 3; // Relais an Digital-Pin D3

// Variablen für pH-Wert
float voltage;
float pHValue;
float calSlope = 3.5; // Kalibrierter Steigungsfaktor
float calOffset = 0.15; // Kalibrierter Offsetwert angepasst
float pHSum = 0; // Summe für Mittelwert
int pHCount = 0; // Anzahl der Messungen

// Schwellenwert
const float maxPH = 6.5;

void setup() {
  Serial.begin(9600); // Serielle Kommunikation starten
  pinMode(pumpRelayPin, OUTPUT); // Relais-Pin als Ausgang definieren
  digitalWrite(pumpRelayPin, HIGH); // Relais standardmäßig ausschalten

  // Display initialisieren
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Adresse 0x3C für die meisten OLED-Displays
    Serial.println("Display konnte nicht initialisiert werden!");
    for (;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("pH-System Start");
  display.display();
  delay(2000);
}

void loop() {
  pHSum = 0;
  pHCount = 0;

  // Sanduhr-Animation mit Messungen während der Wartezeit
  for (int i = 0; i < 60; i++) { // 60-Sekunden-Wartezeit mit Animation und Messungen
    // pH-Sensor-Wert lesen
    int sensorValue = analogRead(pHSensorPin);
    voltage = sensorValue * (5.0 / 1023.0); // Spannung berechnen (Arduino 5V und 10-Bit ADC)
    float currentPH = calSlope * voltage + calOffset; // Aktuellen pH-Wert berechnen

    pHSum += currentPH; // pH-Wert zur Summe hinzufügen
    pHCount++; // Zähler erhöhen

    // Anzeige aktualisieren
    float averagePH = pHSum / pHCount; // Aktuellen Mittelwert berechnen
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("Messung ... :");

    display.setTextSize(1);
    display.setCursor(0, 12);
    display.print("Live pH: ");
    display.print(currentPH, 2); // Aktuellen pH-Wert anzeigen

    display.setCursor(0, 24);
    display.print("Mittel pH: ");
    display.print(averagePH, 2); // Mittelwert anzeigen

    // Countdown anzeigen
    display.setCursor(0, 36);
    display.print("Wartezeit: ");
    display.print(60 - i); // Sekunden verbleibend

    // Fortschrittsbalken
    int progressWidth = map(i, 0, 59, 0, 128); // Fortschritt über 1 Minute gleichmäßig verteilen
    display.fillRect(0, 48, progressWidth, 8, SSD1306_WHITE); // Fortschrittsbalken unten

    display.display();
    delay(1000);
  }

  // Mittelwert berechnen
  float averagePH = pHSum / pHCount;

  // Ausgabe des Mittelwerts
  Serial.print("Mittelwert pH-Wert: ");
  Serial.println(averagePH);

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Mittelwert pH:");
  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print(averagePH, 2); // Mittelwert anzeigen

  // Überprüfen, ob pH-Wert über dem Schwellenwert liegt
  if (averagePH > maxPH) {
    Serial.println("pH zu hoch, Pumpe aktiviert!");
    display.setTextSize(1);
    display.setCursor(0, 50);
    display.println("Pumpe aktiviert!");
    display.display();
    digitalWrite(pumpRelayPin, LOW); // Pumpe einschalten
    delay(1000); // 1 Sekunde Pumpen
    digitalWrite(pumpRelayPin, HIGH); // Pumpe ausschalten
  } else {
    display.setTextSize(1);
    display.setCursor(0, 50);
    display.println("Alles OK");
    display.display();
  }

  delay(5000); // 5 Sekunden Pause bis zum nächsten Durchlauf
}
