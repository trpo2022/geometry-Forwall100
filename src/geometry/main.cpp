#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../geometry_lib/check_figure.hpp"
#include "../geometry_lib/get_circle_params.hpp"
#include "../geometry_lib/get_triangle_params.hpp"
#include "../geometry_lib/print_circle.hpp"
#include "../geometry_lib/print_triangle.hpp"

using namespace std;

int main()
{
    int curent_line = 1;
    string line;
    ifstream file("./input.txt");
    vector<vector<double>> circles, triangles;

    if (file.is_open()) {
        while (getline(file, line)) {
            string figure = check_figure(line);
            if (figure == "circle") {
                circles.push_back(get_circle_params(line));
            } else if (figure == "triangle") {
                triangles.push_back(get_triangle_params(line));
            } else {
                cout << "Syntax error on the line [" << curent_line << "]"
                     << endl;
            }
            curent_line++;
        }
        print_circle(circles);
        print_triangle(triangles);

        return 0;
    }
}
