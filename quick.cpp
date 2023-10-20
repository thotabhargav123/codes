/*{
     It is also devide and conquer algorithm.
    basic:
         1) we will select an element.
         2) we will traverse and keep it in it's correct position.
         3) such that  all elements left to the selected element are small.
         4) right to selelcted element are big.
         5) the elements right to the selected  and left to the selected are not sorted in themselves.
         6) we will call the function again to sort right and left side of the function.
}*/
#include <bits/stdc++.h>

using namespace std;
void swap(int array[], int i, int j)
{
    int temp = array[i]; /*{swap of array take spalce}*/
    array[i] = array[j];
    array[j] = temp;
}
int partition(int array[], int l, int r)
{
    int pivot = array[r];
    int i = l - 1;
    int j = l;
    /*{in this i behind the array and j=l and it will go r-1 element.
         in this function I selected pivot is last elelment.
         and it is constant through out the program.
         }*/
    for (int j = l; j < r; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(array, i, j); //Another function call;

            /*{
                In the loop if elelment is less than r
                first i is incremented bcz it is outside the array , swap function is called. 
                next j is incremented. 
            }*/
        }
    }
    /*{After entire loop is runned all the elements which are below index i and i are less than pivot
       so,pivot element shoulkd present on i+1 index bcz after i they are greater than the pivot
         so,again swap function is called.}*/
    swap(array, i + 1, r); //==>> function call//
    return i + 1;
}
void quicksort(int array[], int l, int r)
{
    if (l < r)
    {                                    //runs up to l<r such that every element pass
                                         // the call
        int pi = partition(array, l, r); //-->> in this we will take an element and we will call the
        /*{The rerturn value of the above function is the pi.
               pi is the index of the number whih is in it's correct position 
               so we don't need to worrry about pi index element and we will call quick sort function 
               up t0 pi-1 and from pi+1{p is excluded}.
               }*/
        // function requersively.to devide the array

        quicksort(array, l, pi - 1);
        quicksort(array, pi + 1, r);
    }
}
int main()
{
    int n; // declaration of size of array for input//
    cin >> n;
    int array[n]; // array declaration//
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    quicksort(array, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
}