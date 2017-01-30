//Alexzander Avila
//CMPS 312
//heapsort
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void heapify(int *arr);
void heapsort(int *arr);
void percolateDown(int * arr);

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int n = 10;
    if (argc > 1)
        n = atoi(argv[1]);
    int *arr = new int[n+1];
    for(int i = 1; i < n+1; i++)
        arr[i] = rand() % 1000;
    arr[0] = n;

    cout << "before heapsort:" << endl;
    for(int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl << endl;
    heapsort(arr);

    //view array
    cout << "after heapsort:" << endl;
    for (int i = 1; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    delete [] arr;
    return 0;
}
void percolateDown(int *arr, int parent)
{
    while(parent * 2 <= arr[0])
    {
        int lchild = (2 * parent);
        int rchild = lchild + 1;
        int child = lchild;
        if (rchild <= arr[0])
        {
            if(arr[rchild] > arr[lchild])
            {
                child = rchild;
            }
        }
        if (arr[child] > arr[parent])
        {
            //swap
            int tmp = arr[parent];
            arr[parent] = arr[child];
            arr[child] = tmp;
            parent = child;
        }
        else
        {
            return;
        }
    }
}
void heapify(int *arr)
{
    int parent = arr[0] / 2;
    while(parent >= 1)
    {
        percolateDown(arr, parent);
        --parent;
    }
}
void heapsort(int *arr)
{
    heapify(arr);
    //int n = arr[0];
    while(arr[0] > 0)
    {
        //swap
        int tmp = arr[1];
        arr[1] = arr[arr[0]];
        arr[arr[0]] = tmp;
        --arr[0];
        percolateDown(arr, 1);
    }
}
