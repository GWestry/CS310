#include <iostream>
#include <stdexcept>
#include "ItemType.h"
using namespace std;

struct Node
{
    ItemType item;
    Node *next;
    Node(const ItemType &newItem) : item(newItem), next(nullptr) {}
};

class LinkedQueue
{

private:
    Node *rear;
    int size;

    LinkedQueue(const LinkedQueue &other) = delete;
    LinkedQueue &operator=(const LinkedQueue &other) = delete;

public:
    LinkedQueue() : rear(nullptr), size(0) {}

    ~LinkedQueue()
    {
        // TODO: Implement destructor to delete all nodes in the queue
    }

    void enqueue(const ItemType &newItem)
    {

        // Check for memory allocation failure
        if (isFull)
        {
            throw bad_alloc("Memory allocation failed");
        }
        Node *newNode = new Node(newItem);

        if (isEmpty())
        {
            rear = newNode;
            rear->next = newNode;
        }
        else
        {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    ItemType dequeue()
    {
        if (isEmpty())
        {
            throw out_of_range("Queue is empty");
        }

        Node *front = rear->next;
        ItemType item = front->item;

        if (rear == front)
        {
            rear = nullptr;
        }
        else
        {
            rear->next = front->next;
        }
        delete front;
        size--;
        return item;
    }

    ItemType front() const
    {
        if (isEmpty())
        {
            throw out_of_range("Queue is empty");
        }

        Node *front = rear->next;
        return front->item;
    }
};
