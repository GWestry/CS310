#include "RecursiveADT.h"
void collect(IntQueue& q,std::vector<int>& v){if(q.empty())return;v.push_back(q.pop());collect(q,v);}
void refill(const std::vector<int>& v,IntQueue& q,int i,int mid){
    if(i==mid)return;
    q.push(v[i]); if(i+mid<(int)v.size()) q.push(v[i+mid]);
    refill(v,q,i+1,mid);
}
int main(){IntQueue q;for(int x:{1,2,3,4})q.push(x);std::vector<int>v;collect(q,v);refill(v,q,0,(int)v.size()/2);while(!q.empty()){std::cout<<q.pop()<<' ';}std::cout<<'\n';}
