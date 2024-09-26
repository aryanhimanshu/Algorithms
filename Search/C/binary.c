#include <stdio.h>
 
int main()
{
   int location, first, last, middle,size, search, array[100];
 
   printf("Enter number of elements: \n");
   scanf("%d",&size);
 
   printf("Enter %d integers: \n", size);
 
   for (location = 0; location < size; location++)
      scanf("%d",&array[location]);
 
   printf("Enter value to find: \n");
   scanf("%d", &search);
 
   first = 0;
   last = size - 1;
   middle = (first+last)/2;
 
   while (first <= last) {
      if (array[middle] < search)
         first = middle + 1;    
      else if (array[middle] == search) {
         printf("%d found at location: %d.\n", search, middle+1);
         break;
      }
      else
         last = middle - 1;
 
      middle = (first + last)/2;
   }
   if (first > last)
      printf("The number is not in the list.\n"); 
}