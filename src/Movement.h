/**
 * Movement.h - C-Headerdatei
 * --------------------------
 * Enthaelt Funktionen zur Berechnung physikalischer Bewegungen.
 * 
 * Uebersetzt aus Java, Original vom August 2021, C-Variante vom Januar 2022.
 * Paul Wolf, Januar 2022
 */

#ifndef MOVEMENT_H_
#define MOVEMENT_H_

/**
 * Berechnungen bei gleichmaessig beschleunigter Bewegung.
 *
 * Berechnung von Zeit, Strecke von 1, Strecke von 2, bis sich
 * zwei gleichmaessig beschleunigte Objekte 1 und 2 treffen.
 *
 * @param	Distanz der beiden Objekte zum Start in m.
 * @param	Beschleunigung des 1. Objekts in m/s^2.
 * @param	Beschleunigung des 2. Objekts in m/s^2.
 * @return	Vektor (3) -->
 * 			- Zeit bis Treffen in s.
 * 			- zurueckgelegte Distanz von Objekt 1 beim Treffen in m.
 * 			- zurueckgelegte Distanz von Objekt 2 beim Treffen in m.
 */
double* acceleratedMovement(double, double, double);

/**
 * Berechnungen bei gleichfoermiger Bewegung.
 *
 * Berechnung von Zeit, Strecke von 1, Strecke von 2, bis sich
 * zwei gleichfoermig bewegte Objekte 1 und 2 treffen.
 *
 * @param	Distanz der beiden Objekte zum Start in m.
 * @param	Geschwindigkeit des 1. Objekts in m/s.
 * @param	Geschwindigkeit des 2. Objekts in m/s.
 * @return	Vektor (3) -->
 * 			- Zeit bis Treffen in s.
 * 			- zurueckgelegte Distanz von Objekt 1 beim Treffen in m.
 * 			- zurueckgelegte Distanz von Objekt 2 beim Treffen in m.
 */
double* uniformMovement(double, double, double);

/**
 * Berechnungen bei gemischter Bewegung.
 *
 * Berechnung von Zeit, Strecke von 1, Strecke von 2, bis sich
 * ein gleichmaessig beschleunigtes Objekt 1 und ein
 * gleichfoermig bewegtes Objekt 2 treffen.
 *
 * @param	Distanz der beiden Objekte zum Start in m.
 * @param	Beschleunigung des 1. Objekts in m/s^2.
 * @param	Geschwindigkeit des 2. Objekts in m/s.
 * @return	Vektor (3) -->
 * 			- Zeit bis Treffen in s.
 * 			- zurueckgelegte Distanz von Objekt 1 beim Treffen in m.
 * 			- zurueckgelegte Distanz von Objekt 2 beim Treffen in m.
 */
double* mixedMovement(double, double, double);

#endif /* MOVEMENT_H_ */
