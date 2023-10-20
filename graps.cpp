// #include <bits/stdc++.h>
// using namespace std;
// vector<int> edges[10000];
// int main()
// {
//     int n;
//     cin >> n;
//     vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));

//     //*********************************** Adjacency Matrix ************************************************/
//     for (int i = 0; i <= n; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         v[x][y] = 1;
//         v[y][x] = 1;
//     }
//     cout << "The Adjacency Matrix is:" << endl;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             cout << v[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
//     cout << endl;

//     //******************************* Adjancency List *************************************//
//     for (int i = 1; i <= n; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         edges[x].push_back(y);
//         edges[y].push_back(x);
//     }

//     cout << "adjacency list" << endl;

//     for (int i = 1; i <= n; i++)
//     {
//         cout << i << "->";
//         vector<int>::iterator it;
//         for (it = edges[i].begin(); it != edges[i].end(); it++)
//         {
//             cout << *it << " ";
//         }
//         cout << endl;
//     }
// }

//***BFS Search Implementation**//

// #include <bits/stdc++.h>
// using namespace std;
// vector<int> edges[10000];
// int main()
// {
//     int n;
//     cin >> n;
//     queue<int> q;
//     for (int i = 1; i <= n; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         edges[x].push_back(y);
//         edges[y].push_back(x);
//     }
//     cout << "adjacency list" << endl;

//     for (int i = 1; i <= n; i++)
//     {
//         cout << i << "->";
//         vector<int>::iterator it;
//         for (it = edges[i].begin(); it != edges[i].end(); it++)
//         {
//             cout << *it << " ";
//         }
//         cout << endl;
//     }

//     int node;
//     int visited[n+1]={0};

//     visited[1] = 1;
//     q.push(1);
//     while(!q.empty()){
//         int node=q.front();
//         q.pop();
//         cout << node << " ";
//         vector<int>::iterator it;
//         for (it = edges[node].begin(); it != edges[node].end(); it++)
//         {
//            if(visited[*it]==0){
//                visited[*it] = 1;
//                q.push(*it);
//            }
//         }
//     }
//     cout << endl;
// }

//*****DFS Implementation**////
// #include<bits/stdc++.h>
// using namespace std;
// vector<int> edges[100000];
// bool visited[100000];
// void dfs(int node){
//     // cout << "hhihfeih";
//     visited[node] = 1;
//     cout << node << " ";
//     vector<int>::iterator it;
//     for (it = edges[node].begin(); it != edges[node].end(); it++){
//         if(visited[*it]==1){
//             continue;
//         }
//         else{
//            dfs(*it);
//         }
//     }
// }
// int main(){
//     int n;
//     cin >> n;
//     stack<int> s;
//    for(int i=0; i<n; i++){
//        int x, y;
//        cin >> x >> y;
//        edges[x].push_back(y);
//        edges[y].push_back(x);
//    }
//    cout << "ADJANCENCY LIST:"  << endl;
//    for (int i = 0; i < n;i++){
//        cout << i << "-> : ";
//        vector<int>::iterator it;
//        for(it = edges[i].begin(); it != edges[i].end();it++) {
//            cout << *it << " ";
//        }
//        cout << endl;
//    }
//    dfs(1);
// }

//**Tropological sort

/*
 ! Graph should ne directed acyclic
 ! we may unique type of orders;
 ! if inorder of an node becomes it is printed or sorted
 !implementation:
    &first make a graph(directed one);
    &next along with graph we need to find inorder of each node;
    &if inorder of a node becomes '0' then we need to push to the queue;
    &then by using loop we need to subtract 1 from every node which is conctd to the present node;
    & at any time if if inorder of any node becomes '0' we need to push to queue
 */

// #include<bits/stdc++.h>
// using namespace std;
// vector<int> edges[100000];
// int main(){
//     int n;
//     cin>>n;
//     vector<int> indeg(n + 1, 0);
//     for(int i=0; i<n;i++) {
//         int x, y;//{x<-y}
//         cin>>x>>y;
//         edges[x].push_back(y);
//         indeg[y]++;
//     }
//     cout << "ADJANCENCY LIST:"  << endl;
//      for (int i = 0; i < n;i++){
//        cout << i << "-> : ";
//        vector<int>::iterator it;
//        for(it = edges[i].begin(); it != edges[i].end();it++) {
//            cout << *it << " ";
//        }
//        cout << endl;
//    }

//    queue<int> q;
//    for(int i = 0; i <=n;i++){
//        if(indeg[i]==0){
//            q.push(i);
//        }
//    }
//    while(!q.empty()){
//        int x = q.front();
//        q.pop();
//        cout << x << " ";
//        for(auto it:edges[x]){
//            indeg[it]--;
//            if(indeg[it]==0){
//                q.push(it);
//            }
//        }
//    }
// }

//************************************  IS CYCLE in undirected graph ****************************************************//
// #include <bits/stdc++.h>
// using namespace std;
// vector<int> edges[100000];
// bool iscycle(int src, vector<vector<int>> &edges, vector<bool> &visited, int parent)
// {
//    visited[src] = true;
//    for (auto i : edges[src])
//    {
//       if (i != parent)
//       {
//          if (visited[i])
//          {
//             return true;
//          }
//          if (!visited[i] and iscycle(i, edges, visited, src))
//          {
//             return true;
//          }
//       }
//    }
//    return false;
// }
// int main()
// {
//    int n;
//    cin >> n;
//    int m;
//    cin>>m;
//    vector<vector<int>> edges(n);
//    for (int i = 0; i < m; i++)
//    {
//       int x, y;
//       cin >> x >> y;
//       edges[x].push_back(y);
//       edges[y].push_back(x);
//    }
//    cout << "Adjacency list is:" << endl;
//    for (int i = 0; i < n; i++)
//    {
//       cout << i << "->";
//       vector<int>::iterator it;
//       for (it = edges[i].begin(); it != edges[i].end(); it++)
//       {
//          cout << *it << " ";
//       }
//       cout << endl;
//    }

//    vector<bool> visited(n, false);
//    bool cycle = false;
//    for (int i = 0; i < n; i++)
//    {
//       if (!visited[i] and iscycle(i, edges, visited, -1))
//       {
//          cycle = true;
//       }
//    }
//    if (cycle)
//    {
//       cout << "The cycle is present" << endl;
//    }
//    else
//    {
//       cout << "The cycle is not present" << endl;
//    }
// }

//************************************  IS CYCLE in directed graph ****************************************************//
// #include <bits/stdc++.h>
// using namespace std;
// bool iscycle(int src, vector<vector<int>> &edges, vector<bool> &visited, vector<int> &s)
// {
//    s[src] = 1;
//    if (!visited[src])
//    {
//       visited[src] = true;
//       for (auto i : edges[src])
//       {
//          if (!visited[i] and iscycle(i, edges, visited, s))
//          {
//             return true;
//          }
//          if (s[i] == 1)
//          {
//             return true;
//          }
//       }
//    }
//    return false;
// }
// int main()
// {
//    int n;
//    cin >> n;
//    int m;
//    cin >> m;
//    vector<vector<int>> edges(n);
//    for (int i = 0; i < m; i++)
//    {
//       int x, y;
//       cin >> x >> y;
//       edges[x].push_back(y);
//    }
//    cout << "edges :";
//    for (int i = 0; i < n; i++)
//    {
//       cout << i << "->";
//       vector<int>::iterator it;
//       for (it = edges[i].begin(); it != edges[i].end(); it++)
//       {
//          cout << *it << " ";
//       }
//       cout << endl;
//    }
//    bool cycle = false;
//    vector<bool> visited(n, false);
//    vector<int> s(n, 0);
//    for (int i = 0; i < n; i++)
//    {
//       if (!visited[i] and iscycle(i, edges, visited, s))
//       {
//          cycle = true;
//       }
//    }
//    if (cycle)
//    {
//       cout << "The cycle is present" << endl;
//    }
//    else
//    {
//       cout << "The cycle is not present" << endl;
//    }
// }

//******************************** Get Components ************************************************************//
/*
^ components reffered to the no of saperated sub graphs in graph graph
^intution:
            ~if a element is graph is visited then will not form component bcz it is cnctd to ohter one already
            ~ one component is always present
            ~ if question in the formof how many diffrent pairs are formed from the given graphs then the answer size of a component mutlipied by rem elements in another components.
^ in this function we find the size of different components;
*/

// #include <bits/stdc++.h>
// using namespace std;
// int getcomp(int src, vector<int> &components, vector<bool>&visited, vector<vector<int>> &edges)
// {
//    if (visited[src])
//    {
//       return 0;
//    }
//    int start = src;

//    visited[src] = true;
//    int ans = 1;
//    for (auto i : edges[src])
//    {
//       if (!visited[i])
//       {
//          ans += getcomp(i, components, visited, edges);
//          visited[i] = true;
//       }
//    }
//    return ans;
// }
// int main()
// {
//    int n;
//    cin >> n;
//    int m;
//    cin >> m;
//    vector<vector<int>> edges(n);
//    for (int i = 0; i < m; i++)
//    {
//       int x, y;
//       cin >> x >> y;
//       edges[x].push_back(y);
//       edges[y].push_back(x);
//    }
//    cout << "edges is :" << endl;
//    for (int i = 0; i < n; i++)
//    {
//       cout << i << "->";
//       vector<int>::iterator it;
//       for (it = edges[i].begin(); it != edges[i].end(); it++)
//       {
//          cout << *it << " ";
//       }
//       cout << endl;
//    }

//    vector<int> components;
//    vector<bool> visited(n, 0);
//    for (int i = 0; i < n; i++)
//    {
//       if (!visited[i])
//       {
//          components.push_back(getcomp(i, components, visited, edges));
//       }
//    }
//    for (auto i : components)
//    {
//       cout << i << " ";
//    }
//    cout << endl;
// }

//******************************** Biparted Graph *********************************************************//

// #include<bits/stdc++.h>
// using namespace std;
// bool bipart=true;
// void color(int src, int curr, vector<bool>&visited, vector<vector<int>> &edges,vector<int>&red){
//    if(red[src]!=-1 && red[src]!=curr){
//       bipart = false;
//       return ;
//    }
//    red[src] = curr;
//    if(visited[src]){
//       return;
//    }
//    visited[src] = true;
//    for(auto i:edges[src]){
//       color(i, curr xor 1, visited, edges, red);
//    }
// }
// int main()
// {
//    int n,m;
//    cin>>n>>m;
//    vector<vector<int>> edges(n);
//    for (int i = 0; i < m; i++){
//       int x, y;
//       cin>>x>>y;
//       edges[x].push_back(y);
//       edges[y].push_back(x);
//    }
//    cout<<"The edges is"<<endl;
//    for (int i = 0; i < n;i++){
//       vector<int> :: iterator it;
//       for(auto it = edges[i].begin(); it != edges[i].end();it++){
//          cout << *it << " ";
//       }
//       cout<<endl;
//    }
//    vector<bool>visited(n,0);
//    vector<int> red(n,-1);
//    for(int i = 0; i < n; i++){
//       if(!visited[i]){
//         color(i,0,visited,edges,red);
//       }
//    }
//    if(bipart){
//       cout<<"Graph is Biparted"<<endl;
//    }
//    else{
//       cout<<"Graph is Unbiparted"<<endl;
//    }
// }

//********************************* Disjoint set union *************************************************//

// #include<bits/stdc++.h>
// using namespace std;
// int parent[100000];
// int ranks[100000];
// void make_set(){
//    for (int i = 1; i <= 100000;i++) {
//       parent[i] = i;
//       ranks[i] = 0;
//    }
// }
// int find_parent(int node){
//    if(node == parent[node]){
//       return node;
//    }
//    return parent[node]=find_parent(parent[node]);
// }
// void make_union(int a,int b){
//    a=find_parent(a);
//    b=find_parent(b);
//    if(ranks[a]<ranks[b]){
//       parent[a] = b;
//    }
//    else if(ranks[a]>ranks[b]){
//       parent[b] = a;
//    }
//    else{
//       parent[a] = b;
//       ranks[b]++;
//    }
// }
// int main(){

//    int m;
//    cin>>m;
//     make_set();
//    for(int i=0;i<m;i++) {
//       int a,b;
//       cin>>a>>b;
//       make_union(a,b);
//    }

// }

//************************************** Cycle detection in Undirected Graph using DSU **************************//

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 6;
// vector<int> parent(N);
// vector<int> sizes(N);
// void make_set(int v)
// {
//    parent[v] = v;
//    sizes[v] = 1;
// }
// int find_parent(int v)
// {
//    if (parent[v] == v)
//    {
//       return v;
//    }
//    return parent[v] = find_parent(parent[v]);
// }
// void make_union(int a, int b)
// {
//    a = find_parent(a);
//    b = find_parent(b);
//    if (a != b)
//    {
//       if (sizes[a] < sizes[b])
//       {
//          swap(a, b);
//       }
//       parent[b] = a;
//       sizes[a] += 1;
//    }
// }
// int main()
// {
//    for (int i = 0; i < N; i++)
//    {
//       make_set(i);
//    }
//    int n, m;
//    cin >> n >> m;
//    vector<vector<int>> edges;
//    for (int i = 0; i < m; i++)
//    {
//       int x, y;
//       cin >> x >> y;
//       edges.push_back({x, y});
//    }
// cout << "edges is :" << endl;
// for (int i = 0; i < n; i++)
// {
//    cout << i << "->";
//    vector<int>::iterator it;
//    for (it = edges[i].begin(); it != edges[i].end(); it++)
//    {
//       cout << *it << " ";
//    }
//    cout << endl;
// }
//    bool cycle = false;
//    for (auto i : edges)
//    {
//       cout<<"ohimasa"<<endl;
//       int u = i[0];
//       int v = i[1];
//       int x = find_parent(u);
//       int y = find_parent(v);
//       if (x == y)
//       {
//          cycle = true;
//       }
//       else
//       {
//          make_union(u, v);
//       }
//    }
//    if (cycle == true)
//    {
//       cout << "Cycle is present" << endl;
//    }
//    else
//    {
//       cout << "Cycle is not Present" << endl;
//    }
// }

//************************************* Spanning Trees  (kruskals algo)*************************************************//
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 6;
// vector<int> parent(N);
// vector<int> sizes(N);
// void make_set(int v)
// {
//    parent[v] = v;
//    sizes[v] = 1;
// }
// int find_parent(int v)
// {
//    if (parent[v] == v)
//    {
//       return v;
//    }
//    return parent[v] = find_parent(parent[v]);
// }
// void make_union(int a, int b)
// {
//    a = find_parent(a);
//    b = find_parent(b);
//    if (a != b)
//    {
//       if (sizes[a] < sizes[b])
//       {
//          swap(a, b);
//       }
//       parent[b] = a;
//       sizes[a] += 1;
//    }
// }
// int main()
// {
//    for (int i = 0; i < N; i++)
//    {
//       make_set(i);
//    }
//    int n, m;
//    cin >> n >> m;
//    vector<vector<int>> edges;
//    for (int i = 0; i < m; i++)
//    {
//       int x, y,cost;
//       cin >> x >> y>>cost;
//       edges.push_back({cost,x, y});
//    }
//   sort(edges.begin(), edges.end());
//   int total = 0;
//   for(auto i:edges){
//      int W = i[0];
//      int U = i[1];
//      int V = i[2];
//      int x = find_parent(U);
//      int y = find_parent(V);
//      if(x== y){
//         continue;
//      }
//      else{
//         cout<<"The Pair of "<<U<<" and "<<V<<" of weight "<<W<<" is accepted"<< endl;
//          total = total + W;
//         make_union(U, V);
//      }
//   }
//   cout<<total<<endl;
// }

//************************    Spanning Tree Using the Prims Algorithm    ********************************/////

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 6;
// vector<vector<int>> adjlist[N];
// vector<int> parent(N);
// vector<bool> visited(N);
// vector<int> distances(N);
// int INF = 1e9;
//  int cost = 0;
// void Primstree(int source)
// {
//    for (int i = 0; i < N; i++)
//    {
//       distances[i] = INF;
//    }
//    set<vector<int>> s;
//    distances[source] = 0;
//    s.insert({0, source});
//    while (!s.empty())
//    {
//       auto x = *(s.begin());
//       s.erase(x);
//       visited[x[1]]=true;
//       int u = x[1];
//       int v=parent[x[1]];
//       int w=x[0];
//       cout << u << " " << v << " " << w << endl;
//       cost = cost + w;
//       for(auto it:adjlist[x[1]]){
//          if(visited[it[0]]){
//             continue;
//          }
//          if(distances[it[0]]>it[1]){
//             s.erase({distances[it[0]], it[0]});
//             distances[it[0]] = it[1];
//             s.insert({distances[it[0]],it[0]});
//             parent[it[0]] = x[1];
//          }
//       }
//    }
//    cout << cost << endl;
// }
// int main()
// {
//    int n, m;
//    cin >> n >> m;
//    for (int i = 0; i < m; i++)
//    {
//       int u, v, w;
//       cin >> u >> v >> w;
//       adjlist[u].push_back({v, w});
//       adjlist[v].push_back({u, w});
//    }
//    Primstree(0);
// }

//*** Shortest Path Djaktris Algo**////////////////////////////////
// sets, one set contains vertices included in the shortest-path tree, other set includes vertices not yet included in the shortest-path tree. At every step of the algorithm, we find a vertex that is in the other set (set of not yet included) and has a minimum distance from the source.
// Below are the detailed steps used in Dijkstra’s algorithm to find the shortest path from a single source vertex to all other vertices in the given graph.

// #include <bits/stdc++.h>
// using namespace std;
// const int INF = 1e9;
// int main()
// {
//    int n, m;
//    cin >> n >> m;
//    vector<int> distances(n+1, INF);
//    vector<vector<pair<int, int>>> graph(n+1);
//    for (int i = 0; i<m; i++)
//    {
//       int u, v, w;
//       cin >> u >> v >> w;
//       graph[u].push_back({v, w});
//       graph[v].push_back({u, w});
//    }
//    int source;
//    cin >> source;
//    distances[source] = 0;
//    set<pair<int, int>> s;
//    s.insert({0, source});
//    while (!s.empty())
//    {
//       auto x = *(s.begin());
//       s.erase(x);
//       for (auto i : graph[x.second])
//       {
//          if (distances[i.first] > distances[x.second] + i.second)
//          {
//             s.erase({distances[i.first], i.first});
//             distances[i.first] = distances[x.second] + i.second;
//             s.insert({distances[i.first], i.first});
//          }
//       }
//    }
//    for (int i = 1;i<=n;i++){
//       if(distances[i]<INF){
//          cout << distances[i] << " ";
//       }
//       else{
//          cout << -1 << endl;
//       }
//    }
// }

//****************************  Bellman Ford Algo (Used for finding Shortest path) *****************************//

//^ It is used of Dijkstra's Algo when there are negative weights or negative cycles

//  #include<bits/stdc++.h>
//  using namespace std;
//  const int INF= 1e9;
//  int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>> adjlist;
//     for(int i=0;i<m;i++){
//        int u, v, w;
//        cin >> u >> v >> w;
//        adjlist.push_back({u,v,w});
//     }
//     int source;
//     cin >> source;

//     vector<int> distances(n, INF);
//      distances[source] = 0;
//     for (int i = 0; i < n - 1;i++){
//        for(auto e:adjlist){
//           int u = e[0];
//           int v = e[1];
//           int w = e[2];
//           distances[v] = min(distances[v], distances[u] + w);
//        }
//     }
//     for(auto i:distances){
//        cout << i << " ";
//     }
//     cout << endl;
//  }

//*********************************  Floydd Washwall algorithm ************************************************//

// #include<bits/stdc++.h>
// using namespace std;
// const int INF = 1e9;
// int main(){
//    int n;
//    cin>>n;
//    int graph[n][n];
//    for(int i=0; i<n; i++){
//       for(int j=0; j<n; j++){
//          int val;
//          cin>>val;
//          graph[i][j] = val;
//       }
//    }
//    for(int i=0; i<n; i++){
//       for(int j=0; j<n; j++){
//          cout << graph[i][j] << " ";
//       }
//       cout<<endl;
//    }
//    cout<<endl;

//    for (int k = 0;k<n;k++){
//       for(int i=0;i<n;i++){
//          for(int j=0;j<n;j++){
//             if(graph[i][k]+graph[k][j]<graph[i][j]){
//                graph[i][j]=graph[i][k]+graph[k][j];
//             }
//          }
//       }
//    }
//    for(int i=0;i<n; i++){
//       for (int j = 0; j < n;j++){
//          if(graph[i][j]==INF){
//             cout<<"INFINITY"<<" ";
//          }
//          else{
//             cout << graph[i][j] << " ";
//          }
//       }
//       cout << endl;
//    }
// }






//*** Snale and Ladder
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//    int ladders, snakes;
//    cin >> ladders >> snakes;
//    map<int, int> ladd_Posn;
//    map<int, int> snake_Posn;
//    for (int i = 0; i < ladders; i++)
//    {
//       int u, v;
//       cin >> u >> v;
//       ladd_Posn[u] = v;
//    }
//    for (int i = 0; i < snakes; i++)
//    {
//       int u, v;
//       cin >> u >> v;
//       snake_Posn[u] = v;
//    }
//    int moves = 0;
//    queue<int> q;
//    q.push(1);
//    vector<int> visited(101, 0);
//    visited[1] = 1;
//    bool found = false;
//    while (!q.empty() and !found)
//    {
//       int sz = q.size();
//       while (sz--)
//       {
//          int target = q.front();
//          q.pop();
//          for (int die = 1; die <= 6; die++)
//          {
//             if (target + die == 100)
//             {
//                found = true;
//             }
//             if (target + die <= 100 && ladd_Posn[die] and !snake_Posn[die] and !visited[ladd_Posn[die]]){
//                visited[ladd_Posn[die]] = true;
//                if(ladd_Posn[die]+target==100){
//                   found = true;
//                }
//                q.push(ladd_Posn[die]);
//             }
//             else if(target+ die<=100 && snake_Posn[die] and !ladd_Posn[die] and !visited[snake_Posn[die]]){
//                visited[snake_Posn[die]]=true;
//                if(snake_Posn[die]+target==100){
//                   found=true;
//                }
//                q.push(snake_Posn[die]);
//             }
//             else if(target + die<=100 && !snake_Posn[die] and !ladd_Posn[die] and !visited[die]){
//                visited[die]=true;
//                q.push(die);
//             }
//          }
//       }
//       moves++;
//    }
//    cout<<moves<<endl;
// }