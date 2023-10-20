#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<int> adj[], vector<int> &vis, vector<int> &dfsv, int node)
{
    vis[node] = 1;
    dfsv[node] = 1;
    for (auto i : adj[node])
    {
        if (vis[i] == 1 and dfsv[i] == 1)
        {
            return true;
        }
        else if (vis[i] == 0)
        {
            bool ans = dfs(adj, vis, dfsv, i);
            if (ans == true)
            {
                return true;
            }
        }
    }
    dfsv[node] = 0;
    return false;
}
// done using the khans algo or topo sort implementation.
bool bfs(vector<int> adj[], int v)
{
    vector<int> indeg(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (auto j : adj[i])
        {
            indeg[j]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto i : adj[node])
        {
            indeg[i]--;
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }
    }
    if (ans.size() != v)
    {
        return true;
    }

    return false;
}
bool isCyclic(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    vector<int> adj[v];
    for (int i = 0; i < e; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int> vis(v, 0);
    vector<int> dfsv(v, 0);

    for (int i = 0; i < v; i++)
    {
        if (vis[i] == 0)
        {
            if (dfs(adj, vis, dfsv, i) == true)
            {
                return true;
            }
        }
    }
    return false;
}
