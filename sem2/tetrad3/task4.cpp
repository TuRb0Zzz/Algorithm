#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinHeap {//переписанны класс из прошлого задания
private:
    vector<int> heap;

    void heapifyDown(int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[i] < heap[parent]) {
                swap(heap[i], heap[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }

public:
    MinHeap() {}

    MinHeap(const vector<int>& nums) {
        for (int num : nums) {
            insert(num);
        }
    }

    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {//удаление + вывод , две функции из прошлого задания
        if (heap.empty()) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minVal;
    }

    int size(){
        return heap.size();
    }

    bool empty(){
        return heap.empty();
    }

    void print(){
        for (int num : heap) {
            cout << num << " ";
        }
        cout << endl;
    }
};

void ropeConnectingProblem(vector<int>& ropes) {
    if (ropes.empty()) {
        cout << "No ropes to connect!" << endl;
        return;
    }

    MinHeap minHeap(ropes);
    int totalCost = 0;
    vector<pair<int, int>> steps;

    while (minHeap.size() > 1) {
        int first = minHeap.extractMin();
        int second = minHeap.extractMin();
        int cost = first + second;
        totalCost += cost;
        minHeap.insert(cost);
        steps.push_back({first, second});
    }

    for (size_t i = 0; i < steps.size(); ++i) {
        cout << "Step " << i + 1 << ": Connect " << steps[i].first << " and " << steps[i].second 
             << " (cost: " << steps[i].first + steps[i].second << ")" << endl;
    }
    cout << "Total cost: " << totalCost << endl;
}

int main() {
    vector<int> ropes = {4, 3, 2, 6};
    ropeConnectingProblem(ropes);
    return 0;
}