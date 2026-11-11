#include "CircularLinkedList.h"
#include "CircularLinkedQueue.h"
#include "CircularLinkedStack.h"
#include "Queue.h"
#include "Stack.h"
#include "TextEditorBuffer.h"

#include <cassert>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

template <typename Function>
void verifyUnderflow(Function operation)
{
    bool threw = false;
    try
    {
        operation();
    }
    catch (const std::underflow_error &)
    {
        threw = true;
    }
    assert(threw);
}

void testArrayStack()
{
    std::cout << "\n1. Array-based stack tests\n";
    Stack<int> stack;
    for (int value = 1; value <= 5; ++value)
    {
        stack.push(value);
    }
    std::cout << "After pushing 5 items: top = " << stack.top()
              << ", size = " << stack.size() << '\n';
    assert(stack.top() == 5);
    assert(stack.size() == 5);

    std::cout << "Popping 3 items: ";
    for (int count = 0; count < 3; ++count)
    {
        std::cout << stack.pop() << (count == 2 ? '\n' : ' ');
    }
    std::cout << "After popping 3 items: top = " << stack.top()
              << ", size = " << stack.size() << '\n';
    assert(stack.top() == 2);
    assert(stack.size() == 2);

    Stack<char> emptyStack;
    bool threw = false;
    try
    {
        emptyStack.pop();
    }
    catch (const std::underflow_error &)
    {
        threw = true;
    }
    assert(threw);
    std::cout << "Empty pop exception: handled\n";

    Stack<char> growthStack;
    for (int index = 0; index < 101; ++index)
    {
        growthStack.push(static_cast<char>('a' + index % 26));
    }
    assert(growthStack.size() == 101);
    std::cout << "Dynamic growth check: 101 items stored\n";
}

void testCircularStack()
{
    std::cout << "Circular linked stack check: ";
    CircularLinkedStack<std::string> stack;
    stack.push("first");
    stack.push("second");
    stack.push("third");
    assert(stack.size() == 3);
    assert(stack.top() == "third");
    assert(stack.pop() == "third");
    assert(stack.pop() == "second");
    assert(stack.pop() == "first");
    verifyUnderflow([&stack]
                    { stack.top(); });
    std::cout << "passed\n";
}

void testArrayQueue()
{
    std::cout << "\n2. Array-based queue tests\n";
    Queue<int> queue;
    for (int value = 1; value <= 5; ++value)
    {
        queue.enqueue(value);
    }
    std::cout << "After enqueueing 5 items: front = " << queue.front()
              << ", size = " << queue.size() << '\n';
    assert(queue.front() == 1);
    assert(queue.size() == 5);

    std::cout << "Dequeuing 3 items: ";
    for (int count = 0; count < 3; ++count)
    {
        std::cout << queue.dequeue() << (count == 2 ? '\n' : ' ');
    }
    std::cout << "After dequeuing 3 items: front = " << queue.front()
              << ", size = " << queue.size() << '\n';
    assert(queue.front() == 4);
    assert(queue.size() == 2);

    Queue<int> emptyQueue;
    bool threw = false;
    try
    {
        emptyQueue.dequeue();
    }
    catch (const std::underflow_error &)
    {
        threw = true;
    }
    assert(threw);
    std::cout << "Empty dequeue exception: handled\n";
}

void testCircularQueue()
{
    std::cout << "Circular linked queue check: ";
    CircularLinkedQueue<char> queue;
    queue.enqueue('A');
    queue.enqueue('B');
    queue.enqueue('C');
    assert(queue.front() == 'A');
    assert(queue.dequeue() == 'A');
    queue.enqueue('D');
    assert(queue.dequeue() == 'B');
    assert(queue.dequeue() == 'C');
    assert(queue.dequeue() == 'D');
    verifyUnderflow([&queue]
                    { queue.front(); });
    std::cout << "passed\n";
}

void testCircularList()
{
    std::cout << "\n3. Circular linked list tests\n";
    CircularLinkedList<int> list;
    list.insertFront(2);
    list.insertRear(3);
    list.insertFront(1);
    list.insertRear(4);
    list.insertRear(5);

    std::ostringstream output;
    list.display(output);
    std::cout << "After inserting 5 items: " << output.str() << '\n';
    assert(output.str() == "[1 2 3 4 5]");

    list.deleteFront();
    list.deleteRear();
    output.str("");
    output.clear();
    list.display(output);
    std::cout << "After deleting 2 items: " << output.str() << '\n';
    assert(output.str() == "[2 3 4]");

    CircularLinkedList<int> emptyList;
    verifyUnderflow([&emptyList]
                    { emptyList.deleteFront(); });
    verifyUnderflow([&emptyList]
                    { emptyList.deleteRear(); });
    std::cout << "Empty delete exceptions: handled\n";
}

void testTextEditorBuffer()
{
    std::cout << "\n4. Text editor buffer tests\n";
    TextEditorBuffer<char> characters;
    const std::string text = "helloworld";
    for (char character : text)
    {
        characters.type(character);
    }

    std::ostringstream output;
    characters.displayBuffer(output);
    std::cout << "After typing 10 characters: " << output.str() << '\n';
    assert(output.str() == "[h e l l o w o r l d]");

    for (int count = 0; count < 3; ++count)
    {
        characters.undo();
    }
    output.str("");
    output.clear();
    characters.displayBuffer(output);
    std::cout << "After undoing 3 characters: " << output.str() << '\n';
    assert(output.str() == "[h e l l o w o]");

    for (int count = 0; count < 2; ++count)
    {
        characters.redo();
    }
    output.str("");
    output.clear();
    characters.displayBuffer(output);
    std::cout << "After redoing 2 characters: " << output.str() << '\n';
    assert(output.str() == "[h e l l o w o r l]");

    output.str("");
    output.clear();
    characters.displayHistory(output);
    std::cout << "Operation history: " << output.str() << '\n';

    TextEditorBuffer<std::string> words;
    words.type("hello");
    words.type("world");
    output.str("");
    output.clear();
    words.displayBuffer(output);
    std::cout << "String template buffer: " << output.str() << '\n';
    assert(output.str() == "[hello world]");
    words.undo();
    assert(words.size() == 1);
}

int main()
{
    testArrayStack();
    testCircularStack();
    testArrayQueue();
    testCircularQueue();
    testCircularList();
    testTextEditorBuffer();
    return 0;
}
