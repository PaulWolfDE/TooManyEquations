# TooManyEquations - Documentation

## Features
- Solving linear systems of equations
- Converting periodic fractions to common fractions
- Algorithmically find the number of decimal places in a floating point number
- Calculating the quadratic formula
- Calculation GCD and LCM
- Solving movement in physics
- Geometrical properties
- Resolving Schaeferhoff's text tasks

## Linear Systems Of Equations
### Implementation
```c
#include "GaussianElimination.h"
#include "StringEvaluation.h"

// Number of results equal to the rows of the linear system of equations.
#define NUMBER_OF_RESULTS 4

int main(void)
{
    // Example matrix entered as 4 strings.
    char stringMatrix[NUMBER_OF_RESULTS][256] =
    { "3x + 4y -5z + 6a = 39", 
    "6x + 5y - 6z + 5a = 43",
    "9x - 4y + 2z + 3a = 6", 
    "2y - 3z + a = 13" };

    // Array for storing the results.
    double matrixr[NUMBER_OF_RESULTS];

    // Turning the matrix to pointer array suitable for functions.
    char *pMatrix[NUMBER_OF_RESULTS];
    for (int i = 0; i < NUMBER_OF_RESULTS; i++)
        pMatrix[i] = stringMatrix[i];

    // Array for storing the result of string evaluation.
    static double resMatrix[NUMBER_OF_RESULTS][NUMBER_OF_RESULTS+1];

    // Turning the coefficient matrix suitable for functions.
    double *pRetMatrix[NUMBER_OF_RESULTS];
    for (int i = 0; i < NUMBER_OF_RESULTS; i++)
        pRetMatrix[i] = resMatrix[i];

    // Evaluating the string matrix.
    seEvaluate(pMatrix, NUMBER_OF_RESULTS, pRetMatrix);
    // Solving the coefficient matrix.
    lsoeSolve(pRetMatrix, matrixr, NUMBER_OF_RESULTS);

    return 0;
}
```

### Important Details
Take care that after each coefficient in the string matrix (for example `4` or `-6`) there is a variable name. There may be spaces in between and variables need not be given in alphabetical order, but no variable letter may be omitted.
Coefficients can be omitted, then it is assumed that their value is 1.
Each coefficient must be preceded by a minus (`-`) or plus (`+`) as an arithmetic operation, which are also signs for the next coefficient.
Matrices can either be specified directly as coefficients or converted to them as a string array by `StringEvaluation`.  Solution is done by `GaussianElimination`.
The coefficients must be ordered before they are put into the `GaussianElimination`.
Solutions are returned ordered by their coefficients, with "xyz" alphabetically before "abc...uvw".

## Periodic Fractions
### Implementation
```c
#include "PeriodicFractionSolver.h"

int main(void)
{
    // Periodic fraction entered as string.
    char pFrac[] = "41.63(421)";
    // Derived common fraction
    char *cFrac = pfsSolve(pFrac);
    
    return 0;
}
```

### Important Details
Periodic fractions must be entered in the following format: `[Whole part].[Decimal places]([Period])`
Instead of the dot (`.`), a comma (`,`) can also be entered to separate the integer part from the decimal part.
Note that the argument of the periodic decimal fraction changes when it is derived. Use `strcpy()` from `<string.h>` to copy the decimal fraction to a new variable beforehand.

## Number Of Decimal Places
### Implementation
```c
#include "Utils.h"

int main(void)
{
    // Floating point number.
    double pi = 3.14159;
    // Determiting the number of decimal places.
    int n = getDecimalPlaces(pi);

    return 0;
}
```

### Important Details
The real decimal places are to be determined, so that inaccuracies of the floating point arithmetic are eliminated using C's native `sprintf()`.

## Quadratic Formula
### Implementation
```c
#include "Utils.h"

int main(void)
{
    // -2x² + 4x + 14 = 0
    double a = -2, b = 4, c = 14;
    // Solving with the quadratic formula.
    double *sol = quadraticFormula(a, b, c);

    return 0;
}
```

### Important Details
The function returns an array with 2 indices representing the two results of the quadratic complement.

## Euclidean Algorithm (GCD, LCM)
### Implementation
```c
#include "Utils.h"

int main(void)
{
    int a = 42, b = 72;
    // Calculation of the greatest common divisor.
    int greatestCommonDivisor = gcd(a, b);
    // Derivation from the least common multiply.
    int leastCommonMultiply = lcm(a, b);

    return 0;
}
```

## Movement
### Implementation
```c
#include "Movement.h"

int main(void)
{
    double distance = 51.3, acceleration = 4.1, double velocity = 7.8;
    // Calculating the movement data.
    double *movement = mixedMovement(distance, acceleration, velocity);

    return 0;
}
```

### Important Details
Other functions can be derivated from this implementation with ease.
All functions return an array with 3 indices (time until meeting, distance from vehicle 1, distance from vehicle 2).

## Geometry
### Implementation
```c
#include "Geometry.h"


int main(void)
{
    double radius = 4.5, height = 24.3;
    // Calculating the surface from a circular cone.
    double surface = getCircularConeSurface(radius, height);
    return 0;
}
```

### Important Details
Other functions can be derivated from this implementation with ease.

## Schaeferhoff's text tasks
> Check header files for implementations.