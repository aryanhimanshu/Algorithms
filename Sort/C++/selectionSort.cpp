#include<iostream>
using namespace std;

void selectionSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int mini=a[i];
        int loc=i;
        for(int j=i+1;j<n;j++){
            if(mini>a[j]){
                mini=a[j];
                loc=j;
            }
        }
        int temp=a[i];
        a[i]=a[loc];
        a[loc]=temp;
    }
}

int main(){
    int a[5]={0,1,2,3,4};
    selectionSort(a,5); //selectionSort(array,size)
    for(int i=0;i<5;i++){
        cout<<a[i]<<"\n";
    }
    return 0;
}
