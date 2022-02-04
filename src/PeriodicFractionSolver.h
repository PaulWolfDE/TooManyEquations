/**
 * PeriodicFractionSolver.h - C-Headerdatei
 * ----------------------------------------
 * Loest einen periodischen Dezimalbruch in einen gemeinen Bruch.
 * 
 * Uebersetzt aus Java, Original vom Oktober 2021, C-Variante vom Januar 2022.
 * Paul Wolf, Januar 2022
 */

#ifndef PERIODICFRACTIONSOLVER_H_
#define PERIODICFRACTIONSOLVER_H_

/**
 * Loesen eines periodischen Dezimalbruchs.
 *
 * Ein Dezimalbruch mit Periode am Ende wird
 * in einen gemeinen Bruch umgeformt.
 *
 * @param	Zeichenkette | Darstellung des Bruchs:
 * 			--> [GANZZAHLIGER_TEIL].[DEZIMALER_TEIL]([PERIODE])
 * 			--> Beispiel: "41.63(421)"
 * @return	Zeichenkette | Gemeiner Bruch:
 * 			--> Beispiel: "2079629 / 49950"
 */
char* pfsSolve(char[]);

#endif /* PERIODICFRACTIONSOLVER_H_ */
