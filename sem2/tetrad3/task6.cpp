#include <iostream>
using namespace std;


struct Node {
    int data;
    int priority;
    Node* next;
};

class PriorityQueue {
private:
    Node* head;
public:
    PriorityQueue(){
        head=nullptr; 
    }
    
    // Деструктор для подчистки памяти
    ~PriorityQueue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    void insert(int data, int priority) {
        Node* newNode = new Node;
        newNode->data=data;
        newNode->priority=priority;
        
        if (head == nullptr || priority < head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr && current->next->priority <= priority) {
                current = current->next;
            }
            
            // Вставляем новый узел
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    
    int takeElement() {
        if (head==nullptr) {
            cout<<"empty"<<endl;
            return -1;
        }
        Node* temp = head;
        int value = temp->data;
        head = head->next;
        delete temp;
        return value;//высший приоритет в корне, достали, корень передвинули вперёд
    }
    
    int check(){
        if (head==nullptr) {
            cout<<"empty"<<endl;
            return -1;
        }
        return head->data;
    }
    
    void display(){
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << "(priority: " << current->priority << ") ";
            current = current->next;
        }
        cout << endl;
    }
    bool isEmpty(){
        return head==nullptr;
    }
};

int main() {
    PriorityQueue pq;
    
    // Добавляем элементы с разными приоритетами
    pq.insert(10, 1);
    pq.insert(20, 3);
    pq.insert(30, 2);
    pq.insert(40, 5);
    
    pq.display();
    
    while (!pq.isEmpty()) {
        cout << "element: " << pq.takeElement() << endl;
    }
    
    return 0;
}