#include "RecursiveADT.h"
Node* quick(Node*h){if(!h||!h->next)return h;int p=h->data;Node*l=nullptr,*g=nullptr,*e=nullptr;while(h){Node*n=h->next;h->next=nullptr;if(h->data<p){h->next=l;l=h;}else if(h->data>p){h->next=g;g=h;}else{h->next=e;e=h;}h=n;}l=quick(l);g=quick(g);Node*r=nullptr,*tail=nullptr;auto add=[&](Node*part){if(!part)return;if(!r)r=part;else tail->next=part;while(part->next)part=part->next;tail=part;};add(l);add(e);add(g);return r;} // avg O(n log n), worst O(n^2)
int main(){Node*h=makeList({3,1,4,2});h=quick(h);printList(h);deleteList(h);}
