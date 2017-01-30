//Alexzander Avila
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void Merge(int* &, int, int, int);
void MergeSort(int* &, int, int);
void printArray(int *, int);

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int n = 8;
    if(argc > 1)
        n = atoi(argv[1]);
    int *arr = new int[n+1];
    arr[0] = n;
    for(int i = 1; i < n+1; i++)
    {
        arr[i] = rand() % 1000;
    }

    cout << "Before merge sort:" << endl;
    printArray(arr, n);

    MergeSort(arr, 1, n);

    cout << "\nAfter merge sort:" << endl;
    printArray(arr, n);

    delete [] arr;
    return 1;
}

void Merge(int* &arr, int start, int mid, int end)
{
    int i, j, k;
    int n1 = mid - start + 1;
    int n2 = end - mid;

    // create temp array to store left and right half values
    int Left_half[n1];
    int Right_half[n2];

    //copy values into left and right halves
    for(int i = 0; i < n1; i++)
        Left_half[i] = arr[start+i];
    for(int j = 0; j < n2; j++)
        Right_half[j] = arr[mid + 1 + j];

    i = 0; //initial index of first half
    j = 0; //initial index of second half
    k = start; //initial index of merged array

    //get the lowest values as the first in the array
    while(i < n1 && j < n2)
    {
        if(Left_half[i] <= Right_half[j])
        {
            arr[k] = Left_half[i];
            i++;
        }
        else
        {
            arr[k] = Right_half[j];
            j++;
        }
        k++;
    }

    //copy whatever is left from left half
    while(i < n1)
    {
        arr[k] = Left_half[i];
        i++;
        k++;
    }
    //copy whatever is left from right half
    while(j < n2)
    {
        arr[k] = Right_half[j];
        j++;
        k++;
    }
}

void MergeSort(int* &arr, int start, int end)
{

    if(start < end)
    {
        int mid = start+(end-start)/2;

        //sort first and second halves
        MergeSort(arr, start, mid);
        MergeSort(arr, mid+1, end);
        
        Merge(arr, start, mid, end);
    }
}

void printArray(int *arr, int mid)
{
    for(int i = 1; i < mid; i++)
        cout << arr[i] << " ";
    cout << endl;
}




