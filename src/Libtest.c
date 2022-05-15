/**
 * Libtest.c - C-Quelldatei
 * ------------------------
 * Hauptfunktion zum Testen der Programmbibliothek, enthaelt Anwendungsmoeglichkeiten.
 * 
 * Erstellt in C.
 * Paul Wolf, Januar 2022
 */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "GaussianElimination.h"
#include "StringEvaluation.h"
#include "PeriodicFractionSolver.h"
#include "TextAssignments.h"
#include "Movement.h"
#include "Geometry.h"

#define NUMBER_OF_RESULTS 4

int main(void)
{
	// Number of results equal to the rows of the linear system of equations.
	
	// Example matrix entered as 4 strings.
	char stringMatrix[NUMBER_OF_RESULTS][256] =
	{ "3x + 4y -5z + 6a = 39", 
	"6x + 5y - 6z + 5a = 43",
	"9x - 4y + 2z + 3a = 6", 
	"2y - 3z + a = 13" };

	// Array for storing the results. 
	double matrixr[NUMBER_OF_RESULTS];

	// Turning the matrix to pointer array suitable for functions.
	char *pMatrix[NUMBER_OF_RESULTS];
	for (int i = 0; i < NUMBER_OF_RESULTS; i++)
		pMatrix[i] = stringMatrix[i];

	// Array for storing the result of string evaluation.
	static double resMatrix[NUMBER_OF_RESULTS][NUMBER_OF_RESULTS+1];

	// Turning the coefficient matrix suitable for functions.
	double *pRetMatrix[NUMBER_OF_RESULTS];
	for (int i = 0; i < NUMBER_OF_RESULTS; i++)
		pRetMatrix[i] = resMatrix[i];

	// Evaluating the string matrix.
	seEvaluate(pMatrix, NUMBER_OF_RESULTS, pRetMatrix);
	// Solving the coefficient matrix.
	lsoeSolve(pRetMatrix, matrixr, NUMBER_OF_RESULTS);

	printf("Lineares Gleichungssystem:\n");
	for (int i = 0; i < 4; i++)
		printf("%s\n", stringMatrix[i]);
	printf("--> ");
	printf("x = %.2f, y = %.2f, z = %.2f, a = %.2f", matrixr[0], matrixr[1],
		matrixr[2], matrixr[3]);
	printf("\n\n");

	printf("Periodischer Dezimalbruch:\n");
	char n[] = "41.63(421)";
	char x[sizeof(n) / sizeof(char)];
	strcpy(x, n);
	char *r = pfsSolve(x);
	printf("--> %s = %s\n", n, r);

	double *mov = mixedMovement(100.0, 4.5, 10.0);
	printf("Zwei Autos sind 100m entfernt. Auto 1 beschleunigt 4.5m/s^2, "
		"Auto 2 bewegt sich gleichfoermig mit 10m/s. "
		"\n--> Die Autos treffen sich nach %.2fs, Auto 1 "
		"ist %.2fm gefahren, Auto 2 %.2fm.\n\n", mov[0], mov[1], mov[2]);

	double *taA = taAge(5, 3, 10);
	printf("Der Vater ist 5x so alt wie sein Sohn, in 10 Jahren ist er "
		"3x so alt.\n--> Der Sohn ist jetzt %.2f Jahre alt, in 10 "
		"Jahren %.2f. Der Vater ist jetzt %.2f Jahre alt, in 10 Jahren "
		"%.2f.\n\n", taA[0], taA[1], taA[2], taA[3]);

	int *taL = taLegs(4, 8, 105, 632);
	printf("105 Elefanten und Spinnen haben zusammen 632 Beine.\n"
		"--> %d Elefanten, %d Spinnen, %d Beine von den Elefanten, "
		"%d Beine von den Spinnen.\n\n", taL[0], taL[1], taL[2], taL[3]);

	double *taAi = taAcid(100, 20, 43, 61);
	printf("100 Liter 43 prozentige Saeure wird mit 20 Litern 61 "
		"prozentiger Saeure gemischt.\n--> Die entstandene Saeure "
		"hat %.2f%% auf %.2fl.\n\n", taAi[0] * 100, taAi[1]);

	double *taG = taGas(104, 86.8, -.06, -10);
	printf("Uwe tankt sein Auto heute und zahlt 104EUR. \nGestern hat "
		"er 10 Liter weniger getankt und 0,06EUR pro Liter weniger "
		"gezahlt als heute. \nGestern bezahlte er 86,8EUR.\n-->"
		" Heute kostet ein Liter %.2fEUR.\n--> Gestern kostete ein "
		"Liter %.2fEUR.\n--> Heute hat Uwe %.2fl getankt.\n--> Gestern "
		"tankte er %.2fl.\n\n", taG[0], taG[1], taG[2], taG[3]);
    
    double degrees = 180;
    printf("%f° = %f rad\n", degrees, degreesToRadians(degrees));

    double radian = M_PI;
    printf("%f rad = %f°\n", radian, radiansToDegrees(radian));

    printf("%f\n", radiansToDegrees(lawOfSinesAngle(degreesToRadians(50), 7, 5)));
}

