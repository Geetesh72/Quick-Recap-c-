#include <iostream>
#include <vector>
using namespace std;

void printAdjList(vector<vector<int>> &adjList) {
    for (int i = 0; i < adjList.size(); i++) {
        cout << i << ": ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cout << "Enter the number of vertices (n) and edges (m): ";
    cin >> n >> m;

    vector<vector<int>> adjList(n);

    cout << "Enter the edges (u v for an edge between u and v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    cout << "Adjacency List:" << endl;
    printAdjList(adjList);

    return 0;
}
