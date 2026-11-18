#include "RecursiveADT.h"
struct MNode{int data;MNode*next;MNode*child;MNode(int x):data(x),next(nullptr),child(nullptr){}};
void flatten(MNode* p,std::vector<int>& out){if(!p)return;out.push_back(p->data);flatten(p->child,out);flatten(p->next,out);}
int main(){MNode a(1),b(2),c(3);a.next=&b;a.child=&c;std::vector<int>o;flatten(&a,o);printValues(o);}
