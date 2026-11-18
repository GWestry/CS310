#ifndef LAB_6_1_STACK_H
#define LAB_6_1_STACK_H

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <utility>

template <typename T>
class Stack
{
public:
    static constexpr std::size_t initialCapacity = 100;

    Stack()
        : data_(new T[initialCapacity]), capacity_(initialCapacity), topIndex_(0)
    {
    }

    Stack(const Stack& other)
        : data_(new T[other.capacity_]), capacity_(other.capacity_), topIndex_(other.topIndex_)
    {
        for (std::size_t index = 0; index < topIndex_; ++index)
        {
            data_[index] = other.data_[index];
        }
    }

    Stack(Stack&& other) noexcept
        : data_(other.data_), capacity_(other.capacity_), topIndex_(other.topIndex_)
    {
        other.data_ = nullptr;
        other.capacity_ = 0;
        other.topIndex_ = 0;
    }

    Stack& operator=(const Stack& other)
    {
        if (this == &other)
        {
            return *this;
        }

        Stack copy(other);
        swap(copy);
        return *this;
    }

    Stack& operator=(Stack&& other) noexcept
    {
        if (this == &other)
        {
            return *this;
        }

        delete[] data_;
        data_ = other.data_;
        capacity_ = other.capacity_;
        topIndex_ = other.topIndex_;

        other.data_ = nullptr;
        other.capacity_ = 0;
        other.topIndex_ = 0;
        return *this;
    }

    ~Stack()
    {
        delete[] data_;
    }

    void push(const T& item)
    {
        if (isFull())
        {
            grow();
        }

        data_[topIndex_] = item;
        ++topIndex_;
    }

    T pop()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Cannot pop from an empty stack.");
        }

        --topIndex_;
        return data_[topIndex_];
    }

    T top() const
    {
        if (isEmpty())
        {
            throw std::underflow_error("Cannot read the top of an empty stack.");
        }

        return data_[topIndex_ - 1];
    }

    bool isEmpty() const
    {
        return topIndex_ == 0;
    }

    bool isFull() const
    {
        return topIndex_ == capacity_;
    }

    std::size_t size() const
    {
        return topIndex_;
    }

private:
    void grow()
    {
        if (capacity_ > std::numeric_limits<std::size_t>::max() / 2)
        {
            throw std::overflow_error("Stack capacity cannot be increased.");
        }

        const std::size_t newCapacity = capacity_ * 2;
        T* newData = nullptr;

        try
        {
            newData = new T[newCapacity];
        }
        catch (const std::bad_alloc&)
        {
            throw std::overflow_error("Stack capacity cannot be increased.");
        }

        for (std::size_t index = 0; index < topIndex_; ++index)
        {
            newData[index] = std::move_if_noexcept(data_[index]);
        }

        delete[] data_;
        data_ = newData;
        capacity_ = newCapacity;
    }

    void swap(Stack& other) noexcept
    {
        std::swap(data_, other.data_);
        std::swap(capacity_, other.capacity_);
        std::swap(topIndex_, other.topIndex_);
    }

    T* data_;
    std::size_t capacity_;
    std::size_t topIndex_;
};

#endif
