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
        new_Node->next=*head;
        new_Node->prev=*head;
        return;
    }
    while(last->next!=nullptr and last->next!=*head){
        last=last->next;
    }
    last->next=new_Node;
    new_Node->prev=last;
    (*head)->prev=new_Node;
}

void deleteData(Node** head,int Data_to_delete){
    Node* first_elem=*head;
    Node* last_elem=(*head)->prev;
    while(first_elem->data!=Data_to_delete){
        first_elem=first_elem->next;
        if(first_elem==*head){
            cout<<"Wrond data to delete"<<endl;
            return;
        }
    }

    if((*head)->data==Data_to_delete){//если нужно удалить первый элемент
        if((*head)->next!=*head){            //
            *head=(*head)->next;      //
            last_elem->next=*head;    //
            (*head)->prev=last_elem;  //
            delete first_elem;        //
        }else{                        //
            *head=nullptr;            //
            delete first_elem;        //
        }                             //
    }else{
        first_elem->prev->next=first_elem->next;
        first_elem->next->prev=first_elem->prev;
        delete first_elem;
    }
}

void display(Node* head,bool reverse = false){
    if(head==nullptr){
        cout<<"Empty LL"<<endl;
        return;
    }
    Node* last=head;
    if(!reverse){
        while(last->next!=head){
            cout<<last->data<<" ";
            last=last->next;
        }
        cout<<last->data<<" ";
        cout<<endl;
    }else{
        last=head->prev;
        while(last!=head){
            cout<<last->data<<" ";
            last=last->prev;
        }
        cout<<last->data<<" ";
        cout<<endl;
    }
}

int CountData(Node* head){
    if(head==nullptr){
        return 0;
    }
    int count=1;
    Node* last=head;
    while(last->next!=head){
        count+=1;
        last=last->next;
    }
    return count;
}

void appendPrev(Node** head, int data,int dataPrev){
    Node* last=*head;
    while(last->data!=dataPrev){
        last=last->next;
        if(last==*head){
            printf("No %d in LL",dataPrev);
            return;
        }
    }
    Node* new_Node = new Node();
    new_Node->data=data;
    new_Node->next=last;
    if(last==*head){
        *head=new_Node;
    }
    new_Node->prev=last->prev;
    last->prev->next=new_Node;
    last->prev=new_Node;
}



int main(){
    Node* main = nullptr;
    append(&main,1);
    append(&main,2);
    append(&main,3);
    append(&main,4);
    appendPrev(&main,90,4);
    display(main);
    display(main,true);
}