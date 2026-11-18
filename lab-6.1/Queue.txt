#ifndef LAB_6_1_QUEUE_H
#define LAB_6_1_QUEUE_H

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <utility>

template <typename T>
class Queue
{
public:
    static constexpr std::size_t initialCapacity = 100;

    Queue()
        : data_(new T[initialCapacity]), capacity_(initialCapacity), frontIndex_(0),
          rearIndex_(0), count_(0)
    {
    }

    Queue(const Queue& other)
        : data_(new T[other.capacity_]), capacity_(other.capacity_), frontIndex_(0),
          rearIndex_(other.count_), count_(other.count_)
    {
        for (std::size_t index = 0; index < count_; ++index)
        {
            data_[index] = other.data_[(other.frontIndex_ + index) % other.capacity_];
        }
    }

    Queue& operator=(const Queue& other)
    {
        if (this != &other)
        {
            Queue copy(other);
            swap(copy);
        }
        return *this;
    }

    Queue(Queue&& other) noexcept
        : data_(other.data_), capacity_(other.capacity_), frontIndex_(other.frontIndex_),
          rearIndex_(other.rearIndex_), count_(other.count_)
    {
        other.data_ = nullptr;
        other.capacity_ = 0;
        other.frontIndex_ = 0;
        other.rearIndex_ = 0;
        other.count_ = 0;
    }

    Queue& operator=(Queue&& other) noexcept
    {
        if (this != &other)
        {
            delete[] data_;
            data_ = other.data_;
            capacity_ = other.capacity_;
            frontIndex_ = other.frontIndex_;
            rearIndex_ = other.rearIndex_;
            count_ = other.count_;
            other.data_ = nullptr;
            other.capacity_ = 0;
            other.frontIndex_ = 0;
            other.rearIndex_ = 0;
            other.count_ = 0;
        }
        return *this;
    }

    ~Queue()
    {
        delete[] data_;
    }

    void enqueue(const T& item)
    {
        if (isFull())
        {
            throw std::overflow_error("Cannot enqueue into a full queue.");
        }
        data_[rearIndex_] = item;
        rearIndex_ = (rearIndex_ + 1) % capacity_;
        ++count_;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Cannot dequeue from an empty queue.");
        }
        T value = data_[frontIndex_];
        frontIndex_ = (frontIndex_ + 1) % capacity_;
        --count_;
        return value;
    }

    T front() const
    {
        if (isEmpty())
        {
            throw std::underflow_error("Cannot read the front of an empty queue.");
        }
        return data_[frontIndex_];
    }

    bool isEmpty() const
    {
        return count_ == 0;
    }

    bool isFull() const
    {
        return count_ == capacity_;
    }

    std::size_t size() const
    {
        return count_;
    }

private:
    void swap(Queue& other) noexcept
    {
        std::swap(data_, other.data_);
        std::swap(capacity_, other.capacity_);
        std::swap(frontIndex_, other.frontIndex_);
        std::swap(rearIndex_, other.rearIndex_);
        std::swap(count_, other.count_);
    }

    T* data_;
    std::size_t capacity_;
    std::size_t frontIndex_;
    std::size_t rearIndex_;
    std::size_t count_;
};

#endif
