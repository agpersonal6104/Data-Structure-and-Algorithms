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

void insertAt(int item, int index)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=item;
    temp->next=NULL;
    if(index==0)
    {
        temp->next=start;
        start=temp;
        return;
    }
    struct node *p=start;
    for(int i=0;i<index-1 && p!=NULL;i++)
    {
        p=p->next;
    }
    if(p==NULL)
    {
        printf("Index out of bounds\n");
        free(temp);
        return;
    }
    temp->next=p->next;
    p->next=temp;
}

void deleteFirst()
{
    if(start==NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *temp=start;
    start=start->next;
    free(temp);
}

void deleteLast()
{
    if(start==NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(start->next==NULL)
    {
        free(start);
        start=NULL;
        return;
    }
    struct node *p=start;
    while(p->next->next!=NULL)
    {
        p=p->next;
    }
    free(p->next);
    p->next=NULL;
}

void deleteAt(int index)
{
    if(start==NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(index==0)
    {
        struct node *temp=start;
        start=start->next;
        free(temp);
        return;
    }
    struct node *p=start;
    for(int i=0;i<index-1 && p->next!=NULL;i++)
    {
        p=p->next;
    }
    if(p->next==NULL)
    {
        printf("Index out of bounds\n");
        return;
    }
    struct node *temp=p->next;
    p->next=temp->next;
    free(temp);
}

void search(int item)
{
    struct node *p=start;
    int index=0;
    while(p!=NULL)
    {
        if(p->data==item)
        {
            printf("Item %d found at index %d\n",item,index);
            return;
        }
        p=p->next;
        index++;
    }
    printf("Item %d not found in the list\n",item);
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