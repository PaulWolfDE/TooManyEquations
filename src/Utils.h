/**
 * Utils.h - C-Headerdatei
 * -----------------------
 * Enthaelt Funktionen zum Loeson verschiedener mathematischer Probleme.
 * 
 * Erstellt in C.
 * Paul Wolf, Januar 2022
 */

#ifndef UTILS_H_
#define UTILS_H_

/**
 * Ermittlung der Dezimalstellen einer Dezimalzahl.
 * 
 * Die nicht von der Fliesskommaarithmetik beeinflussten
 * Nachkommastellen werden ermittelt.
 * 
 * @param	Zahl, deren Dezimalstellen ermittelt werden soll.
 * @return	Anzahl der Dezimalstellen.
 */
int getDecimalPlaces(double);

/**
 * Berechnung der ABC-Formel.
 *
 * Rueckgabe zweier Werte fuer x, berechnet durch die Mitternachtsformel (ABC-Formel).
 * Form: ax^2 + bx + c.
 *
 * @param	a.
 * @param	b.
 * @param	c.
 * @return	Vektor der zwei Loesungen fuer x.
 */
double* quadraticFormula(double, double, double);

/**
 * Rueckgabe des Betrags einer Zahl.
 * 
 * Der Betrag (absolute value) einer Zahl wird 
 * zurueckgegeben.
 * 
 * @param	Zahl dessen Betrag bestimmt werden soll.
 * @return	Betrag der Zahl.
 */
int abs(int);

/**
 * Ermittlung des groessten gemeinsamen Teilers
 * zweier Zahlen.
 *
 * Der groesste gemeinsame Teiler von zwei Zahlen
 * wird mit dem Euklidischen Algorithmus rekursiv gefunden.
 * 
 * @param	Zahl 1.
 * @param	Zahl 2.
 * @return	Groesster gemeinsamer Teiler von 1 und 2.
 */
int gcd(int, int);

/**
 * Ermittlung des kleinsten gemeinsamen Vielfachen
 * zweier Zahlen.
 * 
 * Das kleinste gemeinsame Vielfache wird mit Hilfe deren
 * groessten gemeinsamen Teilers bestimmt. 
 * 
 * @param	Zahl 1.
 * @param	Zahl 2.
 * @return	Kleinstes gemeinsames Vielfaches von 1 und 2.
 */
int lcm(int, int);

#endif /* UTILS_H_ */
