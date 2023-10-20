#include <bits/stdc++.h>
using namespace std;
class Kqueue
{
public:
    int size;
    int m;
    int *arr;
    int *next;
    int *front;
    int *rear;
    int freespot;
    Kqueue(int n, int k)
    {
        size = n;
        m = k;
        arr = new int[size];
        next = new int[size];
        front = new int[k];
        rear = new int[k];
        for (int i = 0; i < size; i++)
        {
            next[i] = i + 1;
        }
        for (int i = 0; i < m; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }
        freespot = 0;
    }

    void enqueue(int val, int k)
    {
        if (freespot == -1)
        {
            cout << "The Array is full";
            return;
        }
        int currindex = freespot;
        freespot = next[currindex];
        if (front[k - 1] == -1)
        {
            // first element
            front[k - 1] = currindex;
        }
        else
        {
            // update the next so that we can move the  next of front which is done connecing the new element to prev element.
            next[rear[k - 1]] = currindex;
        }
        // as our current as last and no next is present update the next of current to -1.
        next[currindex] = -1;
        rear[k - 1] = currindex;

        arr[currindex] = val;
    }

    void dequeue(int k)
    {
        if (front[k - 1] == -1)
        {
            cout << "The given queue is empty" << endl;
            return;
        }
        int index = front[k - 1];
        front[k - 1] = next[index];
        next[index] = freespot;
        freespot = index;
    }
};

int main()
{
}