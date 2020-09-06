#include <stdio.h>
#include <stdlib.h>

struct node
{
    int d;
    struct node* link;
};

typedef struct node NODE;
NODE *newnode,*start=NULL,*currptr,*ptr,*ptr1=NULL,*lptr=NULL,*temp;

NODE *getnode()
{
    newnode=(NODE*)malloc(sizeof(NODE));
    newnode->link=NULL;
    printf("\nEnter the element\n");
    scanf("%d",&newnode->d);
    printf("\n\n");
    return newnode;
}


void insertbeg()
{
    temp=getnode();
    if(start==NULL)
    start=temp;
    else
    {
    temp->link=start;
    start=temp;
    }
}


void insertend()
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



void insertpos()
{
 int pos,i,c=0;
 printf("\n Enter position\n");
 scanf("%d",&pos);
 temp=getnode();
 ptr=start;
 while(ptr!=NULL)
 {
    ptr=ptr->link;
    ++c;
 }
 if(pos==1)
    insertbeg();
 else if(pos>1&&pos<=c)
 {
    ptr=start;
    for(i=1;i<pos-1;++i)
    ptr=ptr->link;
    temp->link=ptr->link;
    ptr->link=temp;
 }
 else if(pos==c+1)
    insertend();
 else
    printf("\n Invalid position \n");
}



void swap(NODE *a, NODE *b) 
{ 
    int temp = a->d; 
    a->d = b->d; 
    b->d = temp; 
} 


void insert_into_ordered_list() 
{ 
    insertbeg();
    int swapped, i; 
    if (start == NULL) 
    {
        printf("\n List empty\n");
        return;
    }
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->link != lptr) 
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


int main()
{
 while(1)
 {
    int ch;
    printf("\n\n\nENTER\n 1.for insertion based on a position\n 2.for insertion into ordered list\n 3.for insertion at the end of the list\n 4.for insertion at the beginning of the list\n 5.for display\n 6.for exit\n\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        insertpos();
        break;
    case 2:
        insert_into_ordered_list();
        break;
    case 3:
        insertend();
        break;
    case 4:
        insertbeg();
        break;
    case 5:
        display();
        break;
    case 6:
        exit(0);
        break;
    default:
    printf("\n Wrong choice entered \n");
    }
 }
}