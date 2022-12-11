#include "trigonometricFunctions.h"
double cot(double x) {
    return (cos(x) / sin(x));
}

double Sin(double x) {
    return (round(sin(x) * 1000000) / 1000000);
}

double Cos(double x) {
    return (round(cos(x) * 1000000) / 1000000);
}