#include <fstream>
#include <iostream>
#include <string>

#include <geometry_lib/check_figure.hpp>
#include <geometry_lib/print_circle.hpp>
#include <geometry_lib/print_triangle.hpp>

using namespace std;

int main()
{
    int line_number = 1;
    string line;
    ifstream file("./input.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            string figure = check_figure(line);
            if (figure == "circle") {
                print_circle(line);
            } else if (figure == "triangle") {
                print_triangle(line);
            } else {
                cout << "Syntax error on the line [" << line_number << "]"
                     << endl;
            }
            line_number++;
        }
        string output = "";

        return 0;
    }
}
