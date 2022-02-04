/**
 * TextAssignments.h - C-Headerdatei
 * ---------------------------------
 * Enthaelt Funktionen zur Berechnung verschiedener Schaeferhoff'scher Textaufgaben.
 * 
 * Uebersetzt aus Java, Original vom Dezember 2020, C-Variante vom Januar 2022.
 * Paul Wolf, Januar 2022
 */

#ifndef TEXTASSIGNMENTS_H_
#define TEXTASSIGNMENTS_H_

/**
 * Berechnung vom Alter des Vaters und des Sohns.
 *
 * Berechnung des Alters des Vaters und des Sohns jetzt und in n Jahren.
 *
 * "Der Vater ist jetzt [PARAM_1] mal so alt wie der Sohn und in [PARAM_3]
 * Jahren [PARAM_2] mal so alt."
 *
 * @param	Faktor, um den der Vater jetzt aelter ist.
 * @param	Faktor, um den der Vater in n Jahren aelter ist.
 * @param	Anzahl der Jahre zwischen den beiden Faktoren.
 * @return	Vektor (4) -->
 * 			- Alter des Sohns jetzt.
 * 			- Alter des Sohns in n Jahren.
 * 			- Alter des Vaters jetzt.
 * 			- Alter des Vaters in n Jahren.
 */
double* taAge(double, double, double);


double taCleaningt1(double, double);
double taCleaningt2(double, double);
double taCleaningt3(double, double);


/**
 * Berechnung der Anzahl von Beinen.
 *
 * Berechnung der Anzahl der Beine einzelner Tiere.
 *
 * "[PARAM_3] [PARAM_1] und [PARAM_2] haben zusammen [PARAM_4] Beine."
 *
 * @param	Anzahl der Beine pro Tier 1.
 * @param	Anzahl der Beine pro Tier 2.
 * @param	Anzahl der Tiere gesamt.
 * @param	Anzahl aller Beine gesamt.
 * @return 	Vektor (4) -->
 * 			- Anzahl der Tiere von Tier 1.
 * 			- Anzahl der Tiere von Tier 2.
 * 			- Anzahl der Beine von allen Tier 1.
 * 			- Anzahl der Beine von allen Tier 2.
 */
int* taLegs(int, int, int, int);

/**
 * Berechnung von Saeure.
 *
 * Berechnung der Menge und der Prozentzahl von Saeure.
 *
 * "[PARAM_1] Liter [PARAM_3] prozentige Saeure werden mit
 * [PARAM_2] Liter [PARAM_4] prozentige Saeure gemischt."
 *
 * @param   Menge der ersten Saeure in l.P
 * @param   Menge der zweiten Saeure in l.
 * @param   Prozentzahl der ersten Saeure.
 * @param   Prozentzahl der zweiten Saeure.
 * @return  Vektor (2) -->
 *          - Prozentzahl der entstehenden Saeure.
 *          - Menge der entstehenden Saeure in l.
 */
double* taAcid(double, double, double, double);


/**
 * Berechnung von Benzinpreisen.
 *
 * Berechnung vom Benzinpreis und der gekauften Menge an zwei Tagen.
 *
 * "Uwe tankt sein Auto heute und zahlt [PARAM_1]EUR. Gestern hat er
 * [PARAM_4] Liter mehr getankt und [PARAM_3]EUR pro Liter mehr gezahlt
 * als heute. Gestern bezahlte er [PARAM_2]EUR."
 *
 * Wenn 'mehr' bei [PARAM_3] und [PARAM_4] nicht zutrifft, muss
 * der Wert mit einem Minus davor angegeben werden!
 *
 * @param	Gesamter Benzinpreis heute in EUR.
 * @param	Gesamter Benzinpreis gestern in EUR.
 * @param	Preisdifferenz in l/EUR.
 * @param	Mengendifferenz des Benzins in l.
 * @return	Vektor (4) -->
 * 			- Preis pro Liter heute in EUR/l.
 * 			- Preis pro Liter gestern in EUR/l.
 * 			- Getanktes Benzin heute in l.
 * 			- Getanktes Benzin gestern in l.
 */
double* taGas(double, double, double, double);

#endif /* TEXTASSIGNMENTS_H_ */
