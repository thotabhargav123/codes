#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() and arr[dq.back()] <= arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    vector<int> ans;
    ans.push_back(dq.front());
    for (int i = k; i < n; i++)
    {
        while (!dq.empty() and dq.front() <= i - k)
        {
            dq.pop_front();
        }
        while (!dq.empty() and arr[dq.back()] <= arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(dq.front());
    }
    for (auto i : ans)
    {
        cout << i << " ";
        
    }
    cout << endl;
}