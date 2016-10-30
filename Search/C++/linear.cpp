#include<iostream>
using namespace std;
bool search(int a[],int x,int n)
{
for(int i=0;i<n;i++)
if(a[i]==x){
return 1;
}
return 0;
}
int main()
{
int a[]={1,2,3,4,5,6};
if(search(a,4,6))cout<<"4 is found in array/n"<<endl;
else cout<<"4 not found"<<endl;
}
