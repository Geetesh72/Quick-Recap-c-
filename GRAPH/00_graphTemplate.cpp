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

    return 0;
}