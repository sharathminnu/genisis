
#include <stdio.h>

int binarySearch(int a[], int k,int low,int high) {
    
 
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (a[mid] == k)
      return mid;

    if (a[mid] < k)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

int main(void) {
  int array[] = {3, 4, 5, 6, 7, 8, 9};
  int low = array[0];
  int high = (sizeof(array)/sizeof(array[0])) - 1;
  
  int x = 4;
  int result = binarySearch(array, x,low,high);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result);
  return 0;
}