#include "trigonometricFunctions.h"


double cot(double x) 
{
    return (Cos(x) / Sin(x));
}

double Sin(double x) 
{
    return (16 * x * (PI - x)) / (5 * PI * PI - 4 * x * (PI - x)); //приближение синуса Ѕхаскары
}

double Cos(double x) 
{
    double y = PI / 2 - x;
    return Sin(y);
}

double tan(double x) 
{
    return 1 / cot(x);
}