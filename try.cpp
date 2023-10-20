#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> v;
    v.push_back({2, 1, 4});
    v.push_back({2, 1, 3});
    v.push_back({4, 4, 4});
    v.push_back({4, 4, 1});
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}