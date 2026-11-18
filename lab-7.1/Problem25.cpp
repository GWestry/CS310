#include "RecursiveADT.h"
void binary(int n,std::vector<std::string>& out){if(n==0)return;binary(n-1,out);out.push_back(std::to_string(n));}
int main(){std::vector<std::string>out;binary(8,out);for(const auto& value:out)std::cout<<value<<' ';std::cout<<'\n';}
