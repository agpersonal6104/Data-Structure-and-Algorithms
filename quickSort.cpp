#include<iostream>
using namespace std;

int partition(int arr[],int low,int high)
{
    int pivot=arr[low];
    int i=low+1;
    int j=high;

    do{
        while(arr[i]<=pivot)
        {
            i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }while(i<j);
    int temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;
}

void quickSort(int arr[],int low, int high)
{
    int partitionIndex;  // Index of pivot element
    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1); // Sort left array
        quickSort(arr, partitionIndex + 1, high); // Sort right array
    }
}

void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    quickSort(arr,0,n-1);
    printArray(arr,n);
    return 0;
}