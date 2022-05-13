#include <math.h>
#include "length_of_segment.hpp"

double length_of_segment(double x1, double x2, double y1, double y2)
{
    return sqrt(pow(x1 - y1, 2) + pow(x2 - y2, 2));
}