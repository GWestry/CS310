#include <iostream>
#include <stdexcept>

void divide(int a, int b)
{
    if (b == 0)
    {
        throw std::invalid_argument("Division by zero is is invalid!");
    }
    std::cout << "Result: " << a / b << std::endl;
}

int main()
{
    try
    {
        divide(10, 0);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << " Caught: " << e.what() << std::endl;
    }

    return 0;
}