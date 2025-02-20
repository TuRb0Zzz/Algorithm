#include <iostream>
using namespace std;

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

int main(){
    int* ar = new int[50];
    for(int i=0; i<50;i++){
        ar[i]=50-i;
    }
    for(int i=0;i<50;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    quickSort(ar,50);
    for(int i=0;i<50;i++){
        cout<<ar[i]<<" ";
    }
    return 0;
}