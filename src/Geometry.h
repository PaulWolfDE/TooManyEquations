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

typedef struct
{
    double radius;
    double diameter;
    double circumference;
    double circleArea;
    double surfaceArea;
    double volume;
} Sphere;

void calculateSphere(Sphere*);
void printSphere(Sphere);

typedef struct
{
    double a;
    double b;
    double c;
    double alpha;
    double beta;
    double gamma;
    double perimeter;
    double area;
} Triangle;

void calculateTriangle(Triangle*);
void printTriangle(Triangle);

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

/**
 * Berechnung des Sinussatzes.
 * 
 * Berechnung einer Seitenlaenge in einem
 * beliebigen Dreieck mit dem Sinussatz.
 *
 * @param   Winkel Alpha
 * @param   Winkel Beta
 * @param   Seitenlaenge a
 *
 * @return  Seitenlaenge b 
 */
double lawOfSinesLength(double, double, double);

/**
 * Berechnung des Sinussatzes.
 * 
 * Berechnung eines Winkels in einem
 * beliebigen Dreieck mit dem Sinussatz.
 *
 * @param   Winkel Alpha
 * @param   Seitenlaenge a
 * @param   Seitenlaenge b
 *
 * @return  Winkel Beta
 */
double lawOfSinesAngle(double, double, double);

/**
 * Berechnung des Kosinussatzes.
 * 
 * Berechnung einer Seitenlaenge in einem
 * beliebigen Dreieck mit dem Kosinussatz.
 *
 * @param   Winkel Alpha
 * @param   Seitenlaenge b
 * @param   Seitenlaenge c
 *
 * @return  Seitenlaenge a
 */
double lawOfCosinesLength(double, double, double);

/**
 * Berechnung des Kosinussatzes.
 * 
 * Berechnung eines Winkels in einem
 * beliebigen Dreieck mit dem Kosinussatz.
 *
 * @param   Seitenlaenge a
 * @param   Seitenlaenge b
 * @param   Seitenlaenge c
 *
 * @return  Winkel Alpha
 */
double lawOfCosinesAngle(double, double, double);

/**
 * Berechnung des Flaecheninhalts eines Dreiecks.
 *
 * Berechnungsformel fuer den Flaecheninhalt in einem
 * beliebigen Dreieck durch einen von zwei Seiten
 * eingeschlossenen Winkel.
 *
 * @param   Winkel Alpha
 * @param   Seitenlaenge b
 * @param   Seitenlaenge c
 *
 * @return  Flaecheninhalt A
 */
double getTriangleArea(double, double, double);

/**
 * Umwandlung von Grad zu Bogenmass.
 *
 * @param   Winkel in Grad
 *
 * @return  Winkel in Bogenmass
 */
double degreesToRadians(double);

/**
 * Umwandlung von Bogenmass zu Grad.
 *
 * @param   Winkel in Bogenmass
 *
 * @return  Winkel in Grad
 */
double radiansToDegrees(double);

#endif /* GEOMETRY_H_ */
