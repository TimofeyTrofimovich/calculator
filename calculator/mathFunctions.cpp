#include "mathFunctions.h"

int pow(int number, int power) {
	for (size_t i = 0; i < power; i++)
		number *= number;
		return number;
}

double sqrt_(double number) {
	double t;
	double squareRoot = number / 2;
	do {
		t = squareRoot;
		squareRoot = (t + (number / t)) / 2;
	} while ((t - squareRoot) != 0);
	return squareRoot;
}

int absolute(int a)
{
	if (a >= 0)
		return abs(a);
	else
		return -a;
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
	return log_e(a)/log_e(10);
}

double log(int a, int b)
{
	return (log_e(a) / log_e(b));
}
