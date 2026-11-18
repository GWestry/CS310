# Complexity table

| Problems | Recursive time | Recursive auxiliary space | Main reason |
|---|---:|---:|---|
| 1, 7, 19, 22 | O(n) | O(n) | One frame per element |
| 2, 13, 26 | O(n) | O(n) | Recursive traversal or midpoint search |
| 3, 14, 15, 16, 17 | O(n) | O(n) | Pointer traversal; circular base guards |
| 4, 5, 6, 8, 9, 10, 11, 12, 28, 30 | O(n) | O(n) | Each node is processed a bounded number of times |
| 18, 20, 21, 25 | O(n) to O(n²) | O(n) | Stack/queue recursion; nested insertion may be quadratic |
| 23, 24 | O(n) | O(n) | Queue elements are moved through recursive calls |
| 27 | O(n log n) average, O(n²) worst | O(n) | Recursive linked-list quicksort |
| 29 | O(n log n) | O(n) | Recursive heap construction and heapify |

For comparison, iterative linked-list reversal uses O(1) auxiliary space,
whereas the recursive version uses O(n) call-stack space. Linked-list binary
search does not achieve array binary search's O(log n) total time because
finding each midpoint requires traversal; this implementation is O(n log n).
