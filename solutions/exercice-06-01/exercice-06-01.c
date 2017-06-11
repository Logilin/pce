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


int frequency = 5;

int main(void)
{
	// Stop the watchdog.
	WDTCTL  = WDTPW + WDTHOLD;

	// System clock 1MHz
	DCOCTL  = CALDCO_1MHZ;
	BCSCTL1 = CALBC1_1MHZ;

	// Configure a 10Hz timer.
	TA0CTL |= TASSEL_2 | ID_3 | MC_1 | TACLR; // System Clock divided by 8.
	TACCR0 = 1000000 / 8 / frequency / 2;

	// Led P1.6 on output.
	P1DIR |= BIT6;

	// Enable timer interrupt
	TACCTL0 = CCIE;

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




#pragma vector = PORT1_VECTOR
__interrupt void P1_ISR(void)
{
	frequency += 5;
	if (frequency >= 50)
		frequency = 5;
	TACCR0 = 1000000 / 8 / frequency / 2;
	P1IFG = 0;
}


