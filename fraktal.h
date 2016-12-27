/* Datei: v3_frakt.h            */
/* P. Rieger; TUD/PLT 20.8.1999 */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Fraktal-Analyse"

*****************************************************************************/

#ifndef __fraktal
#define __fraktal

#include "global.h"
/*--- Datentypvereinbarungen -----------------------------------------------*/


/*--- Fraktal analysieren und grafisch darstellen --------------------------*/
void calc();
void berechne();						//Funktionsprototypen bekanntmachen, damit keine impliziten Funktionen erstellt werden, wenn eine aufgerufene funktion erst später deklariert wird
double absolute(tComplex zAktuell);
void GetColorValue(int);

#endif

/* v3_frakt.h */
