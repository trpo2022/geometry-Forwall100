#include "check_figure.hpp"
#include <regex>

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