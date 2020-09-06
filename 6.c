#include <stdio.h>
#include <stdlib.h>

struct node
{
 int d;
 struct node* link;
};

typedef struct node NODE;
NODE *newnode,*start,*start1=NULL,*start2=NULL,*currptr,*ptr,*temp;

NODE *getnode()
{
  newnode=(NODE*)malloc(sizeof(NODE));
  newnode->link=NULL;
  printf("\nEnter the element\n");
  scanf("%d",&newnode->d);
  printf("\n\n");
  return newnode;
}



void concat_list()
{
    for(currptr=start1;currptr->link!=NULL;currptr=currptr->link);
    currptr->link=start2;
}

int main()
{
  int i = 0;
  while(i<3)
  {
    temp=getnode();
    if(start1==NULL)
        start1=temp;
    else
    {
        for(ptr=start1;ptr->link!=NULL;ptr=ptr->link);
            ptr->link=temp;
    }
    ++i;
  }
  printf("\n\n");
  printf("\n List 1\n");
  for(currptr=start1;currptr!=NULL;currptr=currptr->link)
    printf("\n%d",currptr->d);
  printf("\n\n");
  i=0;
  while(i<2)
  {
    temp=getnode();
    if(start2==NULL)
        start2=temp;
    else
    {
        for(ptr=start2;ptr->link!=NULL;ptr=ptr->link);
            ptr->link=temp;
    }
    ++i;
  }
  printf("\n\n");
  printf("\n List 2\n");
  for(currptr=start2;currptr!=NULL;currptr=currptr->link)
    printf("\n%d",currptr->d);
  printf("\n\n");
  concat_list();
  
  printf("\n\n");
  printf("\n List combined\n");
  for(currptr=start1;currptr!=NULL;currptr=currptr->link)
    printf("\n%d",currptr->d);
  printf("\n\n");
}
