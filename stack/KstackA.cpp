#include <bits/stdc++.h>
using namespace std;
class Kstack
{
    int size;
    int m;
    int *arr;
    int *top;
    int *next;
    int freespot;
    Kstack(int n, int k)
    {
        size = n;
        m = k;
        arr = new int[size];
        top = new int[m];
        next = new int[size];

        for (int i = 0; i < size; i++)
        {
            next[i] = i + 1;
        }
        next[m - 1] = -1;
        for (int i = 0; i < m; i++)
        {
            top[i] = -1;
        }
        freespot = 0;
    }

    void insert(int val, int k)
    {
        if (freespot == -1)
        {
            cout << "Array is full" << endl;
            return;
        }

        int currindex = freespot;
        int freespot = next[currindex];
        arr[currindex] = val;
        next[currindex] = top[k - 1];
        top[k - 1] = currindex;
    }

    void delete_fn(int k)
    {
        if (top[k - 1] == -1)
        {
            cout << "The given stack is empty." << endl;
            return;
        }
        int index = top[k - 1];
        top[k - 1] = next[index]; // to point top  to next top.
        next[index] = freespot;
        freespot = index;
        cout << arr[index] << endl;
    }
};
int main()
{
}