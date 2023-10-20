// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     int arr[n];
//     int k;
//     cin >> k;
//     for(int i=0; i<n; i++){
//         cin>>arr[i];
//     }
//     priority_queue<int> pq; //**smallest on bottom largets on top aso knowm as max heap
//     for(int i=0; i<n; i++){
//         pq.push(arr[i]);
//         if(pq.size()>k){
//             pq.pop();
//         }
//     }
//     cout << pq.top();
// }
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     int arr[n];
//     int k;
//     cin >> k;
//     for(int i=0; i<n; i++){
//         cin>>arr[i];
//     }
//     priority_queue<int, vector<int>, greater<int>> pq; //**largest on bottom smallest on top also known as min heap
//     for(int i=0; i<n; i++){
//         pq.push(arr[i]);
//         if(pq.size()>k){
//             pq.pop();
//         }
//     }
//     cout << pq.top();
// }


//*** K sorted array
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int k;
//     cin >> k;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     priority_queue<int, vector<int>, greater<int>> pq;
//     for (int i = 0; i < n; i++)
//     {
//         pq.push(arr[i]);
//         if (pq.size() > k)
//         {
//             arr[i - k] = pq.top();
//             pq.pop();
//         }
//     }

//     while (!pq.empty())
//     {
//         arr[k + 1] = pq.top();
//         pq.pop();
//         k++;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
// }
