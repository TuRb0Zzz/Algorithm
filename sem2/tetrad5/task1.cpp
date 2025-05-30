#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>

using namespace std;

class Graph {
private:
    int vertexCount;
    vector<vector<int>> adjacencyMatrix;

    void buildFromAdjacencyMatrix() {
        cout << "Введите матрицу смежности (" << vertexCount << "x" << vertexCount << "):\n";
        adjacencyMatrix.resize(vertexCount, vector<int>(vertexCount, 0));
        
        for (int i = 0; i < vertexCount; ++i) {
            for (int j = 0; j < vertexCount; ++j) {
                cin >> adjacencyMatrix[i][j];
            }
        }
    }

    void buildFromIncidenceMatrix(int edgeCount) {
        cout << "Введите матрицу инцидентности (" << vertexCount << "x" << edgeCount << "):\n";
        vector<vector<int>> incidenceMatrix(vertexCount, vector<int>(edgeCount, 0));
        
        for (int i = 0; i < vertexCount; ++i) {
            for (int j = 0; j < edgeCount; ++j) {
                cin >> incidenceMatrix[i][j];
            }
        }
        
        // Преобразование в матрицу смежности
        adjacencyMatrix.resize(vertexCount, vector<int>(vertexCount, 0));
        for (int j = 0; j < edgeCount; ++j) {
            int from = -1, to = -1;
            for (int i = 0; i < vertexCount; ++i) {
                if (incidenceMatrix[i][j] == 1) {
                    if (from == -1) from = i;
                    else to = i;
                } else if (incidenceMatrix[i][j] == -1) {
                    to = i;
                } else if (incidenceMatrix[i][j] == 2) {
                    // Петля
                    from = to = i;
                }
            }
            if (from != -1 && to != -1) {
                adjacencyMatrix[from][to] = 1;
                // Для неориентированного графа
                adjacencyMatrix[to][from] = 1;
            }
        }
    }

public:
    Graph() : vertexCount(0) {}

    void readGraph() {
        int choice;
        cout << "Выберите способ задания графа:\n";
        cout << "1. Матрица смежности\n";
        cout << "2. Матрица инцидентности\n";
        cin >> choice;

        cout << "Введите количество вершин: ";
        cin >> vertexCount;

        if (choice == 1) {
            buildFromAdjacencyMatrix();
        } else if (choice == 2) {
            int edgeCount;
            cout << "Введите количество ребер: ";
            cin >> edgeCount;
            buildFromIncidenceMatrix(edgeCount);
        } else {
            cout << "Неверный выбор.\n";
            vertexCount = 0;
        }
    }

    vector<int> BFS(int startVertex) {
        vector<int> traversalOrder;
        if (vertexCount == 0) return traversalOrder;

        vector<bool> visited(vertexCount, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            traversalOrder.push_back(current);

            for (int i = 0; i < vertexCount; ++i) {
                if (adjacencyMatrix[current][i] && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        return traversalOrder;
    }

    vector<int> DFS(int startVertex) {
        vector<int> traversalOrder;
        if (vertexCount == 0) return traversalOrder;

        vector<bool> visited(vertexCount, false);
        stack<int> s;

        s.push(startVertex);

        while (!s.empty()) {
            int current = s.top();
            s.pop();

            if (!visited[current]) {
                visited[current] = true;
                traversalOrder.push_back(current);

                // Для корректного порядка обхода добавляем вершины в обратном порядке
                for (int i = vertexCount - 1; i >= 0; --i) {
                    if (adjacencyMatrix[current][i] && !visited[i]) {
                        s.push(i);
                    }
                }
            }
        }

        return traversalOrder;
    }

    void printAdjacencyMatrix() {
        cout << "Матрица смежности:\n";
        for (int i = 0; i < vertexCount; ++i) {
            for (int j = 0; j < vertexCount; ++j) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Graph graph;
    graph.readGraph();

    int choice;
    cout << "Выберите алгоритм обхода:\n";
    cout << "1. Поиск в глубину (DFS)\n";
    cout << "2. Поиск в ширину (BFS)\n";
    cin >> choice;

    int startVertex;
    cout << "Введите начальную вершину (0-" << (graph.printAdjacencyMatrix(), 0) << "): ";
    cin >> startVertex;

    vector<int> traversalOrder;
    if (choice == 1) {
        traversalOrder = graph.DFS(startVertex);
        cout << "Порядок обхода DFS: ";
    } else if (choice == 2) {
        traversalOrder = graph.BFS(startVertex);
        cout << "Порядок обхода BFS: ";
    } else {
        cout << "Неверный выбор.\n";
        return 1;
    }

    for (int vertex : traversalOrder) {
        cout << vertex << " ";
    }
    cout << "\n";

    return 0;
}