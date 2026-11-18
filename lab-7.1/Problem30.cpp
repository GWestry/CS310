#include "RecursiveADT.h"
void insertion(std::vector<int>&a,int n){if(n<=1)return;insertion(a,n-1);int x=a[n-1],i=n-2;while(i>=0&&a[i]>x){a[i+1]=a[i];--i;}a[i+1]=x;}
int main(){std::vector<int>a={4,1,3,2};insertion(a,(int)a.size());printValues(a);}
