#include <bits/stdc++.h>
using namespace std;
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges)
{

    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    for (int i = 0; i < n; ++i)
    {
        dist[i][i] = 0;
    }
    for (auto it : edges)
    {
        int u = it[0] - 1;
        int v = it[1] - 1;
        int wt = it[2];
        dist[u][v] = wt;
    }
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dist[i][k] != 1e9 and dist[k][j] != 1e9)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    return dist[src - 1][dest - 1];
}
int main()
{
    // used in finding the shortes distance from every point to every point.
    // here we are using the intution that if we move x to y then there will be a path x to a and a to y here a is a node
    // in graph.
    // it is so  we need find x to a and if x to a aldreadypresent we directly use it.
    // so it is more like dp.

    // here create a matrix[n][n].
    // all diagonals to 0.
    // all edges are added mat[u][v] = w;
    // mat[v][u] = w if undirected.

    // next run loop for n times
    // in each loop for each u and v combination find the path between u and v via i.
    // if we get small distaance update.

    // here we can find neg cycles by cheking diagonals if diagonals went neg means neg cycle present.
}