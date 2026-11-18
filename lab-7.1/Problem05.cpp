#include "RecursiveADT.h"
Node* removeValue(Node* h,int value){
    if(!h)return nullptr;
    if(h->data==value){Node*n=h->next;delete h;return removeValue(n,value);}
    h->next=removeValue(h->next,value);return h;
}
Node* dedupe(Node* h){
    if(!h)return nullptr;
    h->next=removeValue(h->next,h->data);
    h->next=dedupe(h->next);return h;
} // O(n^2) time, O(n) stack space
int main() { Node* h=makeList({1,2,1,3,2}); h=dedupe(h); printList(h); deleteList(h); }
