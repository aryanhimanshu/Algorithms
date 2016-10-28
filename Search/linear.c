#include <stdio.h>

int linearSearch(int *array, int sizeOfArray, int value)
{
  int i;
  for (i=0;i<sizeOfArray;i++)
	if (array[i]==value)
	  return i;  //returning the position of the first occurence of the value to be searched
  return -1;
}

int main()
{
  int array[100000],i,sizeOfArray,value,position;


  // If the array has to be taken as an input
  /*printf("Enter size of array\n");
  scanf("%d",&sizeOfArray);
  printf("Enter the values of the array\n");
  for (i=0;i<sizeOfArray;i++)
	scanf("%d",&array[i]);
  printf("Enter the value to be searched\n");
  scanf("%d",&value);*/


  //Otherwise an example is illustrated
  array[0]=1;
  array[1]=4;
  array[2]=2;
  array[3]=3;
  array[4]=5;
  sizeOfArray=5;
  value=3;
  
  position = linearSearch(array,sizeOfArray,value);
  

  //assuming array to be 0 indexed
  if (position>=0)
	printf("Element was found at position %d in the array\n",position);
  else
	printf("Value not found\n");
  
  return 0;
}
