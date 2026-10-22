#include <iostream>

#include "PostfixEval.h"

using namespace std;

int main()
{
    Stack stack;

    cout << "Assignment 1: basic Stack ADT\n";
    for (int item = 1; item <= 5; ++item)
    {
        stack.push(item);
    }

    cout << "Peek (should be 5): " << stack.peek() << '\n';
    cout << "Popping in reverse: ";
    while (!stack.isEmpty())
    {
        cout << stack.pop() << ' ';
    }
    cout << '\n';
    cout << "Empty (should be 1): " << stack.isEmpty() << '\n';

    cout << "\nAssignment 2/3: capacity and dynamic growth\n";
    for (int item = 1; item <= 100; ++item)
    {
        stack.push(item);
    }

    cout << "Full after 100 pushes: " << stack.isFull() << '\n';
#ifdef LINKED_STACK
    cout << "Linked stack accepts another push: ";
    stack.push(101);
#else
    cout << "Array stack rejects another push: ";
    stack.push(101);
#endif
    cout << "peek is " << stack.peek() << '\n';
    cout << "Popping: ";
    while (!stack.isEmpty())
    {
        cout << stack.pop() << ' ';
    }
    cout << '\n';
    cout << "Pop empty (should be -999): " << stack.pop() << '\n';

    stack.makeEmpty();

    cout << "\nAssignment 4: postfix evaluation\n";
    cout << "23+ = " << evaluatePostfix("23+", stack) << '\n';
    cout << "231*+4- = " << evaluatePostfix("231*+4-", stack) << '\n';
    cout << "82- = " << evaluatePostfix("82-", stack) << '\n';
    cout << "82/ = " << evaluatePostfix("82/", stack) << '\n';
    cout << "2++ = " << evaluatePostfix("2++", stack) << '\n';

    return 0;
}
