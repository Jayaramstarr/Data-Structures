#include <stdio.h>
#include <stdlib.h>
struct node
{
 int d;
 struct node *link;
};

typedef struct node NODE;
NODE *prevptr,*currptr,*start,*newnode;
int c;

NODE *getnode()
{
 newnode=(NODE*)malloc(sizeof(NODE));
 newnode->link=NULL;
 printf("\nENTER THE DATA\n");
 scanf("%d",&newnode->d);
 c++;
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
    while(currptr->link!=NULL)
        currptr=currptr->link;
    currptr->link=newnode;
    }
}


void display()
{
 if(start==NULL)
    printf("\nLIST IS EMPTY\n");
 else
    for(currptr=start;currptr!=NULL;currptr=currptr->link)
        printf("\n%d\n",currptr->d);
}


void palindrome()
{
 if(start==NULL)
    printf("\nLIST IS EMPTY\n");
 else
 {
    int i=0,j;
    NODE *f,*r;
    while(i!=c/2)
    {
        f=start;
        r=start;
        for(j=0;j<i;++j)
            f=f->link;
        for(j=0;j<c-(i+1);++j)
            r=r->link;
        if(r->d!=f->d)
        {
            printf("\nTHE ENTERED LIST IS NOT PALINDROME\n");
            return;
        }
        ++i;
    }
    printf("\nTHE ENTERED LIST IS PALINDROME\n");
    return;
 }
}


int main()
{
 while(1)
 {
    printf("\n\n ENTER:\n1.FOR INSERTION\n2.TO CHECK FOR PALINDROME\n3.FOR DISPLAYING\n4.FOR EXIT\n\n");
    int ch;
    scanf("%d",&ch);
    printf("\n\n");
    switch(ch)
    {
        case 1:insert();break;
        case 2:palindrome();break;

        case 3:display();break;

        case 4:exit(0);break;

        default:printf("\nYOU HAVE ENTERED WRONG CHOICE\n");
    }
 }
return 0;
}