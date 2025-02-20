#include <iostream>
#include <chrono>
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

void insertionSort(int* ar,int size){
        int element;
        int indexArr;
        int j;
        int key=0;
        for(int i = 1; i < size; i++) {
                key=0;
                for( j = i-1; j >= 0; j--) {
                        if (ar[j] < ar[i]) {
                                key=1;
                                element = ar[i];
                                indexArr = j+1;  
                                break;
                        }
                }
                if(key==0){
                     element = ar[i];
                     indexArr = j+1;
                }
                for(  j= i-1; j>=indexArr; j--){
                        ar[ j+1] = ar[ j];
                }
                ar[indexArr] = element; 
        }
}

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

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void quickSort(int* ar, int size) {
	int left = 0;
	int right = size - 1;
	int pivot = ar[size >> 1];

	while(left <= right) {
		while(ar[left] < pivot) {
			left++;
		}
		while (ar[right] > pivot) {
			right--;
		}
		if (left <= right) {
			swap(ar[right], ar[left]);
			right--;
			left++;
		}
	}
	if (right > 0) {
		quickSort(&ar[0], right + 1);
	}

	if (left < size) {
		quickSort(&ar[left], size - left);
	}
}
void (*sortsFunc[4])(int*, int) = {bubbleSort, selectionSort, quickSort, insertionSort};

void sorts(void (*sortName)(int*, int), int* ar, int size) {
    sortName(ar,size);
}

void randomFilling(int* ar,int size,int min,int max){
     srand(time(0));
     for(int p = 0;p < size; p++){
        int num = min + rand() % (max - min + 1);
        ar[p] = num;
    }
}

int main(){
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::chrono::time_point<std::chrono::high_resolution_clock> end;
    chrono::duration<double> diff;
    int size= 100000;
    int* ar = new int[size];
    string array[4]={"bubbleSort","selectionSort","quickSort","insertionSort"};
    for(int i=0;i<size;i++){
        randomFilling(ar,size,0,size);
        start= chrono::high_resolution_clock::now();
        sorts(sortsFunc[i],ar,size);
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        cout<<array[i]<<":\t"<<diff.count()<<endl;
    }
    delete[] ar;
}