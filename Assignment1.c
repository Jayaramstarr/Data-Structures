#include <stdio.h>


int calc(int arr[], int size)
{
  int sum = 0;
  for(int i=0; i<size; ++i)
   sum=sum+arr[i];
  return sum/size;
}


int main(void) {
  printf("Enter size of the array\n");
  int size;
  scanf("%d",&size);  
  printf("\nEnter array elements\n");
  int arr[100];
  for(int i=0; i<size; ++i)
    scanf("%d",&arr[i]);
  printf("\nAverage of array is %d\n", calc(arr,size));
  return 0;
}
