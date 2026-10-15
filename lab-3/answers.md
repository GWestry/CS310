# Lab 3: Head and Tail Questions

## 13. Head

### 1. Array-based `UnsortedType`

Yes. The last inserted item is at `info[length - 1]`, so `Head()` can return it directly. The complexity is **O(1)**.

### 2. Linked `UnsortedType`

Yes. `PutItem` inserts new nodes at the beginning, and `listData` points to the newest node. Therefore, `Head()` returns `listData->info`. The complexity is **O(1)**.

## 14. Tail

### 1. Array-based `UnsortedType`

Yes. `Tail()` creates a new list and copies every item except `info[length - 1]`, which is the last inserted item. The original list is unchanged. The complexity is **O(n)** because the items must be copied.

### 2. Linked `UnsortedType`

Yes. Because the newest item is the first node, `Tail()` starts at the second node and copies the remaining nodes into a new list. The original list is unchanged. The complexity is **O(n)** because the nodes must be visited and copied.

## Summary

| Function | Array-based list | Linked list |
| --- | --- | --- |
| `Head()` | Easy, **O(1)** | Easy, **O(1)** |
| `Tail()` | Easy, **O(n)** | Easy, **O(n)** |
