#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

struct RangeTreeNode {
    vector<Point> points; 
    RangeTreeNode* left;  
    RangeTreeNode* right;
    RangeTreeNode* yTree; 

    RangeTreeNode() : left(nullptr), right(nullptr), yTree(nullptr) {}
};


RangeTreeNode* buildRangeTree(vector<Point>& points, int start, int end) {
    if (start > end) return nullptr;


    sort(points.begin() + start, points.begin() + end + 1, [](const Point& a, const Point& b) {
        return a.x < b.x;
    });

    int mid = (start + end) / 2;
    RangeTreeNode* node = new RangeTreeNode();
    node->points.push_back(points[mid]);


    vector<Point> yPoints = { points[mid] };
    for (int i = start; i <= end; ++i) {
        if (i != mid) {
            yPoints.push_back(points[i]);
        }
    }
    sort(yPoints.begin(), yPoints.end(), [](const Point& a, const Point& b) {
        return a.y < b.y;
    });


    node->yTree = buildRangeTree(yPoints, 0, yPoints.size() - 1);


    node->left = buildRangeTree(points, start, mid - 1);
    node->right = buildRangeTree(points, mid + 1, end);

    return node;
}


int countPointsInRectangle(RangeTreeNode* root, int xMin, int xMax, int yMin, int yMax) {
    if (root == nullptr) return 0;


    if (root->points[0].x < xMin) {
        return countPointsInRectangle(root->right, xMin, xMax, yMin, yMax);
    }
    if (root->points[0].x > xMax) {
        return countPointsInRectangle(root->left, xMin, xMax, yMin, yMax);
    }


    int count = 0;
    for (const Point& p : root->points) {
        if (p.y >= yMin && p.y <= yMax) {
            count++;
        }
    }

  
    count += countPointsInRectangle(root->left, xMin, xMax, yMin, yMax);
    count += countPointsInRectangle(root->right, xMin, xMax, yMin, yMax);

    return count;
}


int main() {
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    vector<Point> points(n);
    cout << "Enter the dots (x y):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }


    RangeTreeNode* root = buildRangeTree(points, 0, n - 1);

    
    int xMin, xMax, yMin, yMax;
    cout << "Enter the coordinates of the rectangle (x_min, y_min, x_max, y_max): ";
    cin >> xMin >> yMin >> xMax >> yMax;


    int count = countPointsInRectangle(root, xMin, xMax, yMin, yMax);
    cout << "Number of dots in a rectangle: " << count << endl;

    return 0;
}