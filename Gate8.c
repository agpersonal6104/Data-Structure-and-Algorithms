#include<stdio.h>

int main()
{
    char A[]="Ayush Gauniyal";
    char B[]="Hello";
    int i;

    for(i=0;B[i]!='\0';i++)
    {
        A[i]=B[i];
    }
    A[i]='\0';

    printf("%s",A);
    return 0;
}