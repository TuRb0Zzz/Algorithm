#include <iostream>
#include <vector>
using namespace std;


struct Node {
    int start;
    int end;  
    Node* left;   
    Node* right;
};

Node* buildSegmentTree(const vector<pair<int, int>>& intervals, int left, int right) {
    if (left > right) {
        return nullptr;
    }
    Node* node = new Node();
    node->start=intervals[left].first;
    node->end=intervals[left].second;
    node->left=nullptr;
    node->right=nullptr;
    node->left = buildSegmentTree(intervals, left + 1, right);
    node->right = buildSegmentTree(intervals, left + 1, right);
    return node;
}

void inOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    cout << "[" << root->start << ", " << root->end << "] ";
    inOrderTraversal(root->right);
}

int countIntervalsContainingPoint(Node* root, int x) {  
    if (root == nullptr) {
        return 0;
    }
    int count = 0;
    if (x >= root->start && x <= root->end) {
        count++;
    }
    count += countIntervalsContainingPoint(root->left, x);
    count += countIntervalsContainingPoint(root->right, x);
    return count;
}

int main() {
    vector<pair<int, int>> intervals = {{1, 5}, {2, 6}, {3, 7}, {4, 8}, {5, 9}};
    Node* root = buildSegmentTree(intervals, 0, intervals.size() - 1);
    int x;
    cin >> x;
    int count = countIntervalsContainingPoint(root, x);
    cout << "Number of intervals "<< count << endl;
    return 0;
}


