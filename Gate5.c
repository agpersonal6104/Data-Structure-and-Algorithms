#include<stdio.h>
#include<string.h>

int main()
{
    char A[]="Ayush";
    char B[]="Gauniyal";
    strcat(A, B);
    printf("Concatenated string is:%s\n", A);
    printf("Length is:%d\n", strlen(A));
    return 0;
}