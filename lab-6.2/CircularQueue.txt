#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <iostream>

class CircularQueue
{
private:
    static const int MAX = 1000;
    int arr[MAX];
    int front;
    int rear;
    int size;

public:
    CircularQueue()
        : front(0), rear(-1), size(0) {}

    // 5.1 Enqueue
    bool enqueue(int x)
    {
        if (isFull())
            return false;

        rear = (rear + 1) % MAX;
        arr[rear] = x;
        ++size;
        return true;
    }

    // 5.2 Dequeue
    int dequeue()
    {
        if (isEmpty())
            return -1;

        int value = arr[front];
        front = (front + 1) % MAX;
        --size;
        return value;
    }

    int getFront() const
    {
        if (isEmpty())
            return -1;

        return arr[front];
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    bool isFull() const
    {
        return size == MAX;
    }

    int length() const
    {
        return size;
    }
};

// 5.3 First Negative in Every Window of Size K
void firstNegative(int arr[], int n, int k)
{
    if (k <= 0 || k > n)
        return;

    for (int start = 0; start <= n - k; ++start)
    {
        int negative = 0;
        for (int index = start; index < start + k; ++index)
        {
            if (arr[index] < 0)
            {
                negative = arr[index];
                break;
            }
        }

        std::cout << negative << ' ';
    }
    std::cout << '\n';
}

// 5.4 Circular Tour
int circularTour(int petrol[], int dist[], int n)
{
    if (n <= 0)
        return -1;

    int start = 0;
    int currentPetrol = 0;
    int deficit = 0;

    for (int station = 0; station < n; ++station)
    {
        currentPetrol += petrol[station] - dist[station];

        if (currentPetrol < 0)
        {
            deficit += currentPetrol;
            start = station + 1;
            currentPetrol = 0;
        }
    }

    return currentPetrol + deficit >= 0 ? start : -1;
}

// 5.5 Fixed-size LRU Cache
class LRU
{
private:
    static const int MAX = 1000;
    int keys[MAX];
    int values[MAX];
    int count;
    int capacity;

    int findKey(int key) const
    {
        for (int i = 0; i < count; ++i)
        {
            if (keys[i] == key)
                return i;
        }
        return -1;
    }

    void moveToFront(int index)
    {
        int key = keys[index];
        int value = values[index];

        for (int i = index; i > 0; --i)
        {
            keys[i] = keys[i - 1];
            values[i] = values[i - 1];
        }

        keys[0] = key;
        values[0] = value;
    }

public:
    explicit LRU(int maxSize)
        : count(0), capacity(maxSize)
    {
        if (capacity < 1)
            capacity = 1;
        if (capacity > MAX)
            capacity = MAX;
    }

    int get(int key)
    {
        int index = findKey(key);
        if (index == -1)
            return -1;

        int value = values[index];
        moveToFront(index);
        return value;
    }

    void put(int key, int value)
    {
        int index = findKey(key);

        if (index != -1)
        {
            values[index] = value;
            moveToFront(index);
            return;
        }

        if (count == capacity)
            --count;

        for (int i = count; i > 0; --i)
        {
            keys[i] = keys[i - 1];
            values[i] = values[i - 1];
        }

        keys[0] = key;
        values[0] = value;
        ++count;
    }
};

// 5.6 Rotate Queue by K Positions
void rotate(CircularQueue& q, int k)
{
    if (q.isEmpty())
        return;

    k %= q.length();
    if (k < 0)
        k += q.length();

    for (int i = 0; i < k; ++i)
        q.enqueue(q.dequeue());
}

// 5.7 Check Palindrome using Circular Queue
bool isPalindrome(const char* s)
{
    CircularQueue q;
    int length = 0;

    while (s[length] != '\0')
    {
        q.enqueue(s[length]);
        ++length;
    }

    int values[1000];
    for (int i = 0; i < length; ++i)
        values[i] = q.dequeue();

    for (int i = 0; i < length / 2; ++i)
    {
        if (values[i] != values[length - 1 - i])
            return false;
    }

    return true;
}

// 5.8 Dequeue All Elements in Reverse Order
void printReverse(CircularQueue& q)
{
    int values[1000];
    int count = 0;

    while (!q.isEmpty())
        values[count++] = q.dequeue();

    for (int i = count - 1; i >= 0; --i)
        std::cout << values[i] << ' ';

    std::cout << '\n';
}

#endif
