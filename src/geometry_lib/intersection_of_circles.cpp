#include "../geometry_lib/intersection_of_circles.hpp"
#include "../geometry_lib/length_of_segment.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

bool intersection_of_circles(
        double x1,
        double y1,
        double radius1,
        double x2,
        double y2,
        double radius2)
{
    double radius_difference = max(radius1, radius2) - min(radius1, radius2);
    double radius_sum = radius1 + radius2;
    double center_distance = length_of_segment(x1, x2, y1, y2);

    if ((center_distance > radius_difference)
        and (center_distance < radius_sum)) {
        return true;
    } else {
        return false;
    }
}