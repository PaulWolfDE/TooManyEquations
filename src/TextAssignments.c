/**
 * TextAssignments.c - C-Quelldatei
 * --------------------------------
 * Enthaelt Funktionen zur Berechnung verschiedener Schaeferhoff'scher Textaufgaben.
 * 
 * Uebersetzt aus Java, Original vom Dezember 2020, C-Variante vom Januar 2022.
 * Paul Wolf, Januar 2022
 */

#include <math.h>

double agSBefore(double, double, double);
double agSAfter(double, double, double);
double agFBefore(double, double, double);
double agFAfter(double, double, double);

int leFirstC(int, int, int, int);
int leSecondC(int, int, int, int);
int leFirstL(int, int, int, int);
int leSecondL(int, int, int, int);

double aiPercent(double, double, double, double);
double aiQuantity(double, double);

double gaPriceToday(double, double, double, double);
double gaPriceYesterday(double, double, double, double);
double gaGasToday(double, double, double, double);
double gaGasYesterday(double, double, double, double);

double* taAge(double multiplierBerfore, double multiplierAfter, double delay)
{
	static double ret[4];
	ret[0] = agSBefore(multiplierBerfore, multiplierAfter, delay);
	ret[1] = agSAfter(multiplierBerfore, multiplierAfter, delay);
	ret[2] = agFBefore(multiplierBerfore, multiplierAfter, delay);
	ret[3] = agFAfter(multiplierBerfore, multiplierAfter, delay);
	return ret;
}

double taCleaningt1(double t2, double t3)
{
	return 1 / (1 / t3 - 1 / t2);
}
double taCleaningt2(double t1, double t3)
{
	return 1 / (1 / t3 - 1 / t1);
}
double taCleaningt3(double t1, double t2)
{
	return 1 / (1 / t1 + 1 / t2);
}

int* taLegs(int legs1, int legs2, int countAll, int countLegs)
{
	static int ret[4];
	ret[0] = leFirstC(legs1, legs2, countAll, countLegs);
	ret[1] = leSecondC(legs1, legs2, countAll, countLegs);
	ret[2] = leFirstL(legs1, legs2, countAll, countLegs);
	ret[3] = leSecondL(legs1, legs2, countAll, countLegs);
	return ret;
}

double* taAcid(double quantity1, double quantity2, double percentage1,
		double percentage2)
{
	static double ret[2];
	ret[0] = aiPercent(quantity1, quantity2, percentage1, percentage2);
	ret[1] = aiQuantity(quantity1, quantity2);
	return ret;
}

double* taGas(double totalPriceToday, double totalPriceYesterday,
		double priceDifference, double gasDifference)
{
	static double ret[4];
	ret[0] = gaPriceToday(totalPriceToday, totalPriceYesterday, priceDifference, gasDifference);
	ret[1] = gaPriceYesterday(totalPriceToday, totalPriceYesterday, priceDifference, gasDifference);
	ret[2] = gaGasToday(totalPriceToday, totalPriceYesterday, priceDifference, gasDifference);
	ret[3] = gaGasYesterday(totalPriceToday, totalPriceYesterday, priceDifference, gasDifference);
	return ret;
}

double agSBefore(double multiplierBerfore, double multiplierAfter, double delay)
{
	return (multiplierAfter * delay - delay)
			/ (multiplierBerfore - multiplierAfter);
}
double agSAfter(double multiplierBerfore, double multiplierAfter, double delay)
{
	return agSBefore(multiplierBerfore, multiplierAfter, delay) + delay;
}
double agFBefore(double multiplierBerfore, double multiplierAfter, double delay)
{
	return agSBefore(multiplierBerfore, multiplierAfter, delay)
			* multiplierBerfore;
}
double agFAfter(double multiplierBerfore, double multiplierAfter, double delay)
{
	return (agSBefore(multiplierBerfore, multiplierAfter, delay) + delay)
			* multiplierAfter;
}

int leFirstC(int legs1, int legs2, int countAll, int countLegs)
{
	return (countLegs - legs2 * countAll) / (legs1 - legs2);
}
int leSecondC(int legs1, int legs2, int countAll, int countLegs)
{
	return countAll - leFirstC(legs1, legs2, countAll, countLegs);
}
int leFirstL(int legs1, int legs2, int countAll, int countLegs)
{
	return leFirstC(legs1, legs2, countAll, countLegs) * legs1;
}
int leSecondL(int legs1, int legs2, int countAll, int countLegs)
{
	return leSecondC(legs1, legs2, countAll, countLegs) * legs2;
}

double aiPercent(double quantity1, double quantity2, double percentage1,
		double percentage2)
{
	return (quantity1 * (percentage1 / 100) + quantity2 * (percentage2 / 100))
			/ (quantity1 + quantity2);
}
double aiQuantity(double quantity1, double quantity2)
{
	return quantity1 + quantity2;
}

double gaPriceToday(double totalPriceToday, double totalPriceYesterday,
		double priceDifference, double gasDifference)
{
	return totalPriceToday
			/ (sqrt(
					pow(
							0.5
									* (totalPriceToday
											+ priceDifference * gasDifference
											- totalPriceYesterday)
									* -(1 / -priceDifference), 2)
							- (totalPriceToday * gasDifference
									* -(1 / -priceDifference)))
					- (0.5
							* (totalPriceToday + priceDifference * gasDifference
									- totalPriceYesterday)
							* -(1 / -priceDifference)));
}

double gaPriceYesterday(double totalPriceToday, double totalPriceYesterday,
		double priceDifference, double gasDifference)
{
	return gaPriceToday(totalPriceToday, totalPriceYesterday, priceDifference, gasDifference) + priceDifference;
}

double gaGasToday(double totalPriceToday, double totalPriceYesterday,
		double priceDifference, double gasDifference)
{
	return totalPriceToday / gaPriceToday(totalPriceToday, totalPriceYesterday, priceDifference, gasDifference);
}

double gaGasYesterday(double totalPriceToday, double totalPriceYesterday,
		double priceDifference, double gasDifference)
{
	return gaGasToday(totalPriceToday, totalPriceYesterday, priceDifference, gasDifference) + gasDifference;
}
