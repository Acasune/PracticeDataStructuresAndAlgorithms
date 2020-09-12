#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

typedef struct ArrayStack
{
  int top;
  int capacity;
  int *array;
} STK;

int CreateStack(STK *pSTK)
{
  int i;
  pSTK->array = (int *)malloc(sizeof(int) * SIZE);
  pSTK->top = SIZE;
  if (pSTK->array == NULL)
  {
    printf("Malloc Error/n");
    return -1;
  }
  for (i = 0; i < SIZE; i++)
  {
    pSTK->array[i] = 0;
    printf("%d\n", pSTK->array[i]);
  }
  return 0;
}

int IsEmptyStack(STK *pSTK)
{
  return (pSTK->top == 0);
}

int IsFullStack(STK *pSTK)
{
  return (pSTK->top == pSTK->capacity);
}

void Push(STK *pSTK, int data)
{
  if (IsFullStack(pSTK))
    printf("Stack Overflow\n");
  else
  {
    printf("%d is pushed \n", data);
    pSTK->array[++pSTK->top] = data;
  }
}

int Pop(STK *pSTK)
{
  if (IsEmptyStack(pSTK))
  {
    printf("Stack is Empty\n");
    return 0;
  }
  else
  {
    printf("%d is poped \n", pSTK->array[pSTK->top]);
    return pSTK->array[pSTK->top--];
  }
}

int DeleteStack(STK *pSTK)
{
  free(pSTK->array);
  printf("Array is deleted\n");
  return 0;
}

int main()
{
  STK Stack;
  STK *pStack = &Stack;

  CreateStack(pStack);

  Pop(pStack);
  Push(pStack, 1);
  Push(pStack, 2);
  Push(pStack, 3);
  Push(pStack, 4);
  Push(pStack, 5);
  Push(pStack, 6);
  Push(pStack, 7);
  Push(pStack, 8);
  Pop(pStack);
  Pop(pStack);
  Pop(pStack);
  Pop(pStack);
  Push(pStack, 3);
  Push(pStack, 4);
  Push(pStack, 5);
  Push(pStack, 6);
  Push(pStack, 7);
  Pop(pStack);
  Pop(pStack);
  Pop(pStack);
  Pop(pStack);
  Pop(pStack);
  Pop(pStack);
  Pop(pStack);
  Pop(pStack);
  Push(pStack, 1);
  Push(pStack, 2);
  Push(pStack, 3);
  Push(pStack, 4);
  Push(pStack, 5);
  Push(pStack, 6);
  Push(pStack, 7);
  Push(pStack, 8);

  DeleteStack(pStack);

  return 0;
}

void display(STK *pSTK)
{
  int i;
  for (i = 0; i < SIZE; i++)
  {
    printf("%d ", pSTK->array[i]);
  }
  printf("\n");
}
