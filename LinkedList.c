#include<stdio.h>
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
    if(temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    temp->data=item;
    temp->next=NULL;
    
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
    if(temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    temp->data=item;
    temp->next=NULL;
    
    if(start==NULL)
    {
        start=temp;
        return;
    }
    
    struct node *p;
    p=start;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=temp;
}

int main()
{
    insertFirst(10);
    insertFirst(20);
    insertLast(30);
    
    // Optional: Print the list to verify
    struct node *current = start;
    printf("Linked List: ");
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    
    return 0;
}