/**
 * GaussianElimination.c - C-Quelldatei
 * ------------------------------------
 * Enthaelt Funktionen zum Loesen von Matrizen linearer Gleichungssysteme.
 * 
 * Uebersetzt aus Java, Original vom August 2021, C-Variante vom Januar 2022.
 * Paul Wolf, Januar 2022
 */

#include <math.h>
#include "Utils.h"

#define MAX_STRING 256

void lsoeSolveRecursive(double**, double[], int, int);
void lsoePartition(double**, int);
void lsoeElimination(double**, int, int);
void lsoeSwap(double**, int, int);
void lsoeExpand(double**, int);
void lsoeShrink(double**, int);

int power;

// Ein lineares Gleichungssystem wird geloest.
void lsoeSolve(double **matrix, double matrixr[], int matrixc)
{
	// Die Stellen einzelner Zeilen der Matrix werden nacheinander eliminiert.
	lsoePartition(matrix, matrixc);
	// Die eliminierte Matrix wird rekursiv in die Unbekannten aufgeloest.
	lsoeSolveRecursive(matrix, matrixr, matrixc, 1);
}

// Eine eliminierte Matrix wird geloest.
void lsoeSolveRecursive(double **matrix, double matrixr[], int matrixc, int i)
{
	// Das Ergebnis einer Zeile i im Gleichungssystem wird gespeichert.
	double res = matrix[matrixc - i][matrixc];

	/**
	 * Ab der zweiten Rekursion wird jeder bekannter Koeffizient mit seinem Wert multipliziert
	 * und dann von dem Ergebnis der Zeile abgezogen.
	 */
	for (int j = 0; j < i; j++)
		res -= matrixr[matrixc - j] * matrix[matrixc - i][matrixc - j];

	// Die Unbekannte der Zeile wird ermittelt und gespeichert.
	matrixr[matrixc - i] = res / matrix[matrixc - i][matrixc - i];

	// Bis die letzte Zeile der Matrix erreicht ist, geht die Rekursion weiter.
	if (i != matrixc)
		lsoeSolveRecursive(matrix, matrixr, matrixc, i + 1);
}

// Die Matrix wird so oft in Zeilen aufgeteilt und eliminiert, bis sie loesbar ist.
void lsoePartition(double **matrix, int matrixc)
{
	// In diesem Vektor werden zwei Zeilen der Matrix gespeichert, die eliminiert werden.
	double part[2][matrixc + 1];

	// Diese verschachtelt Schleifen zaehlen durch die gesamte Matrix.
	for (int a1 = 0; a1 < matrixc - 1; a1++)
		for (int a2 = a1 + 1; a2 < matrixc; a2++)
		{
			// Zwei Zeilen werden aus der Matrix kopiert.
			for (int j = a1; j < matrixc + 1; j++)
			{
				part[0][j] = matrix[a1][j];
				part[1][j] = matrix[a2][j];
			}

			/**
			 * Falls nichts mehr eliminiert werden muss, stoppt der Vorgang und die Zeilen werden 
			 * ggf. getauscht. 
			 */
			if (part[0][a1] == 0 || part[1][a1] == 0)
			{
				if (part[0][a1] == 0)
					lsoeSwap(matrix, a1, a2);
				// Das Programm springt zur naechsten Zeile.
				break;
			}

			// Ein Zeigervektor wird aus der zweidimensionalen Teilmatrix erstellt.
			double *arg[2];
			for (int i = 0; i < 2; i++)
				arg[i] = part[i];

			// Zwei Zeilen der Matrix werden eliminiert.
			lsoeElimination(arg, matrixc, a1);

			// Die eliminierten Zeilen werden an die korrekte Position in der Matrix kopiert.
			for (int j = a1; j < matrixc + 1; j++)
			{
				matrix[a1][j] = part[0][j];
				matrix[a2][j] = part[1][j];
			}
		}
}

// Ein Wert wird aus einer Zeile der Matrix eliminiert.
void lsoeElimination(double **part, int matrixc, int index)
{
	// Die Werte der Matrix werden vergroessert, um alle Dezimalzahlen zu entfernen.
	lsoeExpand(part, matrixc);

	// Das kleinste gemeinsame Vielfache der zwei Werte an der zu eliminierenden Position wird ermittelt.
	int leastCommonMultiply = abs(lcm(part[0][index], part[1][index]));
	// Der Faktor, um das kleinste gemeinsame Vielfache der ersten Zeile zu erreichen, wird gespeichert.
	double factor = leastCommonMultiply / fabs(part[0][index]);

	// Der zu eliminierende Index der unteren Zeile des Gleichungssystems sollte negativ sein.
	if (part[0][index] > 0)
		for (int i = index; i < matrixc + 1; i++)
			part[0][i] *= -(factor);
	else
		for (int i = index; i < matrixc + 1; i++)
			part[0][i] *= factor;

	// Der Faktor, um das kleinste gemeinsame Vielfache der zweiten Zeile zu erreichen, wird gespeichert.
	factor = leastCommonMultiply / fabs(part[1][index]);

	// Der zu eliminierende Index der oberen Zeile des Gleichungssystems sollte positiv sein.
	if (part[1][index] < 0)
		for (int i = index; i < matrixc + 1; i++)
			part[1][i] *= -(factor);
	else
		for (int i = index; i < matrixc + 1; i++)
			part[1][i] *= factor;

	// Beide Zeilen werden addiert, wobei eine Zahl eliminiert wird.
	for (int i = 0; i < matrixc + 1; i++)
		part[1][i] += part[0][i];

	// Die Matrix wird nun wieder verkleinert und die Elimination ist abgeschlossen.
	lsoeShrink(part, matrixc);
}

// Zwei Zeilen in einer Matrix werden getauscht.
void lsoeSwap(double **array, int a, int b)
{
	double *temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

// Die Teilmatrix wird so weit vergroessert, bis sie keine Dezimalzahlen mehr hat.
void lsoeExpand(double **part, int matrixc)
{
	// Die meiste Anzahl an Dezimalzahlen in der Teilmatrix wird gespeichert.
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < matrixc + 1; j++)
		{
			int decimalPlaces;
			decimalPlaces = getDecimalPlaces(part[i][j]);
			if (decimalPlaces > power)
				power = decimalPlaces;
		}

	// Jeder Wert in der Teilmatrix wird nun * 10 ^ (meiste Nachkommastellen) gerechnet.
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < matrixc + 1; j++)
			part[i][j] = part[i][j] * pow(10, power);
}

// Eine Teilmatrix wird verkleinert.
void lsoeShrink(double **part, int matrixc)
{
	// Die Matrix wird um den Faktor verkleinert, um den sie zuvor vergroessert wurde.
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < matrixc + 1; j++)
			part[i][j] = part[i][j] * pow(10, -power);
}
