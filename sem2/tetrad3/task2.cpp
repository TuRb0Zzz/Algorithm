#include <iostream>
#include <vector>
using namespace std;



class Maxheap{
    private:
        vector<int> heap;
        void RepairHeap(int i){
            int largest = i;       // Индекс максимума, в первом запуске - корень
            int left = 2 * i + 1;
            int right = 2 * i + 2;
        
            
            if (left < heap.size() && heap[left] > heap[largest]) {
                largest = left;
            }
            
            if (right < heap.size() && heap[right] > heap[largest]) {
                largest = right;
            }
            //если нашли другой максимум
            if (largest != i) {
                std::swap(heap[i], heap[largest]);
                heapifyDown(largest);
            }
        }
    public:
        Maxheap(){}//при создании класса создаётся пустой heap, дополнительное создание не нужно
        Maxheap(vector<int> input_numbers){//конструктор заполняющий кучу
            for(int num:input_numbers){
                insert(num);
            }
        }
        void heapifyDown(int index){
            while (index > 0)
            {
                int parent = (index - 1) / 2;
                if (heap[index] > heap[parent])
                {
                    swap(heap[index], heap[parent]);
                    index = parent;
                }
                else
                    break;
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
        int Max(){
            if(heap.size()!=0){
                return heap[0];
            }
            cout<<"empty"<<endl;
            return 0;
        }
        void DeleteMax(){//заменили максимум последним элементом и восстановили порядок кучи
            heap[0]=heap.back();
            heap.pop_back();
            RepairHeap(0);
        }

};

int main()
{
	vector<int> numbers{9,8,5,6,7,1,4,2,3};
    Maxheap heap(numbers);
    heap.print();
    heap.DeleteMax();
    heap.print();
    heap.DeleteMax();
    heap.print();
	return 0;
}