#include <stdio.h>
#include <stdlib.h>

struct node
{
    int d;
    struct node* link;
};

typedef struct node NODE;
NODE *newnode,*start=NULL,*currptr,*prevptr,*temp;

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
 else if(start->d>=temp->d)
 {
    temp->link=start;
    start=temp;
 }
 else
 {
    currptr=start;
    prevptr=NULL;
    while(currptr!=NULL&&currptr->d<=temp->d)
    {
        prevptr=currptr;
        currptr=currptr->link;
    }
    if(currptr==NULL&&prevptr->d<=temp->d)
        prevptr->link=temp;
    else
    {
        temp->link=prevptr->link;
        prevptr->link=temp;
    }
 }
}

void display()
{
 if(start==NULL)
    printf("\nList is empty\n");
 else
    for(currptr=start;currptr!=NULL;currptr=currptr->link)
        printf("\n%d",currptr->d);
 printf("\n\n");
}

int main()
{
 while(1)
 {
    int ch;
    printf("\n\n\nENTER\n 1.for insertion\n 2.for display\n 3.to exit\n\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        insert();
        break;
        case 2:
        display();
        break;
        case 3:
        exit(0);
        break;
        default:
        printf("\n Wrong choice entered \n");
    }  
 }
}
