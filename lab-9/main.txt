#include "TreeType.h"
#include <iostream>
using namespace std;

int main()
{
    {
        TreeType tree;
        cout << "Empty tree: " << tree.LeafCount()
             << " (expected 0)" << endl;
    }

    {
        TreeType tree;
        tree.PutItem('5');
        cout << "One node: " << tree.LeafCount()
             << " (expected 1)" << endl;
    }

    {
        TreeType tree;
        tree.PutItem('5');
        tree.PutItem('2');
        cout << "Root with one child: " << tree.LeafCount()
             << " (expected 1)" << endl;
    }

    {
        TreeType tree;
        tree.PutItem('5');
        tree.PutItem('2');
        tree.PutItem('8');
        cout << "Root with two children: " << tree.LeafCount()
             << " (expected 2)" << endl;
    }

    {
        TreeType tree;
        tree.PutItem('1');
        tree.PutItem('2');
        tree.PutItem('3');
        tree.PutItem('4');
        tree.PutItem('5');
        cout << "One-sided tree: " << tree.LeafCount()
             << " (expected 1)" << endl;
    }

    {
        TreeType tree;
        tree.PutItem('5');
        tree.PutItem('3');
        tree.PutItem('7');
        tree.PutItem('2');
        tree.PutItem('4');
        tree.PutItem('6');
        tree.PutItem('8');
        cout << "Balanced tree: " << tree.LeafCount()
             << " (expected 4)" << endl;
    }

    {
        TreeType tree;
        tree.PutItem('5');
        tree.PutItem('5');
        tree.PutItem('5');
        cout << "Duplicate values: " << tree.LeafCount()
             << " (expected 1)" << endl;
    }

    return 0;
}