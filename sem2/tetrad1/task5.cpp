#include <iostream>
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

void ReadFromConsole(Node** main){
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
        append(main,i);
    }
}

void WorkWithNode(Node* first,Node* second,Node** answer){
    bool EndFirst=false;
    bool EndSecond=false;
    int data_first;
    int data_second;
    int buffer=0;
    int summa=0;
    while(first!=nullptr or second!=nullptr){

        if(first==nullptr){
            EndFirst=true;
        }
        if(second==nullptr){
            EndSecond=true;
        }

        if(!EndFirst){
            data_first=first->data;
            first=first->next;
        }else{
            data_first=0;
        }

        if(!EndSecond){
            data_second=second->data;
            second=second->next;
        }else{
            data_second=0;
        }

        summa=data_first+data_second+buffer;
        if(summa>=10 and (first!=nullptr or second!=nullptr)){
            append(answer,summa%10);
            buffer=(summa-(summa%10))/10;
        }else{
            if(summa>=10){
                if(first==nullptr and second==nullptr){
                    append(answer,summa%10);
                    append(answer,(summa-(summa%10))/10);
                }
            }else{
                append(answer,summa);
            }
        }
    }
}

void display(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main(){
    Node* first=nullptr;
    Node* second=nullptr;
    Node* answer=nullptr;
    ReadFromConsole(&first);
    ReadFromConsole(&second);
    WorkWithNode(first,second,&answer);
    display(answer);
    return 0;
}