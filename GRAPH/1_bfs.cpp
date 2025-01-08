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
vector<int>bfs(vector<vector<int>>&adj,vector<int>&vis){
    vector<int>ans;
    queue<int>q;
    vis[0]=1;
    q.push(0);
    
    while(!q.empty()){
        int node  = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return ans;

}
int main()
{
    int n ,m;
    cout<<"Enter the Number ot vertices(n) and edges(m): ";
    cin>>n>>m;
    vector<vector<int>>adjList(n);
    cout<<"Enter the edge(u v for and edge between u and v): "<<endl;
    for(int i =0;i<m;i++){
        int u , v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    cout<<"List "<<endl;
    photoList(adjList);

    vector<int> vis(n, 0); // visited array
    vector<int> bfsResult = bfs(adjList, vis);

    // Print BFS result
    cout << "BFS Traversal: ";
    for (int node : bfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}