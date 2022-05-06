#include <fstream>
#include <iostream>
#include <math.h>
#include <regex>
#include <string>
#include <vector>

using namespace std;

bool check_separator(char input)
{
    if (input == ' ' or input == ')' or input == '(' or input == ',') {
        return true;
    } else {
        return false;
    }
}

double length_of_segment(int x1, int x2, int y1, int y2)
{
    return sqrt(pow(x1 - y1, 2) + pow(x2 - y2, 2));
}

string check_figure(string input)
{
    if (regex_match(input, regex(R"(^triangle\([^)]*\)\))"))) {
        return "triangle";
    } else if (regex_match(input, regex(R"(^circle\([^)]*\))"))) {
        return "circle";
    } else {
        return "not found";
    }
}

vector<double> get_triangle_params(string input)
{
    vector<double> triangle_params;
    for (int i = 0; i < (int)input.length() - 1; i++) {
        if (check_separator(input[i])) {
            continue;
        } else {
            int k = 0;
            string slice = "";
            while (!check_separator(input[i + k])) {
                slice += input[i + k];
                k++;
            }
            i += k;

            if (slice != "triangle") {
                triangle_params.push_back(stod(slice));
            }
        }
    }
    return triangle_params;
}

vector<double> get_circle_params(string input)
{
    vector<double> circle_params;
    for (int i = 0; i < (int)input.length() - 1; i++) {
        if (check_separator(input[i])) {
            i++;
        } else {
            int k = 0;
            string slice = "";
            while (!check_separator(input[i + k])) {
                slice += input[i + k];
                k++;
            }
            i += k;

            if (slice != "circle") {
                circle_params.push_back(stod(slice));
            }
        }
    }
    return circle_params;
}

void print_circle(string line)
{
    double x = get_circle_params(line)[0], y = get_circle_params(line)[1],
           radius = get_circle_params(line)[2], perimeter = 2.0 * M_PI * radius,
           area = M_PI * radius * radius;

    cout << "circle(" << x << " " << y << ", " << radius << ")\n";
    cout << "\tpreimeter = " << perimeter << endl;
    cout << "\tarea = " << area << endl;
}

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
