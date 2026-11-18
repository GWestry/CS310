#include "RecursiveADT.h"
void reverseQueue(IntQueue&q){if(q.empty())return;int x=q.pop();reverseQueue(q);q.push(x);}
int main(){IntQueue q;for(int x:{1,2,3})q.push(x);reverseQueue(q);while(!q.empty()){std::cout<<q.pop()<<' ';}std::cout<<'\n';}
