#include "RecursiveADT.h"
void partition(Node* h,int x,Node*& low,Node*& high) {
    if (!h) return;
    Node* next=h->next; h->next=nullptr;
    if(h->data<x){h->next=low;low=h;} else {h->next=high;high=h;}
    partition(next,x,low,high);
} // O(n) time, O(n) stack space
int main(){Node* h=makeList({3,5,1,4,2});Node* a=nullptr;Node* b=nullptr;partition(h,3,a,b);printList(a);printList(b);deleteList(a);deleteList(b);}
