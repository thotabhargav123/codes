// using  adj matrix.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int edges;
    cin >> edges;
    int vertices;
    cin >> vertices;
    vector<vector<int>> matrix(vertices, vector<int>(vertices, 0));
    for (int i = 0; i < edges; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        matrix[a][b] = 1; // for directed graphs
        // matrix[b][a] = 1 // for undirected graph uncomment this also.
        //  to make weighted ask another variable wt and set mat[a][b] = wt;
    }
}
// using adjList
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int edges;
    cin >> edges;
    int vertices;
    cin >> vertices;
    vector<int> adj[vertices];
    for (int i = 0; i < edges; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); // for undirected graph.
    }
}