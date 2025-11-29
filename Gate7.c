#include<stdio.h>

int main()
{
    char a[]="Sample";
    char b[]="Simple";
    int i,comp=0;

    for(i=0;a[i]!='\0' || b[i]!='\0';i++)
    {
        if(a[i]!=b[i])
        {
            comp=a[i]-b[i];
            break;
        }
    }
    printf("%d",comp);
    return 0;
}