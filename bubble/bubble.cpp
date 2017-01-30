#include <iostream>
using namespace std;

void swap(int [], int, int);
void print(int [], int);

int main() 
{
    int arr[] = {5, 3, 1, 8, 4};
    int n = 5;
    bool sflag;
    for(int i = 0; i < n-1; i++)
    {
        sflag = false;
        for(int j = 0; j < n-1-i; j++)
        {
            if(arr[j+1] < arr[j])
            {
                cout << "before swap: " << endl;
                print(arr, n);
                swap(arr, j, j+1);
                cout << "after swap: " << endl;
                print(arr, n);
                cout << endl;
                sflag = true;
            }
        }
    }

    return 1;
}
void swap(int a[], int j, int k)
{
    int tmp = a[j];
    a[j] = a[k];   
    a[k] = tmp;
}

void print(int a[], int n)
{
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
