
#include <stdio.h>
#include <stdlib.h>

struct node
{
 int d;
 struct node *link;
};

typedef struct node NODE;
NODE *prevptr,*currptr,*start,*newnode;

NODE *getnode()
{
 newnode=(NODE*)malloc(sizeof(NODE));
 newnode->link=NULL;
 printf("\nENTER THE DATA\n");
 scanf("%d",&newnode->d);
 return newnode;
}

void insert()
{
 newnode=getnode();
 currptr=start;
 if(start==NULL)
    start=newnode;
 else
 {
 while(currptr->link!=NULL)
    currptr=currptr->link;
 currptr->link=newnode;
 }
}
void delalt()
{
 if(start==NULL)
 printf("\nLIST IS EMPTY\n");
 else
 {
 prevptr=start;
 currptr=prevptr->link;
 while(prevptr!=NULL && currptr!=NULL)
 {
 prevptr->link=currptr->link;
 free(currptr);
 prevptr=prevptr->link;
 if(prevptr!=NULL)
 currptr=prevptr->link;
 }
 }
}


void display()
{
 if(start==NULL)
    printf("\nLIST IS EMPTY\n");
 else
    for(currptr=start;currptr!=NULL;currptr=currptr->link)
        printf("\n%d\n",currptr->d);
}


int main()
{
while(1)
{
    printf("\n\nENTER\n1.FOR INSERTION\n2.FOR DELETING ALTERNATE NODES\n3.FOR DISPLAY\n4.FOR EXIT\n\n");
    int ch;
    scanf("%d",&ch);
    printf("\n\n");
    switch(ch)
    {
        case 1:insert();break;
        case 2:delalt();break;
        case 3:display();break;
        case 4:exit(0);break;
        default:printf("\nYOU HAVE ENTERED WRONG CHOICE\n");
    }
}
return 0;
}