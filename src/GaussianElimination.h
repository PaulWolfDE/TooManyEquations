/**
 * GaussianElimination.h - C-Headerdatei
 * -------------------------------------
 * Enthaelt Funktionen zum Loesen von Matrizen linearer Gleichungssysteme.
 * 
 * Uebersetzt aus Java, Original vom August 2021, C-Variante vom Januar 2022.
 * Paul Wolf, Januar 2022
 */

#ifndef GAUSSIANELIMINATION_H_
#define GAUSSIANELIMINATION_H_

/**
 * Loesen eines linearen Gleichungssystems.
 * 
 * Ein zweidimensionaler Vektor aus Koeffizienten (Matrix) 
 * eines linearen Gleichungssystems wird mit dem Gaussschen 
 * Eliminationsverfahren geloest.
 * 
 * @param 	Koeffizientenmatrix, die geloest werden soll.
 * @param 	Vektor, in dem die Loesungen gespeichert werden.
 * @param 	Anzahl der Unbekannten (Anzahl der Zeilen) der Matrix.
 */
void lsoeSolve(double**, double[], int);

#endif /* GAUSSIANELIMINATION_H_ */
