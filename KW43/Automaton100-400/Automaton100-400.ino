// Zunächst muss die Bibliothek geladen werden:
#include <Automaton.h>

int ledPin = D6;  // die grüne LED soll blinken

// Nun wird ein Objekt der Klasse Atm_led definiert, das typischerweise für LED verwendet
// wird. Das Objekt bekommt den Variablennamen gruen, damit können wir diese LED
// eindeutig zuordnen.
Atm_led gruen;

void setup() {
  // Dem Objekt gruen werden nun über Methodenaufrufe verschiedene Eigenschaften zugeordnet:
  gruen.begin( ledPin )   // Hier wird der Pin der grünen LED definiert
    .blink( 100, 400 )    // Hier wird das (mögliche) Blinken in Form von 100ms an und
                          // 400ms aus definiert (aber noch nicht aktiviert)
    .trigger( gruen.EVT_BLINK ); // und hier wird das Blinken aktiviert, da ein
                                 // Trigger EVT_BLINK gesetzt wird.
}

void loop() {
  // in Loop muss nun (scheinbar) nichts mehr gemacht werden. Damit die grüne LED aber
  // zu den richtigen Zeitpunkten an- bzw. abgeschaltet wird, muss bei jedem loop die
  // Automaton-Bibliothek aufgerufen werden, die dann jeweils erforderliche
  // Aktionen startet.
  automaton.run();
}