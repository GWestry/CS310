#include "RecursiveADT.h"
bool balanced(const std::string& s,std::size_t i,std::string open){
    if(i==s.size()) return open.empty();
    char c=s[i];
    if(c=='('||c=='['||c=='{') open.push_back(c);
    else if(c==')'||c==']'||c=='}'){
        if(open.empty()||(c==')'&&open.back()!='(')||(c==']'&&open.back()!='[')||(c=='}'&&open.back()!='{')) return false;
        open.pop_back();
    }
    return balanced(s,i+1,open);
}
int main(){std::string open;std::cout<<balanced("({[]})",0,open)<<'\n';}
