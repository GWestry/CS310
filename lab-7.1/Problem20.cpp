#include "RecursiveADT.h"
int eval(const std::string&e,std::size_t&i){while(i<e.size()&&e[i]==' ')++i;if(std::isdigit(e[i]))return e[i++]-'0';char op=e[i++];int a=eval(e,i),b=eval(e,i);return op=='+'?a+b:op=='-'?a-b:op=='*'?a*b:a/b;}
int main(){std::string e="+ 3 * 4 2";std::size_t i=0;std::cout<<eval(e,i)<<'\n';}
