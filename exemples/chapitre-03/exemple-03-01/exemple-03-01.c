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

#include <stdio.h>


int putchar(int c)
{
	// Wait Tx empty.
	while(!(IFG2 & UCA0TXIFG))
			;
	UCA0TXBUF = c;
	return c;
}


void uart_init(void)
{
    // Select a 16MHz Basic clock.
    DCOCTL  = 0;
    BCSCTL1 = CALBC1_16MHZ;
    DCOCTL  = CALDCO_16MHZ;

    // Select secondary function for P1.1 (Rx)  and P1.2 (Tx)
    P1SEL   = BIT1 | BIT2;
    P1SEL2  = BIT1 | BIT2;

    // UART, 8bits, no parity, 1 stop,
    UCA0CTL0 = 0;

    // See MSP430x2xx User Guide (slau144j) p.424:
    // BRCLK = 16MHz
    // Baud rate = 115200
    //  -> UCBRx  = 137
    //  -> UCBRSx = 7
    //  -> UCBRFx = 0
    UCA0CTL1 |= UCSSEL_2;
    UCA0BR0  = 138;
    UCA0BR1  = 0;
    UCA0MCTL = UCBRS2 + UCBRS1 + UCBRS0;
    UCA0CTL1 &= ~UCSWRST; // USCI Reset.

    IE2 |= UCA0TXIE | UCA0RXIE;

}


int main(void)
{
	int i = 0;

	// Disable watchdog.
	WDTCTL = WDTPW + WDTHOLD;

	uart_init();

	for(;;) {
		printf("Hello %d\r\n", i);
		i = i+1;
	}
}

