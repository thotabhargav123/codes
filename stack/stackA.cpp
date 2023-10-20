#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int *arr;
    int top;
    int size;
    Stack(int n)
    {
        size = n;
        arr = new int[size];
        top = -1;
    }
    void insert_fn(int val)
    {
        top++;
        if (top == size)
        {
            cout << "The stack is full" << endl;
            return;
        }
        arr[top] = val;
    }

    void check_top()
    {
        if (top == -1)
        {
            cout << "no  element is present" << endl;
            return;
        }
        cout << "top: " << top << endl;
    }

    void pop_stack()
    {
        top--;
        if (top == -1)
        {
            cout << "the stack is empty" << endl;
            return;
        }
        cout << "the top element " << arr[top] << " removed" << endl;
    }
};
int main()
{
    Stack *s = new Stack(5);
    s->insert_fn(1);
    s->insert_fn(2);
    s->insert_fn(3);
    s->insert_fn(4);
    s->insert_fn(5);

    cout << "over flow " << endl;
    s->insert_fn(6);

    cout << "the top is 5" << endl;
    s->check_top();

    cout << "removing the elements" << endl;
    s->pop_stack();
    s->pop_stack();
    s->pop_stack();
    s->pop_stack();
    s->pop_stack();
    cout << "under flow hit" << endl;
    s->pop_stack();
}