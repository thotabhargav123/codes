#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(vector<vector<int>> &edge, int n, int edges, int src)
{
    // Write your code here.
    // 'edge' contains {u, v, distance} vectors.
    vector<pair<int, int>> adj[n];
    for (auto it : edge)
    {

        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    vector<int> dis(n, 1e9);
    dis[src] = 0;
    while (!pq.empty())
    {
        auto i = pq.top();
        pq.pop();
        int node = i.second;
        int dc = i.first;
        for (auto j : adj[node])
        {
            int temp = j.first;
            int wt = j.second;
            if (dis[temp] > dc + wt)
            {
                dis[temp] = dc + wt;
                pq.push({dc + wt, temp});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (dis[i] == 1e9)
        {
            dis[i] = -1;
        }
    }

    return dis;
}
int main()
{
    // done using pq;
    // pq contains dis, node as pair min heap min at top.
}