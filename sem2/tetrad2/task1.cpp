#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    int balans;
};

Node* createNode(int data){
    Node* new_Node = new Node();
    new_Node->data=data;
    new_Node->left=nullptr;
    new_Node->right=nullptr;
    new_Node->balans=0;
    return new_Node;
}

Node* insert(Node* root, int data){
    if(!root){
        return createNode(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }else{
        root->right=insert(root->right,data);
    }
    return root;
}

void preorder(Node* root){
    if(root){
        cout<<root->data<<" "<<root->balans<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}

int GetBalans(Node* root){
    if(root==nullptr){
        return 0;
    }else{
        int left=GetBalans(root->left)+1;
        int right=GetBalans(root->right)+1;
        root->balans=right-left;
        return max(left,right); 
    }
}

int main(){
    Node* head = nullptr;
    head = insert(head,2);
    head = insert(head,1);
    head = insert(head,3);
    head = insert(head,4);
    head = insert(head,5);
    GetBalans(head);
    preorder(head);
    return 0;
}