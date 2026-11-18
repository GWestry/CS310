#include "RecursiveADT.h"
DNode* rotate(DNode* h,int k){if(!h||k<=0)return h;DNode* n=h;while(k--&&n)n=n->next;if(!n)return h;DNode* p=n->prev;if(p)p->next=nullptr;n->prev=nullptr;DNode*t=h;while(t->next)t=t->next;t->next=h;h->prev=t;return n;} // O(n), O(n)
int main(){DNode*h=makeDoublyList({1,2,3,4});h=rotate(h,2);for(;h;h=h->next)std::cout<<h->data<<' ';std::cout<<'\n';}
