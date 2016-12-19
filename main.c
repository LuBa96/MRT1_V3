/* Datei v3_main.c              */
/* P. Rieger; TUD/PLT 4.10.2001 */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Main-Programm

*****************************************************************************/

#include "fraktal.h"
#include "graphic.h"
#include "dialog.h"
#include <stdio.h>
#include "global.h"
extern struct tParam fType;
int main (void)
{
	/*--- Variablendeklaration ---------------------------------------------*/

		//in global.h

  	/*--- Initialwerte -----------------------------------------------------*/
	tComplex c1 = {0.4, 0.4};
	tComplex z1 = {0, 0};
	tComplex complex = {-2, -2};			//Startwert für die Abtastung des 4*4 Feldes
  	/*----------------------------------------------------------------------*/
  	/*--- Parameter über Dialog abfragen                                  --*/
	void ParamDialog()
	{
		tParam parameter;
		parameter.imax = inputInt();
		parameter.radius = inputDouble();
		parameter.xmax = inputDouble();
		parameter.xmin = inputDouble();
		parameter.xpoints = inputDounble();
		parameter.ymax = inputDouble();
		parameter.ymin = inputDouble();
		parameter.ypoints = inputDouble();
		fType Typ = inputChar();
		xRes = (parameter.xmax - parameter.xmin) / parameter.xpoints;			//Auflösung in x-Richtung berechnen
		yRes = (parameter.ymax - parameter.ymin) / parameter.ypoints;			//Auflösung in y-Richtung berechnen
	}
  	/*----------------------------------------------------------------------*/


    InitGraph (/*xmin, xmax, ymin, ymax übergeben*/); 	// Initialisierung der Grafik
    

    // vllt muss hier das Audrufen der rechne Funktion erfolgen...
    // Fraktal scheint momentan noch unser "main-Program" zu sein...

    LockScreen(); // Bildschirm muss zum Setzen von Pixeln gesperrt sein
  	/*----------------------------------------------------------------------*/
  	/*--- Fraktale berechnen und ausgeben                                 --*/
  	/*----------------------------------------------------------------------*/
    UnlockScreen(); // Alle Änderungen auf Bildschirm ausgeben
    
    /*Aufrufen von InputChar() um das Programm nach dem öffnen der Graphik   */
    /*anzuhalten. Erst wenn in der Konsole eine Taste gedrückt wird, schließt*/
    /*sich das Fenster wieder. */
    InputChar(); 
    CloseGraph();
	
	return 0;
}
