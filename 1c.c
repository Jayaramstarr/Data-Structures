#include <stdio.h>
#include <stdlib.h>

struct node{
 int d;
 struct node* llink;
 struct node* rlink;
};

typedef struct node NODE;
NODE *newnode,*start=NULL,*currptr;

NODE *getnode()
{
 newnode=(NODE*)malloc(sizeof(NODE));
 newnode->llink=NULL;
 newnode->rlink=NULL;
 printf("\nENTER THE ELEMENT\n");
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
    for (currptr=start;currptr->rlink!=NULL;currptr=currptr->rlink);
    currptr->rlink=newnode;
 }
}




void display()
{
 if(start==NULL)
    printf("\nTHE LIST IS EMPTY\n");
 else
 {
    for(currptr=start;currptr!=NULL;currptr=currptr->rlink)
    printf("\n%d\n",currptr->d);
 }
}



int main()
{
  while(1)
  {
    int ch;
    printf("\n\n\nENTER\n 1.for insertion into doubly linked list  \n 2.for displaying doubly linked list\n 3.for exit\n\n");
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