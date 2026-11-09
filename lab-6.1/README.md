# Lab 6.1 Discussion and Checklist

## Submission checklist

### Source code

Completed source is in this folder:

- `Stack.h` - templated dynamic-array stack
- `CircularLinkedStack.h` - templated circular linked stack
- `Queue.h` - templated circular-array queue
- `CircularLinkedQueue.h` - templated circular linked queue
- `CircularLinkedList.h` - templated circular linked list
- `TextEditorBuffer.h` - templated text editor buffer
- `main.cpp` - test cases for all structures and the buffer

### Test output

`main.cpp` prints labeled output for:

- Stack push, pop, top, size, growth, and empty-pop exception
- Queue enqueue, dequeue, front, size, and empty-dequeue exception
- Circular linked list insert, delete, display, and empty-list exceptions
- Text buffer type, undo, redo, display, history, and string input

The test run ends with:

```text
All rubric-aligned tests passed.
```

The printed sections can be used for screenshots and captions in the report.

## Discussion

### Templates

Each structure uses `template <typename T>`, so the same code works with
different types. The tests use `char`, `int`, and `std::string`. This avoids
duplicating the data structures for every possible item type.

### Circular structures

The main challenge was keeping the links correct when inserting or removing
the first or last item. A circular structure has no `nullptr` at the end:
the last node points back to the first node. Empty and one-node cases need
special handling so pointers do not become invalid.

### Array versus linked implementations

Array structures have good cache performance and simple indexing, but they
need allocated storage and can have capacity limits. The array stack grows
by doubling, while the queue has a fixed initial capacity of 100 and reports
overflow when full.

Linked structures grow one node at a time and do not need a contiguous block
of memory, but every node uses extra pointer space. Their operations can also
require traversal. The circular queue is efficient because its `rear` pointer
gives direct access to the front through `rear->next`.

The main stack and queue operations are normally O(1). The circular list
operations that search for the tail are O(n), and displaying or clearing a
structure is O(n). Dynamic-array growth is O(n) when it occurs, but stack
insertion is amortized O(1).

## Reflection

I learned how the same abstract operation can be implemented with arrays,
stacks, queues, and linked nodes. The redo behavior also showed why the
ordering of undo items matters: redo must restore the most recently undone
item first.

The most interesting part was maintaining circular links during one-item and
empty transitions. Testing those edge cases was useful because pointer bugs
can compile normally but fail during execution.

For the report, add screenshots of the labeled program output and include a
short caption describing which test section each screenshot shows.
