#include "get_triangle_params.hpp"
#include "length_of_segment.hpp"
#include <iostream>
#include <math.h>

using namespace std;

void print_triangle(string line)
{
    vector<double> params = get_triangle_params(line);
    double a = length_of_segment(params[0], params[1], params[2], params[3]),
           b = length_of_segment(params[2], params[3], params[4], params[5]),
           c = length_of_segment(params[4], params[5], params[0], params[1]),
           perimeter = a + b + c, semiperimeter = perimeter / 2,
           area
            = sqrt(semiperimeter * (semiperimeter - a) * (semiperimeter - b)
                   * (semiperimeter - c));

    cout << "triangle((" << params[0] << " " << params[1] << ", " << params[2]
         << " " << params[3] << ", " << params[4] << " " << params[5] << ", "
         << params[6] << " " << params[7] << "))\n";
    cout << "\tperimeter = " << perimeter << "\n"
         << "\tarea = " << area << "\n";
}