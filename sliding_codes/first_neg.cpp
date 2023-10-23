#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    deque<int> dq;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }
    vector<int> v;
    if (dq.empty())
    {
        v.push_back(0);
    }
    else
    {
        v.push_back(arr[dq.front()]);
    }
    for (int i = k; i < n; i++)
    {
        while (!dq.empty() and dq.front() <= i - k)
        {
            dq.pop_front();
        }
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
        if (dq.empty())
        {
            v.push_back(0);
        }
        else
        {
            v.push_back(arr[dq.front()]);
        }
    }

    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}