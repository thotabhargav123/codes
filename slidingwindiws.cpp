// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     // int n;
//     // cin >> n;
//     string ptrn;
//     cin >> ptrn;
//     string txt;
//     cin >> txt;
//     int count = 0;
//     unordered_map<char, int> mp;
//     for (int i = 0; i < ptrn.length(); i++)
//     {
//         mp[ptrn[i]]++;
//     }
//     count = mp.size();
//     int j = 0;
//     int i = 0;
//     int ans = INT_MAX;
//     while (j < txt.length())
//     {
//         if (mp.find(txt[j]) != mp.end())
//         {
//             mp[txt[j]]--;
//         }
//         if (mp[txt[j]] == 0)
//         {
//             count--;
//         }
//         if (count > 0)
//         {
//             j++;
//         }
//         else if (count == 0)
//         {
//             ans = max(ans, j - i + 1);
//             while (count = 0)
//             {
//                 if (mp.find(txt[i]) != mp.end())
//                 {
//                     i++;
//                     ans = min(ans, j - i + 1);
//                 }
//                 else
//                 {
//                     mp[txt[i]]++;
//                     if (mp[txt[i]] > 0)
//                     {
//                         i++;
//                         count++;
//                     }
//                     else
//                     {
//                         i++;
//                         ans = min(ans, j - i + 1);
//                     }
//                 }
//             }
//         }
//         j++;
//     }
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> v;
    deque<int> s;
    for (int i = 0; i < k; i++)
    {
        if (!s.empty() and arr[i] > s.back())
        {
            s.pop_back();
        }
        s.push_back(arr[i]);
    }
    int j = 0;
    v.push_back(s.front());
    for (int i = k; i < n; i++)
    {

        if (s.front() == arr[i-k])
        {
            s.pop_front();
        }
        while(!s.empty() and arr[i]>s.back()){
            s.pop_back();
        }
        s.push_back(arr[i]);
    }
}