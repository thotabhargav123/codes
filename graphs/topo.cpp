#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[], int node, stack<int> s, vector<int> &vis)
{
    vis[node] = 1;
    for (auto i : adj[node])
    {
        if (vis[i] == 0)
        {
            dfs(adj, i, s, vis);
        }
    }
    s.push(node);
}
//* khans algo
void bfs(vector<int> adj[], int v, vector<int> &ans)
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

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto i : adj[node])
        {
            indeg[i]--;
            if(indeg[i] == 0){
                q.push(i);
            }
        }
    }
}
int main()
{
    int v;
    vector<int> adj[v];
    vector<int> vis(v, 0);
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if (vis[i] == 0)
        {
            dfs(adj, i, s, vis);
        }
    }
}