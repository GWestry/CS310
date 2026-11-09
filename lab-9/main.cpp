#include "TreeType.h"
#include <iostream>
using namespace std;

int main()
{
    TreeType tree;
    for (char i = '0'; i < '9'; i++)
    {
        tree.PutItem(i);
    }

    cout << "Leaf count: " << tree.LeafCount() << endl;
    return 0;
}