#include <bits/stdc++.h>
using namespace std;
bool bfs(vector<int> &vis, vector<int> adj[], int node, int V)
{
    vis[node] = 1;
    vector<int> parent(V, -1);
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (auto i : adj[temp])
        {
            if (vis[i] == 1 and parent[temp] != i)
            {
                return true;
            }
            else if (vis[i] == 0)
            {
                vis[i] = 1;
                parent[i] = temp;
                q.push(i);
            }
        }
    }
    return false;
}

bool dfs(vector<int> &vis, vector<int> adj[], int val, int parent)
{
    vis[val] = 1;
    for (auto i : adj[val])
    {
        if (vis[i] == 0)
        {
            bool ans = dfs(vis, adj, i, val);
            if (ans == true)
            {
                return true;
            }
        }
        else if (vis[i] == 1 and parent != i)
        {
            return true;
        }
    }

    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    // Code here
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
        {
            // if(bfs(vis, adj, i, V) == true){
            //     return true;
            // }
            if (dfs(vis, adj, i, -1) == true)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    // create a udg and call iscycle to get results.
}