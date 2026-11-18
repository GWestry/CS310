#include "RecursiveADT.h"
void sortedInsert(IntStack&s,int x){if(s.empty()||s.top()<=x){s.push(x);return;}int y=s.pop();sortedInsert(s,x);s.push(y);}
void sortStack(IntStack&s){if(s.empty())return;int x=s.pop();sortStack(s);sortedInsert(s,x);}
int main(){IntStack s;for(int x:{3,1,4,2})s.push(x);sortStack(s);while(!s.empty())std::cout<<s.pop()<<' ';std::cout<<'\n';}
