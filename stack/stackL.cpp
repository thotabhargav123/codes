#include <bits/stdc++.h>
using namespace std;
class stackNode
{
public:
    int value;
    stackNode *next;
    stackNode(int val)
    {
        value = val;
        next = NULL;
    }
};

class Stack
{
public:
    stackNode *top;
    Stack()
    {
        top = new stackNode(-1);
    }

    void insert_stack(int val)
    {
        if (top->value == -1)
        {
            cout << "inserting the first Element" << endl;
        }
        stackNode *newnode = new stackNode(val);
        newnode->next = top;
        top = newnode;
    }

    void top_stack()
    {
        if (top->value == -1)
        {
            cout << "stack is empty" << endl;
            return;
        }
        cout << "The top of the stack is " << top->value << endl;
    }

    void pop_stack()
    {
        if (top->value == -1)
        {
            cout << "stack is empty" << endl;
        }
        stackNode *del = top;
        top = top->next;
        delete del;
    }
};

int main()
{
    Stack *s = new Stack();
    cout << "cout will be first element" << endl;
    s->insert_stack(1);
    cout << "no output" << endl;
    s->insert_stack(2);
    cout << "cout will be 2" << endl;
    s->top_stack();
    cout << "cout will be no output" << endl;
    s->pop_stack();
    cout << "cout will be 1" << endl;
    s->top_stack();
    s->pop_stack();
    cout << "cout will be empty" << endl;
    s->pop_stack();
}