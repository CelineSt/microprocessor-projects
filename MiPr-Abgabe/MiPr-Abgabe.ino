void setup() {
  pinMode(D0, OUTPUT); // Konfiguriere den eingebauten LED-Pin als Ausgang
  digitalWrite(D0, LOW);
}

void loop() {
  digitalWrite(D0, HIGH); // LED einschalten
  delay(20);                       // 100 Millisekunden warten
  digitalWrite(D0, LOW);  // LED ausschalten
  delay(1500);                      // 1,5 Sekunden warten
}
