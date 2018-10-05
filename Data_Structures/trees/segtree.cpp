#include<bits/stdc++.h>

using namespace std;

int makeseg(int *arr,int *seg,int s,int l,int i);
int rmq(int *seg,int ql,int qh,int l,int h,int i);

int main()
{
  int arr[100000],seg[400000],n,i;
  memset(arr,0,100000);
  scanf ("%d",&n);
  for (int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  makeseg(arr,seg,0,n-1,0 );
  for (i=0;i<2*n;i++)
    cout<<seg[i]<<" ";
  cout<<endl;
  cout<<"Bhai rmq ka bhi kuchh daal de aisa na kar"<<endl;
  int ql,qh;
  cin>>ql>>qh;
  cout<<  rmq(seg,ql,qh,0,n-1,0);
  return 0;
}

int makeseg(int *arr,int *seg,int s,int l,int i)
{
  if (s==l)
    {
      seg[i]=arr[s];
      return 1;
    }
  makeseg(arr,seg, s, ((s+l)/2),((2*i)+1));
  makeseg(arr,seg, (((s+l)/2)+1) , l, ((2*i)+2));
  seg[i]=min(seg[2*i+1],seg[2*i+2]);
  return 1;
}

int rmq(int *seg,int ql,int qh,int l,int h,int i)
{
  if (ql<=l&&qh>=h)
    return seg[i];
  if (ql>h||qh<l)
    return INT_MAX;
  return min(rmq(seg,ql,qh,l,(l+h)/2,(2*i)+1),rmq(seg,ql,qh,((l+h)/2)+1,h,(2*i+2)));
}
