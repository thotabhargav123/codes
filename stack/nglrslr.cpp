
#include <bits/stdc++.h>
using namespace std;
// next greater left.
//* find the greater element for every element which is next or near to it.
void ngl(int arr[], vector<int> &ans)
{
    stack<int> st;
    for (int i = 0; i < 10; i++)
    {
        while (!st.empty() and st.top() < arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(st.top());
        }
        st.push(arr[i]);
    }
}

void nsl(int arr[], vector<int> &ans)
{
    stack<int> st;
    for (int i = 0; i < 10; i++)
    {
        while (!st.empty() and st.top() > arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(st.top());
        }
        st.push(arr[i]);
    }
}
void ngr(int arr[], vector<int> &ans)
{
    stack<int> st;
    for (int i = 9; i >= 0; i--)
    {
        while (!st.empty() and st.top() < arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(st.top());
        }
        st.push(arr[i]);
    }
}
void ngl(int arr[], vector<int> &ans)
{
    stack<int> st;
    for (int i = 9; i >= 0; i--)
    {
        while (!st.empty() and st.top() > arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans.push_back(-1);
        }
        else{
            ans.push_back(st.top());
        }
        st.push(arr[i]);
    }
}
int main()
{
    int arr[10] = {2, 6, 4, 0, 8, 5, 3, 1, 7, 9};
    vector<int> ans;
    // ngl(arr, ans);
    // nsl(arr, ans);
    ngr(arr, ans);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}