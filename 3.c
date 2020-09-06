#include <stdio.h>
#include <stdlib.h>

struct node
{
 int d1;
 int d2;
 struct node* link;
};

typedef struct node NODE;
NODE *newnode,*start=NULL,*currptr,*ptr,*temp;

NODE *getnode()
{
  newnode=(NODE*)malloc(sizeof(NODE));
  newnode->link=NULL;
  printf("\nEnter the first element\n");
  scanf("%d",&newnode->d1);
  printf("\nEnter the second element\n");
  scanf("%d",&newnode->d2);
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


void sum()
{
    int sum = 0;
    for(ptr=start;ptr!=NULL;ptr=ptr->link)
        sum = sum + ptr->d1;
    printf("\n\nThe sum of first values of nodes is %d\n\n",sum);
}

int count_nodes()
{
    int count = 0;
    for(currptr=start;currptr!=NULL;currptr=currptr->link)
        ++count;
    return count;
}


void average()
{
    int sum = 0;
    for(ptr=start;ptr!=NULL;ptr=ptr->link)
        sum = sum + ptr->d2;
    printf("\n\nThe average of second values of nodes is %d\n\n",sum/count_nodes());
}

void display()
{
 if(start==NULL)
  printf("\n List empty\n");
 else
 {
  printf("\n\n");
  for(currptr=start;currptr!=NULL;currptr=currptr->link)
  printf("\n%d %d",currptr->d1,currptr->d2);
  printf("\n\n");
 }
}

int main()
{
  while(1)
  {
    int ch;
    printf("\n\n\nENTER\n 1.for insertion into singly linked list  \n 2.for displaying singly linked list \n 3.for calculating sum of first values \n 4.for calculating average of second values \n 5.for exit\n\n");
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
        sum();
        break;
      case 4:
        average();
        break;
      case 5:
        exit(0);
        break;
      default:
        printf("\n Wrong choice entered \n");
    }
  }
 }
