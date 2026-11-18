#include "RecursiveADT.h"
void heapify(std::vector<int>&a,int n,int i){int l=2*i+1,r=l+1,m=i;if(l<n&&a[l]>a[m])m=l;if(r<n&&a[r]>a[m])m=r;if(m!=i){std::swap(a[i],a[m]);heapify(a,n,m);}}
void build(std::vector<int>&a,int i){if(i<0)return;heapify(a,(int)a.size(),i);build(a,i-1);}
void heapSort(std::vector<int>&a,int n){if(n<=1)return;std::swap(a[0],a[n-1]);heapify(a,n-1,0);heapSort(a,n-1);}
int main(){std::vector<int>a={3,1,4,2};build(a,(int)a.size()/2-1);heapSort(a,(int)a.size());printValues(a);}
