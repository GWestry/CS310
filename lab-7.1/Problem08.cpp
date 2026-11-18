#include "RecursiveADT.h"
DNode* insert(DNode* h,int x) {
    if(!h||x<=h->data){DNode*n=new DNode(x);n->next=h;if(h)h->prev=n;return n;}
    h->next=insert(h->next,x);h->next->prev=h;return h;
} // O(n) time, O(n) stack space
int main(){DNode*h=makeDoublyList({1,3,5});h=insert(h,4);for(;h;h=h->next)std::cout<<h->data<<' ';std::cout<<'\n';}
