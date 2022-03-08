#include <fstream>
#include <iostream>
#include <regex>
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

bool check_cicle(string input)
{
    if (regex_match(input, regex(R"(^circle\([^)]*\))"))) {
        return true;
    } else {
        return false;
    }
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

int main()
{
    int line_number = 1;
    string line;
    ifstream file("./input.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            if (check_cicle(line)) {
                double x = get_circle_params(line)[0],
                       y = get_circle_params(line)[1],
                       radius = get_circle_params(line)[2],
                       perimeter = 2.0 * 3.14 * radius,
                       area = 3.14 * radius * radius;
                cout << "circle(" << x << " " << y << ", " << radius << ")\n";
                cout << "\tpreimeter = " << perimeter << endl;
                cout << "\tarea = " << area << endl;
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
