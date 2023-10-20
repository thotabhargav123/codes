#include<bits/stdc++.h>
using namespace std;
void dfs(stack<int>&st, vector<pair<int,int>>adj[], int src, vector<int>&vis){
    vis[src] = 1;
    for(auto j : adj[src]){
        int node = j.first;
        if(vis[node] == 0){
            // vis[node] = 1;
            dfs(st, adj, node, vis);
        }
    }
    st.push(src);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    // Write your code here
    vector<pair<int,int>> adj[n]; 
    for(auto it : edges) {
        adj[it[0]].push_back({it[1], it[2]}); 
    }
    vector<int>dist(n ,1e9);
    // perform toposort to find which nodes can be traversed from the src node.
    stack<int>st;
    vector<int>vis(n, 0);
    dfs(st,adj,0, vis);


    dist[0] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        for(auto j : adj[node]){
            int wt = j.second;
            int temp = j.first;
            if(dist[temp] > dist[node] + wt){
                dist[temp] = dist[node] + wt;
            }
        }
    }

    for(int i =0; i<n; i++){
        if(dist[i] == 1e9){
            dist[i] = -1;
        }
    }

    return dist;
}
