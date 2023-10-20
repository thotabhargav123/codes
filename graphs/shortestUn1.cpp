#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {
    // Write your code here.
     vector<int> adj[n]; 
    for(auto it : edges) {
        adj[it[0]].push_back(it[1]); 
        adj[it[1]].push_back(it[0]); 
    }

    vector<int>dis(n, -1);
    dis[src] = 0;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i : adj[node]){
            if(dis[i] == -1){
                dis[i] = dis[node]+1;
                q.push(i);
            }
        }
    }
    
    return dis;
}