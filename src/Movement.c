/**
 * Movement.c - C-Quelldatei
 * -------------------------
 * Enthaelt Funktionen zur Berechnung physikalischer Bewegungen.
 * 
 * Uebersetzt aus Java, Original vom August 2021, C-Variante vom Januar 2022.
 * Paul Wolf, Januar 2022
 */

#include <math.h>
#include <stdio.h>

#include "Utils.h"

double acTime(double, double, double);
double acFirst(double, double, double);
double acSecond(double, double, double);
double unTime(double, double, double);
double unFirst(double, double, double);
double unSecond(double, double, double);
double miTime(double, double, double);
double miFirst(double, double, double);
double miSecond(double, double, double);

double* acceleratedMovement(double distance, double acceleration1,
		double acceleration2)
{
	static double ret[3];
	ret[0] = acTime(distance, acceleration1, acceleration2);
	ret[1] = acFirst(distance, acceleration1, acceleration2);
	ret[2] = acSecond(distance, acceleration1, acceleration2);
	return ret;
}

double* uniformMovement(double distance, double velocity1, double velocity2)
{
	static double ret[3];
	ret[0] = unTime(distance, velocity1, velocity2);
	ret[1] = unFirst(distance, velocity1, velocity2);
	ret[2] = unSecond(distance, velocity1, velocity2);
	return ret;
}

double* mixedMovement(double distance, double acceleration, double velocity)
{
	static double ret[3];
	ret[0] = miTime(distance, acceleration, velocity);
	ret[1] = miFirst(distance, acceleration, velocity);
	ret[2] = miSecond(distance, acceleration, velocity);
	return ret;
}

double acTime(double distance, double acceleration1, double acceleration2)
{
	return sqrt(2 * distance / (acceleration1 + acceleration2));
}
double acFirst(double distance, double acceleration1, double acceleration2)
{
	return pow(acTime(distance, acceleration1, acceleration2), 2)
			* acceleration1 / 2;
}
double acSecond(double distance, double acceleration1, double acceleration2)
{
	return pow(acTime(distance, acceleration1, acceleration2), 2)
			* acceleration2 / 2;
}

double unTime(double distance, double velocity1, double velocity2)
{
	return distance / (velocity1 + velocity2);
}
double unFirst(double distance, double velocity1, double velocity2)
{
	return velocity1 * unTime(distance, velocity1, velocity2);
}
double unSecond(double distance, double velocity1, double velocity2)
{
	return velocity2 * unTime(distance, velocity1, velocity2);
}

double miTime(double distance, double acceleration, double velocity)
{
	double *qf = quadraticFormula(acceleration / 2, velocity, -distance);
	if (qf[0] > 0)
		return qf[0];
	if (qf[1] > 0)
		return qf[1];
	return 0;
}

double miFirst(double distance, double acceleration, double velocity)
{
	return pow(miTime(distance, acceleration, velocity), 2) * acceleration / 2;
}

double miSecond(double distance, double acceleration, double velocity)
{
	return velocity * miTime(distance, acceleration, velocity);
}
