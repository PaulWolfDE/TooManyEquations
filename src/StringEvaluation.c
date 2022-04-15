/**
 * StringEvaluation.c - C-Quelldatei
 * ---------------------------------
 * Enthaelt Funktionen, um eine Zeichenkette in eine Matrix eines linearen Gleichungssystems umzuwandeln.
 * 
 * Uebersetzt aus Java, Original vom August 2021, C-Variante vom Januar 2022.
 * Paul Wolf, Januar 2022
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_LENGTH 26
#define MAX_ASCII 128
#define MAX_TEMP 256

void seSearch(char[], char[], char[], int, int, double**);
bool seIsDigit(char);

const char possibleVarNames[] = "xyzabcdefghijklmnopqrstuvwxyz";

void seEvaluate(char **line, int linec, double **matrix) // linec: Anzahl Zeilen
{
	bool ascii[MAX_ASCII], v[ALPHABET_LENGTH];
	for (int i = 0; i < MAX_ASCII; i++)
	{
		ascii[i] = false;
		v[i % ALPHABET_LENGTH] = false;
	}
	for (int i = 0; i < linec; i++)
		for (int j = 0; j < strlen(line[i]); j++)
			ascii[(int) line[i][j]] = true;

	for (int i = 0; i < ALPHABET_LENGTH; i++)
	{
		if (i < 23)
		{
			if (ascii[i + 97])
				v[i + 3] = true;
		}
		else
		{
			if (ascii[i + 97])
				v[i - 23] = true;
		}
	}

	char vars[ALPHABET_LENGTH] = "";
	for (int i = 0; i < ALPHABET_LENGTH; i++)
		if (v[i])
		{
			char str[2] = "\0";
			str[0] = possibleVarNames[i];
			strcat(vars, str);
		}

/*	double matrix[strlen(vars)][strlen(vars) + 1];
	for (int i = 0; i < strlen(vars); i++)
		argv[i] = matrix[i];
*/
	char temp[MAX_TEMP];
	for (int i = 0; i < strlen(vars); i++)
	{
		for (int i = 0; i < MAX_TEMP; i++)
			temp[i] = 0;
		seSearch(line[i], vars, temp, 0, i, matrix);
	}
}

void seSearch(char equation[], char vars[], char temp[], int index, int row,
		double **matrix)
{
	if (seIsDigit(equation[index]) || equation[index] == '-')
	{
		char str[2] = "\0";
		str[0] = equation[index];
		strcat(temp, str);
	}

	else if (equation[index] == '.' || equation[index] == ',')
		strcat(temp, ".");
	else
	{
		for (int i = 0; i < strlen(vars); i++)
		{
			if (equation[index] == vars[i])
			{
				if (strcmp(temp, "") == 0 || strcmp(temp, "\0") == 0
						|| strcmp(temp, "-") == 0)
					strcat(temp, "1");
				matrix[row][i] = strtod(temp, NULL);
				memset(temp, 0, MAX_TEMP);
				break;
			}
		}
	}

	if (index + 1 < strlen(equation))
		seSearch(equation, vars, temp, index + 1, row, matrix);
	else
		matrix[row][strlen(vars)] = strtod(temp, NULL);
}
bool seIsDigit(char c)
{
	if (c > 47 && c < 58)
		return true;
	return false;
}

