#include "RecursiveADT.h"
CNode* sortedInsert(CNode* h,CNode*n){if(!h){n->next=n;return n;}if(n->data<=h->data){CNode*t=h;while(t->next!=h)t=t->next;n->next=h;t->next=n;return n;}if(h->next==h||h->next->data>=n->data){n->next=h->next;h->next=n;return h;}h->next=sortedInsert(h->next,n);return h;}
int main(){CNode*h=makeCircularList({1,3});h=sortedInsert(h,new CNode(2));CNode*p=h;for(int i=0;p&&i<3;p=p->next,++i)std::cout<<p->data<<' ';std::cout<<'\n';deleteCircularList(h);}
