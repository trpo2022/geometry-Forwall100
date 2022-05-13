#include "print_circle.hpp"
#include "circle_area.hpp"
#include "circle_perimeter.hpp"
#include "get_circle_params.hpp"
#include "intersection_of_circles.hpp"
#include <iostream>
#include <math.h>

using namespace std;

void print_circle(vector<vector<double>> circles)
{
    for (int i = 0; i < circles.size(); i++) {
        double x = circles[i][0], y = circles[i][1], radius = circles[i][2];
        double area = circle_area(radius), perimeter = circle_perimeter(radius);
        cout << i + 1 << ". circle(" << x << " " << y << ", " << radius
             << ")\n";
        cout << "\tpreimeter = " << perimeter << endl;
        cout << "\tarea = " << area << endl;
        cout << "\tintersects:" << endl;

        for (int j = 0; j < circles.size(); j++) {
            if (j == i) {
                continue;
            } else {
                double x2 = circles[j][0], y2 = circles[j][1],
                       radius2 = circles[j][2];
                if (intersection_of_circles(x, y, radius, x2, y2, radius2)) {
                    cout << "\t\t" << j + 1 << ". circle\n";
                }
            }
        }
    }
}