#include "Stack.h"

#include <iostream>
#include <new>
#include <stdexcept>

Stack::Stack() : stackArray(nullptr), top(-1)
{
    try
    {
        stackArray = new ItemType[MAX_STACK];
    }
    catch (const std::bad_alloc &)
    {
        throw std::runtime_error("Unable to allocate array stack storage");
    }
}

Stack::~Stack()
{
    delete[] stackArray;
}

bool Stack::isEmpty()
{
    return top == -1;
}

bool Stack::isFull()
{
    return top == MAX_STACK - 1;
}

void Stack::push(ItemType item)
{
    if (!isFull())
    {
        ++top;
        stackArray[top] = item;
    }
    else
    {
        std::cerr << "Stack overflow: item was not pushed\n";
    }
}

ItemType Stack::pop()
{
    if (isEmpty())
    {
        std::cerr << "Stack underflow: no item to pop\n";
        return -999;
    }

    return stackArray[top--];
}

ItemType Stack::peek()
{
    if (isEmpty())
    {
        std::cerr << "Stack underflow: no item to peek\n";
        return -999;
    }

    return stackArray[top];
}

void Stack::makeEmpty()
{
    top = -1;
}