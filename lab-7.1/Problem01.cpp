#include "RecursiveADT.h"
Node* reverse(Node* head) {
    if (!head || !head->next) return head;
    Node* result = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return result;
} // O(n) time, O(n) stack space
int main() { Node* h = makeList({1,2,3,4,5}); h = reverse(h); printList(h); deleteList(h); }
