#include <iostream>
#include <vector>
using namespace std;

// Function to print the adjacency matrix
void printAdjMatrix(vector<vector<int>> &matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m; // Number of vertices and edges
    cout << "Enter the number of vertices (n) and edges (m): ";
    cin >> n >> m;

    // Initialize adjacency matrix with zeros
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    cout << "Enter the edges (u v for an edge between u and v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // Assuming an undirected graph
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    cout << "Adjacency Matrix:" << endl;
    printAdjMatrix(adjMatrix);

    return 0;
}

/*  MY UNDERSTANDING 
    n -> how many node 
    m -> how many vertex 
    why run till m ,quite tricky but easy so we have to mark one when we got u ,v from either side 
    then we will take input u and v with node to with node (u----->v)
    then we will map v to u for connect man simple (v---------->u) 

*/
