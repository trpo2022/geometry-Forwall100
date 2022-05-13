#include "get_circle_params.hpp"
#include "check_separator.hpp"

vector<double> get_circle_params(string input)
{
    vector<double> circle_params;
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

            if (slice != "circle") {
                circle_params.push_back(stod(slice));
            }
        }
    }
    return circle_params;
}