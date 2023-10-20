// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int d;
//     cin >> d;
//     vector<vector<int>> arr(n);
//     for(int i=0; i<n;i++) {
//         int x, y;
//         cin >> x >> y;
//         arr[i].push_back(x);
//         arr[i].push_back(y);
//     }
//     sort(arr.begin(), arr.end());
//     vector<vector<int>> v;
//     v.push_back(arr[0]);
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i][0] <= v.back()[1])
//         {
//             v.back()[1] = max(arr[i][1], v.back()[1]);
//         }
//         else
//         {
//             v.push_back(arr[i]);
//         }
//     }
//     cout << v.size() << endl;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int k;
//     cin >> k;
//     int count = 0;
//     unordered_map<int, int> mp;
//     for (int i = 0; i < n; i++)
//     {
//         cout << "The arr[i] - k is " << arr[i] - k << endl;
//         if (mp.find(arr[i] - k) != mp.end())
//         {
//             cout << "MAtch found" << endl;
//             count = count + mp[arr[i] - k];
//         }
//         cout << "The arr[i] + k is " << arr[i] + k << endl;
//         if (mp.find(arr[i] + k) != mp.end())
//         {
//             cout << "Match found" << endl;
//             count = count + mp[k + arr[i]];
//         }
//         mp[arr[i]]++;
//     }
//     cout << "The count is " << count << endl;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    queue<int> q;
    unordered_map<int, bool> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]] = false;
    }
    int k;
    cin >> k;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp[arr[i]] == true)
        {
            cout << "In if case" << endl;
            continue;
        }
        else
        {
            cout << "In else case" << endl;
            if (k == 0)
            {
                int val = q.front();
                mp[val] = false;
                q.pop();
                mp[arr[i]] = true;
            }
            else
            {
                q.push(arr[i]);
                mp[arr[i]] = true;
                k--;
            }
            count++;
        }
    }
    cout << count << endl;
}