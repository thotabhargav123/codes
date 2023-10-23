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
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (mid != 0 and mid != n - 1)
        {
            if (arr[mid] < arr[mid - 1] and arr[mid] < arr[mid + 1])
            {
                cout << "The posn of smallest element is found i.e " << mid << endl;
                break;
            }
            else if (arr[mid] > arr[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        else
        {
            if (mid == 0)
            {
                if (arr[mid] < arr[mid + 1])
                {
                    cout << "The posn of smallest element is found i.e " << mid << endl;
                    break;
                }
                else
                {
                    cout << "The posn of smallest element is found i.e " << mid + 1 << endl;
                    break;
                }
            }
            else
            {
                if (arr[mid] < arr[mid - 1])
                {
                    cout << "The posn of smallest element is found i.e " << mid << endl;
                    break;
                }
                else
                {
                    cout << "The posn of smallest element is found i.e " << mid - 1 << endl;
                    break;
                }
            }
        }
    }

    cout << "Enter the target to be found" << endl;
    int target = 0;
    cin >> target;
    l = 0;
    r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target)
        {
            cout << "The target found at location " << mid << endl;
            break;
        }
        else if (arr[mid] < arr[r])
        {
            if (target > arr[mid] and target < arr[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        else
        {
            if (target < arr[mid] and target > arr[l])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
    }
}

// with duplicates in the array...
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[high])
        {
            cout << "In else if" << endl;
            low = mid + 1;
        }
        else if (arr[mid] < arr[high])
        {
            cout << "IN else " << endl;
            high = mid;
        }
        else
        {
            high--;
        }
    }
    cout << "The smallest is " << arr[low] << endl;
    cout << "Enter the target to search" << endl;
    int key = 0;
    cin >> key;
    int l = 0;
    int h = n - 1;
    // cout<<arr.size()<<endl;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        cout << "The mid is " << mid << "and value is " << arr[mid] << endl;
        if (arr[mid] == key)
        {
            return 1;
        }
        if (arr[mid] == arr[l] and arr[mid] == arr[h])
        {
            l++;
            h--;
            cout << "l and h reduced " << l << " " << h << endl;
        }
        else if (arr[mid] <= arr[h])
        {
            if (key > arr[mid] and key <= arr[h])
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        else
        {
            if (key >= arr[l] and key < arr[mid])
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
    }
    return 0;
}