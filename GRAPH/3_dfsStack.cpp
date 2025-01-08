#include <bits/stdc++.h>
using namespace std;

void photoList(vector<vector<int>>&adj){
    int n = adj.size();
    for(int i = 0;i<n;i++){
        cout<<i<<": ";
        for(auto neighbour:adj[i]){
            cout<<neighbour<<" ";
        }
        cout<<endl;
        
    }

}

void dfsWithStack(vector<vector<int>>&adj , vector<int>&vis, vector<int>&ans,int sNode){
    stack<int>st;
    st.push(sNode);
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            vis[node] = 1;
           ans.push_back(node);  // Add the node to the answer list
        }
        for(auto it :adj[node]){
            if(!vis[it]){
                st.push(it);
            }
        }

    }
}
 
int main()
{
    int T;  // Number of test cases
    cout << "Enter the number of test cases: ";
    cin >> T;
    
    while (T--) {
        int n, m;  // Number of vertices (n) and edges (m)
        cout << "Enter the number of vertices (n) and edges (m): ";
        cin >> n >> m;

        vector<vector<int>> adjList(n);  // Adjacency list
        vector<int> vis(n, 0);  // Visited array to keep track of visited nodes
        vector<int> ans;  // To store the DFS result

        cout << "Enter the edges (u v for an edge between u and v): " << endl;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);  // Assuming an undirected graph
        }
        photoList(adjList);
        int startNode;
        cout << "Enter the starting node: ";
        cin >> startNode;

        dfsWithStack(adjList, vis, ans, startNode);

        cout << "DFS traversal: ";
        for (auto node : ans) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
   
}
