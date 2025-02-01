#include <stdio.h>
#include <conio.h>


void InsertionSort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int arr[100];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    InsertionSort(arr, n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    getch();
    return 0;
}