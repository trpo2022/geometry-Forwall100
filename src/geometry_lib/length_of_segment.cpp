#include <math.h>
#include "length_of_segment.hpp"

double length_of_segment(int x1, int x2, int y1, int y2)
{
    return sqrt(pow(x1 - y1, 2) + pow(x2 - y2, 2));
}