#include <iostream>
using namespace std;

void swap(int [], int, int);
void print(int [], int);

int main()
{
    int s;
    int arr[] = {5, 3, 1, 8, 4};
    int n= 5;

    for(int i = 0; i < n; i++)
    {
        s = i;
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[s])
                s = j;
        }
        cout << "before swap: " << endl;
        print(arr, n);
        swap(arr, i, s);
        cout << "after swap: " << endl;
        print(arr, n);
        cout << endl;
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
