#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10] = {1, 1, 0, 0, 0, 2, 1, 2, 2, 1};
    int i = 0;
    int j = 0;
    int k = 9;
    while (j <= k)
    {
        if (arr[j] == 0)
        {
            swap(arr[i++], arr[j++]);
        }
        else if (arr[j] == 1)
        {
            j++;
        }
        else
        {
            swap(arr[j], arr[k--]);
        }
    }
    for (auto temp : arr)
    {
        cout << temp << " ";
    }
    cout << endl;
}