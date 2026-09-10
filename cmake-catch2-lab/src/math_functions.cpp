#include "math_functions.h"
#include <cmath> // for square root
#include <stdexcept>

double compute_square_root(double number)
{
    if (number < 0)
    {
        throw std::invalid_argument("Cannot compute square root of a negative number"); // error for negative numbers
    }
    return std::sqrt(number);
}