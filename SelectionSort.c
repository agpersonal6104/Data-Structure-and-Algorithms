#include<stdio.h>
#include<conio.h>

void Selection(int arr[], int n)
{
    int i, j, min, temp;
    for(i=0; i<n-1; i++)
    {
        min = i;
        for(j=i+1; j<n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main()
{
    int arr[20], n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    Selection(arr, n);
    printf("Sorted array: ");
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    getch();
    return 0;
}