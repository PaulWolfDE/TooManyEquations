/**
 * Geometry.h - C-Headerdatei
 * ------------------------------------
 * Enthaelt geometrische Loesungsformeln.
 * 
 * Erstellt in C.
 * Paul Wolf, Maerz 2022
 */

#ifndef GEOMETRY_H_
#define GEOMETRY_H_

/**
 * Berechnungen mit Kreiskegeln.
 * 
 * Berechnung des Volumens, der Mantelflaeche
 * und des Oberflaecheninhalts aus Radius
 * und Hoehe.
 * 
 * @param	Radius des Kreiskegels
 * @param	Hoehe des Kreiskegels
 * 
 * @return	(1) Volumen
 * @return	(2) Mantelflaeche
 * @return	(3) Oberflaecheninhalt
 */
double getCircularConeCapacity(double, double);
double getCircularConeMantle(double, double);
double getCircularConeSurface(double, double);

/**
 * Berechnungen mit Kreiszylindern.
 * 
 * Berechnung des Volumens, der Mantelflaeche
 * und des Oberflaecheninhalts aus Radius
 * und Hoehe.
 * 
 * @param	Radius des Kreiskegels
 * @param	Hoehe des Kreiskegels
 * 
 * @return	(1) Volumen
 * @return	(2) Mantelflaeche
 * @return	(3) Oberflaecheninhalt
 */
double getCircularCylinderCapacity(double, double);
double getCircularCylinderMantle(double, double);
double getCircularCylinderSurface(double, double);

/**
 * Berechnungen mit Kugeln.
 * 
 * Berechnung des Volumens und des 
 * Oberflaecheninhalts aus Radius.
 * 
 * @param	Radius der Kugel
 * 
 * @return	(1) Volumen
 * @return	(2) Oberflaecheninhalt
 */
double getSphereCapacity(double);
double getSphereSurface(double);

#endif /* GEOMETRY_H_ */