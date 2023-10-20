// ? sequential search
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//   int n;
//   cin >> n;
//   int array[n];
//   for (int i = 0; i < n; i++)
//   {
//     cin >> array[i];
//   }
//   int query;
//   cin >> query;
//   for (int i = 0; i < n; i++)
//   {
//     if (query == array[i])
//     {
//       cout << "the value " << array[i] << "is present at index " << i << endl;
//       return 1;
//     }
//   }
//   cout << "no value present of given query";
//   return 1;
// }

// // 2nd type of search
// //? binary search
// #include <bits/stdc++.h>
//     using namespace std;
// int search(int array[], int l, int r, int k)
// {

//   if (r >= l)
//   {
//     int mid = (l + r - 1) / 2;
//     if (array[mid] == k)
//     {
//       // cout<<mid;
//       return mid;
//     }
//     if (array[mid] > k)
//     {
//       return search(array, l, mid - 1, k);
//     }
//     if (array[mid] < k)
//     {
//       return search(array, mid + 1, r, k);
//     }
//   }
//   return -1;
// }
// int main()
// {
//   int n;
//   cin >> n;
//   int array[n];
//   for (int i = 0; i < n; i++)
//   {
//     cin >> array[i];
//   }
//   int k;
//   cin >> k;
//   cout << search(array, 0, n - 1, k);
// }

//**************************************FIRST AND LAST INDEX USING SEARCH*****************************************//
// #include <bits/stdc++.h>
// using namespace std;

// int first(int arr[], int low, int high, int x, int n)
// {
//     if (high >= low) {
//         int mid = low + (high - low) / 2;
//         if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
//             return mid;
//         else if (x > arr[mid])
//             return first(arr, (mid + 1), high, x, n);
//         else
//             return first(arr, low, (mid - 1), x, n);
//     }
//     return -1;
// }
// int last(int arr[], int low, int high, int x, int n)
// {
//     if (high >= low) {
//         int mid = low + (high - low) / 2;
//         if ((mid == n - 1 || x < arr[mid + 1]) && arr[mid] == x)
//             return mid;
//         else if (x < arr[mid])
//             return last(arr, low, (mid - 1), x, n);
//         else
//             return last(arr, (mid + 1), high, x, n);
//     }
//     return -1;
// }
// int main()
// {
//     int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
//     int n = sizeof(arr) / sizeof(int);

//     int x = 8;
//     printf("First Occurrence = %d\t",
//            first(arr, 0, n - 1, x, n));
//     printf("\nLast Occurrence = %d\n",
//            last(arr, 0, n - 1, x, n));

//     return 0;
// }

///****************************Sorted Rotated Array************************************///

#include<bits/stdc++.h>
using namespace std;
int search(int arr[],int start,int end,int n){
    if(end>=start){
            int mid=start+(end-start)/2;
            if(arr[(mid+n-1)%n]>arr[mid] and arr[(mid+1)%n]>arr[mid]){
                      return mid;
            }
            else if(arr[start]<=arr[mid]){
               return search(arr,mid+1,end,n);
            }
            else if(arr[end]>=arr[mid]){

                return search(arr,start,mid-1,n);
            }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<search(arr,0,n-1,n);
}

//********************Almosg sorted Array*****************************************************************//////////

// #include <bits/stdc++.h>
// using namespace std;
// int search(int arr[], int l, int r, int key)
// {
//   if (l > r)
//   {
//     return -1;
//   }
//   int mid = l + (r - l) / 2;
//   if (arr[mid] == key or arr[mid + 1] == key or arr[mid - 1] == key)
//   {
//     if (arr[mid] == key)
//     {
//       return mid;
//     }
//     else if (arr[mid + 1] == key)
//     {
//       return mid + 1;
//     }
//     else
//     {
//       return mid - 1;
//     }
//   }
//   else
//   {
//     if (arr[mid] < key)
//     {
//       return search(arr, l, mid - 1, key);
//     }
//     else
//     {
//       return search(arr, mid + 1, r, key);
//     }
//   }

// }
// int main()
// {
//   int n;
//   cin >> n;
//   int arr[n];
//   for (int i = 0; i < n; i++)
//   {
//     cin >> arr[i];
//   }
//   cout << search(arr, 0, n - 1, 3);
// }

//**********************************Smalles t large eleement*****************************************/***//

// #include <bits/stdc++.h>
// using namespace std;
// int gs(int arr[], int l, int r, int k)
// {
//   static int ma = INT_MIN;
//   if (l > r)
//   {
//     if (ma < 0)
//     {
//       return -1;
//     }
//     return ma;
//   }
//   int mid = l + (r - l) / 2;
//   if (arr[mid] == k)
//   {
//     ma = arr[mid];
//     return ma;
//   }
//   else if (arr[mid] > k)
//   {
//     // ma = max(ma, arr[mid]);
//     return gs(arr, l, mid - 1, k);
//   }
//   else
//   {
//     ma = max(ma, arr[mid]);
//     return gs(arr, mid + 1, r, k);
//   }
// }
// int main()
// {
//   int n = 0;
//   cin >> n;
//   int arr[n];
//   for (int i = 0; i < n; i++)
//   {
//     cin >> arr[i];
//   }
//   cout << gs(arr, 0, n - 1, 4);
// }

///*****************************************Greastest Smalllest Element*******************************************//

// #include <bits/stdc++.h>
// using namespace std;
// int gs(int arr[], int l, int r, int k)
// {
//   static int ma = INT_MAX;
//   if (l > r)
//   {
//     // if (ma < 0)
//     // {
//     //   return -1;
//     // }
//     return ma;
//   }
//   int mid = l + (r - l) / 2;
//   if (arr[mid] == k)
//   {
//     ma = arr[mid];
//     return ma;
//   }
//   else if (arr[mid] > k)
//   {
//     ma = min(arr[mid], ma);
//     return gs(arr, l, mid - 1, k);
//   }
//   else
//   {
//     // ma = max(ma, arr[mid]);
//     return gs(arr, mid + 1, r, k);
//   }
// }
// int main()
// {
//   int n = 0;
//   cin >> n;
//   int arr[n];
//   for (int i = 0; i < n; i++)
//   {
//     cin >> arr[i];
//   }
//   cout << gs(arr, 0, n - 1, 4);
// }

// #include <bits/stdc++.h>
// using namespace std;
// int smallcount(int arr[], int l, int r, int key)
// {
//   static int diff = INT_MAX;
//   int num;

//   if (l > r)
//   {
//     return num;
//   }
//   int mid = l + (r - l) / 2;
//   if (arr[mid] == key)
//   {
//     diff = 0;
//     return arr[mid];
//   }
//   if (arr[mid] > key)
//   {
//     if (abs(arr[mid] - key) < diff)
//     {
//       diff = abs(arr[mid] - key);
//       num = arr[mid];
//     }
//     return smallcount(arr, l, mid - 1, key);
//   }
//   else
//   {
//     if (abs(arr[mid] - key) < diff)
//     {
//       diff = abs(arr[mid] - key);
//       num = arr[mid];
//     }
//     return smallcount(arr, mid + 1, r, key);
//   }
// }
// int main()
// {
//   int n = 0;
//   cin >> n;
//   int arr[n];
//   for (int i = 0; i < n; i++)
//   {
//     cin >> arr[i];
//   }
//   cout << smallcount(arr, 0, n - 1, 4);
// }

//************************************PEAK ELEMENT*****************************************************************//
// #include <bits/stdc++.h>
// using namespace std;

// int findPeakUtil(int arr[], int low,
//                  int high, int n)
// {

//   int mid = low + (high - low) / 2;

//   if ((mid == 0 || arr[mid - 1] <= arr[mid]) &&
//       (mid == n - 1 || arr[mid + 1] <= arr[mid]))
//     return mid;

//   else if (mid > 0 && arr[mid - 1] > arr[mid])
//     return findPeakUtil(arr, low, (mid - 1), n);

//   else
//     return findPeakUtil(
//         arr, (mid + 1), high, n);
// }

// int findPeak(int arr[], int n)
// {
//   return findPeakUtil(arr, 0, n - 1, n);
// }

// int main()
// {
//   int arr[] = {3,5,3,2,0};
//   int n = sizeof(arr) / sizeof(arr[0]);
//   cout << "Index of a peak point is "
//        << findPeak(arr, n);
//   return 0;
// }

// #include <iostream>
// using namespace std;
// int search(int A[], int n, int B)
// {
// 	int low = 0, high = n - 1;
// 	while (low <= high) {
// 		int mid = (high + low) / 2;
// 		if (A[mid] == B)
// 			// if we found the element we will return it.
// 			return mid;
// 		else if (mid == n - 1 || A[mid] < A[mid + 1]) {
// 			// we are in the increasing part of the array
// 			// we will apply binarySearch as we do in a
// 			// simple sorted increasing array
// 			if (A[mid] < B) {
// 				low = mid + 1;
// 			}
// 			else
// 				high = mid - 1;
// 		}
// 		else {
// 			// the array is decreasing
// 			if (A[mid] < B) {
// 				high = mid - 1;
// 			}
// 			else
// 				low = mid + 1;
// 		}
// 	}
// 	return -1;
// }
// int main()
// {
// 	int arr[] = { 1, 2, 3, 2, 1, 0 };
// 	cout << "Element found at " << search(arr, 6, 0)
// 		<< " index";
// 	return 0;
// // this code is contributed by Ankit Jha
// }

//**********************************Search in 2d array*************************************************//

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// 	int n;
// 	cin >> n;
// 	int m;
// 	cin>> m;
// 	int key;
// 	cin>> key;
// 	int arr[n][m];
// 	for(int i=0; i< n;i++){
// 		for(int j=0; j< m;j++){
//               cin>> arr[i][j];
// 		}
// 	}
// 	int i = 0;
// 	int j = m - 1;
// 	bool sdf = 1;
// 	while(i>=0 && j>=0 && i<n and j<m){
// 		if(arr[i][j]==key){
// 			cout << i << " " << j << endl;
// 			break;
// 		}
// 		else if(arr[i][j]>key){
// 			j--;
// 		}
// 		else if(arr[i][j]<key){
// 			i++;
// 		}
// 		if(i==n or j==-1){
// 			sdf = 0;
// 		}
// 	}
// 	if(sdf==0){
// 		cout << "Element not found" << endl;
// 	}
// }

//************************************Student and min books*******************************************************//

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//   int n;
//   cin >> n;
//   int k; //***No  of given objects
//   cin >> k;
//   int arr[n];
//   int maxi = -1;
//   int sum = 0;
//   for (int i = 0; i < n; i++)
//   {
//     cin >> arr[i];
//     sum += arr[i];
//     maxi = max(maxi, arr[i]);
//   }
//   cout << "THE MAXI IS " << maxi << endl;
//   int start = maxi;
//   cout << "THE SUM " << sum << endl;
//   int end = sum;
//   int ans = -1;
//   while (start <= end)
//   {
//     int mid = start + (end - start) / 2;
//     cout << "THE MID IS " << mid << endl;
//     int objects_required = 1;
//     ; //* no of objects required if max no of elemts can get is mid;
//     int no_of_elements = 0;
//     int max_elements_object_got = -1;
//     for (int i = 0; i < n; i++)
//     {
//       no_of_elements = no_of_elements + arr[i];
//       if (no_of_elements > mid)
//       {
//         cout << "THE SUM " << no_of_elements << " IS Greater than mid " << endl;
//         objects_required++;
//         max_elements_object_got = max(max_elements_object_got, no_of_elements - arr[i]);
//         no_of_elements = arr[i];
//       }
//     }
//     max_elements_object_got = max(max_elements_object_got, no_of_elements);
//     cout << "objects_required is equal to" << objects_required << endl;
//     cout << "max no of elements a object got is " << max_elements_object_got << endl;
//     if (objects_required == k)
//     {
//       cout << "THE objects requirement is met" << endl;
//       if (max_elements_object_got < mid)
//       {
//         cout << "BUT THE MAX_ELEMENTS_OBJECT_GOT IS SMALLER THAN MID" << endl;
//         end = mid - 1;
//       }
//       else
//       {
//         cout << "ALL requirement are meet" << endl;
//         ans = mid;
//         end = mid - 1;
//       }
//     }
//     else if (objects_required > k)
//     {
//       cout << "THE objects requirement is Greater" << endl;
//       start = mid + 1;
//     }
//     else if (objects_required < k)
//     {
//       cout << "The objects requirement is smaller" << endl;
//       end = mid - 1;
//     }
//   }
// }


///*****different model question:
// #include <bits/stdc++.h>
// using namespace std;
// int n,c;
// int func(int num,int array[])
// {
//     int cows=1,pos=array[0];
//     for (int i=1; i<n; i++)
//     {
//         if (array[i]-pos>=num)
//         {
//             pos=array[i];
//             cows++;
//             if (cows==c)
//                 return 1;
//         }
//     }
//     return 0;
// }
// int bs(int array[])
// {
//     int ini=0,last=array[n-1],max=-1;
//     while (last>ini)
//     {
//         //cout<<last<<" "<<ini<<endl;
//         int mid=(ini+last)/2;
//         if (func(mid,array)==1)
//         {
//             //cout<<mid<<endl;
//             if (mid>max)
//                 max=mid;
//             ini=mid+1;
//         }
//         else
//             last=mid;
//     }
//     return max;
// }
// int main()
// {
//     int t;
//     scanf("%d",&t);
//     while (t--)
//     {
//         scanf("%d %d",&n,&c);
//         int array[n];
//         for (int i=0; i<n; i++)
//             scanf("%d",&array[i]);
//         sort(array,array+n);
//         //cout<<" dfsa \n";
//         int k=bs(array);
//         printf("%d\n",k);
//     }
//     return 0;
// }