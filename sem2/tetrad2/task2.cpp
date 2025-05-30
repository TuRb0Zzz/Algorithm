#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};


int getHeight(Node* node){ // Высота узла
    if(node){
        return node->height;
    }else{
        return 0;
    }
}


int getBalance(Node* node) {// Получение баланса узла(разница между высотами)
    if(node){
        return getHeight(node->left) - getHeight(node->right);
    }else{
        return 0;
    }
}


Node* leftRotate(Node* x) {// Левый поворот
    Node* y = x->right;
    Node* z = y->left;
    y->left = x;
    x->right = z;
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    return y;
}


Node* rightRotate(Node* y) {// Правый поворот
    Node* x = y->left;
    Node* z = x->right;
    x->right = y;
    y->left = z;
    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
    return x;
}

// Создание нового узла
Node* createNode(int key) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;
    return newNode;
}

// Вставка узла
Node* insert(Node* node, int key) {
    if (!node) {
        return createNode(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else{
        node->right = insert(node->right, key);
    }    

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    // L
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    // R
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    // LR
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inorder(Node* node) {//обход
    if (node != nullptr) {
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }
}


void DeleteMemory(Node* node) { //ф-ц для чистки памяти всего дерева.
    if (node != nullptr) {
        DeleteMemory(node->left);
        DeleteMemory(node->right);
        delete node;
    }
}

int main() {
    Node* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    inorder(root);
    std::cout << std::endl;

    DeleteMemory(root);

    return 0;
}