#ifndef LAB_6_1_CIRCULAR_LINKED_QUEUE_H
#define LAB_6_1_CIRCULAR_LINKED_QUEUE_H

#include <stdexcept>
#include <utility>

template <typename T>
class CircularLinkedQueue
{
private:
    struct Node
    {
        T data;
        Node* next;

        explicit Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* rear_ = nullptr;
    int count_ = 0;

public:
    CircularLinkedQueue() = default;

    ~CircularLinkedQueue()
    {
        clear();
    }

    CircularLinkedQueue(const CircularLinkedQueue& other)
    {
        Node* current = other.rear_ == nullptr ? nullptr : other.rear_->next;
        for (int index = 0; index < other.count_; ++index)
        {
            enqueue(current->data);
            current = current->next;
        }
    }

    CircularLinkedQueue& operator=(const CircularLinkedQueue& other)
    {
        if (this != &other)
        {
            CircularLinkedQueue copy(other);
            swap(copy);
        }
        return *this;
    }

    CircularLinkedQueue(CircularLinkedQueue&& other) noexcept
        : rear_(other.rear_), count_(other.count_)
    {
        other.rear_ = nullptr;
        other.count_ = 0;
    }

    CircularLinkedQueue& operator=(CircularLinkedQueue&& other) noexcept
    {
        if (this != &other)
        {
            clear();
            rear_ = other.rear_;
            count_ = other.count_;
            other.rear_ = nullptr;
            other.count_ = 0;
        }
        return *this;
    }

    void enqueue(const T& item)
    {
        Node* node = new Node(item);
        if (isEmpty())
        {
            node->next = node;
        }
        else
        {
            node->next = rear_->next;
            rear_->next = node;
        }
        rear_ = node;
        ++count_;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Cannot dequeue from an empty queue.");
        }

        Node* frontNode = rear_->next;
        T value = frontNode->data;
        if (count_ == 1)
        {
            rear_ = nullptr;
        }
        else
        {
            rear_->next = frontNode->next;
        }
        delete frontNode;
        --count_;
        return value;
    }

    T front() const
    {
        if (isEmpty())
        {
            throw std::underflow_error("Cannot read the front of an empty queue.");
        }
        return rear_->next->data;
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
            dequeue();
        }
    }

    void swap(CircularLinkedQueue& other) noexcept
    {
        std::swap(rear_, other.rear_);
        std::swap(count_, other.count_);
    }
};

#endif
