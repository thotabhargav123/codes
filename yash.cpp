// #include<bits/stdc++.h>
// using namespace std;
// class linpro{
//     int *arr;
//     int cap,size;
//     public:
//     linpro(int c){
//         cap = c;
//         size = 0;
//         arr = new int[cap];
//         for(int i=0;i<cap;i++){
//             arr[i] = -1;
//         }
//     }
//     int hash(int n){
//         return n % cap;
//     }
//     bool insert(int n){
//         if(size == cap){
//             cout<<"sas lene ke liye be jaga ne hai"<<endl;
//             return false;
//         }
//        int  i=hash(n);
//       while(arr[i] != -1 && arr[i] !=-2 && arr[i]!=n){
//           i=(i+1)%cap;
//       }
//       if(arr[i]==n){
//           cout << "kitne bar bejega ek hi element" << endl;
//           return false;
//       }
//       else{
//           arr[i]=n;
//           size++;
//           cout<<"ha bhaya hogayab kam"<< endl;
//           return true;
//       }
//     }
//     bool search(int key){
//         int i = hash(key);
//         int h = i;
//         while(arr[i]!=-1){
//       if(arr[i]==key)
//                 return true;
//             i=(i+1)%cap;
//             if(i==h)
//                 return false;
//         }
//         return false;
//     }
//     bool del(int key){
//          int h=hash(key);
//          int i=h;
//          while(arr[i]!=-1){
//             if(arr[i]==key){
//                 arr[i]=-2;
//                 return true;
//             }
//             i=(i+1)%cap;
//             if(i==h)
//                 return false;
//         }
//         return false;
//     }
// };
// int main(){
//         linpro mh(7);
// 	    mh.insert(49);
// 	    mh.insert(56);
// 	    mh.insert(72);
// 	    if(mh.search(56)==true)
// 	        cout<<"Yes"<<endl;
// 	    else
// 	        cout<<"No"<<endl;
// 	    mh.del(56);
// 	    if(mh.search(56)==true)
// 	        cout<<"Yes"<<endl;
// 	    else
// 	        cout<<"No"<<endl;
// }
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     unordered_map<int, int> mp;
//     for(int i=0; i<n; i++){
//         int val;
//         cin >> val;
//         mp[val]++;
//     }
//     int ninfreq=INT_MAX;
//     int maxele=INT_MIN;
//     for(auto x:mp){
//         int freq = x.second;
//         int ele = x.first;
//         if(ninfreq>freq){
//                ninfreq=freq;
//                maxele=ele;    
//         }
//         else if(freq==ninfreq && maxele<ele){
//             maxele=ele;
//         }
//     }
//     cout << ninfreq << " " << maxele << endl;
// }
#include<bits/stdc++.h>
using namespace std;
int sumd(int N)
{
    // Stores the sum of digits
    int sum = 0;
 
    // If the number N is greater than 0
    while (N) {
        sum += (N % 10);
        N = N / 10;
    }
 
    // Return the sum
    return sum;
}
int main() {
    int n;
    cin>>n;
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        int ad = val + sumd(val);
        mp[ad]++;
    }
    int count = 0;
    for(auto x:mp){
         int rep=x.second;
         count = count + (rep * (rep - 1)) / 2;
    }
    cout<<count<<endl;
}