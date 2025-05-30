#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Node {
    int start; 
    int end;   
    int sum;   
    int min;   
    int max;   
    int evenCount; 
    int oddCount;
    Node* left;
    Node* right;

    Node(int s, int e) : start(s), end(e), sum(0), min(INT_MAX), max(INT_MIN), evenCount(0), oddCount(0) {}
};


Node* buildSegmentTree(const vector<int>& arr, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    Node* node = new Node(start, end);

    if (start == end) {
        node->sum = arr[start];
        node->min = arr[start];
        node->max = arr[start];
        node->evenCount = (arr[start] % 2 == 0) ? 1 : 0;
        node->oddCount = (arr[start] % 2 != 0) ? 1 : 0;
        return node;
    }

    int mid = (start + end) / 2;
    node->left = buildSegmentTree(arr, start, mid);
    node->right = buildSegmentTree(arr, mid + 1, end);

   
    node->sum = node->left->sum + node->right->sum;
    node->min = min(node->left->min, node->right->min);
    node->max = max(node->left->max, node->right->max);
    node->evenCount = node->left->evenCount + node->right->evenCount;
    node->oddCount = node->left->oddCount + node->right->oddCount;

    return node;
}


void updateNode(Node* node) {
    if (node->left && node->right) {
        node->sum = node->left->sum + node->right->sum;
        node->min = min(node->left->min, node->right->min);
        node->max = max(node->left->max, node->right->max);
        node->evenCount = node->left->evenCount + node->right->evenCount;
        node->oddCount = node->left->oddCount + node->right->oddCount;
    }
}


int querySum(Node* root, int l, int r) {
    if (root == nullptr || l > root->end || r < root->start) {
        return 0; 
    }
    if (l <= root->start && r >= root->end) {
        return root->sum; 
    }
    return querySum(root->left, l, r) + querySum(root->right, l, r); 
}


int queryMin(Node* root, int l, int r) {
    if (root == nullptr || l > root->end || r < root->start) {
        return INT_MAX;
    }
    if (l <= root->start && r >= root->end) {
        return root->min; 
    }
    return min(queryMin(root->left, l, r), queryMin(root->right, l, r)); 
}

int queryMax(Node* root, int l, int r) {
    if (root == nullptr || l > root->end || r < root->start) {
        return INT_MIN; 
    }
    if (l <= root->start && r >= root->end) {
        return root->max; 
    }
    return max(queryMax(root->left, l, r), queryMax(root->right, l, r));
}


void queryEvenOddCount(Node* root, int l, int r, int& evenCount, int& oddCount) {
    if (root == nullptr || l > root->end || r < root->start) {
        return;
    }
    if (l <= root->start && r >= root->end) {
        evenCount += root->evenCount;
        oddCount += root->oddCount;
        return; 
    }
    queryEvenOddCount(root->left, l, r, evenCount, oddCount);
    queryEvenOddCount(root->right, l, r, evenCount, oddCount);
}

int main() {
    int n;
    cout << "Number of elements ";
    cin >> n;

    vector<int> arr(n);
    cout << "Elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Node* root = buildSegmentTree(arr, 0, n - 1);

    int l, r;
    cout << "enter (l, r): ";
    cin >> l >> r;
    cout << "summ on  [" << l << ", " << r << "] = " << querySum(root, l, r) << endl;

    cout << "min on [" << l << ", " << r << "] = " << queryMin(root, l, r) << endl;
    cout << "Max on [" << l << ", " << r << "] = " << queryMax(root, l, r) << endl;

    int evenCount = 0, oddCount = 0;
    queryEvenOddCount(root, l, r, evenCount, oddCount);
    cout << "even on [" << l << ", " << r << "] = " << evenCount << endl;
    cout << "odd on [" << l << ", " << r << "] = " << oddCount << endl;

    return 0;
}