#include <iostream>
#include <vector>
using namespace std;

struct Node{
    string Name;
    vector<string> PhoneNumbers;
    Node* left;
    Node* right;
};

Node* createNode(string Name, string PhoneNumber){
    Node* new_Node = new Node();
    new_Node->Name = Name;
    new_Node->PhoneNumbers.push_back(PhoneNumber);
    new_Node->left=nullptr;
    new_Node->right=nullptr;
    return new_Node;
}

Node* insert(Node* root, string Name, string PhoneNumber){
    if(!root){
        return createNode(Name,PhoneNumber);
    }
    if(Name==root->Name){
        root->PhoneNumbers.push_back(PhoneNumber);
        return root;
    }
    if(Name<root->Name){
        root->left=insert(root->left,Name,PhoneNumber);
    }else{
        root->right=insert(root->right,Name,PhoneNumber);
    }
    return root;
}

Node* FindData(Node* root, string Name){
    if(root==nullptr){
        return nullptr;
    }
    if(root->Name==Name){
        return root;
    }
    if(Name<root->Name){
        return FindData(root->left,Name);
    }else{
        return FindData(root->right,Name);
    }
}

Node* findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

Node* deleteNode(Node* root, string Name) {
    if (root == nullptr) {
        return nullptr;
    }
    if (Name < root->Name) {
        root->left = deleteNode(root->left, Name);
    } else if (Name > root->Name) {
        root->right = deleteNode(root->right, Name);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        } else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = findMin(root->right);
            root->Name = temp->Name;
            root->PhoneNumbers = temp->PhoneNumbers;
            root->right = deleteNode(root->right, temp->Name);
        }
    }
    return root;
}