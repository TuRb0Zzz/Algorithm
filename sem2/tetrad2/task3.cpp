#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

int getHeight(Node* node) { // Высота узла
    if (node) {
        return node->height;
    } else {
        return 0;
    }
}

int getBalance(Node* node) { // Получение баланса узла (разница между высотами)
    if (node) {
        return getHeight(node->left) - getHeight(node->right);
    } else {
        return 0;
    }
}

Node* leftRotate(Node* x) { // Левый поворот
    Node* y = x->right;
    Node* z = y->left;
    y->left = x;
    x->right = z;
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    return y;
}

Node* rightRotate(Node* y) { // Правый поворот
    Node* x = y->left;
    Node* z = x->right;
    x->right = y;
    y->left = z;
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
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
    } else {
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

Node* deleteNode(Node* root, int key) {// Удаление элемента, функция из прошлых тетрадей
    if (!root) {                       // с добавлением в конец проверки на баланс 
                                       // и если надо поворотов
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {

        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;


            if (!temp) {
                temp = root;
                root = nullptr;
            } else { 
                *root = *temp;
            }
            delete temp;
        } else {
            Node* temp = root->right;
            while (temp->left) {
                temp = temp->left;
            }

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (!root) {
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root );

    // L
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    // LR
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // R
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    // RL
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(Node* node) { // Обход
    if (node != nullptr) {
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }
}

void DeleteMemory(Node* node) { // Функция для чистки памяти всего дерева
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
    cout << endl;

    root = deleteNode(root, 30);

    inorder(root);
    cout << endl;

    DeleteMemory(root);

    return 0;
}