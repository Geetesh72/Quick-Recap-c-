#include <bits/stdc++.h>
using namespace std;
// DIRECTED GRAPH 
vector<vector<int>>convertToAdjList(vector<vector<int>>&adjMatrix){
    int n = adjMatrix.size();
    vector<vector<int>>adjList(n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(adjMatrix[i][j]==1){
                adjList[i].push_back(j);  // Add edge i -> j
                 // Add edge j ->i 
            }
        }
    }
    return adjList;
}
// FOR UNDIRECTED GRAPH 
vector<vector<int>>convertToAdjListUndirected(vector<vector<int>>&adjMatrix){
    int n = adjMatrix.size();
    vector<vector<int>>adjList(n);
    for(int i = 0;i<n;i++){
        for(int j = 0;i<n;i++){
            if(adjMatrix[i][j]==1 && i!=j){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    return adjList;
}
void printAdjList(vector<vector<int>>& adjList) {
    for (int i = 0; i < adjList.size(); i++) {
        cout << i << ": ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}
int main()
{
     int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> adjMatrix(n, vector<int>(n));
    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjMatrix[i][j];
        }
    }

    vector<vector<int>> adjList = convertToAdjList(adjMatrix);
    vector<vector<int>> adjList2 = convertToAdjListUndirected(adjMatrix);

    cout << "Directed Adjacency List:" << endl;
    printAdjList(adjList);
    cout << "UnDirected Adjacency List:" << endl;
    printAdjList(adjList2);
    
    return 0;
}