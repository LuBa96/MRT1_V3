/* Datei: v3_frakt.c              */
/* P. Rieger; TUD/PLT 4.10.2001   */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Fraktal-Analyse"

*****************************************************************************/
#include "fraktal.h"
#include "graphic.h"
#include "global.h"
#include <math.h>

	extern int imax;
	extern struct tParam fType;
	extern tComplex c1;
	extern tComplex z1;
	extern tComplex  complex;
	tComplex  c;
	tComplex z;
	tComplex zLog ={0,0};
	boolean finished = false;
	tColor inputColor;

/*--- Interne Funktion: Analyse der Iterationsanzahl -----------------------*/
void entscheide()
{
	if(fType == 0)			//0 = julia
	{
		c =  c1;
		z = NULL;
	}
	else
	{
		c = NULL;
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
															//d.h. einmal werden die generierten cs und einmal die zs
															//geplottet, je nach art der menge?
	}
}

struct tComplex generiere()					//raster viele komlexe zahlen
{

  while (complex.im <= 2)
  {
	if (complex.re < 2)
	{
		complex.re = complex.re + xRes;
	}
	else
	{
		complex.re = -2;
		complex.im = complex.im + yRes;
	}
  }
/*  else
  {
	  printf ("Built fertig");
	  finished = true;						//ändern; Programm beenden
  }
  */
  printf (complex.re & "+ i" & complex.im);

  return complex;

}


int berechne()				//z = c + z²
{
	while (finished == false)
	{
		int i = 0;						//iterationszahl
		extern double radius;
		if(c==NULL)
		{
			c = generiere();

		}
		else
		{
			z = generiere();
		}

		while((abs(z) < radius) && (i < imax))  //solange der Betrag kleiner als der Konvergenzradius ist und imax nicht erreicht ist; Berechnung ausführen
		{
			double x = z.re;					// z = c + z²
			double y = z.im;
			z.re = c.re + (pow(x,2) - pow(y,2));
			z.im = c.im + (2 * x * y);
			i++;
		}
		return i;
	}
}

double abs(tComplex zAktuell)				//Betragsberechnung
	{
		double d = 	sqrt(pow((zAktuell.re),2) + pow((zAktuell.im),2));
		return d;
	}
/*--- Interne Funktion: Farbwert bestimmen ---------------------------------*/

void GetColorValue(int i)
{

	switch (i)
	{
	case imax: inputColor = 0;
	break;
	case (15*imax/16-1) - (14*imax/16-1): inputColor = 1;
	break;
	case (14*imax/16-1) - (13*imax/16-1): inputColor = 2;
	break;
	case (13*imax/16-1) - (12*imax/16-1): inputColor = 3;
	break;
	case (12*imax/16-1) - (11*imax/16-1): inputColor = 4;
	break;
	case (11*imax/16-1) - (10*imax/16-1): inputColor = 5;
	break;
	case (10*imax/16-1) - (9*imax/16-1): inputColor = 6;
	break;
	case (9*imax/16-1) - (8*imax/16-1): inputColor = 7;
	break;
	case (8*imax/16-1) - (7*imax/16-1): inputColor = 8;
	break;
	case (7*imax/16-1) - (6*imax/16-1): inputColor = 9;
	break;
	case (6*imax/16-1) - (5*imax/16-1): inputColor = 10;
	break;
	case (5*imax/16-1) - (4*imax/16-1): inputColor = 11;
	break;
	case (4*imax/16-1) - (3*imax/16-1): inputColor = 12;
	break;
	case (3*imax/16-1) - (14*imax/16-1): inputColor = 13;
	break;
	case (2*imax/16-1) - (13*imax/16-1): inputColor = 14;
	break;
	case (1*imax/16-1) - 0: inputColor = 15;
	break;
	}
}
	/*alternativ:
	int idiv = i/(imax/16);
	inputColor = idiv;
	*/
/*--- Fraktal-Figur analysieren und zeichnen -------------------------------*/


/* v3_frakt.c */
