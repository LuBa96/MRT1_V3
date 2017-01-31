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


tParam parameter;

int main (void)
{
  	/*--- Parameter über Dialog abfragen ---*/

		printf("Geben Sie die maximale Anzahl der Iterationen ein!\n");		// lies & als "Address of"; scanf stellt nur einen Pointer auf
																			//einen Speicherplatz des jeweiligen Typen bereit (%d --> int*)
																			//mit der Vorsilbe "&" wird der Speicherplatz dann gefüllt;
																			//alternativ: *(content)
		scanf("%d", &parameter.imax);
		printf("Geben Sie den gewuenschten Konvergenzradius ein!\n");
		scanf("%le", &parameter.radius);
		printf("Obere Grenze des x-Wertebereiches: ");
		scanf("%le", &parameter.xmax);
		printf("Untere Grenze des x-Wertebereiches: ");
		scanf("%le",&parameter.xmin);
		printf("Aufloesung (x): ");
		scanf("%le",&parameter.xpoints);
		printf("Obere Grenze des y-Wertebereiches: ");
		scanf("%le",&parameter.ymax);
		printf("Untere Grenze des y-Wertebereiches: ");
		scanf("%le",&parameter.ymin);
		printf("Aufloesung (y): ");
		scanf("%le",&parameter.ypoints);

		//parameter.FraktalTyp = a;
		printf("Julia- oder Mandelbrotmenge?\n 0/1/2\n");
		scanf("%u",&parameter.FraktalTyp);
		while (parameter.FraktalTyp != 0 && parameter.FraktalTyp != 1 && parameter.FraktalTyp != 2)
		{
			printf("Nur 1 für Mandelbrotmenge und 0 für Juliamenge erlaubte Eingabewerte!");
			scanf("%u",&parameter.FraktalTyp);
		}

		xRes = (parameter.xmax - parameter.xmin) / parameter.xpoints;				//Auflösung in x-Richtung berechnen
		yRes = (parameter.ymax - parameter.ymin) / parameter.ypoints;				//Auflösung in y-Richtung berechnen



  	/*----------------------------------------------------------------------*/
	void entscheide();																//berechne bekanntmachen (Funktionsprototyp)

    InitGraph (parameter.xmin, parameter.xmax, parameter.ymin, parameter.ymax); 	// Initialisierung der Grafik
    

    LockScreen(); // Bildschirm muss zum Setzen von Pixeln gesperrt sein
  	/*----------------------------------------------------------------------*/
    InputChar();
    /*--- Fraktale berechnen und ausgeben                                 --*/
    entscheide();

    /*----------------------------------------------------------------------*/
    UnlockScreen(); // Alle Änderungen auf Bildschirm ausgeben
    
    /*Aufrufen von InputChar() um das Programm nach dem öffnen der Graphik   */
    /*anzuhalten. Erst wenn in der Konsole eine Taste gedrückt wird, schließt*/
    /*sich das Fenster wieder. */
    int Ende;
    scanf("%d", &Ende);
    CloseGraph();
	
	return 0;
}
