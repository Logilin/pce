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


void boucle(int nombre)
{
	int i, j;
	for (i = 0; i < nombre; i ++) {
		for (j = 0; j < 100; j ++) {
		}

	}
}


int main(void)
{
        WDTCTL = WDTPW + WDTHOLD;  // Desactiver le watchdog

        P1DIR = BIT0 | BIT6;  // Broches P1.0 (led rouge) et P1.6 (verte) en sortie

        P1OUT = BIT3;  // P1.3 (bouton) en pull-up
        P1REN = BIT3;  // Pull-up de P1.3 actif

        while (1) {
                if ((P1IN & BIT3) == 0) {// Bouton presse
                	P1OUT = BIT0 | BIT3;
                	boucle(100);
                	P1OUT = BIT6 | BIT3;
                	boucle(100);
                	P1OUT = BIT0 | BIT3;
                	boucle(100);
                	P1OUT = BIT6 | BIT3;
                	boucle(100);
                	P1OUT = BIT3;
                }
        }

        return 0;
}

