#include "RecursiveADT.h"
Node* merge(Node* a, Node* b) {
    if (!a) return b; if (!b) return a;
    if (a->data <= b->data) { a->next = merge(a->next,b); return a; }
    b->next = merge(a,b->next); return b;
} // O(n+m) time, O(n+m) stack space
int main() { Node* a=makeList({1,3,5}); Node* b=makeList({2,4,6}); Node* h=merge(a,b); printList(h); deleteList(h); }
