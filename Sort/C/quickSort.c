#include <stdio.h>
#include <stdlib.h>

void swap(int *a1, int *a2){
    int tmp;
    tmp = *a1;

    *a1 = *a2;
    *a2 = tmp;
}

int standardPartition(int *a, int p, int r){
    int x = a[r];
    int i,j;

    i = p-1;

    for(j=p; j<r; j++){
        if(a[j] <= x){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[r]);

    return i+1;
}

void standarQuicksort(int *a, int p, int r){
    int q;
    if(p<r){
        q = standardPartition(a,p,r);
        standarQuicksort(a,p,q-1);
        standarQuicksort(a,q+1,r);
    }
}

void printArray(int *a, int l, int u){
    int i;
    for(i=l; i<u; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(){

    int a[10] = {9,6,7,8,4,5,6,7,3,0};

    standarQuicksort(a,0,9);
    printArray(a,0,9);

    return 0;
}
