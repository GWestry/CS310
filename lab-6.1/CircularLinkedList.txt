#ifndef LAB_6_1_CIRCULAR_LINKED_LIST_H
#define LAB_6_1_CIRCULAR_LINKED_LIST_H

#include <iostream>
#include <stdexcept>

template <typename T>
class CircularLinkedList
{
private:
    struct Node
    {
        T data;
        Node* next;

        explicit Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head_ = nullptr;
    int count_ = 0;

public:
    CircularLinkedList() = default;

    ~CircularLinkedList()
    {
        clear();
    }

    void insertFront(const T& item)
    {
        Node* node = new Node(item);
        if (isEmpty())
        {
            node->next = node;
        }
        else
        {
            Node* tail = head_;
            while (tail->next != head_)
            {
                tail = tail->next;
            }
            node->next = head_;
            tail->next = node;
        }
        head_ = node;
        ++count_;
    }

    void insertRear(const T& item)
    {
        if (isEmpty())
        {
            insertFront(item);
            return;
        }

        Node* node = new Node(item);
        Node* tail = head_;
        while (tail->next != head_)
        {
            tail = tail->next;
        }
        node->next = head_;
        tail->next = node;
        ++count_;
    }

    void deleteFront()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Cannot delete the front of an empty list.");
        }

        Node* oldHead = head_;
        if (count_ == 1)
        {
            head_ = nullptr;
        }
        else
        {
            Node* tail = head_;
            while (tail->next != head_)
            {
                tail = tail->next;
            }
            head_ = head_->next;
            tail->next = head_;
        }
        delete oldHead;
        --count_;
    }

    void deleteRear()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Cannot delete the rear of an empty list.");
        }

        if (count_ == 1)
        {
            deleteFront();
            return;
        }

        Node* previous = head_;
        while (previous->next->next != head_)
        {
            previous = previous->next;
        }
        delete previous->next;
        previous->next = head_;
        --count_;
    }

    void display(std::ostream& out = std::cout) const
    {
        out << "[";
        Node* current = head_;
        for (int index = 0; index < count_; ++index)
        {
            if (index > 0)
            {
                out << ' ';
            }
            out << current->data;
            current = current->next;
        }
        out << "]";
    }

    bool isEmpty() const
    {
        return count_ == 0;
    }

    int size() const
    {
        return count_;
    }

private:
    void clear() noexcept
    {
        while (!isEmpty())
        {
            deleteFront();
        }
    }
};

#endif
