#include<string.h>
#include<stdio.h>
#include<stdlib.h>

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
	printf("%s ",arr[i]);
  printf("\n");
}
 
int main()
{
  int n,i;
  char *arr[100000];
  printf("Enter the size of the array of strings\n");
  scanf("%d",&n);
  printf("Enter the strings\n");
  for (i=0;i<n;i++)
	{
	  arr[i]=(char*)malloc(100*sizeof(char));
	  scanf("%s",arr[i]);
	}
  selectionSort(arr, n);
  printf("Sorted array:\n");
  printArray(arr, n);
  return 0;
}
