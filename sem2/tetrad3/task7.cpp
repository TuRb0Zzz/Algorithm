#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;


struct Task {
    string name;
    int priority;
    
    bool operator<(const Task& other) const {//переопределил меньше больше для простоты обращения к приоритету
        return priority < other.priority;
    }
    
    bool operator>(const Task& other) const {
        return priority > other.priority;
    }
};

class PriorityQueue {
    private:
        vector<Task> heap;
        
        void siftUp(int index) {
            while (index > 0) {
                int parent = (index - 1) / 2;
                if (heap[index] > heap[parent]) {
                    swap(heap[index], heap[parent]);
                    index = parent;
                } else {
                    break;
                }
            }
        }
        
        void siftDown(int index) {
            int left, right, largest;
            while (true) {
                left = 2 * index + 1;
                right = 2 * index + 2;
                largest = index;
                
                if (left < heap.size() && heap[left] > heap[largest]) {
                    largest = left;
                }
                
                if (right < heap.size() && heap[right] > heap[largest]) {
                    largest = right;
                }
                
                if (largest != index) {
                    swap(heap[index], heap[largest]);
                    index = largest;
                } else {
                    break;
                }
            }
        }

    public:
        PriorityQueue() {}
        
        void insert(const Task& task) {
            heap.push_back(task);
            siftUp(heap.size() - 1);
        }
        
        // Извлечение задачи с наивысшим приоритетом
        Task dequeue() {
            if (isEmpty()) {
                throw out_of_range("Очередь пуста");
            }
            
            Task result = heap[0];
            heap[0] = heap.back();
            heap.pop_back();
            
            if (!isEmpty()) {
                siftDown(0);
            }
            
            return result;
        }

        int findTaskIndex(const string& name) {
            for (int i = 0; i < heap.size(); ++i) {
                if (heap[i].name == name) {
                    return i;
                }
            }
            return -1;
        }

        Task check(){
            if (isEmpty()) {
                throw out_of_range("Очередь пуста");
            }
            return heap[0];
        }
        
        bool isEmpty() const {
            return heap.empty();
        }
        
        // Редактирование задачи
        bool editTask(const string& oldName, const string& newName, int newPriority) {
            int index = findTaskIndex(oldName);
            if (index == -1) return false;
            
            heap[index].name = newName;
            int oldPriority = heap[index].priority;
            heap[index].priority = newPriority;
            
            if (newPriority > oldPriority) {
                siftUp(index);
            } else if (newPriority < oldPriority) {
                siftDown(index);
            }
            
            return true;
        }
    
        void display(){
            if (isEmpty()) {
                cout << "no tasks" << endl;
                return;
            }
            
            cout << "tasks:" << endl;
            for (const auto& task : heap) {
                cout << "- " << task.name << " (priority: " << task.priority << ")" << endl;
            }
        }
    };

int main() {
    PriorityQueue todoList;
    Task Task1;
    Task1.name="feed cat";
    Task1.priority=1;
    Task Task2;
    Task2.name="go to mirea";
    Task2.priority=2;
    Task Task3;
    Task3.name="go home";
    Task3.priority=3;
    todoList.insert(Task1);
    todoList.insert(Task2);
    todoList.insert(Task3);
    todoList.display();
    todoList.editTask("go home","go to shop",5);
    todoList.display();
    return 0;
}