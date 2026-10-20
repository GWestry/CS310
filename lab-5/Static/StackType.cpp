#include "StackType.h"

StackType::StackType()
{
    top = -1;
}

bool StackType::IsEmpty() const
{
    return top == -1;
}

bool StackType::IsFull() const
{
    return top == MAX_ITEMS - 1;
}

void StackType::Push(ItemType newItem)
{
    if (IsFull())
        throw FullStack();
    top++;
    items[top] = newItem;
}

void StackType::Pop()
{
    if (IsEmpty())
        throw EmptyStack();
    top--;
}

ItemType StackType::Top()
{
    if (IsEmpty())
        throw EmptyStack();
    return items[top];
}

void StackType::SetSecondElement(ItemType item)
{
    if (top < 1)
        throw EmptyStack();
    items[1] = item;
}

void StackType::EmptyAndSetBottomElement(ItemType item)
{
    top = -1;
    Push(item);
}

void StackType::SetBottomElementUnchanged(ItemType item)
{
    if (IsFull())
        throw FullStack();

    for (int index = top + 1; index > 0; index--)
        items[index] = items[index - 1];
    items[0] = item;
    top++;
}

StackType StackType::copyStack() const
{
    StackType copy;
    copy.top = top;
    for (int index = 0; index <= top; index++)
        copy.items[index] = items[index];
    return copy;
}
