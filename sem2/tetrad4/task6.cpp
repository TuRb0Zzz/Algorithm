#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task {
    int start, end;
};

// Жадный алгоритм выбора непересекающихся задач
vector<Task> selectMaxTasks(vector<Task>& tasks) {
    sort(tasks.begin(), tasks.end(),[](const Task& a, const Task& b){
        return a.end < b.end;
    });

    vector<Task> selected;
    int lastEndTime = -1;

    for (const Task& task : tasks) {
        if (task.start >= lastEndTime) {
            selected.push_back(task);
            lastEndTime = task.end;
        }
    }
    return selected;
}

int main() {
    vector<Task> tasks = {
        {1, 3},
        {2, 5},
        {3, 6},
        {5, 7},
        {8, 9}
    };

    vector<Task> selected = selectMaxTasks(tasks);

    cout << "max number of tasks: " << selected.size() << endl;
    cout << "selected tasks:" << endl;
    for (const Task& task : selected) {
        cout << "[" << task.start << ", " << task.end << "]" << endl;
    }

    return 0;
}