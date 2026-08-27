#include "math_functions.h"
#include <cmath> // for square root

double compute_square_root(double number)
{
    if (number < 0)
    {
        return -1; // error for negative numbers
    }
    return std::sqrt(number);
}