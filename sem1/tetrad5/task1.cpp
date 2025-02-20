#include <iostream>
using namespace std;

void bubbleSort(int* ar,int size){
    int num;
    for(int s=size;s>0;s--){
        for(int i=0;i<size-1;i++){
            if (ar[i]>ar[i+1]){
                num = ar[i];
                ar[i]=ar[i+1];
                ar[i+1]=num;
            }
        }
    }
}

int main(){
    int* ar = new int[50];
    for(int i=0; i<50;i++){
        ar[i]=50-i;
    }
    bubbleSort(ar,50);
    for(int i=0;i<50;i++){
        cout<<ar[i]<<" ";
    }
    return 0;
}