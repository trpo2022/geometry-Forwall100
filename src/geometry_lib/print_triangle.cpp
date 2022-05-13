#include "get_triangle_params.hpp"
#include "length_of_segment.hpp"
#include "triangle_area.hpp"
#include "triangle_perimeter.hpp"
#include <iostream>
#include <math.h>

using namespace std;

void print_triangle(vector<vector<double>> triangles)
{
    for (int i = 0; i < triangles.size(); i++) {
        double a = length_of_segment(
                       triangles[i][0],
                       triangles[i][1],
                       triangles[i][2],
                       triangles[i][3]),
               b = length_of_segment(
                       triangles[i][2],
                       triangles[i][3],
                       triangles[i][4],
                       triangles[i][5]),
               c = length_of_segment(
                       triangles[i][4],
                       triangles[i][5],
                       triangles[i][0],
                       triangles[i][1]);
        double perimeter = triangle_perimeter(a, b, c),
               area = triangle_area(a, b, c, perimeter);

        cout << "triangle((" << triangles[i][0] << " " << triangles[i][1]
             << ", " << triangles[i][2] << " " << triangles[i][3] << ", "
             << triangles[i][4] << " " << triangles[i][5] << ", "
             << triangles[i][6] << " " << triangles[i][7] << "))\n";
        cout << "\tperimeter = " << perimeter << "\n"
             << "\tarea = " << area << "\n";
    }
}