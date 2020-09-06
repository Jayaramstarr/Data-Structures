#include <stdio.h>
#include <stdlib.h>

struct node
{
 int d;
 struct node* link;
};

typedef struct node NODE;
NODE *newnode,*start=NULL,*currptr,*ptr,*temp;

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

void smallest()
{
    int small = start->d;
    for(currptr=start;currptr!=NULL;currptr=currptr->link)
    {
        if(currptr->d<small)
            small=currptr->d;
    }
    printf("\nThe smallest item in the list is %d\n",small);
}

int main()
{
  while(1)
  {
    int ch;
    printf("\n\n\nENTER\n 1.for insertion into singly linked list  \n 2.for displaying singly linked list \n 3.for displaying smallest item in the list\n 4.for exit\n\n");
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
        smallest();
        break;
      case 4:
        exit(0);
        break;
      default:
        printf("\n Wrong choice entered \n");
    }
  }
 }
