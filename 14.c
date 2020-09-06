#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int coeff;
    int pow;
    struct node* link;
};

typedef struct node NODE;
NODE *newnode,*start=NULL,*currptr,*prevptr,*temp;

NODE *getnode()
{
    newnode=(NODE*)malloc(sizeof(NODE));
    newnode->link=NULL;
    printf("\nEnter the coefficient and power\n");
    scanf("%d%d",&newnode->coeff,&newnode->pow);
    printf("\n\n");
    return newnode;
}


void insert()
{
 temp=getnode();
 if(start==NULL)
    start=temp;
 else if(start->pow>=temp->pow)
 {
    temp->link=start;
    start=temp;
 }
 else
 {
    currptr=start;
    prevptr=NULL;
    while(currptr!=NULL&&currptr->pow<=temp->pow)
    {
        prevptr=currptr;
        currptr=currptr->link;
    }
    if(currptr==NULL&&prevptr->pow<=temp->pow)
        prevptr->link=temp;
    else
    {
        temp->link=prevptr->link;
        prevptr->link=temp;
    }
 }
}


void display()
{
 if(start==NULL)
    printf("\nList is empty\n");
 else
 for(currptr=start;currptr!=NULL;currptr=currptr->link)
    printf("\n%dx%d",currptr->coeff,currptr->pow);
 printf("\n\n");
}


void evaluate()
{
 int x,sum=0;
 printf("\nEnter the value of x\n");
 scanf("%d",&x);
 currptr=start;
 while(currptr!=NULL)
 {
    sum=sum+currptr->coeff*pow(x,currptr->pow);
    currptr=currptr->link;
 }
 printf("\nThe solution of the equation is %d\n",sum);
}


int main()
{
  while(1)
  {
    int ch;
    printf("\n\n\nENTER\n 1.for insertion\n 2.for display\n 3.for evaluation\n 4.to exit\n\n");
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
            evaluate();
            break;
        case 4:
            exit(0);
            break;
        default:
        printf("\n Wrong choice entered \n");
    }
 }
}