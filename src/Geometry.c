/**
 * Geometry.c - C-Quelldatei
 * ------------------------------------
 * Enthaelt geometrische Loesungsformeln.
 * 
 * Erstellt in C.
 * Paul Wolf, Maerz 2022
 */

#include <math.h>
#include <stdio.h>

#include "Geometry.h"

void calculateSphere(Sphere *s)
{
    if (s->diameter != 0)
        s->radius = s->diameter / 2;
    else if (s->circumference != 0)
        s->radius = s->circumference / (2 * M_PI);
    else if (s->circleArea != 0)
        s->radius = sqrt(s->circleArea / M_PI);
    else if (s->surfaceArea != 0)
        s->radius = sqrt(s->surfaceArea / (4 * M_PI));
    else if (s->volume != 0)
        s->radius = pow((3 * s->volume) / (4 * M_PI), 1 / 3);
    
    if (s->radius == 0)
    {
        fprintf(stderr, "The sphere is missing values.\n");
        return;
    }

    s->diameter = 2 * s->radius;
    s->circumference = 2 * M_PI * s->radius;
    s->circleArea = M_PI * pow(s->radius, 2);
    s->surfaceArea = 4 * M_PI * pow(s->radius, 2);
    s->volume = (4/3) * M_PI * pow(s->radius, 3);
}

void printSphere(Sphere s)
{
    printf("Radius:\t\t%.2lf\n"
            "Diameter:\t%.2lf\n"
            "Circumference:\t%.2lf\n"
            "Circle area:\t%.2lf\n"
            "Surface area:\t%.2lf\n"
            "Volume:\t\t%.2lf\n",
            s.radius, s.diameter, s.circumference, s.circleArea, s.surfaceArea, s.volume);
}

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

double lawOfSinesLength(double alpha, double beta, double a)
{
    return a / sin(alpha) * sin(beta);
}

double lawOfSinesAngle(double alpha, double a, double b)
{
    return asin(sin(alpha) / a * b);
}

double lawOfCosinesLength(double alpha, double b, double c)
{
    return sqrt(pow(b,2) + pow(c,2) - 2*b*c * cos(alpha));
}

double lawOfCosinesAngle(double a, double b, double c)
{
    return acos((pow(a,2) - pow(b,2) - pow(c, 2)) / (-2*b*c));
}

double getTriangleArea(double alpha, double b, double c) 
{
    return 0.5 * b * c * sin(alpha);
}

double degreesToRadians(double degrees)
{
    return degrees * M_PI / 180;
}

double radiansToDegrees(double radians)
{
    return radians / M_PI * 180;
}
