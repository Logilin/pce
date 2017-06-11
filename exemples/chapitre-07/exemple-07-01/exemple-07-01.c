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

#include <ctype.h>
#include <stdio.h>


/// \brief Send a single character to the serial port.
///
/// \param c - The character to send.
///
/// \returns The character sent.
///
int putchar(int c)
{
	// Wait Tx empty.
	while(!(IFG2 & UCA0TXIFG))
			;
	UCA0TXBUF = c;
	return c;
}


/// \brief Read a single character from the serial port.
///
/// \returns The character read.
///
int getchar(void)
{
	int c;
	// Wait for a character
	while (!(IFG2&UCA0RXIFG))
		;
	c = UCA0RXBUF;

	// Toggle the led.
	P1OUT ^= BIT6;

	putchar(c);

	return c;
}


/// \brief Read a line from the serial port.
///
/// \param line - The buffer to write. Must be reserved before calling this function.
/// \param size - The size of the buffer.
///
/// \returns The number of characters read, not counting the final '\0'.
///
int readline(char *line, int size)
{
	int nb = 0;

	for(;;) {
		// Check the maximal length.
		line[nb] = '\0';
		if (nb >= (size - 1))
			return nb;

		line[nb] = getchar();

		if (line[nb] == '\n') {
			// ignore.
			continue;
		}

		if (line[nb] == '\r') {
			line[nb] = '\0';
			return nb;
		}
		nb ++;
	}
}


int main(void)
{
	int n, i;
	char line[256];

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
	IE2 |= UCA0RXIE | UCA0TXIE;


	for (;;) {
		printf("--> ");
		n = readline(line, 1024);
		if (n == 0)
			continue;
		for (i = 0; i < n; i ++)
			line[i] = toupper(line[i]);
		printf("\r\n");
		printf("%s\r\n", line);
	}
	return 0;
}


