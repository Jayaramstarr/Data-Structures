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


void delete_node()
{
    if(start==NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    int value;
    printf("\nEnter the value to be deleted\n");
    scanf("%d",&value);
    ptr=start;
    for(currptr=start;currptr->link!=NULL;currptr=currptr->link)
    {
        if(currptr->d==value && currptr == start)
        {
            start = start->link;
            free(ptr);
            printf("\n%d node deleted\n",value);
            return;
        }
        if(currptr->d==value)
        {
            ptr->link=currptr->link;
            free(currptr);
            printf("\n%d node deleted\n",value);
            return;
        }
        else
            ptr=currptr;
    }
    printf("\nNode not found\n");
}

int main()
{
  while(1)
  {
    int ch;
    printf("\n\n\nENTER\n 1.for insertion into singly linked list  \n 2.for displaying singly linked list\n  \n 3.for deleting a particular value\n 4.for exit\n\n");
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
        delete_node();
        break;
      case 4:
        exit(0);
        break;
      default:
        printf("\n Wrong choice entered \n");
    }
  }
 }
