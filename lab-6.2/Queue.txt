#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

class Queue
{
private:
    static const int MAX = 1000;
    int arr[MAX];
    int front;
    int rear;
    int count;

public:
    Queue()
        : front(0), rear(-1), count(0) {}

    // 4.1 Enqueue
    bool enqueue(int x)
    {
        if (isFull())
            return false;

        rear = (rear + 1) % MAX;
        arr[rear] = x;
        ++count;
        return true;
    }

    // 4.2 Dequeue
    int dequeue()
    {
        if (isEmpty())
            return -1;

        int value = arr[front];
        front = (front + 1) % MAX;
        --count;
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
        return count == 0;
    }

    bool isFull() const
    {
        return count == MAX;
    }

    int size() const
    {
        return count;
    }
};

// 4.3 Reverse First K Elements
void reverse(Queue& q, int k)
{
    if (k <= 0 || k > q.size())
        return;

    int values[1000];

    for (int i = 0; i < k; ++i)
        values[i] = q.dequeue();

    for (int i = k - 1; i >= 0; --i)
        q.enqueue(values[i]);

    int remaining = q.size() - k;
    for (int i = 0; i < remaining; ++i)
        q.enqueue(q.dequeue());
}

// 4.4 Generate Binary Numbers 1 to N
void generateBinary(int n)
{
    Queue values;
    values.enqueue(1);

    for (int i = 0; i < n; ++i)
    {
        int value = values.dequeue();
        std::cout << value << ' ';

        values.enqueue(value * 10);
        values.enqueue(value * 10 + 1);
    }

    std::cout << '\n';
}

// 4.5 Implement Stack Using Two Queues
class StackFromQueue
{
private:
    Queue q1;
    Queue q2;

public:
    void push(int x)
    {
        q2.enqueue(x);
        while (!q1.isEmpty())
            q2.enqueue(q1.dequeue());

        while (!q2.isEmpty())
            q1.enqueue(q2.dequeue());
    }

    int pop()
    {
        return q1.dequeue();
    }
};

// 4.6 Level Order Traversal
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

void levelOrder(TreeNode* root)
{
    if (root == nullptr)
        return;

    TreeNode* nodes[1000];
    int frontIndex = 0;
    int rearIndex = 0;
    nodes[rearIndex++] = root;

    while (frontIndex < rearIndex)
    {
        TreeNode* current = nodes[frontIndex++];
        std::cout << current->val << ' ';

        if (current->left != nullptr)
            nodes[rearIndex++] = current->left;
        if (current->right != nullptr)
            nodes[rearIndex++] = current->right;
    }

    std::cout << '\n';
}

// 4.7 Maximum in Sliding Window
void slidingWindowMax(int arr[], int n, int k, int out[])
{
    if (k <= 0 || k > n)
        return;

    int indices[1000];
    int frontIndex = 0;
    int rearIndex = -1;

    for (int i = 0; i < n; ++i)
    {
        while (frontIndex <= rearIndex && indices[frontIndex] <= i - k)
            ++frontIndex;

        while (frontIndex <= rearIndex &&
               arr[indices[rearIndex]] <= arr[i])
        {
            --rearIndex;
        }

        indices[++rearIndex] = i;

        if (i >= k - 1)
            out[i - k + 1] = arr[indices[frontIndex]];
    }
}

// 4.8 Interleave First Half and Second Half
void interleave(Queue& q)
{
    int total = q.size();
    int firstHalfSize = total / 2;
    int firstHalf[1000];
    int secondHalf[1000];

    for (int i = 0; i < firstHalfSize; ++i)
        firstHalf[i] = q.dequeue();

    int secondHalfSize = total - firstHalfSize;
    for (int i = 0; i < secondHalfSize; ++i)
        secondHalf[i] = q.dequeue();

    for (int i = 0; i < firstHalfSize; ++i)
    {
        q.enqueue(firstHalf[i]);
        if (i < secondHalfSize)
            q.enqueue(secondHalf[i]);
    }

    if (secondHalfSize > firstHalfSize)
        q.enqueue(secondHalf[secondHalfSize - 1]);
}

#endif
