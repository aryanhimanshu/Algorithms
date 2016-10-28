#include<iostream>
using namespace std;

void bubbleSort(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int main(){
    int a[5]={4,3,2,1,0};
    bubbleSort(a,5); //bubbleSort(array,size)
    for(int i=0;i<5;i++){
        cout<<a[i]<<"\n";
    }
    return 0;
}
