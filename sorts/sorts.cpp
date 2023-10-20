#include <bits/stdc++.h>
using namespace std;
void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge(int arr[], int s, int mid, int e)
{
    int n1 = mid - s + 1;
    int n2 = e - mid;
    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[i + s];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = s;
    while (i < n1 and j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k++] = a[i++];
        }
        else
        {
            arr[k++] = b[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = a[i++];
    }
    while (j < n2)
    {
        arr[k++] = b[j++];
    }
}
void merge_sort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    merge_sort(arr, s, mid);
    merge_sort(arr, mid + 1, e);
    merge(arr, s, mid, e);
}

int find_pivot(int arr[], int s, int e)
{
    int pivot = arr[e];
    int i = s - 1;
    for (int j = s; j < e; j++)
    {
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[e]);
    return i + 1;
}
void quick_sort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int pos = find_pivot(arr, s, e);
    quick_sort(arr, s, pos - 1);
    quick_sort(arr, pos + 1, e);
}

int main()
{
    int arr[10] = {9, 7, 1, 4, 3, 8, 6, 0, 2, 5};
    // selection_sort(arr, 10);
    // cout << "After the selection sort the Array is: ";
    // bubble_sort(arr, 10);
    // cout << "After the Bubble sort the Array is: ";
    // insertion_sort(arr, 10);
    // cout << "After the insertion sort the Array is: ";
    // merge_sort(arr, 0, 9);
    // cout << "After the merge sort the Array is: ";
    quick_sort(arr, 0, 9);
    cout << "After the quick sort the Array is: ";
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}