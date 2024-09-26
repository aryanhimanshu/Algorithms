#include <stdio.h>
void main(){

    int input[10],location,size,search,c=0;

    printf("Enter the size of an array: ");
    scanf("%d",&size);

    printf("Enter the elements of the array: ");
    for(location=0;location<=size-1;location++){
         scanf("%d",&input[location]);
    }

    printf("Enter the number to be search: ");
    scanf("%d",&search);
    for(location=0;location<=size-1;location++){
         if(input[location]==search){
             c=1;
             break;
         }
    }
    if(c==0)
         printf("The number is not in the list \n");
    else
     printf("The number is found at location %d \n",location+1);
}