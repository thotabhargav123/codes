// #include<bits/stdc++.h>
// using namespace std;
// int top = -1;
// void push(int arr[], int n, int x){
//     if(top==n-1){
//         cout<<"ERROR"<<endl;
//         return;
//     }
//     top++;
//     arr[top] = x;
// }
// void pop(int arr[]){
//     if (top==-1){
//         cout<<"ERROR"<<endl;
//     }
//     cout<<arr[top]<<endl;
//     top--;
// }
// void dis(int arr[],int n){
//     while(top>=0){
//         cout << arr[top] << " ";
//         top--;
//     }
//     cout<<endl;
// }
// int main(){
//     cout<<"Enter size"<<endl;
//     int n;
//     cin >> n;
//     int arr[n];
//     int cho;
//     do{
//         cin >> cho;
//         if(cho==1){
//             cout<<"Enter num"<<endl;
//             int x;
//             cin >> x;
//             push(arr,n,x);
//         }
//         if(cho==2){
//             pop(arr);
//         }
//         if(cho==3){
//             dis(arr,n);
//         }
//         if(cho==4){
//             break;
//         }
//     }while(true);
//     cout<<"Done"<<endl;
// }

//*stack identificaton deone by n^2 mtd in which  i to n and jis from 0 to i or any other in this format

//! NGL
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     stack<int> s;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     vector<int> v;
//     for (int i = 0; i < n; i++)
//     {
//         while (!s.empty() and arr[i] > s.top())
//         {
//             s.pop();
//         }
//         if (s.empty())
//         {
//             v.push_back(-1);
//         }
//         else
//         {
//             v.push_back(s.top());
//         }
//         s.push(arr[i]);
//     }
//     for (int i = 0; i < v.size(); i++)
//     {
//         cout << v[i] << " ";
//     }
//     cout << endl;
// }

//*ngr
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     stack<int> s;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     vector<int> v;
//     for (int i = n-1; i >=0; i--)
//     {
//         while (!s.empty() and arr[i] > s.top())
//         {
//             s.pop();
//         }
//         if (s.empty())
//         {
//             v.push_back(-1);
//         }
//         else
//         {
//             v.push_back(s.top());
//         }
//         s.push(arr[i]);
//     }
//     for (int i = 0; i < v.size(); i++)
//     {
//         cout << v[i] << " ";
//     }
//     cout << endl;
// }

//***NSL;
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     stack<int> s;
//     vector<int> v;
//     for (int i = 0; i < n; i++)
//     {
//         while (!s.empty() and s.top() > arr[i])
//         {

//             s.pop();
//         }
//         if (s.empty())
//         {
//             v.push_back(-1);
//         }
//         else
//         {
//             v.push_back(s.top());
//         }
//         s.push(arr[i]);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout << v[i] << " ";
//     }
//     cout << endl;
// }

//*NSR

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     stack<int> s;
//     vector<int> v;
//     for (int i = n-1; i >= 0; i--)
//     {
//         while (!s.empty() and s.top() > arr[i])
//         {

//             s.pop();
//         }
//         if (s.empty())
//         {
//             v.push_back(-1);
//         }
//         else
//         {
//             v.push_back(s.top());
//         }
//         s.push(arr[i]);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout << v[i] << " ";
//     }
//     cout << endl;
// }

//*count of elemets greater to it from left; or nsl
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> v;
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        while (!s.empty() and s.top().first >= arr[i])
        {
            count=count+s.top().second;
            s.pop();
        }
        v.push_back(count);
        s.push(make_pair(arr[i], count));
    }
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout<<endl;
}

//*count of elemets greater to it from right; or nsr
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     vector<int> v;
//     stack<pair<int, int>> s;
//     for (int i = n-1; i >=0; i--)
//     {
//         int count = 1;
//         while (!s.empty() and s.top().first >= arr[i])
//         {
//             count=count+s.top().second;
//             s.pop();
//         }
//         v.push_back(count);
//         s.push(make_pair(arr[i], count));
//     }
//     for(int i = 0; i < n; i++){
//         cout << v[i] << " ";
//     }
//     cout<<endl;
// }

//*Histogram nsl+nsr
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     stack<pair<int, int>> s;
//     vector<int> left;
//     vector<int> right;
//     for (int i = 0; i < n; i++)
//     {
//         int count = 1;
//         while (!s.empty() and s.top().first >= arr[i])
//         {
//             count = count + s.top().second;
//             s.pop();
//         }
//         left.push_back(count);
//         s.push(make_pair(arr[i], count));
//     }
//     stack<pair<int, int>> temp2;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         int count = 1;
//         while (!temp2.empty() and temp2.top().first >= arr[i])
//         {
//             count = count + temp2.top().second;
//             temp2.pop();
//         }
//         right.push_back(count);
//         temp2.push(make_pair(arr[i], count));
//     }
//     reverse(right.begin(), right.end());
//     for (int i = 0; i < n; i++)
//     {
//         cout << left[i] << " " << right[i] << endl;
//     }
//     int maxarea = -1;
//     for (int i = 0; i < n; i++)
//     {
//         maxarea = max(maxarea, ((left[i]+right[i])-1)*arr[i]);
//         cout << maxarea << endl;
//     }

// }

//*netx greater frquency element;
//*identification:
// itreate over i t0 n;
// and j ranges from i t0 n - 1;
// == > stacking used;
// next greatest frequency element =>ngram
// pair is used beacause element and frequency of element required

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int array[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> array[i];
//     }
//     unordered_map<int, int> mp;
//     for (int i = 0; i < n; i++)
//     {
//         mp[array[i]]++;
//     }
//     stack<pair<int, int>> s;
//     vector<int> v;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         while (!s.empty() and mp[array[i]] >= s.top().second)
//         {
//             s.pop();
//         }
//         if (s.empty())
//         {
//             v.push_back(-1);
//         }
//         else
//         {
//             v.push_back(s.top().first);
//         }
//         s.push(make_pair(array[i], mp[array[i]]));
//     }
//     for (int i = 0; i < n; i++){
//         cout << v[i] << " ";
//     }
//     cout<<endl;
// }

//*product of index of next gretaer to left and next greater to right
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     stack<int> s;
//     vector<int> left;
//     for (int i = 0; i < n; i++)
//     {
//         while (!s.empty() and arr[i] >= arr[s.top() - 1])
//         {
//             s.pop();
//         }
//         if (s.empty())
//         {
//             left.push_back(0);
//         }
//         else
//         {
//             left.push_back(s.top());
//         }
//         s.push(i + 1);
//     }
//     vector<int> right;
//     stack<int> temp2;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         while (!temp2.empty() and arr[i] >= arr[temp2.top() - 1])
//         {
//             temp2.pop();
//         }
//         if (temp2.empty())
//         {
//             right.push_back(0);
//         }
//         else
//         {
//             right.push_back(temp2.top());
//         }
//         temp2.push(i + 1);
//     }
//     reverse(right.begin(), right.end());
//     int maxi = -1;
//     for (int i = 0; i < n; i++)
//     {
//         cout << left[i] << " " << right[i] << " " << right[i] * left[i] << endl;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         maxi = max(maxi, right[i] * left[i]);
//     }
//     cout << maxi << endl;
// }

// //*** HISTOGRAM FOR 2D array
// #include <bits/stdc++.h>
// using namespace std;
// int mha(int arr[], int m)
// {
//     //*left nearest small element
//     stack<pair<int, int>> temp;
//     vector<int> left;
//     vector<int> right;
//     stack<pair<int, int>> temp2;
//     for (int i = 0; i < m; i++)
//     {
//         int count = 1;
//         while (!temp.empty() and temp.top().first >= arr[i])
//         {
//             count = count + temp.top().second;
//             temp.pop();
//         }
//         left.push_back(count);
//         temp.push(make_pair(arr[i], count));
//     }
//     for (int i = m - 1; i >= 0; i--)
//     {
//         int count = 1;
//         while (!temp2.empty() and temp2.top().first >= arr[i])
//         {
//             count = count + temp2.top().second;
//             temp2.pop();
//         }
//         right.push_back(count);
//         temp.push(make_pair(arr[i], count));
//     }
//     int maxi = 0;

//     for (int i = 0; i < m; i++)
//     {
//         maxi = max(maxi, arr[i] * ((left[i] + right[i] - 1)));
//     }
//     return maxi;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int m;
//     cin >> m;
//     int arr[n][m];
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> arr[i][j];
//         }
//     }
//     // int totalmax = 0;
//     int maxi = mha(arr[0], m);
//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (arr[i][j] != 0)
//             {
//                 arr[i][j] = arr[i][j] + arr[i - 1][j];
//             }
//         }
//         maxi = max(maxi, mha(arr[i], m));
//     }
// }

//*Greatest element to  right for given indexes is

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     vector<int> queries;
//     for (int i = 0; i < n; i++)
//     {
//         int val;
//         cin >> val;
//         queries.push_back(val);
//     }
//     for (int i = n - 1; i >= 0; i--)
//     {

//     }
// }

//*reverse stack

// #include <bits/stdc++.h>
// using namespace std;
// void reverse(stack<int> s)
// {
//     if (s.size() > 0)
//     {
//         int x = s.top();
//         s.pop();
//         reverse(s);
//         s.push(x);
//     }
//     return;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     stack<int> s;
//     for (int i = 0; i < n; i++)
//     {
//         int val;
//         cin >> val;
//         s.push(val);
//     }
//     reverse(s);
//     for (int i = 0; i < n; i++)
//     {
//         cout << s.top() << " ";
//         s.pop();
//     }
// }


