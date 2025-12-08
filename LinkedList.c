#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start=NULL;

void insertFirst(int item)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=item;
    if(start==NULL)
    {
        start=temp;
        return;
    }
    temp->next=start;
    start=temp;
}

void insertLast(int item)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    struct node *p;
    p=start;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    temp->data=item;
    p->next=temp;
    temp->next=NULL;
    return;
}

int main()
{
    insertFirst(10);
    insertFirst(20);
    insertLast(30);
    return 0;
}