#include<bits/stdc++.h>
using namespace std;
bool issafe(int **array,int x,int y,int n){
    if(x<n and y<n and array[x][y]==1){
        return true;
    }
    return false;
}
bool Ratmovememts(int **array,int n,int x,int y, int **sol){
    if(x==n-1 and y==n-1 and array[x][y]==1){
        return true;
    }
    
    if(issafe(array,x,y,n)){
         sol[x][y] = 1;
         if(Ratmovememts(array,x+1,y,n, sol)){
             return true;
         }
         if(Ratmovememts(array,x,y+1,n,sol)){
             return true;
         }
         sol[x][y] = 0;
         return false;
    }
    return false;
}
int main(){
    int n;
    int arr[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    int solarr[n][n] = {0};
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


#include <bits/stdc++.h>
using namespace std;
bool issafe(int **array,int x,int y,int n){
    for (int row = 0; row < x;row++){
        if(array[row][y]==1){
            return false;
        }
    }
    int row = x;
    int col = y;
    while(row>=0 and col>=0){
        if(array[row][col]==1){
            return false;
        }
        row--;
        col--;
    }
     row = x;
     col = y;
    while(row>=0 and col<n){
        if(array[row][col]==1){
            return false;
        }
        row--;
        col++;
    }
    return true;

}
bool Queen(int **array,int x,int n){
    if(x>=n){
        return true;
    }
    for(int col = 0; col < n;col++){
             if(issafe(array,x,col,n)){
                 array[x][col] = 1;
              
                if(Queen(array,x+1,n)){
                    return true;
               }
              array[x][col] = 0;
         }
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    int**array=new int*[n];
    for(int i=0;i<n; i++){
        array[i] =new int[n];
        for(int j=0;j<n; j++){
            array[i][j] = 0;
        }
    }
    if(Queen(array,0,n)){
          for(int j=0; j<n; j++){
              for(int i=0; i<n; i++){
                  cout << array[j][i] << " ";
              }
              cout<<endl;
          }
    }
}