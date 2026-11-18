#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

struct CLLNode
{
    int val;
    CLLNode* next;

    CLLNode(int v)
        : val(v), next(nullptr) {}
};

// 2.1 Insert at Head
void insertHead(CLLNode*& head, int val)
{
    CLLNode* newNode = new CLLNode(val);

    if (head == nullptr)
    {
        head = newNode;
        newNode->next = newNode;
        return;
    }

    CLLNode* tail = head;
    while (tail->next != head)
        tail = tail->next;

    newNode->next = head;
    tail->next = newNode;
    head = newNode;
}

// 2.2 Insert at Tail
void insertTail(CLLNode*& head, int val)
{
    CLLNode* newNode = new CLLNode(val);

    if (head == nullptr)
    {
        head = newNode;
        newNode->next = newNode;
        return;
    }

    CLLNode* tail = head;
    while (tail->next != head)
        tail = tail->next;

    newNode->next = head;
    tail->next = newNode;
}

// 2.3 Delete Head
void deleteHead(CLLNode*& head)
{
    if (head == nullptr)
        return;

    if (head->next == head)
    {
        delete head;
        head = nullptr;
        return;
    }

    CLLNode* tail = head;
    while (tail->next != head)
        tail = tail->next;

    CLLNode* oldHead = head;
    head = head->next;
    tail->next = head;
    delete oldHead;
}

// 2.4 Delete Last Node
void deleteTail(CLLNode*& head)
{
    if (head == nullptr)
        return;

    if (head->next == head)
    {
        delete head;
        head = nullptr;
        return;
    }

    CLLNode* previous = head;
    while (previous->next->next != head)
        previous = previous->next;

    delete previous->next;
    previous->next = head;
}

// 2.5 Josephus Problem
int josephus(CLLNode* head, int k)
{
    if (head == nullptr || k <= 0)
        return -1;

    CLLNode* previous = head;
    while (previous->next != head)
        previous = previous->next;

    CLLNode* current = head;
    while (current->next != current)
    {
        for (int count = 1; count < k; ++count)
        {
            previous = current;
            current = current->next;
        }

        previous->next = current->next;
        delete current;
        current = previous->next;
    }

    int survivor = current->val;
    delete current;
    return survivor;
}

// 2.6 Split into Two Halves
void split(CLLNode* head, CLLNode*& firstHalf, CLLNode*& secondHalf)
{
    if (head == nullptr)
    {
        firstHalf = nullptr;
        secondHalf = nullptr;
        return;
    }

    CLLNode* slow = head;
    CLLNode* fast = head;

    while (fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    CLLNode* secondHead = slow->next;
    slow->next = head;

    CLLNode* secondTail = secondHead;
    while (secondTail->next != head)
        secondTail = secondTail->next;

    secondTail->next = secondHead;
    firstHalf = head;
    secondHalf = secondHead;
}

// 2.7 Detect Loop Length
int cycleLength(CLLNode* head)
{
    if (head == nullptr)
        return 0;

    CLLNode* slow = head;
    CLLNode* fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    int length = 1;
    fast = slow->next;
    while (fast != slow)
    {
        fast = fast->next;
        ++length;
    }

    return length;
}

// 2.8 Sorted Insert
void sortedInsert(CLLNode*& head, int val)
{
    CLLNode* newNode = new CLLNode(val);

    if (head == nullptr)
    {
        head = newNode;
        newNode->next = newNode;
        return;
    }

    if (val <= head->val)
    {
        CLLNode* tail = head;
        while (tail->next != head)
            tail = tail->next;

        newNode->next = head;
        tail->next = newNode;
        head = newNode;
        return;
    }

    CLLNode* current = head;
    while (current->next != head && current->next->val < val)
        current = current->next;

    newNode->next = current->next;
    current->next = newNode;
}

#endif