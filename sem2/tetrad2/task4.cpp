#include <iostream>

using namespace std;


struct Node {
    int data;
    char color;
    Node* left;
    Node* right;
    Node* parent;
};

// Функция для создания нового узла
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->color = 'R'; // Новый узел всегда красный
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->parent = nullptr;
    return newNode;
}

Node* leftRotate(Node* root, Node* x) {
    Node* y = x->right;
    x->right = y->left;

    if (y->left != nullptr) {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;

    return root;
}

Node* rightRotate(Node* root, Node* y) {
    Node* x = y->left;
    y->left = x->right;

    if (x->right != nullptr) {
        x->right->parent = y;
    }

    x->parent = y->parent;

    if (y->parent == nullptr) {
        root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    x->right = y;
    y->parent = x;

    return root;
}

Node* balanceAfterInsert(Node* root, Node* newNode) {
    Node* parent = nullptr;
    Node* grandparent = nullptr;

    while ((newNode != root) && (newNode->color == 'R') && (newNode->parent->color == 'R')) {
        parent = newNode->parent;
        grandparent = parent->parent;
        if (parent == grandparent->left) {
            Node* uncle = grandparent->right;


            if (uncle != nullptr && uncle->color == 'R') {
                grandparent->color = 'R';
                parent->color = 'B';
                uncle->color = 'B';
                newNode = grandparent;
            } else {
                if (newNode == parent->right) {
                    root = leftRotate(root, parent); 
                    newNode = parent;
                    parent = newNode->parent;
                }
                root = rightRotate(root, grandparent); 
                swap(parent->color, grandparent->color); 
                newNode = parent; 
            }
        } else { 
            Node* uncle = grandparent->left;

            // Случай 1: Дядя красный
            if (uncle != nullptr && uncle->color == 'R') {
                grandparent->color = 'R';
                parent->color = 'B';
                uncle->color = 'B';
                newNode = grandparent; // Поднимаемся на уровень выше
            } else {
                if (newNode == parent->left) {
                    root = rightRotate(root, parent); 
                    newNode = parent;
                    parent = newNode->parent;
                }
                root = leftRotate(root, grandparent); 
                swap(parent->color, grandparent->color); 
                newNode = parent; 
            }
        }
    }
    root->color = 'B';
    return root;
}

Node* insert(Node* root, int value) {
    Node* newNode = createNode(value);
    if (!root) {
        newNode->color = 'B';
        return newNode;
    }

    Node* parent = nullptr;
    Node* current = root;

    while (current) {
        parent = current;
        if (value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    newNode->parent = parent;
    if (value < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    root = balanceAfterInsert(root, newNode);
    return root;
}



int countBlackHeight(Node* node) {
    if (!node){
       return 1;  
    } 
    int count=0; 
    if(node->color == 'B'){
        count =1;
    }else{
        count = 0;
    }
    return count + countBlackHeight(node->left) + countBlackHeight(node->right);
}


bool isBalanced(Node* node) {// првоерка на баланс дерева
    if (!node) return true;
    int leftBlackHeight = countBlackHeight(node->left);
    int rightBlackHeight = countBlackHeight(node->right);
    return leftBlackHeight == rightBlackHeight && isBalanced(node->left) && isBalanced(node->right);
}


bool isProperColoring(Node* node) {// проверка цветов
    if (!node) return true;
    if (node->color == 'R') {
        if ((node->left && node->left->color == 'R') || (node->right && node->right->color == 'R')) {
            return false;
        }
    }
    return isProperColoring(node->left) && isProperColoring(node->right);
}


bool isRedBlackTree(Node* root) {//ф-ц для проврки на баланс и расскраску
    return isBalanced(root) && isProperColoring(root);
}


void deleteTree(Node* node) {// Освобождение памяти
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

int main() {
    Node* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 15);
    root = insert(root, 25);

    if (isRedBlackTree(root)) {
        cout << "read black tree." << endl;
    } else {
        cout << "is not red- black tree" << endl;
    }

    deleteTree(root);

    return 0;
}