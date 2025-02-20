#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

void append(Node** head,int data){
    Node* new_Node = new Node();
    Node* last = *head;
    new_Node->data=data;
    new_Node->next=*head;
    if(*head==nullptr){
        *head=new_Node;
        new_Node->prev=nullptr;
        return;
    }
    while(last->next!=nullptr and last->next!=*head){
        last=last->next;
    }
    last->next=new_Node;
    new_Node->prev=last;
    (*head)->prev=new_Node;
}


int main(){
    Node* main = nullptr;
    append(&main,1);
    append(&main,2);
    append(&main,3);
    append(&main,4);
    return 0;
}