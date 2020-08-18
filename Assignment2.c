#include <stdio.h>


void bubbleSort(int arr[], int count) 
{ 
  int i=0,j=0,temp=0;
    for(i=count-2;i>=0;i--)
    {
      for(j=0;j<=i;j++)
      {
        if(arr[j]>arr[j+1])
        {
           temp=arr[j];
           arr[j]=arr[j+1];
           arr[j+1]=temp;
        }
      }
    }
} 

int main(void) {
  printf("Enter size of the array\n");
  int size;
  scanf("%d",&size);  
  printf("\nEnter array elements\n");
  int arr[100];
  for(int i=0; i<size; ++i)
    scanf("%d",&arr[i]);
  bubbleSort(arr,size);
  for(int i=0; i<size; ++i)
    printf("\n%d",arr[i]);
  return 0;
}
