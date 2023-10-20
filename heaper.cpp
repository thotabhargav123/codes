//***************************kth Smallest Element*******************************//
//^{max is at the top and min is bottom so max is removed and we can get min easily}
//^Known as max heap bcz of presence of max at top
#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> q;
    int n = 0;
    cin >> n;
    int k;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        q.push(val);
        if (q.size() > k)
        {
            q.pop();
        }
    }
    // for (int i = 0; i < n; i++)
    // {
        cout << q.top() << endl;
        q.pop();
    // }
}

//*************************** Kth Largest Element*******************************//
//^{min is at the top and max is bottom so min is removed and we can get max easily}
//^Known as min heap bcz of presence of min at top

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     priority_queue<int ,vector<int> , greater<int>>q;
//     int n = 0;
//     cin >> n;
//     int k;
//     cin >> k;
//     for(int i = 0; i < n;i++){
//         int val;
//         cin>>val;
//         q.push(val);
//         if(q.size()>k){
//             q.pop();
//         }
//     }
//    cout<<q.top()<<endl;
// }

//     //***************************K Sortedd Array*******************************//
//   //^ sorting the array by taking  k   elements  by usinng min heap{we are using min heap so that the top is always smallest}////
//   #include<bits/stdc++.h>
//   using namespace std;
//   int main() {
//       int n;
//       cin>>n;
//       int k;
//       cin>>k;
//       int arr[n];
//       for (int i = 0; i < n;i++) {
//           cin>>arr[i];
//       }
//       priority_queue<int ,vector<int> , greater<int>>q;
//       for (int i = 0; i < n;i++){
//           q.push(arr[i]);
//           if(q.size()>k){
//               cout << q.top()<<" ";
//               q.pop();
//           }
//       }
//       while(!q.empty()){
//           cout << q.top() << " ";
//           q.pop();
//       }
//       cout << endl;
//   }

//*************************CLOSEST ELEMENTS****************************//
//^ Max Heap is used and we use relative abs diff to find nearsest one and pair is used so than we can make pair the integer with the difference

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     int sizes;
//     cin >> sizes;
//     int k;
//     cin >> k;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//    priority_queue<pair<int,int>>q;
//    for(int i = 0; i < n; i++){
//        q.push({abs(arr[i] - k) , arr[i]});
//        if(q.size()>sizes){
//            q.pop();
//        }
//    }
//    while(!q.empty()){
//        cout << q.top().second << " ";
//        q.pop();
//    }
//    cout<<endl;
// }

//*****************************K-HIGH FREQUENCY NUMBERS******************************************************//
//^done by using min heap and pairing. It is done using frequency as sorting element and we need to find k high frequency numbers.
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     unordered_map<int, int> mp;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//         mp[arr[i]]++;
//     }

//     int k;
//     cin >> k;
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
//    for(auto i=mp.begin(); i!=mp.end(); i++)
//     {
//         q.push({i->second, i->first});
//         if(q.size()>k){
//             q.pop();
//         }
//     }
//     while (!q.empty()){
//         cout<<q.top().second << " ";
//         q.pop();
//     }
//     cout << endl;
// }

//**********************************FREQUENCY SORT *************************************************************//

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     unordered_map<int, int> mp;
//     priority_queue<pair<int, int>> q;
//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         mp[x]++;
//     }
//     for (auto i = mp.begin(); i != mp.end(); i++)
//     {
//         q.push({i->second, i->first});
//     }
//     // while (!q.empty())
//     // {
//     //     cout << q.top().second << " ";
//     //     q.pop();
//     // }
//     // cout << endl;
//     while (!q.empty())
//     {
//         int len = q.top().first;
//         while (len!= 0)
//         {
//             cout<<"The Number "<<q.top().second<<" is occured "<<len<<endl;
//             len--;
//         }
//         q.pop();
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     priority_queue<pair<int,pair<int,int>>> q;
//     int k;
//     cin>>k;
//     for (int i = 0; i < n; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         int val = (x * x + y * y);
//         q.push({val,{x,y}});
//         if(q.size()>k){
//             q.pop();
//         }
//     }
//     cout<<"the size is "<<q.size()<<endl;
//     while(!q.empty()){
//         // cout<<"jhiehfiuh"<<endl;
//         cout << q.top().second.first << " " << q.top().second.second << endl;
//         q.pop();
//     }
// }

//***********************************MIN COST OF ROPE********************************************************//
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     priority_queue<int ,vector<int> , greater<int>>q;
//    for(int i=0; i<n; i++) {
//        int val;
//        cin>>val;
//        q.push(val);
//    }
//    int sum = 0;
//    while(q.size()>1){
//        int temp1=q.top();
//        q.pop();
//        int temp2=q.top();
//        q.pop();
//        q.push(temp1+temp2);
//        sum=sum+temp1+temp2;
//    }
//    cout << sum << endl;
// }