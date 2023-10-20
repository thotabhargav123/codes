#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10001];
    int size = 0;
    arr[0] = 0;
    int n;
    cin >> n;
    while (n--)
    {
        int val;
        cin >> val;
        size++;
        arr[size] = val;
        int i = size;
        while (i > 1)
        {
            if (arr[i / 2] < arr[i])
            {
                swap(arr[i / 2], arr[i]);
                i = i / 2;
            }
            else
            {
                break;
            }
        }
    }

    for (int i = 0; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}