#include<stdio.h>

int main()
{
    char A[20]="Ayush";
    char B[]="Gauniyal";
    int i,j;

    for(i=0;A[i]!='\0';i++);

    for(j=0;B[j]!='\0';i++,j++)
    {
        A[i]=B[j];
    }
    A[i]='\0';

    printf("%s",A);
    return 0;
}