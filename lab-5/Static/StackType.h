#ifndef STATIC_STACK_TYPE_H
#define STATIC_STACK_TYPE_H

#include "ItemType.h"

class FullStack
{
};
class EmptyStack
{
};

class StackType
{
public:
    StackType();
    bool IsFull() const;
    bool IsEmpty() const;
    void Push(ItemType item);
    void Pop();
    ItemType Top();
    void SetSecondElement(ItemType item);
    void EmptyAndSetBottomElement(ItemType item);
    void SetBottomElementUnchanged(ItemType item);
    StackType copyStack() const;

private:
    int top;
    ItemType items[MAX_ITEMS];
};

#endif
