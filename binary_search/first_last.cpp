#include <bits/stdc++.h>
using namespace std;
// finding the first idnex.
int find_first_index(int arr[], int n, int target)
{
    int l = 0;
    int r = n - 1;
    int ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            r = mid - 1;
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
    return ans;
}
// finding the last idnex.
int find_last_index(int arr[], int n, int target)
{
    int l = 0;
    int r = n - 1;
    int ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            l = mid + 1;
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
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the target" << endl;
    int target = 0;
    cin >> target;
    int Findex = find_first_index(arr, n, target);
    int Lindex = find_last_index(arr, n, target);
    cout << "The first and last indexes are: " << Findex << " " << Lindex << endl;
    cout << "The lenght is ";
    if (Findex == -1)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << Lindex - Findex + 1 << endl;
    }
}