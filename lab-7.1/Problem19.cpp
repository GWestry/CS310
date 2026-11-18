#include "RecursiveADT.h"
void reverseStack(IntStack&s){if(s.empty())return;int x=s.pop();reverseStack(s);IntStack t;while(!s.empty()){t.push(s.pop());}s.push(x);while(!t.empty()){s.push(t.pop());}}
int main(){IntStack s;for(int x:{1,2,3})s.push(x);reverseStack(s);while(!s.empty()){std::cout<<s.pop()<<' ';}std::cout<<'\n';}
