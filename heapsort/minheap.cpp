#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[1001];
    arr[0] = 0;
    int n;
    cin >> n;
    int size = 0;
    while (n--)
    {
        int val;
        cin >> val;
        size++;
        arr[size] = val;
        int i = size;
        while (i > 1)
        {
            if (arr[i / 2] > arr[i])
            {
                swap(arr[i], arr[i / 2]);
                i = i / 2;
            }
            else
            {
                break;
            }
        }
    }

    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
}