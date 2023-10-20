#include <bits/stdc++.h>
using namespace std;
class Cqueue
{
public:
    int front;
    int rear;
    int size;
    int *arr;
    Cqueue(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void insert_fn(int val)
    {
        if (front == 0 and rear == size - 1 or front != 0 and rear == (front - 1) % (size - 1))
        {
            cout << "Queue is full!" << endl;
            return;
        }
        else if (front == -1 and rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (front != 0 and rear == size - 1)
        {
            rear = 0; // to maintain cyclic nature.
        }
        else
        {
            rear++;
        }
        arr[rear] = val;
    }

    void delete_fn()
    {
        if (front == -1)
        {
            cout << "Empty nothig to delete" << endl;
            return;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else{
            front = front + 1;
        }
    }
};
int main()
{
}