# Programming Assignment 4

This folder contains a stack implementation and a postfix-expression evaluator.

## Source files

- `Stack.h` declares the common stack interface.
- `ArrayStack.cpp` implements a fixed-capacity stack using dynamically allocated
  array storage.
- `LinkedStack.cpp` implements a dynamically growing linked stack.
- `PostfixEval.cpp` implements `evaluatePostfix`.
- `main.cpp` demonstrates both stack operations and postfix evaluation.

Use either `ArrayStack.cpp` or `LinkedStack.cpp` when compiling. Do not compile
both implementations in the same command because they define the same
`Stack` methods.

## Compile and run

From the `programming-assignment-4` directory:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic ArrayStack.cpp PostfixEval.cpp main.cpp -o array_stack
.\array_stack.exe
```

To build the linked implementation:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic -DLINKED_STACK LinkedStack.cpp PostfixEval.cpp main.cpp -o linked_stack
.\linked_stack.exe
```

## Error handling and memory management

- The array stack allocates its storage with `new[]` and releases it with
  `delete[]` in the destructor.
- The linked stack allocates one node per pushed item and deletes each node when
  it is popped or when the destructor calls `makeEmpty()`.
- Allocation failures are handled without changing the stack contents.
- Array-stack overflow and empty-stack operations report an error through the
  existing sentinel value (`-999`) or an error message.
- Invalid postfix expressions, insufficient operands, and division by zero
  return `-999` and clear the supplied stack.
- Copying `Stack` objects is disabled because each implementation owns dynamic
  memory.
