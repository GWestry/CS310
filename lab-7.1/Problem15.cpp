#include "RecursiveADT.h"
void deleteAfter(CNode* p){if(!p||!p->next||p->next==p)return;CNode* old=p->next;p->next=old->next;delete old;}
int main(){CNode*h=makeCircularList({1,2,3});deleteAfter(h);CNode*p=h;for(int i=0;i<2;p=p->next,++i)std::cout<<p->data<<' ';std::cout<<'\n';deleteCircularList(h);}
