#include "RecursiveADT.h"
bool search(Node* h,int n,int target){if(n<=0||!h)return false;int half=n/2;Node*m=nodeAt(h,half);if(m->data==target)return true;if(target<m->data)return search(h,half,target);return search(m->next,n-half-1,target);}
int main(){Node*h=makeList({1,2,3,4,5,6,7});std::cout<<search(h,7,6)<<'\n';deleteList(h);}
