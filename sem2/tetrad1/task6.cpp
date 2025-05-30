#include <iostream>
#include <ctime>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data){
    Node* new_Node = new Node();
    new_Node->data=data;
    new_Node->left=nullptr;
    new_Node->right=nullptr;
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
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

int depth(Node* root){
    if(root==nullptr){
        return 0;
    }else{
        int left=depth(root->left);
        int right=depth(root->right);
        return max(left,right)+1;
    }
}

bool FindData(Node* root, int data){
    if(root==nullptr){
        return false;
    }
    if(root->data==data){
        return true;
    }
    if(data<root->data){
        return FindData(root->left,data);
    }else{
        return FindData(root->right,data);
    }
}

void fillTree(Node** root, int size){
    srand(time(0));
    for(int i=0;i<size;i++){
        int num = rand()%100;
        *root = insert(*root,num);
    }
}

Node* FindMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

Node* DeleteNode(Node* root, int data) {
    if (root == nullptr) {
        return root;
    }

    if (data < root->data) {
        root->left = DeleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = DeleteNode(root->right, data);
    } else {

        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = FindMin(root->right); 
        root->data = temp->data;
        root->right = DeleteNode(root->right, temp->data);
    }
    return root;
}

int main(){
    Node* root=nullptr;
    fillTree(&root,5);
    preorder(root);
    return 0;
}
