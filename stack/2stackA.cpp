#include <bits/stdc++.h>
using namespace std;
class Stack2
{
public:
    int size;
    int *arr;
    int top1;
    int top2;
    Stack2(int n)
    {
        size = n;
        arr = new int[size];
        top1 = -1;
        top2 = n;
    }

    void insert1(int val)
    {
        if (top1 + 1 == top2)
        {
            cout << "Array is full" << endl;
            return;
        }
        top1++;
        arr[top1] = val;
    }
    void insert2(int val)
    {
        if (top1 + 1 == top2)
        {
            cout << "Array is full!" << endl;
            return;
        }
        top2--;
        arr[top2] = val;
    }

    void pop1()
    {
        if (top1 == -1)
        {
            cout << "Array  is empty!" << endl;
            return;
        }
        cout << "Element at top1: " << arr[top1] << " is removed" << endl;
        top1--;
    }

    void pop2()
    {
        if (top2 == size)
        {
            cout << "Array is empty" << endl;
            return;
        }
        cout << "Element at top2: " << arr[top2] << " is removed" << endl;
        top2++;
    }

    void peek1()
    {
        if (top1 == -1)
        {
            cout << "Array is empty" << endl;
            return;
        }
        cout << "Element at top1 is " << arr[top1] << endl;
    }

    void peek2()
    {
        if (top2 == size)
        {
            cout << "Array is empty" << endl;
            return;
        }
        cout << "Element at top2 is " << arr[top2] << endl;
    }
};

int main()
{
}