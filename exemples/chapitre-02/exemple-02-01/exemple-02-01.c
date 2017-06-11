// -------------------------------------------------------------------------
// Exemples du cours "Programmer en C sur microcontroleurs".
// 
// https://www.logilin.fr/formations/formation-langage-c-embarque-sur-micro-controleurs/
//
// (c) 2007-2017 Logilin - https://www.logilin.fr
//
// christophe.blaess@logilin.fr
//


/* Ce programme affiche un simple message
   puis se termine en indiquant qu'il a réussi
   son travail
*/

#include <stdio.h>


int main(void)
{
        /* Afficher le message */
        printf("Hello World! \n");

        // Retour 0 signifie "tout va bien"
        return 0;
}

