#include <iostream>
using namespace std;

void selectionSort(int* ar,int size){
    int tmpMax;
    int nb;
    int tmp;
    int bufer;
    for(int i=0;i<size;i++){
        tmpMax=ar[i];
        nb=i;
        tmp=i;
        for (int j=i+1;j<size;j++){
            if(tmpMax>ar[j]){
                tmpMax=ar[j];
                tmp=j;
            }
        }
         
        bufer=ar[nb];
        ar[nb]=ar[tmp];
        ar[tmp]=bufer;
    }
}


int main(){
    int* ar = new int[50];
    for(int i=0; i<50;i++){
        ar[i]=50-i;
    }
    for(int i=0;i<50;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    selectionSort(ar,50);
    for(int i=0;i<50;i++){
        cout<<ar[i]<<" ";
    }
    return 0;
}
