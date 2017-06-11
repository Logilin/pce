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

	// Alternate functions TX/RX on P1.1 and P1.2.
	P1SEL   = BIT1 | BIT2;
	P1SEL2  = BIT1 | BIT2;

	// System clock at 1MHz
	DCOCTL  = 0;
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL  = CALDCO_1MHZ;

	// Use 115200 bits/sec. configuration
	UCA0CTL1 |= UCSSEL_2;
	UCA0BR0  = 8;
	UCA0BR1  = 0;
	UCA0MCTL = UCBRS2 | UCBRS1;
	UCA0CTL1 &= ~UCSWRST;

	// Led P1.6 on output.
	P1DIR |= BIT6;
	// Led turned off.
	P1OUT &= ~BIT6;

	// Enable USCI_A0 RX interrupt
	IE2 |= UCA0RXIE;

	// Send a first message.
	UCA0TXBUF = 'h';  while (!(IFG2&UCA0TXIFG));
	UCA0TXBUF = 'e';  while (!(IFG2&UCA0TXIFG));
	UCA0TXBUF = 'l';  while (!(IFG2&UCA0TXIFG));
	UCA0TXBUF = 'l';  while (!(IFG2&UCA0TXIFG));
	UCA0TXBUF = 'o';  while (!(IFG2&UCA0TXIFG));
	UCA0TXBUF = '\r'; while (!(IFG2&UCA0TXIFG));
	UCA0TXBUF = '\n'; while (!(IFG2&UCA0TXIFG));

	// Let's sleep
	__bis_SR_register(LPM0_bits + GIE);
	return 0;
}


#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{
	// Wait for output buffer empty.
	while (!(IFG2&UCA0TXIFG))
		;
	// Echo the received character
	UCA0TXBUF = UCA0RXBUF;
	// Toggle the led.
	P1OUT ^= BIT6;
}


