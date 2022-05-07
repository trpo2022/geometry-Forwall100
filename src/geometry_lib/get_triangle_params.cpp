#include "get_triangle_params.hpp"
#include "check_separator.hpp"

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