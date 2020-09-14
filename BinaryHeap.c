#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryHeap
{
  int *array;
  int count;
  int capacity;
  int heap_type;
} BH;

BH *createHeap(int capacity, int heap_type)
{
  BH *h = (BH *)malloc(sizeof(BH));
  if (h == NULL)
  {
    printf("Memorry Error");
    return;
  }
  h->heap_type = heap_type;
  h->count = 0;
  h->capacity = capacity;
  h->array = (int *)malloc(sizeof(int) * h->capacity);
  if (h->array == NULL)
  {
    printf("Memory Error");
    return;
  }
  return h;
}

int getParent(BH *h, int i)
{
  if (i <= 0 || i >= h->count)
    return -1;
  return (i - 1) / 2;
}

int getLeftChild(BH *h, int i)
{
  int left = 2 * i + 1;
  if (left >= h->count)
    return -1;
  return left;
}

int getRightChild(BH *h, int i)
{
  int right = 2 * i + 2;
  if (right >= h->count)
    return -1;
  return right;
}

int getMaximum(BH *h)
{
  if (h->count == 0)
    return -1;
  return h->array[0];
}

void percolateDown(BH *h, int i)
{
  int l, r, max, tmp;
  l = getLettChild(h, i);
  r = getRightChild(h, i);
  if (l != -1 && h->array[i])
    max = l;
  else
    max = i;
  if (r != -1 && h->array[r] > h->array[max])
    max = r;
  if (max != i)
  {
    tmp = h->array[i];
    h->array[i] = h->array[max];
    h->array[i] = tmp;
  }
  percolateDown(h, max);
}

int deleteMax(BH *h)
{
  int data;
  if (h->count == 0)
    return 0;
  data = h->array[0];
  h->array[0] = h->array[h->count - 1];
  h->count--;
  percolateDown(h, 0);
  return data;
}

void ResizeHeap(BH *h)
{
  int *array_old = h->array;
  h->array = (int *)malloc(sizeof(int) * h->capacity * 2);
  if (h->array == NULL)
  {
    printf("Memory Error");
    return;
  }
  for (int i = 0; i < h->capacity; i++)
    h->array[i] = array_old[i];
  h->capacity *= 2;
  free(array_old);
}

int insert(BH *h, int data)
{
  int i;
  if (h->count == h->capacity)
    ResizeHeap(h);
  h->count++;
  i = h->count - 1;
  while (i > 0 && data > h->array[(i - 1) / 2])
  {
    h->array[i] = h->array[(i - 1) / 2];
    i = (i - 1) / 2;
  }
  h->array[i] = data;
}
