#include <bits/stdc++.h>
using namespace std;
vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> dist(n + 1, 1e8);
    dist[src] = 0;
    for (int j = 0; j < n - 1; j++)
    {
        for (auto i : edges)
        {
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            if (dist[v] > dist[u] + wt)
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    return dist;
}
int main()
{
    // used in detection on nge cycles and helps in finding the shortes path when neg wt are present.
    // here we can use djkstar but it not wroks on neg wts and when neg cycles are present it will give tle.
    // so to handle neg cycles in directed or undirected graph we use bellamford algorithm.
    // when an undirected graph present for every edge in edges array a->b insert b->a in it.

    // how works:
    // loop verticles-1 times and for every itreation check for every edge u->v if dist[v] > dist[u] + wt if yes
    // we found new short distance to v so update it.

    // next loop once again if again the updation occurs neg cycle present.

    // here we are doing n-1 cycles bcz the edges will not be given in sorted order at worst case ex:1->2->3 and edges given as 2,3 1,2 then at first itreation 2,3 wont change 1,2 will update(1 is src).
    // next iteration 2,3 can be changed as 3 depend on 2 and 2 depend on 1.

    // here we again do a check bcz by n-1 times we get s distance if we still getting updated means a neg cycle present.
}