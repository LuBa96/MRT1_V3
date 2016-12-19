/*
 * global.h
 *
 *  Created on: 29.11.2016
 *      Author: mrt
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

typedef struct
	{
		double re, im;
	}tComplex;


	typedef struct tParam
	{
		double radius;
		int imax;
		typedef enum {j, a} fType;				//input liest nur ersten Buchstaben
		double xmin, xmax, ymin, ymax;
		double xpoints, ypoints;
	}tParam;

double xRes, yRes;
typedef enum {false, true}boolean;

#endif /* GLOBAL_H_ */
