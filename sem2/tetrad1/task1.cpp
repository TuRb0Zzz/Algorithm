#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void append(Node** head,int data){
    Node* new_Node = new Node();
    Node* last = *head;
    new_Node->data=data;
    new_Node->next=nullptr;
    if(*head==nullptr){
        *head=new_Node;
        return;
    }
    while(last->next!=nullptr){
        last=last->next;
    }
    last->next=new_Node;
}

void checkLoop(Node* head){
    Node* one = head;
    Node* two = head;
    do{
        one=one->next;
        two=two->next->next;
    }while(one!=two || one==nullptr || two==nullptr);
    if(one==two){
        cout<<"Loop found"<<endl;
    }else{
        cout<<"No loop found"<<endl;
    }
}
