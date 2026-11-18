#include "RecursiveADT.h"
void enqueueRecursive(IntQueue&q,const std::vector<int>&v,std::size_t i=0){if(i==v.size())return;q.push(v[i]);enqueueRecursive(q,v,i+1);}
int main(){IntQueue q;enqueueRecursive(q,{1,2,3});while(!q.empty()){std::cout<<q.pop()<<' ';}std::cout<<'\n';}
