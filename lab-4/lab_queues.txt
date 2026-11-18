#include <iostream>
#include <deque>
#include <vector>

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {};
};

class LinkedListQueue
{

private:
    Node *head;
    Node *tail;

public:
    LinkedListQueue() : head(nullptr), tail(nullptr) {}

    ~LinkedListQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
        // TODO: Implement destructor to free all nodes and prevent memory leaks
    }

    void enqueue(int val)
    {
        Node *newNode = new Node(val);
        if (tail == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void dequeue()
    {
        // TODO: Remove element from the front of the queue
        if (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;

            if (head == nullptr)
            {
                tail = nullptr;
            }
        }
    }

    int front()
    {
        // TODO: Return the front element (-1 if empty)
        if (head != nullptr)
        {
            return head->data;
        }
        return -1;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }
};

// Section 2: Bounded Circular Queue Skeleton

class MyCircularQueue
{

private:
    std::vector<int> data;
    int head;
    int tail;
    int size;
    int capacity;

public:
    MyCircularQueue(int k)
    {
        capacity = k;
        data.resize(capacity);
        head = 0;
        tail = 0;
        size = 0;

        // TODO: Initialize capacity and data vector
    }

    bool enQueue(int value)
    {
        if (isFull())
        {
            std::cout << "Queue is full" << std::endl;
            return false;
        }
        // TODO: Insert element into circular queue
        data[tail] = value;
        tail = (tail + 1) % capacity;
        size++;
        return true;
    }

    bool deQueue()
    {
        // TODO: Delete element from circular queue
        if (isEmpty())
        {
            std::cout << "Queue is empty" << std::endl;
            return false;
        }
        head = (head + 1) % capacity;
        size--;
        return true;
    }

    int Front()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        return data[head];
        // TODO: Return front item
    }

    int Rear()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        return data[(tail - 1 + capacity) % capacity];
        // TODO: Return rear item
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {

        return size == capacity;
    }
};

// Section 3: Sliding window maximum function skeleton

std::vector<int> maxSlidingWindow(const std::vector<int> &nums, int k)
{

    std::vector<int> result;

    std::deque<int> dq; // Store indices

    // TODO: Implement sliding window maximum using monotonic deque logic

    if (k <= 0 || nums.empty() || k > nums.size())
    {
        return result;
    }

    for (int index = 0; index < nums.size(); index++)
    {
        while (!dq.empty() && dq.front() <= index - k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && nums[dq.back()] <= nums[index])
        {
            dq.pop_back();
        }
        dq.push_back(index);
        if (index >= k - 1)
        {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}

int main()
{
    std::cout << "--- Testing Custom Queue Lab ---" << std::endl;

    std::cout << "\nSection 1: Linked List Queue" << std::endl;
    LinkedListQueue linkedQueue;
    linkedQueue.enqueue(10);
    linkedQueue.enqueue(20);
    linkedQueue.enqueue(30);
    std::cout << "Test 1 - Front after enqueue: " << linkedQueue.front() << std::endl;
    linkedQueue.dequeue();
    std::cout << "Test 2 - Front after dequeue: " << linkedQueue.front() << std::endl;
    linkedQueue.dequeue();
    linkedQueue.dequeue();
    std::cout << "Test 3 - Front of empty queue: " << linkedQueue.front() << std::endl;

    std::cout << "\nSection 2: Bounded Circular Queue" << std::endl;
    MyCircularQueue circularQueue(3);
    circularQueue.enQueue(10);
    circularQueue.enQueue(20);
    circularQueue.enQueue(30);
    std::cout << "Test 4 - Front: " << circularQueue.Front() << std::endl;
    std::cout << "Test 5 - Rear: " << circularQueue.Rear() << std::endl;
    circularQueue.deQueue();
    circularQueue.enQueue(40);
    std::cout << "Test 6 - Front after wraparound: " << circularQueue.Front() << std::endl;
    std::cout << "Test 7 - Rear after wraparound: " << circularQueue.Rear() << std::endl;

    std::cout << "\nSection 3: Sliding Window Maximum" << std::endl;
    std::vector<int> numbers = {1, 3, -1, -3, 5, 3, 6, 7};
    std::vector<int> maximums = maxSlidingWindow(numbers, 3);
    std::cout << "Test 8 - Maximums: ";
    for (int value : maximums)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    std::cout << "Test 9 - Empty input: " << maxSlidingWindow({}, 3).size() << " results" << std::endl;
    std::cout << "Test 10 - Window size one: ";
    std::vector<int> singleWindow = maxSlidingWindow(numbers, 1);
    for (int value : singleWindow)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}