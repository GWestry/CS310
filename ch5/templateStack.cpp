#include <iostream>

using namespace std;

template <typename T, int Capacity>
class ArrayStack
{
    T data[Capacity];
    int top = -1;

public:
    void Push(T value)
    {
        if (isFull())
        {
            cout << "Stack is full!" << endl;
            return;
        }

        top++;
        data[top] = value;
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "Nothing inside stack yet" << endl;
        }
        return data[top];
    }

    T Pop()
    {
        if (isEmpty())
        {
            cout << "Nothing inside stack yet" << endl;
        }
        return data[top--];
        // decrement after getting top
    }

    bool isEmpty()
    {
        return top == -1;
    }
};