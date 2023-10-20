#include <bits/stdc++.h>
using namespace std;
class Queue
{
public:
    int front;
    int *arr;
    int size;
    int rear;
    Queue(int n)
    {
        size = n;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void insert_fn(int val)
    {
        if (rear == size)
        {
            cout << "The queue is  full!" << endl;
            return;
        }
        arr[rear++] = val;
    }

    void getFront()
    {
        if (front == rear)
        {
            cout << "The Queue is empty!" << endl;
            return;
        }
        cout << "The front of the queue is " << arr[front] << endl;
    }

    void deleteFront()
    {
        if (front == rear)
        {
            cout << "The queue is empty and nothing to delete!" << endl;
            return;
        }
        cout << "deleting the front of the queue " << arr[front] << endl;
        front++;
    }
};
int main()
{
    Queue *q = new Queue(3);
    q->getFront();
    q->deleteFront();

    q->insert_fn(1);
    q->getFront();
    q->deleteFront();
    q->deleteFront();

    q->insert_fn(2);
    q->insert_fn(3);
    // q->insert_fn(4);
}