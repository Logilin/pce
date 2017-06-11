// -------------------------------------------------------------------------
// Exemples du cours "Programmer en C sur microcontroleurs".
// 
// https://www.logilin.fr/formations/formation-langage-c-embarque-sur-micro-controleurs/
//
// (c) 2007-2017 Logilin - https://www.logilin.fr
//
// christophe.blaess@logilin.fr
// -------------------------------------------------------------------------


#include <msp430g2553.h>


int main(void)
{
	// Disable watchdog
	WDTCTL = WDTPW + WDTHOLD;

	// P1.0 (led) on output.
	P1DIR = BIT0;

	// Pull-up on P1.3 (push button).
	P1OUT = BIT3;
	P1REN = BIT3;

	while (1) {
		if ((P1IN & BIT3) == 0) // button pressed
			P1OUT |= BIT0; // Led on
		else
			P1OUT &= ~BIT0; // Led off
	}
	return 0;
}

