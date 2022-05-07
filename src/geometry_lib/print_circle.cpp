#include "print_circle.hpp"
#include "get_circle_params.hpp"
#include <iostream>
#include <math.h>

using namespace std;

void print_circle(string line)
{
    double x = get_circle_params(line)[0], y = get_circle_params(line)[1],
           radius = get_circle_params(line)[2], perimeter = 2.0 * M_PI * radius,
           area = M_PI * radius * radius;

    cout << "circle(" << x << " " << y << ", " << radius << ")\n";
    cout << "\tpreimeter = " << perimeter << endl;
    cout << "\tarea = " << area << endl;
}