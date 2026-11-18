#include "RecursiveADT.h"
DNode* reverse(DNode* h) {
    if(!h) return nullptr; std::swap(h->next,h->prev);
    if(!h->prev) return h; return reverse(h->prev);
} // O(n) time, O(n) stack space
int main(){DNode* h=makeDoublyList({1,2,3});h=reverse(h);for(DNode*p=h;p;p=p->next)std::cout<<p->data<<' ';std::cout<<'\n';deleteDoublyList(h);}
