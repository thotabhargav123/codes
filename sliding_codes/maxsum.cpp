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
    // bruteforce is to do is find every sub array and find sum and find max in it...
    int maxi = INT_MIN;
    int k;
    cin >> k;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    cout << "The sum is " << sum << endl;
    maxi = max(maxi, sum);
    for (int i = k; i < n; i++)
    {
        sum = sum - arr[i - k];
        sum = sum + arr[i];
        cout << "The sum is " << sum << endl;
        maxi = max(maxi, sum);
    }
    cout << "The max value is " << maxi << endl;
}