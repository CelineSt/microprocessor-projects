int intensity = 1;   // Variable für die gewünschte Helligkeit. Läuft von 1 hoch auf 1023,
                     // dann wieder zurück auf 0
int delta = 1;       // Der Unterschied zwischen zwei aufeinanderfolgenden
                     // Helligkeitsstufen. Je größer, desto
                     // schneller ändert sich die Helligkeit.

void setup() {
  pinMode(D6, OUTPUT);
  digitalWrite(D6, LOW);   // externe LED, LOW ist hier AUS
}

void loop() {
   analogWrite(D6, intensity);   // LED D6 wird mit PWM für den Wert intensity angesteuert.
   delay(5);                     // 5 ms warten, damit der Effekt überhaupt beobachtbar wird

   // intensity darf nicht über 1023 hinaus laufen und nicht unter 0 sinken. Wir drehen
   // rechtzeitig das Vorzeichen von delta:
   if ( intensity >= 1023 || intensity <= 0 ) delta = delta * -1;
      // Der Operator || steht für 'oder' (wie in Ruby)

   // nun das aktuelle Delta anwenden auf den Wert von intensity:
   intensity += delta;
}