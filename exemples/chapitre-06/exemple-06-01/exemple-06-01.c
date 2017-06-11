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
	// Stop the watchdog.
	WDTCTL = WDTPW + WDTHOLD;
	// Leds P1.0 et P1.6 on output.
	P1DIR = BIT0 | BIT6;
	// Green Led On
    P1OUT = BIT0;
    // Pull-up resistor P1.3
	P1REN |= BIT3;
	P1OUT |= BIT3;
    // Interrupt on falling edge
	P1IES |= BIT3;
	// Avoid immediate interrupt.
	P1IFG &= ~BIT3;
	// Enable push button interrupt.
	P1IE  |= BIT3;
	__enable_interrupt();
	// Let's sleep (cf SLAU144j § 2.3 p. 38)
	__bis_SR_register(LPM1_bits + GIE);
	// Never reached.
	return 0;
}


#pragma vector = PORT1_VECTOR
__interrupt void P1_ISR(void)
{
	// Button pressed?
	if (P1IFG & BIT3)
		P1OUT ^= BIT0 | BIT6;
	// Acknowledge the interrupt.
	P1IFG = 0;
}


