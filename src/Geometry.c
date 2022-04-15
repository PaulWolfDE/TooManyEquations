/**
 * Geometry.c - C-Quelldatei
 * ------------------------------------
 * Enthaelt geometrische Loesungsformeln.
 * 
 * Erstellt in C.
 * Paul Wolf, Maerz 2022
 */

#include <math.h>

double getCircularConeCapacity(double radius, double height)
{
	return M_PI * pow(radius, 2) * height / 3;
}

double getCircularConeMantle(double radius, double height)
{
	return M_PI * radius * sqrt(pow(radius, 2) + pow(height, 2));
}

double getCircularConeSurface(double radius, double height)
{
	return M_PI * radius * (radius + sqrt(pow(radius, 2) + pow(height, 2)));
}

double getCircularCylinderCapacity(double radius, double height)
{
    return M_PI * pow(radius, 2) * height;
}

double getCircularCylinderMantle(double radius, double height)
{
    return 2 * M_PI * radius * height;
}

double getCircularCylinderSurface(double radius, double height)
{
    return 2 * M_PI * radius * (radius + height);
}

double getSphereCapacity(double radius)
{
    return 4 * M_PI * pow(radius, 3) / 3;
}

double getSphereSurface(double radius)
{
    return 4 * M_PI * pow(radius, 2);
}

double lawOfSinesLength(double alpha, double beta, double a)
{
    return a / sin(alpha) * sin(beta);
}

double lawOfSinesAngle(double alpha, double a, double b)
{
    return sin(alpha) / a * b;
}

double lawOfCosinesLength(double alpha, double b, double c)
{
    return sqrt(pow(b,2) + pow(c,2) - 2*b*c * cos(alpha));
}

double lawOfCosinesAngle(double a, double b, double c)
{
    return acos((pow(a,2) - pow(b,2) - pow(c, 2)) / (-2*b*c));
}
