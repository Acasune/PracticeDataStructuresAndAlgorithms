#include <stdio.h>
#include <stdlib.h>

void Merge(int A[], int tmp[], int, int l, int r);
void MergeSort(int A[], int tmp[], int l, int r);

void MergeSort(int A[], int tmp[], int l, int r)
{
  int mid;
  if (r > l)
  {
    mid = (l + r) / 2;
    MergeSort(A, tmp, l, mid);
    MergeSort(A, tmp, mid + 1, r);
    Merge(A, tmp, l, mid + 1, r);
  }
}
