/*
 * global.h
 *
 *  Created on: 29.11.2016
 *      Author: mrt
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

/*Definition der komplexen Zahl*/
typedef struct
	{
		double re, im;
	}tComplex;


/*Definition der Paremeterstruktur*/
typedef struct
	{
		enum fType {j, a, n}FraktalTyp;
		double radius;
		int imax;
		double xmin, xmax, ymin, ymax;
		double xpoints, ypoints;
	}tParam;

double xRes, yRes;							//Schrittweite für generiere()
typedef enum {false, true}boolean;
#endif /* GLOBAL_H_ */
