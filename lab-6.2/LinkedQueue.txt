#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

struct QNode
{
    int val;
    QNode* next;

    QNode(int v)
        : val(v), next(nullptr) {}
};

class LinkedQueue
{
private:
    QNode* front;
    QNode* rear;

    void clear()
    {
        while (front != nullptr)
        {
            QNode* oldFront = front;
            front = front->next;
            delete oldFront;
        }
        rear = nullptr;
    }

public:
    LinkedQueue()
        : front(nullptr), rear(nullptr) {}

    LinkedQueue(const LinkedQueue& other)
        : front(nullptr), rear(nullptr)
    {
        QNode* current = other.front;
        while (current != nullptr)
        {
            enqueue(current->val);
            current = current->next;
        }
    }

    LinkedQueue& operator=(const LinkedQueue& other)
    {
        if (this == &other)
            return *this;

        clear();
        QNode* current = other.front;
        while (current != nullptr)
        {
            enqueue(current->val);
            current = current->next;
        }
        return *this;
    }

    ~LinkedQueue()
    {
        clear();
    }

    // 6.1 Enqueue
    void enqueue(int x)
    {
        QNode* newNode = new QNode(x);

        if (rear == nullptr)
        {
            front = newNode;
            rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    // 6.2 Dequeue
    int dequeue()
    {
        if (front == nullptr)
            return -1;

        QNode* oldFront = front;
        int value = oldFront->val;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete oldFront;
        return value;
    }

    int getFront() const
    {
        return front == nullptr ? -1 : front->val;
    }

    bool isEmpty() const
    {
        return front == nullptr;
    }

    int size() const
    {
        int count = 0;
        QNode* current = front;
        while (current != nullptr)
        {
            ++count;
            current = current->next;
        }
        return count;
    }
};

// 6.3 Reverse Linked Queue
void reverse(LinkedQueue& q)
{
    int count = q.size();
    int values[1000];

    for (int i = 0; i < count; ++i)
        values[i] = q.dequeue();

    for (int i = count - 1; i >= 0; --i)
        q.enqueue(values[i]);
}

// 6.4 Merge Two Sorted Queues
LinkedQueue merge(const LinkedQueue& a, const LinkedQueue& b)
{
    LinkedQueue first = a;
    LinkedQueue second = b;
    LinkedQueue result;

    while (!first.isEmpty() && !second.isEmpty())
    {
        if (first.getFront() <= second.getFront())
            result.enqueue(first.dequeue());
        else
            result.enqueue(second.dequeue());
    }

    while (!first.isEmpty())
        result.enqueue(first.dequeue());
    while (!second.isEmpty())
        result.enqueue(second.dequeue());

    return result;
}

// 6.5 Remove Duplicates
void removeDuplicates(LinkedQueue& q)
{
    LinkedQueue unique;

    while (!q.isEmpty())
    {
        int value = q.dequeue();
        LinkedQueue remaining = unique;
        bool alreadyExists = false;

        while (!remaining.isEmpty())
        {
            if (remaining.dequeue() == value)
            {
                alreadyExists = true;
                break;
            }
        }

        if (!alreadyExists)
            unique.enqueue(value);
    }

    q = unique;
}

// 6.6 Implement Stack Using One Linked Queue
class StackFromLinkedQueue
{
private:
    LinkedQueue q;

public:
    void push(int x)
    {
        q.enqueue(x);
        int count = q.size();

        for (int i = 1; i < count; ++i)
            q.enqueue(q.dequeue());
    }

    int pop()
    {
        return q.dequeue();
    }
};

// 6.7 Find Middle Element
int middle(const LinkedQueue& q)
{
    LinkedQueue copy = q;
    int count = copy.size();
    int middleValue = -1;

    for (int i = 0; i <= count / 2; ++i)
        middleValue = copy.dequeue();

    return middleValue;
}

// 6.8 Move Front to Rear K Times
void rotateK(LinkedQueue& q, int k)
{
    if (q.isEmpty())
        return;

    k %= q.size();
    if (k < 0)
        k += q.size();

    for (int i = 0; i < k; ++i)
        q.enqueue(q.dequeue());
}

#endif