#ifndef STACK_H
#define STACK_H

const int MAX_STACK = 100;
typedef int ItemType;

#ifdef LINKED_STACK
struct Node
{
    ItemType data;
    Node *next;

    Node(ItemType item) : data(item), next(nullptr) {}
};
#endif

class Stack
{
public:
    Stack();
    ~Stack();
    Stack(const Stack &) = delete;
    Stack &operator=(const Stack &) = delete;

    bool isEmpty();
    bool isFull();
    void push(ItemType item);
    ItemType pop();
    ItemType peek();
    void makeEmpty();

private:
#ifdef LINKED_STACK
    Node *top;
#else
    ItemType *stackArray;
    int top;
#endif
};

#endif
