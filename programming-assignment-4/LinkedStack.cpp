#include "Stack.h"

#include <iostream>
#include <new>

Stack::Stack() : top(nullptr) {}

Stack::~Stack()
{
    makeEmpty();
}

bool Stack::isEmpty()
{
    return top == nullptr;
}

bool Stack::isFull()
{
    return false;
}

void Stack::push(ItemType item)
{
    try
    {
        Node *newNode = new Node(item);
        newNode->next = top;
        top = newNode;
    }
    catch (const std::bad_alloc &)
    {
        std::cerr << "Stack allocation failed: item was not pushed\n";
    }
}

ItemType Stack::pop()
{
    if (isEmpty())
    {
        std::cerr << "Stack underflow: no item to pop\n";
        return -999;
    }

    ItemType item = top->data;
    Node *temp = top;
    top = top->next;
    delete temp;
    return item;
}

ItemType Stack::peek()
{
    if (isEmpty())
    {
        std::cerr << "Stack underflow: no item to peek\n";
        return -999;
    }

    return top->data;
}

void Stack::makeEmpty()
{
    while (!isEmpty())
    {
        pop();
    }
}