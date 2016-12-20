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


int inputInt();
int inputDouble();
char inputChar();

void berechne();

int main (void)
{

	/*--- Variablendeklaration ---------------------------------------------*/
	tParam parameter;
		//in global.h

  	/*--- Initialwerte -----------------------------------------------------*/

		//in Fraktal.c

	/*----------------------------------------------------------------------*/
  	/*--- Parameter über Dialog abfragen                                  --*/


	void ParamDialog()
	{

		parameter.imax = inputInt();
		parameter.radius = inputDouble();
		parameter.xmax = inputDouble();
		parameter.xmin = inputDouble();
		parameter.xpoints = inputDouble();
		parameter.ymax = inputDouble();
		parameter.ymin = inputDouble();
		parameter.ypoints = inputDouble();
		parameter.fType = inputChar();
		xRes = (parameter.xmax - parameter.xmin) / parameter.xpoints;			//Auflösung in x-Richtung berechnen
		yRes = (parameter.ymax - parameter.ymin) / parameter.ypoints;			//Auflösung in y-Richtung berechnen
	}
  	/*----------------------------------------------------------------------*/


    InitGraph (parameter.xmin, parameter.xmax, parameter.ymin, parameter.ymax); 	// Initialisierung der Grafik
    

    // vllt muss hier das Audrufen der rechne Funktion erfolgen...
    // Fraktal scheint momentan noch unser "main-Program" zu sein...

    LockScreen(); // Bildschirm muss zum Setzen von Pixeln gesperrt sein
  	/*----------------------------------------------------------------------*/

    /*--- Fraktale berechnen und ausgeben                                 --*/
    	berechne();

    /*----------------------------------------------------------------------*/
    UnlockScreen(); // Alle Änderungen auf Bildschirm ausgeben
    
    /*Aufrufen von InputChar() um das Programm nach dem öffnen der Graphik   */
    /*anzuhalten. Erst wenn in der Konsole eine Taste gedrückt wird, schließt*/
    /*sich das Fenster wieder. */
    InputChar(); 
    CloseGraph();
	
	return 0;
}
