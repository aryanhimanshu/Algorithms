#include<bits/stdc++.h>
using namespace std;
int a[100000];
int bsearch(int a[],int x,int i,int j)
{
	int mid;
	while(i<=j){
		mid=i+(j-i)/2;
		if(a[mid]==x){
			return 1;
		}
		if(a[mid]>x)j=mid-1;
		if(a[mid]<x)i=mid+1;
	}
	return 0;
}
main(){
	int n;
	a[]={1,2,3,4,5,6,7};
  n=7;
	sort(a,a+n);
	if(bsearch(a,4,0,6))cout<<"prsent"<<endl;
  else cout<<"not found"<<endl;
}
