#include<stdio.h>

int main()
{
    printf('Hello World');
    return 0;
}

#include <stdio.h>
#include<stdlib.h>

struct Hotel{
  char item[20];
  int qty;
  float price;
  struct Hotel *link;
}*ptrHotel, *head;

int main()
{
  ptrHotel = NULL;
  printf("\nEnter the number of items\n"); int num;
  scanf("%d",&num);
  ptrHotel = (struct Hotel*)malloc(num * sizeof(struct Hotel));
  head = ptrHotel;
  for(int i=0; i<num ; ++i)
  {
    printf("\nEnter the name of item#%d",i+1);
    scanf("%s",ptrHotel->item);
    printf("\nEnter the price of item#%d",i+1);
    scanf("%f",&ptrHotel->price);
    printf("\nEnter the quantity of item#%d",i+1);
    scanf("%d",&ptrHotel->qty);
    ptrHotel->link=ptrHotel+1;
    ptrHotel=ptrHotel->link;
  }
  for(int j =0; j<num; j++)
  {
    printf("\nItem %d details are",j+1);
    printf("\nItem name: %s\nItem price %f\nItem quantity%d",head->item,head->price,head->qty);
  }
  printf("\n");
}
