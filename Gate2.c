#include<stdio.h>
float area(float r)
{
    return (3.14*r*r);
}

float circum(float r)
{
    return (2*3.14*r);
}

int main()
{
    float rad;
    printf("Enter radius!\n");
    scanf("%f",&rad);
    printf("Area of Circle is = %f\n",area(rad));
    printf("Parameter of Circle is = %f",circum(rad));
    return 0;
}