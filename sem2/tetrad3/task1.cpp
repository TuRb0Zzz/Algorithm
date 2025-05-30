#include <iostream>
#include <vector>
using namespace std;

vector<int> heap;

void heapifyDown(int index)
{
    while (index > 0){
        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent]){
            swap(heap[index], heap[parent]);
            index = parent;
        }else{
            break;
        }
    }
}

void insert(int value){
    heap.push_back(value);
    heapifyDown(heap.size() - 1);
}

void print(){
    for (int v : heap)
        cout << v << " ";
    cout << endl;
}

int main(){
	vector<int> numbers{11,5,8,3,4};
    for(int num:numbers){
        insert(num);
    }
	print();
	return 0;
}