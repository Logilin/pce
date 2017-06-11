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
	WDTCTL  = WDTPW + WDTHOLD;

	// System clock 1MHz
	DCOCTL  = CALDCO_1MHZ;
	BCSCTL1 = CALBC1_1MHZ;

	// Configure a 2Hz timer.
	TA0CTL |= TASSEL_2 | ID_3 | MC_1 | TACLR; // System Clock divided by 8.
	TACCR0 = 62500;  // 1MHz / 8 / 2Hz = 62500

	// Led P1.6 on output.
	P1DIR |= BIT6;

	// Enable timer interrupt
	TACCTL0 = CCIE;

	__enable_interrupt();

	// Let's sleep
	__bis_SR_register(LPM1_bits + GIE);
	return 0;
}


#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER_A(void)
{
	// Toggle the led.
	P1OUT ^= BIT6;
}


