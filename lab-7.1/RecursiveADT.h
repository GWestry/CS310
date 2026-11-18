#ifndef RECURSIVE_ADT_H
#define RECURSIVE_ADT_H

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

struct Node {
    int data;
    Node* next;
    explicit Node(int value) : data(value), next(nullptr) {}
};

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
    explicit DNode(int value) : data(value), next(nullptr), prev(nullptr) {}
};

struct CNode {
    int data;
    CNode* next;
    explicit CNode(int value) : data(value), next(nullptr) {}
};

inline Node* makeList(const std::vector<int>& values) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int value : values) {
        Node* node = new Node(value);
        if (!head) head = node;
        else tail->next = node;
        tail = node;
    }
    return head;
}

inline void deleteList(Node* head) {
    while (head) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

inline std::vector<int> values(Node* head, std::size_t limit = 10000) {
    std::vector<int> result;
    while (head && result.size() < limit) {
        result.push_back(head->data);
        head = head->next;
    }
    return result;
}

inline void printValues(const std::vector<int>& result) {
    for (std::size_t i = 0; i < result.size(); ++i)
        std::cout << (i ? " " : "") << result[i];
    std::cout << '\n';
}

inline void printList(Node* head) { printValues(values(head)); }

inline DNode* makeDoublyList(const std::vector<int>& input) {
    DNode* head = nullptr;
    DNode* tail = nullptr;
    for (int value : input) {
        DNode* node = new DNode(value);
        if (!head) head = node;
        else { tail->next = node; node->prev = tail; }
        tail = node;
    }
    return head;
}

inline void deleteDoublyList(DNode* head) {
    while (head) {
        DNode* next = head->next;
        delete head;
        head = next;
    }
}

inline CNode* makeCircularList(const std::vector<int>& input) {
    CNode* head = nullptr;
    CNode* tail = nullptr;
    for (int value : input) {
        CNode* node = new CNode(value);
        if (!head) head = node;
        else tail->next = node;
        tail = node;
    }
    if (tail) tail->next = head;
    return head;
}

inline void deleteCircularList(CNode*& head) {
    if (!head) return;
    CNode* current = head->next;
    while (current != head) {
        CNode* next = current->next;
        delete current;
        current = next;
    }
    delete head;
    head = nullptr;
}

class IntStack {
    std::vector<int> data_;
public:
    bool empty() const { return data_.empty(); }
    void push(int value) { data_.push_back(value); }
    int pop() { int value = data_.back(); data_.pop_back(); return value; }
    int top() const { return data_.back(); }
    std::size_t size() const { return data_.size(); }
};

class IntQueue {
    std::queue<int> data_;
public:
    bool empty() const { return data_.empty(); }
    void push(int value) { data_.push(value); }
    int pop() { int value = data_.front(); data_.pop(); return value; }
    std::size_t size() const { return data_.size(); }
};

inline int length(Node* head) {
    return head ? 1 + length(head->next) : 0;
}

inline Node* nodeAt(Node* head, int index) {
    return index == 0 ? head : nodeAt(head->next, index - 1);
}

#endif
