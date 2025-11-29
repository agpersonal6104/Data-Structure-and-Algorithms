#include<stdio.h>
#include<string.h>

int main()
{
    char A[]="Hello\0 World!";
    printf("Length of the string is:%d\n", strlen(A));
    return 0;
}