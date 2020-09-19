#include <stdio.h>
#include <stdlib.h>

int Partition(int *A, int low, int high);
void QuickSort(int *A, int low, int high);

void QuickSort(int *A, int low, int high)
{
  int pivot;
  if (high > low)
  {
    pivot = Partition(A, low, high);
    QuickSort(A, low, pivot - 1);
    QuickSort(A, pivot, high);
  }
}

int Partition(int *A, int low, int high)
{
  int left, right, pivot_item = A[low];
  left = low;
  right = high;
  while (left < right)
  {
    while (A[left] <= pivot_item)
      left++;
    while (A[right] > pivot_item)
      right--;
    if (left < right)
    {
      int tmp = A[left];
      A[left] = A[right];
      A[right] = tmp;
    }
  }
  A[low] = A[right];
  A[right] = pivot_item;
  return right;
}

void displayElemOfArray(int *A, int arraySize)
{
  for (int i = 0; i < 20; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}

int main()
{
  int arraySize = 20;
  int B[20];
  for (int i = 0; i < arraySize; i++)
  {
    B[i] = rand() % 10 + 1;
  }
  printf("-----Initial State-----\n");
  displayElemOfArray(B, arraySize);
  QuickSort(B, 0, 20);
  displayElemOfArray(B, arraySize);
}
