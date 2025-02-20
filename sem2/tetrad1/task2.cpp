#include <iostream>
#include <string> 
#include <vector>
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

void display(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

void solve(Node* main,int x){
    Node* men=nullptr;
    Node* bol=nullptr;
    while(main!=nullptr){
        if( main->data<x){
            append(&men,main->data);
        }else{
            append(&bol,main->data);
        }
        main=main->next;
    }
    display(men);
    display(bol);
}

int main(){
    Node* main = nullptr;
    int x;
    int number;
    vector<int> a;
    string s;
    getline(cin,s);
    string buffernumber="";
    for(int i=0;i<s.size();i++){
        if(s[i]!=' '){
            buffernumber+=s[i];
        }else{
            a.push_back(stoi(buffernumber));
            buffernumber="";
        }
    }
    a.push_back(stoi(buffernumber));
    for(int i:a){
        append(&main,i);
    }
    cin>>x;
    solve(main,x);
    return 0;
}