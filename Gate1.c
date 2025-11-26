#include<stdio.h>

int main()
{
    int row,col;
    // int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};

    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    printf("Row wise traversal! \n");

    for(row=0;row<3;row++)
    {
        for(col=0;col<3;col++)
        {
            printf("%d ",arr[row][col]);
        }
        printf("\n");
    }

    printf("Column wise Traversal! \n");

    for(col=0;col<3;col++)
    {
        for(row=0;row<3;row++)
        {
            printf("%d ",arr[row][col]);
        }
        printf("\n");
    }
    
    return 0;
}