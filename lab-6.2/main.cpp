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

void printDLL(DLLNode* head)
{
    if (head == nullptr)
    {
        std::cout << "NULL";
        return;
    }

    DLLNode* current = head;
    while (current != nullptr)
    {
        std::cout << current->val;
        if (current->next != nullptr)
            std::cout << "<->";
        current = current->next;
    }
}

void printCLL(CLLNode* head)
{
    if (head == nullptr)
    {
        std::cout << "NULL";
        return;
    }

    CLLNode* current = head;
    do
    {
        std::cout << current->val;
        current = current->next;
        if (current != head)
            std::cout << "->";
    } while (current != head);
    std::cout << "->HEAD";
}

void printArray(const int values[], int size)
{
    std::cout << "[";
    for (int i = 0; i < size; ++i)
    {
        if (i > 0)
            std::cout << ", ";
        std::cout << values[i];
    }
    std::cout << "]";
}

void printTraversal(const char* text)
{
    std::cout << "Traversal: " << text << '\n';
}

// 1.1 Insert at Head
/*
Problem 1.1
BEFORE: head->10<->20, tail->20.
ACTION: insertHead(5).
AFTER: head->5<->10<->20, tail->20.
COMPLEXITY: O(1) time/O(1) space.
EDGE: empty list makes the new node both head and tail conceptually.
*/
void test1_1()
{
    DLLNode* head = nullptr;
    DLLNode* tail = nullptr;
    insertTail(head, tail, 10);
    insertTail(head, tail, 20);
    insertHead(head, 5);
    std::cout << "1.1 insertHead\nInput: 10<->20\nOutput: ";
    printDLL(head);
    std::cout << '\n';
    printTraversal("10<->20 -> insert 5 at head -> 5<->10<->20");
    clearDLL(head);
}

// 1.2 Insert at Tail
/*
Problem 1.2
BEFORE: head->10<->20, tail->20.
ACTION: insertTail(30).
AFTER: head->10<->20<->30<-tail.
COMPLEXITY: O(1)/O(1).
EDGE: empty list sets head and tail to the new node.
*/
void test1_2()
{
    DLLNode* head = nullptr;
    DLLNode* tail = nullptr;
    insertTail(head, tail, 10);
    insertTail(head, tail, 20);
    insertTail(head, tail, 30);
    std::cout << "1.2 insertTail\nInput: 10<->20\nOutput: ";
    printDLL(head);
    std::cout << '\n';
    printTraversal("10 -> 20 -> 30");
    clearDLL(head);
}

// 1.3 Delete Head
/*
Problem 1.3
BEFORE: head->10<->20, tail->20.
ACTION: deleteHead().
AFTER: head->20<-tail, deleted node 10.
COMPLEXITY: O(1)/O(1).
EDGE: empty list does nothing; one node resets both pointers.
*/
void test1_3()
{
    DLLNode* head = nullptr;
    DLLNode* tail = nullptr;
    insertTail(head, tail, 10);
    insertTail(head, tail, 20);
    deleteHead(head, tail);
    std::cout << "1.3 deleteHead\nInput: 10<->20\nOutput: ";
    printDLL(head);
    std::cout << '\n';
    printTraversal("head 10 -> delete 10 -> head 20");
    clearDLL(head);
}

// 1.4 Delete Tail
/*
Problem 1.4
BEFORE: head->10<->20, tail->20.
ACTION: deleteTail().
AFTER: head->10<-tail, deleted node 20.
COMPLEXITY: O(1)/O(1).
EDGE: empty list does nothing; one node resets both pointers.
*/
void test1_4()
{
    DLLNode* head = nullptr;
    DLLNode* tail = nullptr;
    insertTail(head, tail, 10);
    insertTail(head, tail, 20);
    deleteTail(head, tail);
    std::cout << "1.4 deleteTail\nInput: 10<->20\nOutput: ";
    printDLL(head);
    std::cout << '\n';
    printTraversal("10 -> 20 -> delete 20");
    clearDLL(head);
}

// 1.5 Insert After a Given Node
/*
Problem 1.5
BEFORE: 10<->30, given node=10.
ACTION: insertAfter(10,20).
AFTER: 10<->20<->30.
COMPLEXITY: O(1)/O(1).
EDGE: null given node is ignored; inserting after the tail leaves next=NULL.
*/
void test1_5()
{
    DLLNode* head = nullptr;
    DLLNode* tail = nullptr;
    insertTail(head, tail, 10);
    insertTail(head, tail, 30);
    insertAfter(head, 20);
    std::cout << "1.5 insertAfter\nInput: 10<->30, insert 20 after 10\nOutput: ";
    printDLL(head);
    std::cout << '\n';
    printTraversal("10 -> 30; insert 20 after 10 -> 10<->20<->30");
    clearDLL(head);
}

// 1.6 Delete a Given Node
/*
Problem 1.6
BEFORE: 10<->20<->30, given node=20.
ACTION: deleteNode(20).
AFTER: 10<->30; 20 is deleted.
COMPLEXITY: O(1)/O(1).
EDGE: null, head, and tail are rejected because they lack two neighbors.
*/
void test1_6()
{
    DLLNode* head = nullptr;
    DLLNode* tail = nullptr;
    insertTail(head, tail, 10);
    insertTail(head, tail, 20);
    insertTail(head, tail, 30);
    deleteNode(head->next);
    std::cout << "1.6 deleteNode\nInput: 10<->20<->30, delete 20\nOutput: ";
    printDLL(head);
    std::cout << '\n';
    printTraversal("10 -> 20 -> 30; delete 20 -> 10<->30");
    clearDLL(head);
}

// 1.7 Reverse DLL
/*
Problem 1.7
BEFORE: head->1<->2<->3<-tail.
ACTION: swap next and prev at every node.
AFTER: head->3<->2<->1<-tail.
COMPLEXITY: O(n)/O(1).
EDGE: empty list remains empty; head and tail are exchanged.
*/
void test1_7()
{
    DLLNode* head = nullptr;
    DLLNode* tail = nullptr;
    insertTail(head, tail, 1);
    insertTail(head, tail, 2);
    insertTail(head, tail, 3);
    reverse(head, tail);
    std::cout << "1.7 reverse\nInput: 1<->2<->3\nOutput: ";
    printDLL(head);
    std::cout << '\n';
    printTraversal("1 -> 2 -> 3 -> 3 -> 2 -> 1");
    clearDLL(head);
}

// 1.8 Find Middle Node
/*
Problem 1.8
BEFORE: 1<->2<->3<->4.
ACTION: slow/fast move one/two nodes.
AFTER: slow points to middle node 3.
COMPLEXITY: O(n)/O(1).
EDGE: empty returns NULL; even-length lists return the later middle.
*/
void test1_8()
{
    DLLNode* head = nullptr;
    DLLNode* tail = nullptr;
    insertTail(head, tail, 1);
    insertTail(head, tail, 2);
    insertTail(head, tail, 3);
    insertTail(head, tail, 4);
    std::cout << "1.8 middle\nInput: 1<->2<->3<->4\nTraversal: slow 1/fast 1 -> slow 2/fast 3 -> slow 3/fast end\nOutput: "
              << middle(head)->val << '\n';
    clearDLL(head);
}

// 1.9 Detect Cycle
/*
Problem 1.9
BEFORE: 1<->2<->3->NULL.
ACTION: Floyd slow/fast traversal.
AFTER: pointers meet only if a cycle exists; result=false here.
COMPLEXITY: O(n)/O(1).
EDGE: empty and one-node acyclic lists return false.
*/
void test1_9()
{
    DLLNode* head = nullptr;
    std::cout << "1.9 hasCycle\nInput: NULL\nOutput: ";
    if (hasCycle(head))
        std::cout << "true";
    else
        std::cout << "false";
    std::cout << '\n';
    printTraversal("slow 1 -> fast 1 -> no meeting -> false");
}

// 2.1 Insert at Head
/*
Problem 2.1
BEFORE: head->10->20->HEAD.
ACTION: find tail, link new 5 before head.
AFTER: head->5->10->20->HEAD.
COMPLEXITY: O(n)/O(1).
EDGE: empty creates 5->HEAD.
*/
void test2_1()
{
    CLLNode* head = nullptr;
    insertHead(head, 10);
    insertHead(head, 5);
    std::cout << "2.1 insertHead\nInput: 10->20->HEAD\nOutput: ";
    printCLL(head);
    std::cout << '\n';
    printTraversal("find tail -> link 5 before head -> 5->10->20->HEAD");
    clearCLL(head);
}

// 2.2 Insert at Tail
/*
Problem 2.2
BEFORE: head->10->20->HEAD.
ACTION: find tail, append 30 before HEAD.
AFTER: head->10->20->30->HEAD.
COMPLEXITY: O(n)/O(1).
EDGE: empty creates a self-loop.
*/
void test2_2()
{
    CLLNode* head = nullptr;
    insertTail(head, 10);
    insertTail(head, 20);
    insertTail(head, 30);
    std::cout << "2.2 insertTail\nInput: 10->20->HEAD\nOutput: ";
    printCLL(head);
    std::cout << '\n';
    printTraversal("10 -> 20 -> 30 -> HEAD");
    clearCLL(head);
}

// 2.3 Delete Head
/*
Problem 2.3
BEFORE: head->10->20->HEAD.
ACTION: bypass and delete old head.
AFTER: head->20->HEAD.
COMPLEXITY: O(n)/O(1).
EDGE: empty does nothing; one node becomes NULL.
*/
void test2_3()
{
    CLLNode* head = nullptr;
    insertTail(head, 10);
    insertTail(head, 20);
    deleteHead(head);
    std::cout << "2.3 deleteHead\nInput: 10->20->HEAD\nOutput: ";
    printCLL(head);
    std::cout << '\n';
    printTraversal("head 10 -> bypass 10 -> head 20 -> HEAD");
    clearCLL(head);
}

// 2.4 Delete Last Node
/*
Problem 2.4
BEFORE: head->10->20->HEAD.
ACTION: find penultimate and delete tail.
AFTER: head->10->HEAD.
COMPLEXITY: O(n)/O(1).
EDGE: empty does nothing; one node becomes NULL.
*/
void test2_4()
{
    CLLNode* head = nullptr;
    insertTail(head, 10);
    insertTail(head, 20);
    deleteTail(head);
    std::cout << "2.4 deleteTail\nInput: 10->20->HEAD\nOutput: ";
    printCLL(head);
    std::cout << '\n';
    printTraversal("10 -> 20 -> delete 20 -> 10 -> HEAD");
    clearCLL(head);
}

// 2.5 Josephus Problem
/*
Problem 2.5
BEFORE: 1->2->3->HEAD, k=2.
ACTION: remove every second current node.
AFTER: survivor=3 (remaining node is deleted before return).
COMPLEXITY: O(nk)/O(1).
EDGE: empty or k<=0 returns -1; one node survives.
*/
void test2_5()
{
    CLLNode* head = nullptr;
    insertTail(head, 1);
    insertTail(head, 2);
    insertTail(head, 3);
    std::cout << "2.5 josephus\nInput: 1->2->3->HEAD, k=2\nOutput: survivor="
              << josephus(head, 2) << '\n';
    printTraversal("remove 2 -> remaining 1->3 -> remove 1 -> survivor 3");
}

// 2.6 Split into Two Halves
/*
Problem 2.6
BEFORE: 1->2->3->4->HEAD.
ACTION: slow/fast find split point.
AFTER: first=1->2->HEAD; second=3->4->HEAD.
COMPLEXITY: O(n)/O(1).
EDGE: empty returns two NULL lists; odd lists put the extra node in first.
*/
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
    std::cout << "2.6 split\nInput: 1->2->3->4->HEAD\nOutput: ";
    printCLL(first);
    std::cout << "; ";
    printCLL(second);
    std::cout << '\n';
    printTraversal("1 -> 2 -> midpoint -> split -> 1->2->HEAD and 3->4->HEAD");
    clearCLL(first);
    clearCLL(second);
}

// 2.7 Detect Loop Length
/*
Problem 2.7
BEFORE: 1->2->3->HEAD.
ACTION: tortoise/hare meet, then count the ring.
AFTER: cycle length=3.
COMPLEXITY: O(n)/O(1).
EDGE: empty returns 0; circular input is required by this function.
*/
void test2_7()
{
    CLLNode* head = nullptr;
    insertTail(head, 1);
    insertTail(head, 2);
    insertTail(head, 3);
    std::cout << "2.7 cycleLength\nInput: 1->2->3->HEAD\nOutput: "
              << cycleLength(head) << '\n';
    printTraversal("1 -> 2 -> 3 -> HEAD -> 1; cycle length=3");
    clearCLL(head);
}

// 2.8 Sorted Insert
/*
Problem 2.8
BEFORE: 1->3->HEAD, insert 2.
ACTION: scan to insertion point.
AFTER: 1->2->3->HEAD.
COMPLEXITY: O(n)/O(1).
EDGE: empty creates a self-loop; values before head become the new head.
*/
void test2_8()
{
    CLLNode* head = nullptr;
    sortedInsert(head, 20);
    sortedInsert(head, 10);
    sortedInsert(head, 30);
    std::cout << "2.8 sortedInsert\nInput: 20, 10, 30\nOutput: ";
    printCLL(head);
    std::cout << '\n';
    printTraversal("10 -> 20 -> 30 -> HEAD");
    clearCLL(head);
}

// 3.1 Implement push and 3.2 Implement pop
/*
Problem 3.1
BEFORE: top=-1, [_,_,_,_].
ACTION: push(10), push(20).
AFTER: top=1, [10,20,_,_].
COMPLEXITY: O(1)/O(1).
EDGE: full array rejects push; capacity boundary is top=MAX-1.
*/
/*
Problem 3.2
BEFORE: top=1, [10,20,_,_].
ACTION: pop().
AFTER: returns 20, top=0, [10,_,_,_].
COMPLEXITY: O(1)/O(1).
EDGE: empty pop returns -1; top=-1 is the empty boundary.
*/
void test3_1_to_3_2()
{
    Stack stack;
    stack.push(10);
    stack.push(20);
    std::cout << "3.1 push / 3.2 pop\nInput: push 10, push 20\nOutput: "
              << stack.pop() << '\n';
    printTraversal("push 10 -> push 20 -> pop 20");
}

// 3.3 Next Greater Element
/*
Problem 3.3
BEFORE: input [4,5,2,10,8], scan right to left.
AFTER: output [5,10,10,-1,-1].
COMPLEXITY: O(n)/O(n).
EDGE: last element has no greater value; stack removes smaller candidates.
*/
void test3_3()
{
    int input[] = {4, 5, 2, 10, 8};
    int output[5];
    nextGreater(input, 5, output);
    std::cout << "3.3 nextGreater\nInput: ";
    printArray(input, 5);
    std::cout << "\nOutput: ";
    printArray(output, 5);
    std::cout << '\n';
    printTraversal("scan 8 -> 10 -> 2 -> 5 -> 4 -> [5,10,10,-1,-1]");
}

// 3.4 Check Balanced Parentheses
/*
Problem 3.4
BEFORE: string ({[]}), stack empty.
ACTION: push opening symbols; pop matching symbols on close.
AFTER: stack empty, balanced=true.
COMPLEXITY: O(n)/O(n).
EDGE: early close/mismatch is false; leftover opening symbols are false.
*/
void test3_4()
{
    std::cout << "3.4 balanced\nInput: ({[]})\nOutput: ";
    if (balanced("({[]})"))
        std::cout << "true";
    else
        std::cout << "false";
    std::cout << '\n';
    printTraversal("( -> { -> [ -> ] -> } -> ) -> empty stack -> true");
}

// 3.5 Infix to Postfix and 3.6 Evaluate Postfix
/*
Problem 3.5
BEFORE: infix (2+3)*4, operator stack empty.
ACTION: output operands and pop higher/equal precedence operators.
AFTER: postfix 23+4*.
COMPLEXITY: O(n)/O(n).
EDGE: spaces are skipped; parentheses are removed from output.
*/
/*
Problem 3.6
BEFORE: postfix 23+4*, value stack empty.
ACTION: push operands; pop right/left for each operator.
AFTER: result=20.
COMPLEXITY: O(n)/O(n).
EDGE: valid postfix is required; division uses left/right order.
*/
void test3_5_to_3_6()
{
    char postfix[100];
    infixToPostfix("(2+3)*4", postfix);
    std::cout << "3.5 infixToPostfix\nInput: (2+3)*4\nOutput: " << postfix
              << "\n3.6 evalPostfix\nInput: " << postfix
              << "\nOutput: " << evalPostfix(postfix) << '\n';
    printTraversal("( -> 2 -> + -> 3 -> ) -> * -> 4 -> 23+4* -> 20");
}

// 3.7 Sort Stack
/*
Problem 3.7
BEFORE: top values 3,1,2.
ACTION: move each value into sorted stack.
AFTER: top=1,2,3.
COMPLEXITY: O(n^2)/O(n).
EDGE: empty and one-element stacks are already sorted.
*/
void test3_7()
{
    Stack stack;
    stack.push(3);
    stack.push(1);
    stack.push(2);
    sortStack(stack);
    std::cout << "3.7 sortStack\nInput: [3,1,2]\nOutput top: "
              << stack.peek() << '\n';
    printTraversal("pop 3 -> pop 1 -> place 1 -> pop 2 -> top=1");
}

// 3.8 Stock Span Problem
/*
Problem 3.8
BEFORE: prices [100,80,60,70,60,75,85], index stack empty.
ACTION: remove previous lower/equal prices and compute spans.
AFTER: spans [1,1,1,2,1,4,6].
COMPLEXITY: O(n)/O(n).
EDGE: first span is 1; decreasing data keeps all indices.
*/
void test3_8()
{
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int spans[7];
    stockSpan(prices, 7, spans);
    std::cout << "3.8 stockSpan\nInput: ";
    printArray(prices, 7);
    std::cout << "\nOutput: ";
    printArray(spans, 7);
    std::cout << '\n';
    printTraversal("100 -> 80 -> 60 -> 70 -> 60 -> 75 -> 85 -> spans [1,1,1,2,1,4,6]");
}

// 3.9 Min Stack
/*
Problem 3.9
BEFORE: values top=3,1 and minimums top=3,1.
ACTION: push each value with the smaller running minimum.
AFTER: getMin()=1.
COMPLEXITY: O(1) per operation/O(n) storage.
EDGE: full push fails; empty pop/getMin return -1.
*/
void test3_9()
{
    MinStack stack;
    stack.push(3);
    stack.push(1);
    std::cout << "3.9 getMin\nInput: push 3, push 1\nOutput: "
              << stack.getMin() << '\n';
    printTraversal("push 3, minimum 3 -> push 1, minimum 1");
}

// 4.1 Enqueue and 4.2 Dequeue
/*
Problem 4.1
BEFORE: FRONT=0, REAR=-1, COUNT=0.
ACTION: enqueue 10,20.
AFTER: FRONT=0, REAR=1, [10,20,...], COUNT=2.
COMPLEXITY: O(1)/O(1).
EDGE: full queue rejects enqueue; rear wraps modulo MAX.
*/
/*
Problem 4.2
BEFORE: FRONT=0, REAR=1, COUNT=2.
ACTION: dequeue().
AFTER: returns 10, FRONT=1, COUNT=1.
COMPLEXITY: O(1)/O(1).
EDGE: empty dequeue returns -1; front wraps modulo MAX.
*/
void test4_1_to_4_2()
{
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    std::cout << "4.1 enqueue / 4.2 dequeue\nInput: enqueue 10, enqueue 20\nOutput: "
              << queue.dequeue() << '\n';
    printTraversal("empty -> enqueue 10 -> enqueue 20 -> dequeue 10");
}

// 4.3 Reverse First K Elements
/*
Problem 4.3
BEFORE: FRONT=1,2,3,4,5 REAR, k=3.
ACTION: reverse first three then rotate.
AFTER: FRONT=3,2,1,4,5 REAR.
COMPLEXITY: O(k+n)/O(k).
EDGE: k<=0 or k>size leaves queue unchanged.
*/
void test4_3()
{
    Queue queue;
    for (int value = 1; value <= 5; ++value)
        queue.enqueue(value);
    reverse(queue, 3);
    std::cout << "4.3 reverseFirstK\nInput: 1,2,3,4,5; k=3\nOutput: ";
    while (!queue.isEmpty())
    {
        std::cout << queue.dequeue();
        if (!queue.isEmpty())
            std::cout << ',';
    }
    std::cout << '\n';
    printTraversal("1,2,3,4,5 -> reverse first 3 -> 3,2,1,4,5");
}

// 4.4 Generate Binary Numbers
/*
Problem 4.4
BEFORE: queue starts [1].
ACTION: dequeue each value and enqueue 10x and 10x+1.
AFTER: output 1 10 11 ... through requested N values.
COMPLEXITY: O(n)/O(n).
EDGE: n<=0 should produce no requested values.
*/
void test4_4()
{
    std::cout << "4.4 generateBinary\nInput: n=3\nOutput: ";
    generateBinary(3);
    printTraversal("dequeue 1 -> enqueue 10/11 -> dequeue 10 -> dequeue 11");
}

// 4.5 Implement Stack Using Two Queues
/*
Problem 4.5
BEFORE: q1=1,2 and q2 empty.
ACTION: put new value in q2, move q1, swap roles.
AFTER: stack top is newest value.
COMPLEXITY: O(n) push/O(n) storage.
EDGE: pop on empty returns -1 through the queue.
*/
void test4_5()
{
    StackFromQueue stack;
    stack.push(1);
    stack.push(2);
    std::cout << "4.5 stackFromQueue\nInput: push 1, push 2\nOutput pop: "
              << stack.pop() << '\n';
    printTraversal("push 1 -> [1] -> push 2 -> [2,1] -> pop 2");
}

// 4.6 Level Order Traversal
/*
Problem 4.6
BEFORE: tree root 1 with left child 2, queue [1].
ACTION: dequeue node, enqueue left then right children.
AFTER: traversal 1 2.
COMPLEXITY: O(n)/O(n).
EDGE: NULL root returns immediately; children are optional.
*/
void test4_6()
{
    TreeNode leaf{2, nullptr, nullptr};
    TreeNode root{1, &leaf, nullptr};
    std::cout << "4.6 levelOrder\nInput: root 1, left 2\nOutput: ";
    levelOrder(&root);
    printTraversal("visit 1 -> enqueue left 2 -> visit 2");
}

// 4.7 Maximum in Sliding Window
/*
Problem 4.7
BEFORE: array [1,3,2,5,4], window k=3, index deque empty.
ACTION: remove expired/smaller indices; front index is each maximum.
AFTER: output [3,5,5].
COMPLEXITY: O(n)/O(k).
EDGE: invalid k returns; each output begins at index k-1.
*/
void test4_7()
{
    int input[] = {1, 3, 2, 5, 4};
    int output[3];
    slidingWindowMax(input, 5, 3, output);
    std::cout << "4.7 slidingWindowMax\nInput: ";
    printArray(input, 5);
    std::cout << ", k=3\nOutput: ";
    printArray(output, 3);
    std::cout << '\n';
    printTraversal("window [1,3,2] max 3 -> [3,2,5] max 5 -> [2,5,4] max 5");
}

// 4.8 Interleave First Half and Second Half
/*
Problem 4.8
BEFORE: FRONT=1,2,3,4,5,6 REAR.
ACTION: split halves and alternate values.
AFTER: FRONT=1,4,2,5,3,6 REAR.
COMPLEXITY: O(n)/O(n).
EDGE: odd size leaves the final second-half value at the rear.
*/
void test4_8()
{
    Queue queue;
    for (int value = 1; value <= 6; ++value)
        queue.enqueue(value);
    interleave(queue);
    std::cout << "4.8 interleave\nInput: 1,2,3,4,5,6\nOutput: ";
    while (!queue.isEmpty())
    {
        std::cout << queue.dequeue();
        if (!queue.isEmpty())
            std::cout << ',';
    }
    std::cout << '\n';
    printTraversal("first 1,2,3 -> second 4,5,6 -> 1,4,2,5,3,6");
}

// 5.1 Enqueue and 5.2 Dequeue
/*
Problem 5.1
BEFORE: FRONT=0, REAR=-1, SIZE=0.
ACTION: enqueue 10,20.
AFTER: FRONT=0, REAR=1, SIZE=2.
COMPLEXITY: O(1)/O(1).
EDGE: full queue rejects; rear advances modulo MAX.
*/
/*
Problem 5.2
BEFORE: FRONT=0, REAR=1, SIZE=2.
ACTION: dequeue().
AFTER: returns 10, FRONT=1, SIZE=1.
COMPLEXITY: O(1)/O(1).
EDGE: empty dequeue returns -1; front advances modulo MAX.
*/
void test5_1_to_5_2()
{
    CircularQueue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    std::cout << "5.1 enqueue / 5.2 dequeue\nInput: enqueue 10, enqueue 20\nOutput: "
              << queue.dequeue() << '\n';
    printTraversal("empty -> enqueue 10 -> enqueue 20 -> dequeue 10");
}

// 5.3 First Negative in Every Window
/*
Problem 5.3
BEFORE: windows [12,-1,-7],[-1,-7,8],[-7,8,-15],... .
ACTION: scan each window until its first negative.
AFTER: output -1 -1 -7 -15.
COMPLEXITY: O(nk)/O(1).
EDGE: invalid k returns; a window with no negative prints 0.
*/
void test5_3()
{
    int values[] = {12, -1, -7, 8, -15, 30};
    std::cout << "5.3 firstNegative\nInput: ";
    printArray(values, 6);
    std::cout << ", k=3\nOutput: ";
    firstNegative(values, 6, 3);
    printTraversal("window [12,-1,-7] -> -1; [-1,-7,8] -> -1; [-7,8,-15] -> -7; [8,-15,30] -> -15");
}

// 5.4 Circular Tour
/*
Problem 5.4
BEFORE: petrol [4,6,7,4], distance [6,5,3,5].
ACTION: reset candidate after a negative running balance.
AFTER: start station=1.
COMPLEXITY: O(n)/O(1).
EDGE: impossible tour returns -1; n<=0 returns -1.
*/
void test5_4()
{
    int petrol[] = {4, 6, 7, 4};
    int distance[] = {6, 5, 3, 5};
    std::cout << "5.4 circularTour\nInput: petrol [4,6,7,4], distance [6,5,3,5]\nOutput: "
              << circularTour(petrol, distance, 4) << '\n';
    printTraversal("station 0 -2 -> 1 1 -> 2 5 -> 3 4 -> start 1");
}

// 5.5 Fixed-Size LRU Cache
/*
Problem 5.5
BEFORE: LRU capacity=2, front order [1:10,2:20].
ACTION: get(1), move accessed pair to front.
AFTER: order [1:10,2:20], result=10.
COMPLEXITY: O(capacity)/O(capacity).
EDGE: miss returns -1; capacity is clamped to [1,MAX].
*/
void test5_5()
{
    LRU cache(2);
    cache.put(1, 10);
    cache.put(2, 20);
    std::cout << "5.5 LRU\nInput: put(1,10), put(2,20), get(1)\nOutput: "
              << cache.get(1) << '\n';
    printTraversal("put 1 -> put 2 -> get 1 moves 1 to front");
}

// 5.6 Rotate Queue
/*
Problem 5.6
BEFORE: queue FRONT=1,2,3, k=1.
ACTION: dequeue then enqueue once.
AFTER: FRONT=2,3,1.
COMPLEXITY: O(k)/O(1).
EDGE: empty queue unchanged; negative k rotates in the opposite direction.
*/
void test5_6()
{
    CircularQueue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    rotate(queue, 1);
    std::cout << "5.6 rotate\nInput: 1,2,3; k=1\nOutput: ";
    while (!queue.isEmpty())
    {
        std::cout << queue.dequeue();
        if (!queue.isEmpty())
            std::cout << ',';
    }
    std::cout << '\n';
    printTraversal("1,2,3 -> dequeue 1/enqueue 1 -> 2,3,1");
}

// 5.7 Check Palindrome
/*
Problem 5.7
BEFORE: string "level", queue contains its characters.
ACTION: copy characters into an array and compare mirrored indices.
AFTER: palindrome=true.
COMPLEXITY: O(n)/O(n).
EDGE: empty string is true; input must fit the fixed queue/array.
*/
void test5_7()
{
    std::cout << "5.7 palindrome\nInput: level\nOutput: ";
    if (isPalindrome("level"))
        std::cout << "true";
    else
        std::cout << "false";
    std::cout << '\n';
    printTraversal("l=0/r=4 -> l=1/r=3 -> l=2/r=2 -> palindrome");
}

// 5.8 Dequeue All Elements in Reverse Order
/*
Problem 5.8
BEFORE: queue FRONT=1,2,3 REAR.
ACTION: dequeue all, print array backwards.
AFTER: output 3 2 1; queue empty.
COMPLEXITY: O(n)/O(n).
EDGE: empty queue prints a blank line.
*/
void test5_8()
{
    CircularQueue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    std::cout << "5.8 printReverse\nInput: 1,2,3\nOutput: ";
    printReverse(queue);
    printTraversal("dequeue 1 -> 2 -> 3 -> print 3 -> 2 -> 1");
}

// 6.1 Enqueue and 6.2 Dequeue
/*
Problem 6.1
BEFORE: front->10->20->NULL, rear->20.
ACTION: enqueue 30.
AFTER: front->10->20->30->NULL, rear->30.
COMPLEXITY: O(1)/O(1).
EDGE: empty enqueue sets both front and rear.
*/
/*
Problem 6.2
BEFORE: front->10->20->NULL, rear->20.
ACTION: dequeue().
AFTER: returns 10, front/rear point to 20.
COMPLEXITY: O(1)/O(1).
EDGE: removing the last node resets both pointers; empty returns -1.
*/
void test6_1_to_6_2()
{
    LinkedQueue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    std::cout << "6.1 enqueue / 6.2 dequeue\nInput: enqueue 10, enqueue 20\nOutput: "
              << queue.dequeue() << '\n';
    printTraversal("front 10 -> 20 rear -> dequeue 10 -> front 20");
}

// 6.3 Reverse Linked Queue
/*
Problem 6.3
BEFORE: front->1->2->3->NULL.
ACTION: remove into array, enqueue reverse order.
AFTER: front->3->2->1->NULL.
COMPLEXITY: O(n)/O(n).
EDGE: empty queue remains empty.
*/
void test6_3()
{
    LinkedQueue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    reverse(queue);
    std::cout << "6.3 reverse\nInput: 1,2,3\nOutput: ";
    while (!queue.isEmpty())
    {
        std::cout << queue.dequeue();
        if (!queue.isEmpty())
            std::cout << "->";
    }
    std::cout << '\n';
    printTraversal("1 -> 2 -> 3 -> 3 -> 2 -> 1");
}

// 6.4 Merge Two Sorted Queues
/*
Problem 6.4
BEFORE: A=1->3->5, B=2->4->6.
ACTION: compare both fronts and enqueue smaller.
AFTER: 1->2->3->4->5->6.
COMPLEXITY: O(n+m)/O(n+m).
EDGE: either empty queue is copied into the result unchanged.
*/
void test6_4()
{
    LinkedQueue first;
    LinkedQueue second;
    first.enqueue(1);
    first.enqueue(3);
    first.enqueue(5);
    second.enqueue(2);
    second.enqueue(4);
    second.enqueue(6);
    LinkedQueue result = merge(first, second);
    std::cout << "6.4 merge\nInput: A=1,3,5; B=2,4,6\nOutput: ";
    while (!result.isEmpty())
    {
        std::cout << result.dequeue();
        if (!result.isEmpty())
            std::cout << "->";
    }
    std::cout << '\n';
    printTraversal("A 1,3,5 -> B 2,4,6 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6");
}

// 6.5 Remove Duplicates
/*
Problem 6.5
BEFORE: queue 1->1->2->3->2.
ACTION: compare each value with prior unique values.
AFTER: 1->2->3.
COMPLEXITY: O(n^2)/O(n).
EDGE: empty and all-unique queues are unchanged.
*/
void test6_5()
{
    LinkedQueue queue;
    queue.enqueue(1);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(2);
    removeDuplicates(queue);
    std::cout << "6.5 removeDuplicates\nInput: 1,1,2,3,2\nOutput: ";
    while (!queue.isEmpty())
    {
        std::cout << queue.dequeue();
        if (!queue.isEmpty())
            std::cout << "->";
    }
    std::cout << '\n';
    printTraversal("1 -> 1 duplicate -> 2 -> 3 -> 2 duplicate -> 1,2,3");
}

// 6.6 Implement Stack Using One Linked Queue
/*
Problem 6.6
BEFORE: linked queue contains 1,2.
ACTION: enqueue then rotate old values behind new.
AFTER: linked stack top/pop order is 2,1.
COMPLEXITY: O(n) push/O(n) storage.
EDGE: empty pop returns -1.
*/
void test6_6()
{
    StackFromLinkedQueue stack;
    stack.push(1);
    stack.push(2);
    std::cout << "6.6 stackFromLinkedQueue\nInput: push 1, push 2\nOutput pop: "
              << stack.pop() << '\n';
    printTraversal("push 1 -> push 2 -> rotate 1 behind 2 -> pop 2");
}

// 6.7 Find Middle Element
/*
Problem 6.7
BEFORE: queue 1->2->3, copied without changing original.
ACTION: remove through the copied queue to index count/2.
AFTER: middle=2.
COMPLEXITY: O(n)/O(n).
EDGE: empty returns -1; this implementation selects the later middle for even size.
*/
void test6_7()
{
    LinkedQueue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    std::cout << "6.7 middle\nInput: 1,2,3\nOutput: " << middle(queue) << '\n';
    printTraversal("copy 1 -> 2 -> 3 -> middle=2");
}

// 6.8 Move Front to Rear K Times
/*
Problem 6.8
BEFORE: queue front->1->2->3, k=1.
ACTION: dequeue front and enqueue it k times.
AFTER: front->2->3->1.
COMPLEXITY: O(k)/O(1).
EDGE: empty queue unchanged; k is reduced modulo queue size.
*/
void test6_8()
{
    LinkedQueue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    rotateK(queue, 1);
    std::cout << "6.8 rotateK\nInput: 1,2,3; k=1\nOutput: ";
    while (!queue.isEmpty())
    {
        std::cout << queue.dequeue();
        if (!queue.isEmpty())
            std::cout << "->";
    }
    std::cout << '\n';
    printTraversal("1,2,3 -> move 1 -> 2,3,1");
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
