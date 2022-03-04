#include <math.h>
#include <stdio.h>

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