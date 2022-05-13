#include "check_separator.hpp"

bool check_separator(char input)
{
    if (input == ' ' or input == ')' or input == '(' or input == ',') {
        return true;
    } else {
        return false;
    }
}