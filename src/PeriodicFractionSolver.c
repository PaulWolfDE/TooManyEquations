/**
 * PeriodicFractionSolver.c - C-Quelldatei
 * ---------------------------------------
 * Loest einen periodischen Dezimalbruch in einen gemeinen Bruch.
 * 
 * Uebersetzt aus Java, Original vom Oktober 2021, C-Variante vom Januar 2022.
 * Paul Wolf, Januar 2022
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#include "Utils.h"

#define MAX_ARR 256

char* pfsSolve(char input[])
{
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == ',')
		{
			input[i] = '.';
			break;
		}
	}

	char *split1, *split2;
	char del[] = "(", del2[] = ".";
	split1 = strtok(input, del);
	char *intVal = split1;
	split1 = strtok(NULL, del);
	char *perVal = split1;

	double a = strtod(strtok(input, del), NULL);	// Dezimalzahl
	int b = strtol(perVal, NULL, 10);				// Periode

	strtok(intVal, del2);
	split2 = strtok(NULL, del2);
	char *decVal = split2;
	perVal[strlen(perVal) - 1] = '\0';

	int a2 = intVal[strlen(intVal) - 1] == '.' ? 0 : strlen(decVal);	// Nachkommastellen
	int b2 = strlen(perVal);											// Periodenstellen

	long int r1 = a * pow(10, a2) * (pow(10, b2) - 1);
	long int r2 = (long int) ((pow(10, b2) - 1) * pow(10, a2));
	r1 += b;

	int greatesCommonDivisor = gcd(r1, (int) r2);

	static char r[MAX_ARR];

	snprintf(r, sizeof(r), "%ld / %.0ld\n", r1 / greatesCommonDivisor,
			r2 / greatesCommonDivisor);

	return r;
}
