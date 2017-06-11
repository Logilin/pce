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


int main(void)
{
        WDTCTL = WDTPW + WDTHOLD;  // Desactiver le watchdog

        P1DIR = BIT0;  // Broche P1.0 (led) en sortie

        P1OUT = BIT3;  // P1.3 (bouton) en pull-up
        P1REN = BIT3;  // Pull-up de P1.3 actif

        while (1) {
                if ((P1IN & BIT3) != 0) // Bouton relache
                        P1OUT = BIT0 | BIT3; // Led rouge allumee (+ pull-up)
                else
                        P1OUT = BIT3; // Led rouge eteinte (pull-up seul)
        }

        return 0;
}
