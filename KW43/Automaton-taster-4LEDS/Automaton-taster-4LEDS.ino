#include <Automaton.h>

Atm_led blau1, blau2, rot, gruen;
Atm_button taste;

void setup() {
  blau1.begin( D0, true ).blink(100, 400);
  blau2.begin( D4, true ).blink(100, 400);
  rot.begin( D5 ).blink(100, 400).brightness( 10 );  // Helligkeit auf 10 eingestellt
  gruen.begin( D6 ).blink( 200, 300 );               // Rhythmus geändert

  taste.begin( D2 ).onPress( tastendruck );
}

void tastendruck( int idx, int v, int up ) {
  if ( v ) {
    // Dieser Bereich wird immer ausgeführt, wenn die Taste gedrückt wurde:
    blau1.trigger( blau1.EVT_TOGGLE_BLINK );
    blau2.trigger( blau2.EVT_TOGGLE_BLINK );
    rot.trigger( rot.EVT_TOGGLE_BLINK );
    gruen.trigger( gruen.EVT_TOGGLE_BLINK );
  }
}

void loop() {
  automaton.run();
}