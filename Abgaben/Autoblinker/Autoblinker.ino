#include <Automaton.h>

Atm_led blau1, blau2, rot, gruen;
Atm_button taste;

int on = 600;
int off = 900;

void setup() {
  blau1.begin( D0, true ).blink(on, off);
  blau2.begin( D4, true).lead( 300 ).blink(on, off);
  rot.begin( D5 ).lead( 600 ).blink(on, off); // verzögerter Start des Blinkens
  gruen.begin( D6 ).lead( 900 ).blink(on, off);

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