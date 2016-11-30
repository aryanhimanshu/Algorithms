/* Write C++ programs for sorting a given list of elements in ascending order using Quick sort sorting methods */

#include<iostream>
using namespace std;
int a[10],l,u,i,j;
void quick(int *,int,int);
int main()
{

cout <<"enter 10 elements";
for(i=0;i<10;i++)
cin >> a[i];
l=0;
u=9;
quick(a,l,u);
cout <<"\n sorted elements";
for(i=0;i<10;i++)
cout << a[i] << " ";

}

void quick(int a[],int l,int u)
{
   int p,temp;
   if(l<u)
   {
   p=a[l];
   i=l;
   j=u;
    while(i<j)
   {
      while(a[i] <= p && i<j )
	 i++;
      while(a[j]>p && i<=j )
	   j--;
      if(i<=j)
      {
      temp=a[i];
      a[i]=a[j];
      a[j]=temp;}
  }
  temp=a[j];
  a[j]=a[l];
  a[l]=temp;
  cout <<"\n";
  for(i=0;i<10;i++)
  cout <<a[i]<<" ";
  quick(a,l,j-1);
  quick(a,j+1,u);
 }

}
