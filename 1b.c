#include <stdio.h>
#include <stdlib.h>


struct node
{
    int d;
    struct node* link;
};
typedef struct node NODE;
NODE *newnode,*last=NULL,*currptr,*ptr,*temp;


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
 if(last==NULL)
 {
    last=temp;
    last->link=last;
 }
 else
 {
    temp->link=last->link;
    last->link=temp;
    last=temp;
 }
}



void display()
{
 if(last==NULL)
    printf("\nList is empty\n");
 else
 {
    for(ptr=last->link;ptr!=last;ptr=ptr->link)
        printf("\n%d",ptr->d);
    printf("\n%d",ptr->d);
    printf("\n\n");
 }
}


int main()
{
  while(1)
  {
    int ch;
    printf("\n\n\nENTER\n 1.for insertion into circular linked list  \n 2.for displaying circular linked list\n 3.for exit\n\n");
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