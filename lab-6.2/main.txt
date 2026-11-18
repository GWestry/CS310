#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "CircularQueue.h"
#include "LinkedQueue.h"

#include <iostream>

void clearDLL(DLLNode*& head)
{
    while (head != nullptr)
    {
        DLLNode* oldNode = head;
        head = head->next;
        delete oldNode;
    }
}

void clearCLL(CLLNode*& head)
{
    if (head == nullptr)
        return;

    CLLNode* current = head->next;
    while (current != head)
    {
        CLLNode* oldNode = current;
        current = current->next;
        delete oldNode;
    }

    delete head;
    head = nullptr;
}

// 1.1 Insert at Head
void test1_1()
{
    DLLNode* head = nullptr;
    insertHead(head, 10);
    insertHead(head, 5);
    std::cout << "1.1 insertHead: " << head->val << '\n';
    clearDLL(head);
}

// 1.2 Insert at Tail
void test1_2()
{
    DLLNode* head = nullptr;
    DLLNode* tail = nullptr;
    insertTail(head, tail, 10);
    insertTail(head, tail, 20);
    std::cout << "1.2 insertTail: " << tail->val << '\n';
    clearDLL(head);
}

// 1.3 Delete Head
void test1_3()
{
    DLLNode* head = nullptr;
    DLLNode* tail = nullptr;
    insertTail(head, tail, 10);
    insertTail(head, tail, 20);
    deleteHead(head, tail);
    std::cout << "1.3 deleteHead: " << head->val << '\n';
    clearDLL(head);
}

// 1.4 Delete Tail
void test1_4()
{
    DLLNode* head = nullptr;
    DLLNode* tail = nullptr;
    insertTail(head, tail, 10);
    insertTail(head, tail, 20);
    deleteTail(head, tail);
    std::cout << "1.4 deleteTail: " << tail->val << '\n';
    clearDLL(head);
}

// 1.5 Insert After a Given Node
void test1_5()
{
    DLLNode* head = nullptr;
    DLLNode* tail = nullptr;
    insertTail(head, tail, 10);
    insertTail(head, tail, 30);
    insertAfter(head, 20);
    std::cout << "1.5 insertAfter: " << head->next->val << '\n';
    clearDLL(head);
}

// 1.6 Delete a Given Node
void test1_6()
{
    DLLNode* head = nullptr;
    DLLNode* tail = nullptr;
    insertTail(head, tail, 10);
    insertTail(head, tail, 20);
    insertTail(head, tail, 30);
    deleteNode(head->next);
    std::cout << "1.6 deleteNode: " << head->next->val << '\n';
    clearDLL(head);
}

// 1.7 Reverse DLL
void test1_7()
{
    DLLNode* head = nullptr;
    DLLNode* tail = nullptr;
    insertTail(head, tail, 1);
    insertTail(head, tail, 2);
    reverse(head, tail);
    std::cout << "1.7 reverse: " << head->val << '\n';
    clearDLL(head);
}

// 1.8 Find Middle Node
void test1_8()
{
    DLLNode* head = nullptr;
    DLLNode* tail = nullptr;
    insertTail(head, tail, 1);
    insertTail(head, tail, 2);
    insertTail(head, tail, 3);
    std::cout << "1.8 middle: " << middle(head)->val << '\n';
    clearDLL(head);
}

// 1.9 Detect Cycle
void test1_9()
{
    DLLNode* head = nullptr;
    std::cout << "1.9 hasCycle: " << (hasCycle(head) ? "true" : "false")
              << '\n';
}

// 2.1 Insert at Head
void test2_1()
{
    CLLNode* head = nullptr;
    insertHead(head, 10);
    insertHead(head, 5);
    std::cout << "2.1 insertHead: " << head->val << '\n';
    clearCLL(head);
}

// 2.2 Insert at Tail
void test2_2()
{
    CLLNode* head = nullptr;
    insertTail(head, 10);
    insertTail(head, 20);
    std::cout << "2.2 insertTail: " << head->next->val << '\n';
    clearCLL(head);
}

// 2.3 Delete Head
void test2_3()
{
    CLLNode* head = nullptr;
    insertTail(head, 10);
    insertTail(head, 20);
    deleteHead(head);
    std::cout << "2.3 deleteHead: " << head->val << '\n';
    clearCLL(head);
}

// 2.4 Delete Last Node
void test2_4()
{
    CLLNode* head = nullptr;
    insertTail(head, 10);
    insertTail(head, 20);
    deleteTail(head);
    std::cout << "2.4 deleteTail: " << head->val << '\n';
    clearCLL(head);
}

// 2.5 Josephus Problem
void test2_5()
{
    CLLNode* head = nullptr;
    insertTail(head, 1);
    insertTail(head, 2);
    insertTail(head, 3);
    std::cout << "2.5 josephus: " << josephus(head, 2) << '\n';
}

// 2.6 Split into Two Halves
void test2_6()
{
    CLLNode* head = nullptr;
    insertTail(head, 1);
    insertTail(head, 2);
    insertTail(head, 3);
    insertTail(head, 4);
    CLLNode* first = nullptr;
    CLLNode* second = nullptr;
    split(head, first, second);
    std::cout << "2.6 split: " << first->val << ", " << second->val << '\n';
    clearCLL(first);
    clearCLL(second);
}

// 2.7 Detect Loop Length
void test2_7()
{
    CLLNode* head = nullptr;
    insertTail(head, 1);
    insertTail(head, 2);
    insertTail(head, 3);
    std::cout << "2.7 cycleLength: " << cycleLength(head) << '\n';
    clearCLL(head);
}

// 2.8 Sorted Insert
void test2_8()
{
    CLLNode* head = nullptr;
    sortedInsert(head, 20);
    sortedInsert(head, 10);
    sortedInsert(head, 30);
    std::cout << "2.8 sortedInsert: " << head->val << '\n';
    clearCLL(head);
}

// 3.1 Implement push and 3.2 Implement pop
void test3_1_to_3_2()
{
    Stack stack;
    stack.push(10);
    stack.push(20);
    std::cout << "3.1 push / 3.2 pop: " << stack.pop() << '\n';
}

// 3.3 Next Greater Element
void test3_3()
{
    int input[] = {4, 5, 2, 10, 8};
    int output[5];
    nextGreater(input, 5, output);
    std::cout << "3.3 nextGreater: " << output[0] << '\n';
}

// 3.4 Check Balanced Parentheses
void test3_4()
{
    std::cout << "3.4 balanced: "
              << (balanced("({[]})") ? "true" : "false") << '\n';
}

// 3.5 Infix to Postfix and 3.6 Evaluate Postfix
void test3_5_to_3_6()
{
    char postfix[100];
    infixToPostfix("(2+3)*4", postfix);
    std::cout << "3.5 postfix: " << postfix
              << "\n3.6 evaluate: " << evalPostfix(postfix) << '\n';
}

// 3.7 Sort Stack
void test3_7()
{
    Stack stack;
    stack.push(3);
    stack.push(1);
    stack.push(2);
    sortStack(stack);
    std::cout << "3.7 sortStack: " << stack.peek() << '\n';
}

// 3.8 Stock Span Problem
void test3_8()
{
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int spans[7];
    stockSpan(prices, 7, spans);
    std::cout << "3.8 stockSpan: " << spans[0] << '\n';
}

// 3.9 Min Stack
void test3_9()
{
    MinStack stack;
    stack.push(3);
    stack.push(1);
    std::cout << "3.9 getMin: " << stack.getMin() << '\n';
}

// 4.1 Enqueue and 4.2 Dequeue
void test4_1_to_4_2()
{
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    std::cout << "4.1 enqueue / 4.2 dequeue: "
              << queue.dequeue() << '\n';
}

// 4.3 Reverse First K Elements
void test4_3()
{
    Queue queue;
    for (int value = 1; value <= 5; ++value)
        queue.enqueue(value);
    reverse(queue, 3);
    std::cout << "4.3 reverse: " << queue.getFront() << '\n';
}

// 4.4 Generate Binary Numbers
void test4_4()
{
    std::cout << "4.4 generateBinary: ";
    generateBinary(3);
}

// 4.5 Implement Stack Using Two Queues
void test4_5()
{
    StackFromQueue stack;
    stack.push(1);
    stack.push(2);
    std::cout << "4.5 stackFromQueue: " << stack.pop() << '\n';
}

// 4.6 Level Order Traversal
void test4_6()
{
    TreeNode leaf{2, nullptr, nullptr};
    TreeNode root{1, &leaf, nullptr};
    std::cout << "4.6 levelOrder: ";
    levelOrder(&root);
}

// 4.7 Maximum in Sliding Window
void test4_7()
{
    int input[] = {1, 3, 2, 5, 4};
    int output[3];
    slidingWindowMax(input, 5, 3, output);
    std::cout << "4.7 slidingWindowMax: " << output[0] << '\n';
}

// 4.8 Interleave First Half and Second Half
void test4_8()
{
    Queue queue;
    for (int value = 1; value <= 6; ++value)
        queue.enqueue(value);
    interleave(queue);
    std::cout << "4.8 interleave: " << queue.getFront() << '\n';
}

// 5.1 Enqueue and 5.2 Dequeue
void test5_1_to_5_2()
{
    CircularQueue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    std::cout << "5.1 enqueue / 5.2 dequeue: "
              << queue.dequeue() << '\n';
}

// 5.3 First Negative in Every Window
void test5_3()
{
    int values[] = {12, -1, -7, 8, -15, 30};
    std::cout << "5.3 firstNegative: ";
    firstNegative(values, 6, 3);
}

// 5.4 Circular Tour
void test5_4()
{
    int petrol[] = {4, 6, 7, 4};
    int distance[] = {6, 5, 3, 5};
    std::cout << "5.4 circularTour: "
              << circularTour(petrol, distance, 4) << '\n';
}

// 5.5 Fixed-Size LRU Cache
void test5_5()
{
    LRU cache(2);
    cache.put(1, 10);
    cache.put(2, 20);
    std::cout << "5.5 LRU get: " << cache.get(1) << '\n';
}

// 5.6 Rotate Queue
void test5_6()
{
    CircularQueue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    rotate(queue, 1);
    std::cout << "5.6 rotate: " << queue.getFront() << '\n';
}

// 5.7 Check Palindrome
void test5_7()
{
    std::cout << "5.7 palindrome: "
              << (isPalindrome("level") ? "true" : "false") << '\n';
}

// 5.8 Dequeue All Elements in Reverse Order
void test5_8()
{
    CircularQueue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    std::cout << "5.8 printReverse: ";
    printReverse(queue);
}

// 6.1 Enqueue and 6.2 Dequeue
void test6_1_to_6_2()
{
    LinkedQueue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    std::cout << "6.1 enqueue / 6.2 dequeue: "
              << queue.dequeue() << '\n';
}

// 6.3 Reverse Linked Queue
void test6_3()
{
    LinkedQueue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    reverse(queue);
    std::cout << "6.3 reverse: " << queue.getFront() << '\n';
}

// 6.4 Merge Two Sorted Queues
void test6_4()
{
    LinkedQueue first;
    LinkedQueue second;
    first.enqueue(1);
    second.enqueue(2);
    LinkedQueue result = merge(first, second);
    std::cout << "6.4 merge: " << result.getFront() << '\n';
}

// 6.5 Remove Duplicates
void test6_5()
{
    LinkedQueue queue;
    queue.enqueue(1);
    queue.enqueue(1);
    removeDuplicates(queue);
    std::cout << "6.5 removeDuplicates: " << queue.size() << '\n';
}

// 6.6 Implement Stack Using One Linked Queue
void test6_6()
{
    StackFromLinkedQueue stack;
    stack.push(1);
    stack.push(2);
    std::cout << "6.6 stackFromLinkedQueue: " << stack.pop() << '\n';
}

// 6.7 Find Middle Element
void test6_7()
{
    LinkedQueue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    std::cout << "6.7 middle: " << middle(queue) << '\n';
}

// 6.8 Move Front to Rear K Times
void test6_8()
{
    LinkedQueue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    rotateK(queue, 1);
    std::cout << "6.8 rotateK: " << queue.getFront() << '\n';
}

int main()
{
    std::cout << "Doubly Linked List\n";
    test1_1();
    test1_2();
    test1_3();
    test1_4();
    test1_5();
    test1_6();
    test1_7();
    test1_8();
    test1_9();

    std::cout << "\nCircular Linked List\n";
    test2_1();
    test2_2();
    test2_3();
    test2_4();
    test2_5();
    test2_6();
    test2_7();
    test2_8();

    std::cout << "\nStack\n";
    test3_1_to_3_2();
    test3_3();
    test3_4();
    test3_5_to_3_6();
    test3_7();
    test3_8();
    test3_9();

    std::cout << "\nQueue\n";
    test4_1_to_4_2();
    test4_3();
    test4_4();
    test4_5();
    test4_6();
    test4_7();
    test4_8();

    std::cout << "\nCircular Queue\n";
    test5_1_to_5_2();
    test5_3();
    test5_4();
    test5_5();
    test5_6();
    test5_7();
    test5_8();

    std::cout << "\nLinked Queue\n";
    test6_1_to_6_2();
    test6_3();
    test6_4();
    test6_5();
    test6_6();
    test6_7();
    test6_8();

    return 0;
}
