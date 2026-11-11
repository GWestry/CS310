#ifndef LAB_6_1_CIRCULAR_LINKED_STACK_H
#define LAB_6_1_CIRCULAR_LINKED_STACK_H

#include <stdexcept>
#include <utility>
#include <vector>

template <typename T>
class CircularLinkedStack
{
private:
    struct Node
    {
        T data;
        Node* next;

        explicit Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* topNode_ = nullptr;
    int count_ = 0;

public:
    CircularLinkedStack() = default;

    CircularLinkedStack(const CircularLinkedStack& other)
    {
        if (!other.isEmpty())
        {
            std::vector<T> values;
            Node* current = other.topNode_;
            for (int index = 0; index < other.count_; ++index)
            {
                values.push_back(current->data);
                current = current->next;
            }

            for (auto value = values.rbegin(); value != values.rend(); ++value)
            {
                push(*value);
            }
        }
    }

    CircularLinkedStack& operator=(const CircularLinkedStack& other)
    {
        if (this != &other)
        {
            CircularLinkedStack copy(other);
            swap(copy);
        }
        return *this;
    }

    CircularLinkedStack(CircularLinkedStack&& other) noexcept
        : topNode_(other.topNode_), count_(other.count_)
    {
        other.topNode_ = nullptr;
        other.count_ = 0;
    }

    CircularLinkedStack& operator=(CircularLinkedStack&& other) noexcept
    {
        if (this != &other)
        {
            clear();
            topNode_ = other.topNode_;
            count_ = other.count_;
            other.topNode_ = nullptr;
            other.count_ = 0;
        }
        return *this;
    }

    ~CircularLinkedStack()
    {
        clear();
    }

    void push(const T& item)
    {
        Node* node = new Node(item);
        if (isEmpty())
        {
            node->next = node;
        }
        else
        {
            Node* bottom = topNode_;
            for (int index = 1; index < count_; ++index)
            {
                bottom = bottom->next;
            }
            node->next = topNode_;
            bottom->next = node;
        }
        topNode_ = node;
        ++count_;
    }

    T pop()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Cannot pop from an empty stack.");
        }

        T value = topNode_->data;
        if (count_ == 1)
        {
            delete topNode_;
            topNode_ = nullptr;
        }
        else
        {
            Node* bottom = topNode_;
            for (int index = 0; index < count_ - 1; ++index)
            {
                bottom = bottom->next;
            }
            Node* oldTop = topNode_;
            topNode_ = topNode_->next;
            bottom->next = topNode_;
            delete oldTop;
        }
        --count_;
        return value;
    }

    T top() const
    {
        if (isEmpty())
        {
            throw std::underflow_error("Cannot read the top of an empty stack.");
        }
        return topNode_->data;
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
            pop();
        }
    }

    void swap(CircularLinkedStack& other) noexcept
    {
        std::swap(topNode_, other.topNode_);
        std::swap(count_, other.count_);
    }
};

#endif
