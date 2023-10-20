// // ?---->> selection sort<<----//
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int array[n];
//     for(int i=0;i<n;i++){
//         cin>>array[i];
//     }

//     for(int i=0;i<n;i++){
//          for(int j=i+1;j<n;j++){
//              if(array[i]>array[j]){
//                  int temp=array[j];
//                  array[j]=array[i];
//                  array[i]=temp;
//              }
//          }
//          for(int i=0; i < n;i++){
//              cout << array[i] << " ";
//          }
//          cout<<endl;
//     }
//     for(int i=0;i<n;i++){
//         cout<<array[i]<<" ";
//     }
//     return 0;
// }
//  //?---->>> bubble sort
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int array[n];
//     for(int i=0;i<n;i++){      
//         cin>>array[i];
//     }

//   int counter=0;
//   for(counter=0;counter<n-1;counter++){
//       for(int i=0;i<n;i++){
//           if(array[i]>array[i+1]){
//               int temp=array[i+1];
//               array[i+1]=array[i];
//               array[i]=temp;
//           }
//       }
//   }
//    for(int i=0;i<n;i++){
//         cout<<array[i]<<" ";
//     }
// }

// // !---->>insertion sort--->>>
// #include<bits/stdc++.h>
// using namespace std;
// int  main(){
//     int n;
//     cin>>n;
//     int array[n];
//     for(int i=0;i<n;i++){   
//         cin>>array[i];
//     }

//     for(int i=1;i<n;i++){
//         int current=array[i];
//         int j=i-1;
//         while(array[j]>current && j>=0){
//            array[j+1]=array[j];
//            j--;
//        }
//        cout<<"The value of the j is "<<j<<endl;
//      array[j+1]=current;
//      for(int i=0; i<n;i++){
//          cout << array[i] << " ";
//      }
//      cout<<endl;
//        }
//       for(int i=0;i<n;i++){
//         cout<<array[i]<<" "<<endl;
//     }
// }

// //?---->>MERGE SORTING-->>>//

// #include<bits/stdc++.h>
// using namespace std;
// void merge(int array[],int l,int mid,int r){

//       int n1=mid-l+1;
//       int n2=r-mid;
//       int a[n1];
//       int b[n2];
//       for(int i=0;i<n1;i++){
//           a[i]=array[l+i];
//       }
//       for(int i=0;i<n2;i++){
//           b[i]=array[mid+1+i];
//       }

//       int i=0;
//       int j=0;
//       int k=l;
//      while(i<n1 && j<n2){
//          if(a[i]<b[j]){
//              array[k]=a[i];
//              k++;i++;
//          }
//          else{
//              array[k]=b[j];
//              k++;
//              j++;
//          }
//      }
//       while(i<n1){
//          array[k]=a[i];
//         k++;i++;
//      }
//      while(j<n2){
//          array[k]=b[j];
//          k++;j++;
//      }
// }
                                        
// void mergesort(int array[],int l,int r){
     
//       if(l<r){
//           int mid=(l+r)/2;
//           mergesort(array,l,mid);
//           mergesort(array,mid+1,r);
//           merge(array,l,mid,r);
//       }
// }
// int main(){
//     int n;
//     cin>>n;
//     int array[n];
//     for(int i=0;i<n;i++){
//         cin>>array[i];
//     }
//     mergesort(array,0,n-1);
//     for(int i=0;i<n;i++){
//         cout<<array[i]<<" "<<endl;
//     }
// }

// // 5TH TYPE
// ///!---->>QUICK SORT<<----//---->>

// #include<bits/stdc++.h>
// using namespace std;
// void swap(int array[],int i,int j){
//       int temp=array[i];
//       array[i]=array[j];
//       array[j]=temp;
// }
// int partiton(int array[],int l,int r){
//     int pivot=array[r];
//     int i=l-1;
    
//     for(int j=l;j<r;j++){
//          if(array[j]<pivot){
//            i++;
//            swap(array,i,j);
//          }
//     }
//     swap(array,i+1,r);
//     return i+1;
// }
// void quicksort(int array[],int l, int r){
//         if(l<r){
//             int pi=partiton(array,l,r);
//             quicksort(array,l,pi-1);
//             quicksort(array,pi+1,r);
//         }
// }
// int main(){
//     int n;
//     cin>>n;

//     int array[n];
//     for(int i=0;i<n;i++){
//         cin>>array[i];
//     }
//     quicksort(array,0,n-1);
//     for(int i=0;i<n;i++){
//         cout<<array[i]<<endl;
//     }
// }


// //*******************************************DNF-SORT**************************************************************//
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     int array[n];
//     for(int i=0;i<n;i++){
//         cin>>array[i];
//     }
//     int l = 0;
//     int mid = 0;
//     int r = n - 1;
//     while(mid<=r){
//         if(array[mid]==0){
//             swap(array[l], array[mid]);
//             l++;
//             mid++;
//         }
//         else if(array[mid]==1){
//             mid++;
//         }
//         else{
//             swap(array[r], array[mid]);
//             r--;
//             mid;
//         }
//     }
//      for(int i=0;i<n;i++){
//          cout << array[i] << " ";
//     }
// }