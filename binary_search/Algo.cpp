#include <bits/stdc++.h>
using namespace std;
int using_recursive(int arr[], int target, int l, int r)
{
    if (l > r)
    {
        return -1;
    }
    int mid = l + (r - l) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        using_recursive(arr, target, l, mid - 1);
    }
    else
    {
        using_recursive(arr, target, mid + 1, r);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int l = 0;
    int r = n - 1;
    cout << "Enter the Target " << endl;
    int target = 0;
    cin >> target;

    int ans = using_recursive(arr, target, 0, n - 1);
    cout << "The ans is " << ans << endl;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target)
        {
            cout << "Target is found at location " << mid << endl;
            return 0;
        }
        else if (arr[mid] > target)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << "taget not found i guess target not in array" << endl;
}