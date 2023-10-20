#include <bits/stdc++.h>
using namespace std;

class QueueNode
{
public:
    int val;
    QueueNode *next;
    QueueNode(int data)
    {
        val = data;
        next = NULL;
    }
};
class Queue
{
public:
    QueueNode *head;
    QueueNode *tail;
    Queue()
    {
        head = NULL;
        tail = head;
    }

    void insertfn(int val)
    {
        if (head == NULL)
        {
            cout << "inserting first value in queue" << endl;
            head = new QueueNode(val);
            tail = head;
            return;
        }

        tail->next = new QueueNode(val);
        tail = tail->next;
    }

    void getfront()
    {
        if (head == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "The head is " << head->val << endl;
    }

    void deletefront()
    {
        if (head == NULL)
        {
            cout << "Queue is empty nothing to delete" << endl;
            return;
        }
        cout << "The head is " << head->val << " is removed" << endl;
        QueueNode *del = head;
        head = head->next;
        delete del;
    }
};

int main()
{
    Queue *q = new Queue();
    q->insertfn(1);
    q->getfront();
    q->deletefront();
    q->deletefront();
    q->insertfn(2);
    q->getfront();
    q->insertfn(3);
    q->deletefront();
    q->getfront();
}