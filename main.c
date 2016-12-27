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
#include <string.h>
#include "global.h"


/*int inputInt();
int inputDouble();
char inputChar();
*/
void entscheide();

tParam parameter;

int main (void)
{

	/*--- Variablendeklaration ---------------------------------------------*/

		//in global.h

  	/*--- Initialwerte -----------------------------------------------------*/

		//in Fraktal.c

	/*----------------------------------------------------------------------*/
  	/*--- Parameter über Dialog abfragen                                  --*/


	//void ParamDialog()
	//{

		parameter.imax = 75;
		parameter.radius = 2;
		parameter.xmax = 2;
		parameter.xmin = -2;
		parameter.xpoints = 640;//640;
		parameter.ymax = 2;
		parameter.ymin = -2;
		parameter.ypoints = 480;// 480;
		strcpy(parameter.fType, "j");


	/*	parameter.imax = inputInt();
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
	*/
	//}
	xRes = (parameter.xmax - parameter.xmin) / parameter.xpoints;			//Auflösung in x-Richtung berechnen
	yRes = (parameter.ymax - parameter.ymin) / parameter.ypoints;
  	/*----------------------------------------------------------------------*/


    InitGraph (parameter.xmin, parameter.xmax, parameter.ymin, parameter.ymax); 	// Initialisierung der Grafik
    

    // vllt muss hier das Audrufen der rechne Funktion erfolgen...
    // Fraktal scheint momentan noch unser "main-Program" zu sein...

    LockScreen(); // Bildschirm muss zum Setzen von Pixeln gesperrt sein
  	/*----------------------------------------------------------------------*/

    /*--- Fraktale berechnen und ausgeben                                 --*/
    	entscheide();

    /*----------------------------------------------------------------------*/
    UnlockScreen(); // Alle Änderungen auf Bildschirm ausgeben
    
    /*Aufrufen von InputChar() um das Programm nach dem öffnen der Graphik   */
    /*anzuhalten. Erst wenn in der Konsole eine Taste gedrückt wird, schließt*/
    /*sich das Fenster wieder. */
    InputChar();
    CloseGraph();
	
	return 0;
}
