#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int A[100],B[100],C[100];
    int i,j,number,max;

    printf("Enter the number of elements:\n");
    scanf("%d",&number);

    max=0;
    printf("Enter the elements:\n");
    for(i=1;i<=number;i++)
    {
        scanf("%d",&A[i]);
        if(A[i]>max)
        {
            max=A[i];
        }
    }

    for(j=0;j<=max;j++)
    {
        B[j]=0;
    }

    for(i=1;i<=number;i++)
    {
        B[A[i]]=B[A[i]]+1;
    }

    for(j=1;j<=max;j++)
    {
        B[j]=B[j]+B[j-1];
    }

    for(i=number;i>=1;i--)
    {
        C[B[A[i]]]=A[i];
        B[A[i]]=B[A[i]]-1;
    }

    for(i=1;i<=number;i++)
    {
        printf("%d\t",C[i]);
    }
    printf("\n");
}
