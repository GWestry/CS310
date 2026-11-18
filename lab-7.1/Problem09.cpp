#include "RecursiveADT.h"
DNode* erase(DNode* h,int x) {
    if(!h)return nullptr;if(h->data==x){DNode*n=h->next;if(n)n->prev=nullptr;delete h;return n;}
    h->next=erase(h->next,x);if(h->next)h->next->prev=h;return h;
} // O(n) time, O(n) stack space
int main(){DNode*h=makeDoublyList({1,2,3});h=erase(h,2);for(;h;h=h->next)std::cout<<h->data<<' ';std::cout<<'\n';}
