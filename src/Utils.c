/**
 * Utils.c - C-Quelldatei
 * ----------------------
 * Enthaelt Funktionen zum Loeson verschiedener mathematischer Probleme.
 * 
 * Erstellt in C.
 * Paul Wolf, Januar 2022
 */

#include <math.h>
#include <stdio.h>
#include <stdbool.h>

#include "Utils.h"

#define MAX_STRING 256

int getDecimalPlaces(double n)
{
	char string[MAX_STRING];
	int numberOfDecimalPlaces = 0;
	int i = sprintf(string, "%f", n);
	bool countZero = false;
	for (int j = i - 1; j > 0; j--)
	{
		if (string[j] == '.')
			break;
		if (!countZero && string[j] != 48)
			countZero = true;
		if (countZero)
			numberOfDecimalPlaces++;
	}
	return numberOfDecimalPlaces;
}

double *quadraticFormula(double a, double b, double c)
{
	static double ret[2];
	double res = sqrt((pow(b, 2) - 4*a*c));
	ret[0] = (-b + res) / (2 * a);
	ret[1] = (-b - res) / (2 * a);
	return ret;
}

int abs(int n)
{
	if (n < 0)
		return n * -1;
	return n;
}

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int lcm(int a, int b)
{
	return a / gcd(a, b) * b;
}
