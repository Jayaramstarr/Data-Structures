#include <stdio.h>
#include <stdlib.h>

struct node
{
 int d;
 struct node* link;
};

typedef struct node NODE;
NODE *newnode,*start=NULL,*nstart=NULL,*currptr,*ptr,*temp;

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



int main()
{
    int l,i=0;
    printf("\nEnter the length of the list to be created\n");
    scanf("%d",&l);
    while (i<l)
    {
        ++i;
        insert();
    }
    printf("\nCombined list\n");
    for(currptr=start;currptr!=NULL;currptr=currptr->link)
        printf("\n%d",currptr->d);
    printf("\n\n");
    i=0;
    ptr=start;
    for(currptr=start;i<l/2;currptr=currptr->link)
        ++i;
    nstart=currptr->link;
    currptr->link=NULL;
    printf("\nList 1\n");
    for(currptr=start;currptr!=NULL;currptr=currptr->link)
        printf("\n%d",currptr->d);
    printf("\n\n");
    printf("\nList 2\n");
    for(currptr=nstart;currptr!=NULL;currptr=currptr->link)
        printf("\n%d",currptr->d);
    printf("\n\n");
}
