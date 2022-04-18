#include <iostream>
using namespace std;

void printArray(int arr[], int len);

void bubbleSort(int arr[], int length)
{
    for(int i = 0; i < length - 1; i++)
    {
        for(int j = 0; j < length - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }        
    }
}

int Partition(int *arr, int left, int right)
{
    int pivot = left;
    int len = right - left + 1;

    while(left <= right)
    {
        for(; right >= pivot; right--)
        {
            if(arr[pivot] > arr[right])
            {
                swap(arr[pivot], arr[right]);
                left = pivot + 1;
                pivot = right;
                break;
            }
        }
        printArray(arr, len);
        for(; left <= pivot; left++)
        {
            if(arr[pivot] < arr[left])
            {
                swap(arr[pivot], arr[left]);
                right = pivot - 1;
                pivot = left;
                break;
            }
        }

        printArray(arr, len);
    }

    return pivot;
}

void quickSort(int *arr, int left, int right)
{
    if(left > right)
            return;

    int pivot = Partition(arr, left, right);

    quickSort(arr, left, pivot - 1);
    quickSort(arr, pivot + 1, right);
}


void buildMaxHeap(int arr[], int begin, int end)
{
    int dad = begin;
    int son = 2 * dad + 1;
    
    while(son <= end)
    {
        if((son + 1 < end) && (arr[son] < arr[son + 1]))
            son = son + 1;
        if(arr[dad] > arr[son])
            return;
        else
        {
            swap(arr[dad], arr[son]);

            dad = son;
            son = 2*dad + 1;
        }
    }
}

void heapSort(int arr[], int len)
{
    for(int i = len/2 - 1; i >= 0 ; i--)
    {
        cout << "first...." << endl; 
        buildMaxHeap(arr, i, len - 1);
        printArray(arr, 10);
    }

    for(int i = len - 1; i > 0; i--)
    {
        cout << "second..." << endl;
        printArray(arr, 10);
        swap(arr[0], arr[i]);
        buildMaxHeap(arr, 0, i - 1);
        printArray(arr, 10);
    }
}



void printArray(int arr[], int len)
{
    for(int i = 0; i < len; i++)
        cout << arr[i];
    cout << endl;
}

int main()
{
    int arr[10] = {3,1,4,2,7,5,9,6,8,0};

//    bubbleSort(arr, 10);

    cout << "QuickSort Test!!!" << endl;
    quickSort(arr, 0, 9);

//    cout << "heapSort Test" << endl;
//    heapSort(arr, 10);

    printArray(arr, 10);
}
