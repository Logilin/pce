pce
===
(c) Christophe BLAESS 2007-2017

Version 4.0

Exemples de notre cours _"Langage C embarqué sur microcontrôleur"_

Pour tout renseignement voir http://www.logilin.fr

Version à jour sur https://github.com/Logilin/pce/

* **I – Introduction**
 - Présentation des microcontrôleurs : vocabulaire, spécificités, gamme MSP430.
 - Le langage C : principes, environnement de développement, compilateur, outils.

* **II – Organisation d’un programme C**
 - Premier exemple : analyse et essai d’un programme simple.
 - Les fonctions : définitions et invocations de fonctions.
 - Travaux pratiques : création de projet pour MSP430, pilotage de leds.

* **III – Données et opérateurs**
 - Types de données : entiers, réels, affichage, conversion, caractères et chaînes.
 - Opérateurs : numériques et logiques, standards et abrégés.
 - Travaux pratiques : interprétation et affichage d’expressions numériques et logiques.

* **IV – Structures de contrôle**
 - Tests : _if_, conditions, _switch_.
 - Boucles : _while_, _for_, ruptures de séquences.
 - Travaux pratiques : programmation de signaux à rapports cycliques différents.

* **V – Tableaux, pointeurs et registres**
 - Tableaux : déclaration et manipulation, représentation en mémoire.
 - Pointeurs : notions d’adresse et de déréférencement, registres d’entrées-sorties.
 - Travaux pratiques : manipulation de pointeurs, programmation de registres GPIO.

* **VI – Fonctions**
 - Fonctions classiques : déclaration et implémentation, arguments, valeur de retour.
 - Routines d’interruption : principes, GPIO, port série, timer.
 - Travaux pratiques : gestion d’interruption du timer, du bouton poussoir, _PWM_.

* **VII – Chaînes de caractères**
 - Retour sur les chaînes de caractères : déclaration, représentation en mémoire.
 - Manipulation de chaînes : copie, concaténation, comparaison, parcours.
 - Travaux pratiques : écriture d’un automate d’entrées-sorties communiquant sur port série.

* **VIII – Structures**
 - Principes des structures : déclaration,  représentation en mémoire, manipulation.
 - Pointeurs sur les structures : passage en argument, retours de fonction.

* **IX – Compilation séparée**
 - Principes : nécessité, utilisations, bibliothèques, édition des liens.
 - Fichiers d’en-tête : variables externes, inclusions multiples.
 - Travaux pratiques : examen d’un fichier _Makefile_.

