#include "RecursiveADT.h"
Node* mergeLists(Node*a,Node*b){if(!a)return b;if(!b)return a;if(a->data<=b->data){a->next=mergeLists(a->next,b);return a;}b->next=mergeLists(a,b->next);return b;}
Node* mergeSort(Node*h){if(!h||!h->next)return h;Node*slow=h,*fast=h->next;while(fast&&fast->next){slow=slow->next;fast=fast->next->next;}Node*r=slow->next;slow->next=nullptr;return mergeLists(mergeSort(h),mergeSort(r));}
int main(){Node*h=makeList({4,1,3,2});h=mergeSort(h);printList(h);deleteList(h);}
