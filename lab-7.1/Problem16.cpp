#include "RecursiveADT.h"
void split(CNode*h,CNode*&a,CNode*&b,int n){if(!h||n<=0){a=b=nullptr;return;}a=h;CNode*p=h;for(int i=1;i<n/2;i++)p=p->next;b=p->next;p->next=a;CNode*q=b;while(q->next!=h)q=q->next;q->next=b;}
int main(){CNode*h=makeCircularList({1,2,3,4});CNode*a,*b;split(h,a,b,4);CNode*p=a;for(int i=0;i<2;p=p->next,++i)std::cout<<p->data<<' ';std::cout<<'\n';}
