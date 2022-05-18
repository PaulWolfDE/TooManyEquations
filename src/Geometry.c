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

void calculateTriangle(Triangle *t)
{
    double *lengths[3] = {&t->a, &t->b, &t->c};
    double *angles[3] = {&t->alpha, &t->beta, &t->gamma};

    if (t->area != 0)
    {
        for (int i = 0; i < 3; i++)
        {
            if (!(*lengths[i] == 0 || *lengths[(i+1)%3] == 0) && angles[(i+2)%3] == 0)
                *angles[(i+2)%3] = radiansToDegrees(asin((2 * t->area) / (*lengths[i] * *lengths[(i+1)%3])));
            else if (!(*lengths[i] == 0 || *angles[(i+2)%3] == 0) && *lengths[(i+1)%3] == 0)
                *lengths[(i+1)%3] = (2 * t->area) / (*lengths[i] * sin(degreesToRadians(*angles[(i+2)%3])));
            else if (!(*lengths[(i+1)%3] == 0 || *angles[(i+2)%3] == 0) && *lengths[i] == 0)
                *lengths[i] = (2 * t->area) / (*lengths[(i+1)%3] * sin(degreesToRadians(*angles[(i+2)%3])));
        }
    }

    if (t->perimeter != 0 && !(*lengths[0] != 0 && *lengths[1] != 0 && *lengths[2] != 0))
        for (int i = 0; i < 3; i++)
            if (*lengths[i] != 0 && *lengths[(i+1)%3] != 0)
                *lengths[(i+2)%3] = t->perimeter - *lengths[i] - *lengths[(i+1)%3];

    for (int i = 0; i < 3; i++)
        if (!(*lengths[i] == 0 || *lengths[(i+1)%3] == 0 || *angles[(i+2)%3] == 0))
            *lengths[(i+2)%3] = sqrt(pow(*lengths[(i+1)%3], 2) + pow(*lengths[i], 2) - 2 * *lengths[(i+1)%3] * *lengths[i] * cos(degreesToRadians(*angles[(i+2)%3])));

    for (int i = 0; i < 3; i++)
    {
        if (!(*lengths[i] == 0 || *angles[i] == 0))
        {
            for (int j = 1; j <= 2; j++)
            {
                int k = (i+j)%3;
                if (*lengths[k] != 0)
                    *angles[k] = radiansToDegrees(asin(sin(degreesToRadians(*angles[i])) * *lengths[k] / *lengths[i]));
                if (*angles[k] != 0)
                    *lengths[k] = *lengths[i] * sin(degreesToRadians(*angles[k])) / sin(degreesToRadians(*angles[i]));
            }
        }
    }
    
    if (!(t->a == 0 || t->b == 0|| t->c == 0))
    {
        t->alpha = radiansToDegrees(acos((pow(t->a, 2) - pow(t->b, 2) - pow(t->c, 2)) / (-2 * t->b * t->c)));
        t->beta = radiansToDegrees(acos((pow(t->b, 2) - pow(t->a, 2) - pow(t->c, 2)) / (-2 * t->a * t->c)));
        t->gamma = radiansToDegrees(acos((pow(t->c, 2) - pow(t->a, 2) - pow(t->b, 2)) / (-2 * t->a * t->b)));
    }

    t->perimeter = t->a + t->b + t->c;
    t->area = 0.5 * t->b * t->c * sin(degreesToRadians(t->alpha));
}

void printTriangle(Triangle t)
{
    printf("a:\t\t%.2lf\n"
            "b:\t\t%.2lf\n"
            "c:\t\t%.2lf\n"
            "Alpha:\t\t%.2lf\n"
            "Beta:\t\t%.2lf\n"
            "Gamma:\t\t%.2lf\n"
            "Perimeter:\t%.2lf\n"
            "Area:\t\t%.2lf\n",
            t.a, t.b, t.c, t.alpha, t.beta, t.gamma, t.perimeter, t.area);
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
