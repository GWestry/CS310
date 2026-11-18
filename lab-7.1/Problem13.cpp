#include "RecursiveADT.h"
int cycleLength(CNode* h,CNode* p,int count=0){if(!p)return 0;if(count&&p==h)return count;return cycleLength(h,p->next,count+1);}
int main(){CNode*h=makeCircularList({1,2,3,4});std::cout<<cycleLength(h,h)<<'\n';deleteCircularList(h);}
