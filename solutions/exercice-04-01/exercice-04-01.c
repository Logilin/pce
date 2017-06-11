// -------------------------------------------------------------------------
// Correction d'exercice du cours "Programmer en C sur microcontroleurs".
// 
// https://www.logilin.fr/formations/formation-langage-c-embarque-sur-micro-controleurs/
//
// (c) 2007-2017 Logilin - https://www.logilin.fr
//
// christophe.blaess@logilin.fr
//

#include <msp430g2553.h>

void wait_ms(int delay_ms);

int main(void)
{
	int push = 0;
	int i;

	// Disable watchdog
	WDTCTL = WDTPW + WDTHOLD;

	// Leds P1.0 and P1.6 on output.
	P1DIR = BIT0 | BIT6;

	// Pull-up on P1.3 (button).
	P1OUT = BIT3;
	P1REN = BIT3;

	while (1) {
		// If button pressed...
		if ((P1IN & BIT3) == 0) {
			if (push == 0) {
				// Toggle green led 10 times, period 0.5 sec, duty cycle 1/4
				for (i = 0; i < 10; i ++) {
					// Green led on during 500/4 msec.
					P1OUT |= BIT6;
					wait_ms(500/4);
					// Green led off during 3*500/4 msec.
					P1OUT &= ~BIT6;
					wait_ms(3*500/4);
				}
				push = 1;
			} else {
				// Toggle red led 5 times, period 1 sec, duty cycle 1/2
				for (i = 0; i < 5; i ++) {
					// Red led on during 1000/2 msec.
					P1OUT |= BIT0;
					wait_ms(500);
					// Red led off during 1000/2 msec.
					P1OUT &= ~BIT0;
					wait_ms(500);
				}
				push = 0;
			}
        }
	}
    return 0;
}


void wait_ms(int delay_ms)
{
	int i;
	for (i = 0; i < delay_ms * 10; i ++)
		;
}


