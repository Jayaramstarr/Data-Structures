#include <stdio.h>
struct node
{
  char s[30];
  int i;
  float f;
}node1;



void printer(struct node n)
{
  printf("\nName of the person is         :%s", n.s);
  printf("\nAge of the person is          :%d",n.i);
  printf("\nBank balance of the person    :%f",n.f);
}


void callByValue(struct node n)
{
  n.i=30;
  n.f=30000.00;
}

void callByReference(struct node* n)
{
  n->i=30;
  n->f=30000.00;
}

int main()
{
  printf("\nEnter name,age and bank balance of the person\n");
  scanf("%s",node1.s);
  scanf("%d",&node1.i);
  scanf("%f",&node1.f);
  callByValue(node1);
  printer(node1);
  callByReference(&node1);
  printer(node1);
  return 0;
}
