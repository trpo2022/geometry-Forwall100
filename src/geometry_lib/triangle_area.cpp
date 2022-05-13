#include <math.h>

double triangle_area(double a, double b, double c, double perimeter)
{
    double semiperimeter = perimeter / 2;

    return sqrt(
            semiperimeter * (semiperimeter - a) * (semiperimeter - b)
            * (semiperimeter - c));
}