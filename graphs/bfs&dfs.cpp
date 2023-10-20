// bfs
#include <bits/stdc++.h>
using namespace std;
//dfs
void dfs(vector<int> adj[], int node, vector<int> &vis, vector<int> &ans)
{
    vis[node] = 1;
    ans.push_back(node);
    for (auto i : adj[node])
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            dfs(adj, i, vis,  ans);
        }
    }
    return;
}
int main()
{
    vector<int> adj[5];

    // for udg.
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(4);

    adj[3].push_back(1);
    adj[3].push_back(2);

    adj[4].push_back(1);

    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[1].push_back(2);

    adj[2].push_back(1);
    adj[2].push_back(0);
    adj[2].push_back(3);

    // for dg
    // adj[0].push_back(3);
    // adj[0].push_back(2);

    // adj[1].push_back(0);

    // adj[2].push_back(1);
    // adj[2].push_back(3);

    vector<int> vis(5, 0);
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int node = q.front();
        cout << node << " ";
        q.pop();
        for (auto i : adj[node])
        {
            if (vis[i] == 0)
            {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
}