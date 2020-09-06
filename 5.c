#include <stdio.h>
#include <stdlib.h>

struct node
{
    int d;
    struct node* link;
};

typedef struct node NODE;
NODE *newnode,*start=NULL,*currptr,*prevptr,*ptr,*temp;

NODE *getnode()
{
    newnode=(NODE*)malloc(sizeof(NODE));
    newnode->link=NULL;
    printf("\nEnter the element\n");
    scanf("%d",&newnode->d);
    printf("\n\n");
    return newnode;
}

void insert()
{
 temp=getnode();
 if(start==NULL)
    start=temp;
 else
 {
    for(ptr=start;ptr->link!=NULL;ptr=ptr->link);
    ptr->link=temp;
 }
}


void reverselist()
{
 if(start==NULL)
    printf("\nList is empty\n");
 else
 {
    prevptr=start;
    currptr=start->link;
    start=start->link;
    prevptr->link=NULL;
    while(start!=NULL)
    {
        start=start->link;
        currptr->link=prevptr;
        prevptr=currptr;
        currptr=start;
    }
    start=prevptr;
 }
}


void display()
{
 if(start==NULL)
    printf("\n List empty\n");
 else
 {
    printf("\n\n");
    for(currptr=start;currptr!=NULL;currptr=currptr->link)
        printf("\n%d",currptr->d);
    printf("\n\n");
 }
}


int main()
{
 while(1)
 {
    int ch;
    printf("\n\n\nENTER\n 1.for insertion\n 2.for reversing linked list\n 3.for display\n 4.to exit\n\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            insert();
            break;
        case 2:
            reverselist();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
        printf("\n Wrong choice entered \n");
    }
 }
}