/**
 * StringEvaluation.h - C-Headerdatei
 * ---------------------------------
 * Enthaelt Funktionen, um eine Zeichenkette in eine Matrix eines linearen Gleichungssystems umzuwandeln.
 * 
 * Uebersetzt aus Java, Original vom August 2021, C-Variante vom Januar 2022.
 * Paul Wolf, Januar 2022
 */

#ifndef STRINGEVALUATION_H_
#define STRINGEVALUATION_H_

/**
 * Erstellung einer Koeffizienten-Matrix aus einem Vektor
 * von Zeichenketten.
 * 
 * Aus der Eingabe von Zeilen wird ein zweidimensionaler
 * Vektor (Matrix) geformt, der dann mit dem Gaussschen
 * Eliminationsverfahren geloest werden kann.
 * 
 * @param 	Gleichungssystem, zeilenweise aufgeteilt.
 * @param	Anzahl der Zeilen im Gleichungssystem.
 * @param	Rueckgabevektor fuer die entstandene Matrix.
 */
void seEvaluate(char**, int, double**);

#endif /* STRINGEVALUATION_H_ */
