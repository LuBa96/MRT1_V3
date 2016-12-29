/* Datei: v3_frakt.c              */
/* P. Rieger; TUD/PLT 4.10.2001   */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Fraktal-Analyse"

*****************************************************************************/
#include "fraktal.h"
#include "graphic.h"
#include "global.h"
#include "math.h"							//habe in properties beim linker die Bibliothek -lm hinzugefügt
#include <string.h>

	extern tParam parameter;
	tComplex c1 = {0.4, 0.4};
	tComplex z1 = {0, 0};
	tComplex complex;
	tComplex  c;
	tComplex z;
	boolean finished = false;
	boolean julia;
	tColor inputColor;

/*--- Interne Funktion: Analyse der Iterationsanzahl -----------------------*/


tComplex complex = {-2, -2};

void entscheide()
{
	/*char typ = fType;
	if(strcmp(typ, "j") == 0)
	{
		julia = true;
	}
	else if (strcmp(typ, "a") == 0)
	{
		julia = false;
	}
	*/
	if(parameter.FraktalTyp == j)
	{
		c =  c1;
		z.re = 1000;						//unschoen, aber Null-Objekt Zuweisung funktioniert nicht so wie ich das will
	}
	else
	{
		c.re = 1000;
		z = z1;
	}
	calc();
}

void calc()
{
	while (finished == false)
	{
		berechne();
		LockScreen();
		SetPoint(complex.re, complex.im, inputColor);		//complex sollte die pro durchlauf generierte Zahl sein,
		UnlockScreen();													//d.h. einmal werden die generierten cs und einmal die zs													//geplottet, je nach art der menge?

	}
	printf("calc finished");
}

tComplex generiere()										//raster viele komlexe zahlen
{

  if (complex.im <= parameter.ymax)
  {
	if (complex.re < parameter.xmax)
	{
		complex.re = complex.re + xRes;
	}
	else
	{
		complex.re = parameter.xmin;
		complex.im = complex.im + yRes;
	}
	//printf("%f + i*%f", complex.re, complex.im);
  }
  else
  {
	  printf ("Built fertig");
	  finished = true;						//ändern; Programm beenden
  }

  return complex;


 // printf("%f + i*%f", complex.re, complex.im);

}


void berechne()																//z = c + z²
{
		int i = 0;															//iterationszahl
		if(parameter.FraktalTyp == a)										//Mandelbrotmenge
		{
			c = generiere();												//für die Mandelbrotmenge muss z0 fest sein und c ist veränderlich
			z = z1;															//bei der Juliamenge ist es genau umgekehrt
		}																	//generiere() erzeugt komplexe Zahlen von -2-2i bis 2+2i
		else																//Die Auflösung erfolgt entsprechend xRes und yRes --> main()
		{																	//Wichtig: Die Zuweisung z = z1 muss hier erneut erfolgen, da bei der Mandelbrotmenge
			z = generiere();												//z bei jeder neuen Berechnung wieder der Startwert z1 sei soll, andernfalls wird mit
		}																	//dem letzten z der vorherigen Berechnung weitergerechnet-->also "unendlich oft mit den
																			//gleichen Parametern iteriert
		while((absolute(z) < parameter.radius) && (i < parameter.imax))  	//solange der Betrag kleiner als der Konvergenzradius ist und imax nicht erreicht ist; Berechnung ausführen
		{
			double x = z.re;												// z = c + z²
			double y = z.im;
			z.re = c.re + (pow(x,2) - pow(y,2));
			z.im = c.im + (2 * x * y);
			i++;
		}
		GetColorValue(i);

}

double absolute(tComplex zAktuell)				//Betragsberechnung
	{
		double d = 	sqrt(pow((zAktuell.re),2) + pow((zAktuell.im),2));
		return d;
	}
/*--- Interne Funktion: Farbwert bestimmen ---------------------------------*/

void GetColorValue(int i)
{


	//case imax: inputColor = 0; case labels müssen leider zur compile zeit constant sein... muss hier festgelegt werden..argh


	if 		(i >= parameter.imax)
			{inputColor = 0;}
	else if (i >= ((parameter.imax/15)*14))
			{inputColor = 1;}
	else if (i >= ((parameter.imax/15)*13))
			{inputColor = 2;}
	else if (i >= ((parameter.imax/15)*12))
			{inputColor = 3;}
	else if (i >= ((parameter.imax/15)*11))
			{inputColor = 4;}
	else if (i >= ((parameter.imax/15)*10))
			{inputColor = 5;}
	else if (i >= ((parameter.imax/15)*9))
			{inputColor = 6;}
	else if (i >= ((parameter.imax/15)*8))
			{inputColor = 7;}
	else if (i >= ((parameter.imax/15)*7))
			{inputColor = 8;}
	else if (i >= ((parameter.imax/15)*6))
			{inputColor = 9;}
	else if (i >= ((parameter.imax/15)*5))
			{inputColor = 10;}
	else if (i >= ((parameter.imax/15)*4))
			{inputColor = 11;}
	else if (i >= ((parameter.imax/15)*3))
			{inputColor = 12;}
	else if (i >= ((parameter.imax/15)*2))
			{inputColor = 13;}
	else if (i >= ((parameter.imax/15)))
			{inputColor = 14;}
	else if (i >= 0)
			{inputColor = 15;}
}
	/*alternativ:
	int idiv = i/(parameter.imax/16);
	inputColor = idiv;
	*/
/*--- Fraktal-Figur analysieren und zeichnen -------------------------------*/


/* v3_frakt.c */
