#ifndef LINKED_STACK_TYPE_H
#define LINKED_STACK_TYPE_H

#include "ItemType.h"

class FullStack
{
};
class EmptyStack
{
};

struct NodeType;

class StackType
{
public:
    StackType();
    ~StackType();
    bool IsFull() const;
    bool IsEmpty() const;
    void Push(ItemType item);
    void Pop();
    ItemType Top();

private:
    NodeType *topPtr;
};

#endif
