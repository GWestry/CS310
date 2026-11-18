#include "RecursiveADT.h"
bool pairSum(Node* a,int target){if(!a)return false;for(Node*b=a->next;b;b=b->next)if(a->data+b->data==target)return true;return pairSum(a->next,target);}
int main(){Node*h=makeList({1,4,6,9});std::cout<<pairSum(h,10)<<'\n';deleteList(h);}
