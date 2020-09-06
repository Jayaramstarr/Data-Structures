#include <stdio.h>
#include <stdlib.h>


struct node
{
    int d;
    struct node* link;
};

typedef struct node NODE;
NODE *newnode,*last=NULL,*currptr,*ptr1=NULL,*lptr=NULL,*ptr,*temp,*head;


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


void deletebeg()
{
 if(last==NULL)
  printf("\nList is empty\n");
 else if(last->link==last)
 {
  ptr=last;
  last->link=NULL;
  last=NULL;
  free(ptr);
 }
 else
 {
  ptr=last->link;
  last->link=ptr->link;
  free(ptr);
 }
}


void deleteend()
{
 if(last==NULL)
  printf("\nList is empty\n");
 else if(last->link==last)
 {
  ptr=last;
  last->link=NULL;
  last=NULL;
  free(ptr);
 }
 else
 {
  currptr=last->link;
  ptr=NULL;
  while(currptr->link!=last->link)
  {
  ptr=currptr;
  currptr=currptr->link;
  }
  ptr->link=last->link;
  last=ptr;
  free(currptr);
 }
}


void delete_node()
{
  if(last==NULL)
  {
    printf("\nList is empty\n");
    return;
  }
  int value;
  printf("\nEnter the value to be deleted\n");
  scanf("%d",&value);
  if(last->link->d==value)
  {
    deletebeg();
    printf("\nNode %d was deleted\n",value);
    return;
  }
  
  int c=0,i,f=0;
  ptr=last->link;
  while(ptr->link!=last->link)
  {
    ptr=ptr->link;
    ++c;
  }
  currptr=last->link;
  ptr=NULL;
  for(i=1;i<=c;++i)
  {
    if(currptr->d == value)
    {
      f=1;
      break;
    }
    ptr=currptr;
    currptr=currptr->link;
  }
  if(f==1)
  {
    ptr->link=currptr->link;
    printf("\nNode %d was deleted\n",value);
    free(currptr);
  }
  else
  {
    if(last->d == value)
    {
      deleteend();
      printf("\nNode %d was deleted\n",value);
      return;
    }
    else
      printf("\nNode not found\n");
  }
    
}


void swap(NODE *a, NODE *b) 
{ 
    int temp = a->d; 
    a->d = b->d; 
    b->d = temp; 
} 


void insert_into_ordered_list() 
{ 
    insert();
    int swapped, i; 
    if (last == NULL) 
    {
        printf("\n List empty\n");
        return;
    }
    do
    { 
        swapped = 0; 
        ptr1 = last->link; 
  
        while (ptr1->link != last->link) 
        { 
            if (ptr1->d > ptr1->link->d) 
            {  
                swap(ptr1, ptr1->link); 
                swapped = 1; 
            } 
            ptr1 = ptr1->link; 
        } 
        lptr = ptr1; 
    } 
    while (swapped);
    head=last->link; 
} 

int main()
{
  while(1)
  {
    int ch;
    printf("\n\n\nENTER\n 1.for insertion into circular linked list  \n 2.for displaying circular linked list \n 3.for ordered insertion\n 4.Delete a node based on value\n 5.for exit\n\n");
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
        insert_into_ordered_list();
        break;
      case 4:
        delete_node();
        break;
      case 5:
        exit(0);
        break;
      default:
        printf("\n Wrong choice entered \n");
    }
  }
 }