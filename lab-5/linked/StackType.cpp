#include "StackType.h"
#include <new>

struct NodeType
{
    ItemType info;
    NodeType *next;
};

void StackType::Push(ItemType newItem)
{
    NodeType *location = new NodeType;
    location->info = newItem;
    location->next = topPtr;
    topPtr = location;
}

void StackType::Pop()
{
    if (IsEmpty())
        throw EmptyStack();

    NodeType *tempPtr = topPtr;
    topPtr = topPtr->next;
    delete tempPtr;
}

ItemType StackType::Top()
{
    if (IsEmpty())
        throw EmptyStack();
    return topPtr->info;
}

StackType::StackType() : topPtr(nullptr)
{
}

bool StackType::IsFull() const
{
    NodeType *location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch (const std::bad_alloc &)
    {
        return true;
    }
}

StackType::~StackType()
{
    while (topPtr != nullptr)
    {
        NodeType *tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
}

bool StackType::IsEmpty() const
{
    return topPtr == nullptr;
}
