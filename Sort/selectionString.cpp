#include <bits/stdc++.h>
using namespace std;
void selectionSort(char * arr[], int n)
{
  int i, j, min_idx;
  char temp[1000];
 
  for (i = 0; i < n-1; i++)
    {
	  min_idx = i;
	  for (j = i+1; j < n; j++)
		if (strcmp(arr[j],arr[min_idx])<0)
		  min_idx = j;
 
	  strcpy(temp,arr[min_idx]);
	  strcpy(arr[min_idx],arr[i]);
	  strcpy(arr[i],temp);
    }
}
 
void printArray(char * arr[], int size)
{
  int i;
  for (i=0; i < size; i++)
	cout<<arr[i]<<" ";
  cout<<endl;
}
 
int main()
{
  int n,i;
  char *arr[100000];
  cout<<"Enter the size of the array of strings"<<endl;
  cin>>n;
  cout<<"Enter the strings"<<endl;
  for (i=0;i<n;i++)
	{
	  arr[i]=(char*)malloc(100*sizeof(char));
	  cin>>arr[i];
	}
  selectionSort(arr, n);
  cout<<"Sorted array:"<<endl;
  printArray(arr, n);
  return 0;
}

