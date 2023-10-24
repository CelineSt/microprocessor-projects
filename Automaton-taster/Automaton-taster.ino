// Zunächst muss die Bibliothek geladen werden:
#include <Automaton.h>

int ledPin     = D6;  // die grüne LED soll blinken
int tastenPin  = D2;  // Pin der Taste

// Nun wird ein Objekt der Klasse Atm_led definiert, das typischerweise für LED verwendet
// wird. Das Objekt bekommt den Variablennamen gruen, damit können wir diese LED
// eindeutig zuordnen.
Atm_led gruen;
Atm_button taste;

void setup() {
  gruen.begin( ledPin )
    .blink( 100, 400 );  // Der Trigger entfällt hier, damit ist das Blinken zwar
                         // definiert, aber nicht gestartet.

  taste.begin( tastenPin )    // Taste wird konfiguriert
    .onPress( tastendruck );  // Die Callback-Funktion für den Fall eines Tastendrucks
                              // wird als 'tastendruck' festgelegt
}

void tastendruck( int idx, int v, int up ) {
  if ( v ) {
    // Dieser Bereich wird immer ausgeführt, wenn die Taste gedrückt wurde:
    gruen.trigger( gruen.EVT_TOGGLE_BLINK );
  }
  // Die Funktion hat keinen Rückgabewert (deshalb void), da sie nur
  // das Umschalten durchführen soll.
}

void loop() {
  // in Loop muss nun (scheinbar) nichts mehr gemacht werden. Damit die grüne LED aber
  // zu den richtigen Zeitpunkten an- bzw. abgeschaltet wird, muss bei jedem loop die
  // Automaton-Bibliothek aufgerufen werden, die dann jeweils erforderliche
  // Aktionen startet.
  // Zudem wird so auch ein eventueller Tastendruck registriert, das Debouncing überwacht
  // und der Callback aufgerufen.
  automaton.run();
}