#include <queue>
#include <climits>

using namespace std;

//дерево
struct Node {
    int val;
    Node* left;
    Node* right;
};

bool isMaxHeap(Node* root) {//проверка на макс кучу
    if (!root) return true;
    
    bool leftOK = (!root->left) || (root->val >= root->left->val && isMaxHeap(root->left));
    bool rightOK = (!root->right) || (root->val >= root->right->val && isMaxHeap(root->right));
    
    return leftOK && rightOK;
}


bool isMinHeap(Node* root) {//проверка на мин кучу
    if (!root) return true;
    
    bool leftOK = (!root->left) || (root->val <= root->left->val && isMinHeap(root->left));
    bool rightOK = (!root->right) || (root->val <= root->right->val && isMinHeap(root->right));
    
    return leftOK && rightOK;
}


bool isBinaryHeap(Node* root) {
    if (!root) return true;
    return isMaxHeap(root) || isMinHeap(root);
}