#include "RecursiveADT.h"
Node* middle(Node* slow, Node* fast) {
    if (!fast || !fast->next) return slow;
    return middle(slow->next, fast->next->next);
} // O(n) time, O(n) stack space
int main() { Node* h = makeList({1,2,3,4,5}); std::cout << middle(h,h)->data << '\n'; deleteList(h); }
