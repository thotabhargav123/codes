#include <bits/stdc++.h>
using namespace std;

class Deque
{
public:
    int size;
    int front;
    int rear;
    int *arr;
    Deque(int val)
    {
        size = val;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    void insertFront(int val)
    {
        if (isFull())
        {
            cout << "The queue is full!" << endl;
            return;
        }
        else if (isempty())
        {
            // setting both to  zero
            rear = 0;
            front = 0;
        }
        else if (front == 0 and rear != size - 1)
        {
            // heer front moves from back to front so if rear is not at end means it can add from end.
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = val;
    }

    void insertRear(int val)
    {
        if (isempty())
        {
            rear = 0;
            front = 0;
        }
        else if (isFull())
        {
            cout << "Quuee is full " << endl;
            return;
        }
        else if (rear == size - 1 and front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = val;
    }

    void popFront()
    {
        if (isempty())
        {
            cout << "Nothing to pop!" << endl;
            return;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
        {
            // all elemets removed;
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }

    void pop_back()
    {
        if (isempty())
        {
            cout << "Nothing to pop back" << endl;
            return;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
    }

    bool isempty()
    {
        // checking array is empty or not
        if (front == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        // checking array is full
        // if front at start and rear at end or rear+1 == front means end.
        if (front == 0 and rear == size - 1 or (front != 0 and rear == (front - 1) % (size - 1)))
        {
            return true;
        }
        return false;
    }
};