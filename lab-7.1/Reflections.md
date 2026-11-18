# Reflections and challenge answers

## Challenge questions

1. Recursion naturally follows tree-shaped data because each child is a
   smaller instance of the same problem. Linear lists also support recursion,
   but the call stack adds O(n) space without improving traversal time.
   Deep inputs can overflow the stack, so iterative code or an explicit stack
   is safer for unbounded production data.

2. Tail-call optimization can remove a frame only when the recursive call is
   the final operation. Compilers may optimize a tail-recursive list walk,
   but a stack/queue algorithm that must resume work after the call generally
   cannot rely on that optimization. It is therefore important to document
   the actual worst-case stack use rather than assume optimization.

3. A circular list has no null terminator, so a null-only base case never
   stops. The safe guards used here carry the original head, count visited
   nodes, or stop when the cursor returns to the start. A malformed cycle can
   also be bounded with a visited set or a traversal limit.

4. Recursion makes quicksort and tree algorithms concise and mirrors their
   divide-and-conquer structure. Iterative merge sort is preferable for large
   linked lists because it has predictable O(n log n) time, avoids worst-case
   quicksort behavior, and uses less call-stack space.

5. Problem 1 (list reversal) was the most difficult because the recursive
   return value is the new head while pointer changes happen during unwind.
   Drawing the heap and call stack separately made the ownership change
   visible and exposed the required `head->next = nullptr` tail step.

## Group reflection

The list exercises showed that recursion is primarily a control-flow tool:
it does not make pointer traversal cheaper. The doubly linked problems added
the invariant that every `next` update needs a matching `prev` update. Circular
lists required an explicit stopping condition, while stacks and queues made
the call stack interact with the ADT's own storage. Sorting examples made the
trade-off clear: recursive code is readable for divide-and-conquer, but an
iterative algorithm is often more robust for production-sized inputs.
