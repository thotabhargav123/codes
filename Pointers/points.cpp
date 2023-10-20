#include <bits/stdc++.h>
using namespace std;
void swaper(int &x, int &y)
{
    cout << "The x and y are " << x << " " << y << endl;
    int temp = x;
    x = y;
    y = temp;
}
int main()
{
    int a = 10;
    int *b = &a;
    cout << "The value of b is" << b << endl;
    cout << "The above value is adress" << endl;

    cout << "The value of *b is " << *b << endl;
    cout << "The above value is value at particular location" << endl;

    cout << "The value of &b is " << &b << endl;
    cout << "The above is adress of b" << endl;

    int c = 10;
    int d = 20;
    swaper(c, d);
    cout << "After the swap the c and d are: " << c << " " << d << endl;

    int *e;
    cout << "here e is wild pointer pointing to " << e << endl;

    int *f = NULL;
    cout << "Insted of making f point to random location it will point to NULL " << f << endl;
}