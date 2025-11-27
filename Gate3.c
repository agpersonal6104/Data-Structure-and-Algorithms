#include <stdio.h>

// Call by Value
void swap1(int a,int b)
{
    int t=a;
    a=b;
    b=t;
    printf("%d %d\n",a,b);
}

// Call by Reference using Pointers
void swap2(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
    printf("%d %d\n",*a,*b);
}

// Call by Reference using References/Call by Address
void swap3(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
    printf("%d %d\n",a,b);
}

int main()
{
    int x=5,y=8;
    printf("before: %d %d\n",x,y);
    swap3(x,y);
    printf("after: %d %d\n",x,y);
}