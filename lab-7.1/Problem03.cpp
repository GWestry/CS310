#include "RecursiveADT.h"
bool cycle(Node* slow, Node* fast) {
    if (!fast || !fast->next) return false;
    if (slow == fast) return true;
    return cycle(slow->next, fast->next->next);
} // O(n) time, O(n) stack space
int main() { Node* h = makeList({1,2,3}); h->next->next->next = h; std::cout << cycle(h,h->next) << '\n'; h->next->next->next = nullptr; deleteList(h); }
