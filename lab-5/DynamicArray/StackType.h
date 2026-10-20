#ifndef DYNAMIC_STACK_TYPE_H
#define DYNAMIC_STACK_TYPE_H

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
    explicit StackType(int max);
    ~StackType();
    bool IsEmpty() const;
    bool IsFull() const;
    void Push(ItemType item);
    void Pop();
    ItemType Top();

private:
    int maxStack;
    int top;
    ItemType *items;
};

#endif
