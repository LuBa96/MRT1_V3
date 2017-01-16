/* Datei: v3_dialo.c            */
/* P. Rieger; TUD/PLT 4.10.2001 */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Parameterdialog"

*****************************************************************************/

#include "dialog.h"
#include <stdio.h>
#include <stdlib.h>

/*--- Definitionen ---------------------------------------------------------*/

enum bool {FALSE, TRUE};


/*--- Tastatureingabe lesen und nur ersten Character beachten --------------*/

char InputChar ()
{
	char s[80];									//stream s der Länge 80
	fgets(s,sizeof(s), stdin);					//lies von standard input der Länge von s entsprechend(80) in s ein
  	return s[0];								//nur erster Buchstabe wird gelesen
};

/*--- Double-Zahl von der Tastatur lesen -----------------------------------*/

double InputDouble (double *value)				//habe hier mal die Rückgabe von void auf double geändert, damit ich
												//die Lesefunktion für die Parametereingabe nutzen kann
{
  	char *endptr;
  	char s[80];
  	fgets(s,sizeof(s), stdin);
  	if (s[0]!=10) *value=strtod (s, &endptr);
  	return *value;
};


/*--- Int-Zahl von der Tastatur lesen --------------------------------------*/

int InputInt (int *value)						//void-->int
{
  char s[80];
  fgets(s,sizeof(s), stdin);
  if (s[0]!=10) *value=atoi (s);
  return *value;
};


/*--- Parameter Dialog ------------------------------------------------------*/


/* v3_frakt.c */
