#include <iostream>
#include <random>
#include "unsorted.h"

using namespace std;

int main()
{
    random_device rd;
    mt19937 eng(rd());
    int min = 0;
    int max = 99;
    uniform_int_distribution<int> distr(min, max);

    cout << distr(eng) << endl;

    return 0;
}
