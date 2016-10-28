#include <iostream>
using namespace std;

void merging(int a[],int b[],int low, int mid, int high) {
   int l1,l2,i;
   for(l1=low,l2=mid+1,i=low; l1<=mid && l2<=high ; i++){
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }

   while(l1 <= mid)
      b[i++] = a[l1++];

   while(l2 <= high)
      b[i++] = a[l2++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

void mergesort(int a[],int b[],int low, int high) {
   if(low < high) {
      int mid = (low + high) / 2;
      mergesort(a,b,low, mid);
      mergesort(a,b,mid+1, high);
      merging(a,b,low, mid, high);
   }
   else {
      return;
   }
}

int main() {
    int a[10]={ 10, 14, 19, 26, 27, 31, 33, 35, 42, 44 };
    int b[10]={0};
    mergesort(a,b,0,10);
    for(int i=0;i<10;i++)
        cout<<a[i]<<"\n";
    return 0;
}
