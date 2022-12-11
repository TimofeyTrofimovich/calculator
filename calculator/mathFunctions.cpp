#include "mathFunctions.h"
double sqrt_(double a) {
	return sqrt(a);
}

int absolute(int a)
{
	return abs(a);
}

int factorial(int a)
{
	int b = 1;
	for (size_t i = 1; i <= a; i++)
	{
		b *= i;
	}
	return b;
}

double log_e(int a)
{
	return log(a);
}

double log_10(int a)
{
	return log10(a);
}

double log(int a, int b)
{
	return (log(a) / log(b));
}
