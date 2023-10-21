// Teilaufgabe A1: Werberblinklicht

// im Set-Up werden immer die Voreinstellungen vorgenommen, die der Prozessor einmal zu Beginn des Programmes auführt.

// In diesem Fall habe ich definiert, das über den Pin D0 die Lampe erreicht werden kann. Da die Lampe ein Bauteil ist, welches einen Output (und keinen Input, wie beispielsweise ein Sensor) erzeugt, habe ich für den Pin D0 auch noch als Output Anschluss definiert.

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); 
}

// in dem Loop habe ich nun das Programm geschrieben, welches die Lampe zum blinken bringt.

void loop() {
  //die LED wird ausgeschaltet (bei der LED, die ich über den Pin D0 angesteuert habe schaltet wird die LED bei HIGH ausgeschaltet)
  digitalWrite(LED_BUILTIN, HIGH);
  // nun halte ich den Mikroprozessor mit dem Kommando 'delay' für 1,5 Sekunden an (da der Mikroprozessor in diesem Fall keine weiteren Aufgaben hat und nicht noch mehr Lichter etc. angeschlossen sind, kann hier auch das delay Kommando genutzt werden)
  delay(1500);
  // nun wird die LED angeschaltet...
  digitalWrite(LED_BUILTIN, LOW);
  // ... und der Mikroprozessor für 20ms angehalten, um ein kurzes aufblinken zu erzeugen.
  delay(20);
  // dieser Loop wird wiederholt solange der Mikroprozessor mit Strom versorgt wird.                    
}
