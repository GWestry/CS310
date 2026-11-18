#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct DLLNode
{
    int val;
    DLLNode* prev;
    DLLNode* next;

    DLLNode(int v)
        : val(v), prev(nullptr), next(nullptr) {}
};

// 1.1 Insert at head
void insertHead(DLLNode*& head, int val)
{
    DLLNode* newNode = new DLLNode(val);
    newNode->next = head;

    if (head != nullptr)
        head->prev = newNode;

    head = newNode;
}

// 1.2 Insert at Tail
void insertTail(DLLNode*& head, DLLNode*& tail, int val)
{
    DLLNode* newNode = new DLLNode(val);
    newNode->prev = tail;

    if(tail == nullptr){
        head = newNode;
    }
    else{
        tail->next = newNode;
    }

    tail = newNode;
}

// 1.3 Delete Head

void deleteHead(DLLNode*& head, DLLNode*& tail){
    if (head == nullptr){
        return;
    }
    else{
        DLLNode* temp = head;
        head = head->next;

    if (head == nullptr){
        tail = nullptr;
    }
    else{
        head->prev = nullptr;
    }

    delete temp;
    }
}

// 1.4 Delete Tail
void deleteTail(DLLNode*& head, DLLNode*& tail)
{
    if (tail == nullptr)
        return;

    DLLNode* temp = tail;
    tail = tail->prev;

    if (tail == nullptr)
    {
        head = nullptr;
    }
    else
    {
        tail->next = nullptr;
    }

    delete temp;
}

// 1.5 Insert After a Given Node
void insertAfter(DLLNode* node, int val)
{
    if (node == nullptr)
        return;

    DLLNode* newNode = new DLLNode(val);
    newNode->prev = node;
    newNode->next = node->next;

    if (node->next != nullptr)
        node->next->prev = newNode;

    node->next = newNode;
}

// 1.6 Delete a Given Node (not head/tail)
void deleteNode(DLLNode* node)
{
    if (node == nullptr || node->prev == nullptr || node->next == nullptr)
        return;

    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
}

// 1.7 Reverse DLL
void reverse(DLLNode*& head, DLLNode*& tail)
{
    DLLNode* current = head;

    while (current != nullptr)
    {
        DLLNode* nextNode = current->next;
        current->next = current->prev;
        current->prev = nextNode;
        current = nextNode;
    }

    DLLNode* oldHead = head;
    head = tail;
    tail = oldHead;
}

// 1.8 Find Middle Node (one pass)
DLLNode* middle(DLLNode* head)
{
    DLLNode* slow = head;
    DLLNode* fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// 1.9 Detect Cycle (Floyd)
bool hasCycle(DLLNode* head)
{
    DLLNode* slow = head;
    DLLNode* fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

#endif